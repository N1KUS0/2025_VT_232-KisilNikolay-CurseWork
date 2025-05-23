#ifndef HABITDIALOG_H
#define HABITDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "habit.h"


namespace Ui {
class HabitDialog;
}

class HabitDialog : public QDialog {
    Q_OBJECT

public:
    explicit HabitDialog(QWidget *parent = nullptr, const Habit *habit = nullptr);
    ~HabitDialog();

    QString getName() const;
    QString getDescription() const;
    QSet<int> getTargetDays() const;

private slots:
    void accept() override;

private:
    Ui::HabitDialog *ui;
};

#endif // HABITDIALOG_H
