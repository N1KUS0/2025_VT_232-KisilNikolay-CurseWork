#include "mainwindow.h"
#include "habitdialog.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QLocale>
#include <QTextCharFormat>
#include <QToolTip>
#include <QMap>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels({"Название", "Описание", "Дни", "Прогресс"});
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::onAddButtonClicked);
    connect(ui->deleteButton, &QPushButton::clicked, this, &MainWindow::onDeleteButtonClicked);
    connect(ui->markButton, &QPushButton::clicked, this, &MainWindow::onMarkCompletedClicked);
    connect(ui->editButton, &QPushButton::clicked, this, &MainWindow::onEditButtonClicked);
    connect(ui->calendarWidget, &QCalendarWidget::selectionChanged, this, [this]() {
        onDateSelected(ui->calendarWidget->selectedDate());
    });

    ui->calendarWidget->setGridVisible(true);
    ui->calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);

    loadData();
    updateTable();
}

MainWindow::~MainWindow() {
    saveData();
    updateCalendarAppearance();
    delete ui;
}

void MainWindow::updateProgressForRow(int row) {
    if (row < 0 || row >= m_tracker.getHabits().size()) return;

    const Habit& habit = m_tracker.getHabits()[row];
    QTableWidgetItem* item = ui->tableWidget->item(row, 3);

    if (!item) {
        item = new QTableWidgetItem();
        ui->tableWidget->setItem(row, 3, item);
    }

    int completed = habit.getCompletedDates().size();
    item->setText(QString("%1 дн.").arg(completed));

    if (completed == 0) {
        item->setBackground(QColor(255, 200, 200)); // Красный
    } else {
        item->setBackground(QColor(200, 255, 200)); // Зеленый
    }
}
void MainWindow::updateTable() {
    ui->tableWidget->setRowCount(m_tracker.getHabits().size());
    QLocale locale(QLocale::Russian);

    for (int row = 0; row < m_tracker.getHabits().size(); ++row) {
        const Habit& habit = m_tracker.getHabits()[row];
        QString habitName = habit.getName();

        QTableWidgetItem* nameItem = new QTableWidgetItem(habitName);
        nameItem->setToolTip(habitName);
        ui->tableWidget->setItem(row, 0, nameItem);

        QTableWidgetItem* descItem = new QTableWidgetItem(habit.getDescription());
        descItem->setToolTip(habit.getDescription());
        ui->tableWidget->setItem(row, 1, descItem);

        QString daysStr;
        for (int day : habit.getTargetDays()) {
            daysStr += locale.dayName(day, QLocale::ShortFormat) + " ";
        }
        QTableWidgetItem* daysItem = new QTableWidgetItem(daysStr);
        daysItem->setToolTip("Дни выполнения: " + daysStr);
        ui->tableWidget->setItem(row, 2, daysItem);

        updateProgressForRow(row);
        updateCalendarAppearance();
    }
}

void MainWindow::onDeleteButtonClicked() {
    int row = ui->tableWidget->currentRow();
    if (row >= 0) {
        m_tracker.removeHabit(m_tracker.getHabits()[row].getId());
        updateTable();
    }
}
void MainWindow::updateCalendarAppearance() {
    ui->calendarWidget->setDateTextFormat(QDate(), QTextCharFormat());

    m_dateHabits.clear();
    for (const Habit& habit : m_tracker.getHabits()) {
        for (const QDate& date : habit.getCompletedDates()) {
            m_dateHabits[date].insert(habit.getName());
        }
    }

    QTextCharFormat completedFormat;
    completedFormat.setBackground(QColor(144, 238, 144));

    for (const QDate& date : m_dateHabits.keys()) {
        QStringList habitsList;
        for (const QString& habitName : m_dateHabits[date]) {
            habitsList << habitName;
        }

        completedFormat.setToolTip("Выполненные привычки:\n" + habitsList.join("\n"));
        ui->calendarWidget->setDateTextFormat(date, completedFormat);
    }
}

void MainWindow::onMarkCompletedClicked() {
    QDate selectedDate = ui->calendarWidget->selectedDate();
    int row = ui->tableWidget->currentRow();

    if (row < 0 || row >= m_tracker.getHabits().size()) {
        QMessageBox::information(this, "Ошибка",
                                 QString("Привычка не выбрана"));
        return;
    }

    Habit& habit = m_tracker.getHabits()[row];
    QString habitName = habit.getName();

    if (!habit.getTargetDays().contains(selectedDate.dayOfWeek())) {

        static QMap<QString, QString> dayCases = {
            {"понедельник", "понедельникам"},
            {"вторник", "вторникам"},
            {"среда", "средам"},
            {"четверг", "четвергам"},
            {"пятница", "пятницам"},
            {"суббота", "субботам"},
            {"воскресенье", "воскресеньям"}
        };

        QLocale russian(QLocale::Russian);
        QString dayName = dayCases[russian.dayName(selectedDate.dayOfWeek(), QLocale::LongFormat)];
        QMessageBox::information(this, "Информация",
                                 QString("Привычка \"%1\" не должна выполняться по %2!")
                                     .arg(habitName)
                                     .arg(dayName));
        return;
    }

    if (habit.isCompleted(selectedDate)) {
        habit.getCompletedDates().remove(selectedDate);
        ui->statusbar->showMessage(
            QString("Снята отметка выполнения для \"%1\" на %2")
                .arg(habitName)
                .arg(selectedDate.toString("dd.MM.yyyy")),
            3000);
    } else {
        habit.markCompleted(selectedDate);
        ui->statusbar->showMessage(
            QString("Привычка \"%1\" отмечена выполненной на %2")
                .arg(habitName)
                .arg(selectedDate.toString("dd.MM.yyyy")),
            3000);
    }

    saveData();
    updateProgressForRow(row);
    updateCalendarAppearance();
}

void MainWindow::on_calendarWidget_clicked(const QDate& date) {
    QString message = QString("Выбрана дата: %1").arg(date.toString("dd.MM.yyyy"));

    if (m_dateHabits.contains(date)) {
        message += QString(" (Выполнено %1 привычек)").arg(m_dateHabits[date].size());
    }

    ui->statusbar->showMessage(message, 3000);
}

void MainWindow::onDateSelected(const QDate &date) {
    ui->statusbar->showMessage("Выбрана дата: " + date.toString("dd.MM.yyyy"));
}

void MainWindow::loadData() {
    if (DataStorage::loadFromFile(m_tracker, m_dataFilePath)) {
        updateTable();
        updateCalendarAppearance(); // Раскрашиваем календарь при загрузке
    }
}

void MainWindow::saveData() {
    if (!DataStorage::saveToFile(m_tracker, m_dataFilePath)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось сохранить данные!");
    }
}

void MainWindow::onAddButtonClicked() {
    HabitDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        Habit newHabit(
            m_tracker.generateId(),
            dialog.getName(),
            dialog.getDescription(),
            QDate::currentDate(),
            dialog.getTargetDays()
            );
        m_tracker.addHabit(newHabit);
        updateTable();
    }
}

void MainWindow::onEditButtonClicked() {
    int row = ui->tableWidget->currentRow();
    if (row >= 0) {
        Habit habit = m_tracker.getHabits()[row];
        HabitDialog dialog(this, &habit);
        if (dialog.exec() == QDialog::Accepted) {
            // Обновляем привычку
            Habit updatedHabit(
                habit.getId(),
                dialog.getName(),
                dialog.getDescription(),
                habit.getCreationDate(),
                dialog.getTargetDays()
                );
            m_tracker.removeHabit(habit.getId());
            m_tracker.addHabit(updatedHabit);
            updateTable();
        }
    }
}
