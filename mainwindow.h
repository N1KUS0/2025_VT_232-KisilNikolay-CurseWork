#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "habittracker.h"
#include "datastorage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddButtonClicked();
    void onDeleteButtonClicked();
    void onMarkCompletedClicked();
    void onEditButtonClicked();
    void on_calendarWidget_clicked(const QDate &date);
    void onDateSelected(const QDate &date);

private:
    void updateCalendarAppearance();
    QMap<QDate, QSet<QString>> m_dateHabits;
    Ui::MainWindow *ui;
    HabitTracker m_tracker;
    DataStorage m_storage;
    QString m_dataFilePath = "habits.json";

    void updateTable();
    void updateProgressForRow(int);
    void loadData();
    void saveData();
};

#endif // MAINWINDOW_H
