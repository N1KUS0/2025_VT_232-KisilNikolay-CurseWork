#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QLocale>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels({"Название", "Описание", "Дни", "Прогресс"});
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

     connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::onAddButtonClicked);
    connect(ui->deleteButton, &QPushButton::clicked, this, &MainWindow::onDeleteButtonClicked);
    connect(ui->markButton, &QPushButton::clicked, this, &MainWindow::onMarkCompletedClicked);
    connect(ui->calendarWidget, &QCalendarWidget::selectionChanged, this, [this]() {
        onDateSelected(ui->calendarWidget->selectedDate());
    });

    loadData();
    updateTable();
}

MainWindow::~MainWindow() {
    saveData();
    delete ui;
}

void MainWindow::updateTable() {
    ui->tableWidget->setRowCount(0);
    QLocale russian(QLocale::Russian);

    for (const Habit &habit : m_tracker.getHabits()) {
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(habit.getName()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(habit.getDescription()));

        QString daysStr;
        for (int day : habit.getTargetDays()) {
             daysStr += russian.dayName(day, QLocale::ShortFormat) + ", ";
        }
        daysStr.chop(2);
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(daysStr));
    }
}

void MainWindow::onAddButtonClicked() {
      QMessageBox::information(this, "Info", "Функция добавления будет реализована позже");
}

void MainWindow::onDeleteButtonClicked() {
    int row = ui->tableWidget->currentRow();
    if (row >= 0) {
        m_tracker.removeHabit(m_tracker.getHabits()[row].getId());
        updateTable();
    }
}

void MainWindow::onMarkCompletedClicked() {
    QDate selectedDate = ui->calendarWidget->selectedDate();
    int row = ui->tableWidget->currentRow();
    if (row >= 0) {
        Habit habit = m_tracker.getHabits()[row];
        habit.markCompleted(selectedDate);
        updateTable();
    }
}

void MainWindow::onDateSelected(const QDate &date) {
    ui->statusbar->showMessage("Выбрана дата: " + date.toString("dd.MM.yyyy"));
}

void MainWindow::loadData() {
    m_storage.loadFromFile(m_tracker, m_dataFilePath);
}

void MainWindow::saveData() {
    m_storage.saveToFile(m_tracker, m_dataFilePath);
}
