#include "habitdialog.h"
#include "ui_habitdialog.h"

HabitDialog::HabitDialog(QWidget *parent, const Habit *habit)
    : QDialog(parent), ui(new Ui::HabitDialog) {
    ui->setupUi(this);

    // Заполнение данных, если передан существующий Habit
    if (habit) {
        ui->nameEdit->setText(habit->getName());
        ui->descriptionEdit->setText(habit->getDescription());

        for (int day : habit->getTargetDays()) {
            QCheckBox *checkBox = findChild<QCheckBox*>(QString("day%1CheckBox").arg(day));
            if (checkBox) checkBox->setChecked(true);
        }
    }
}

HabitDialog::~HabitDialog() {
    delete ui;
}

QString HabitDialog::getName() const {
    return ui->nameEdit->text().trimmed();
}

QString HabitDialog::getDescription() const {
    return ui->descriptionEdit->toPlainText().trimmed();
}

QSet<int> HabitDialog::getTargetDays() const {
    QSet<int> days;
    for (int day = 1; day <= 7; ++day) {
        QCheckBox *checkBox = findChild<QCheckBox*>(QString("day%1CheckBox").arg(day));
        if (checkBox && checkBox->isChecked()) {
            days.insert(day);
        }
    }
    return days;
}

void HabitDialog::accept() {
    if (getName().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Название привычки не может быть пустым!");
        return;
    }
    if (getTargetDays().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Выберите хотя бы один день!");
        return;
    }
    QDialog::accept();  // Вызываем базовую реализацию
}
