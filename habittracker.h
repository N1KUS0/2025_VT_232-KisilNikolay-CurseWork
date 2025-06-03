#ifndef HABITTRACKER_H
#define HABITTRACKER_H

#include "habit.h"
#include <QList>
#include <QDate>

class HabitTracker {
public:
    void addHabit(const Habit& habit);
    void removeHabit(int id);
    QList<Habit>& getHabits() { return m_habits; } // Неконстантная версия
    const QList<Habit>& getHabits() const { return m_habits; } // Константная версия
    QList<Habit> getHabitsForDate(const QDate& date) const;  // Привычки, актуальные на дату
    int generateId() const;  // Генератор уникальных ID

private:
    QList<Habit> m_habits;
};

#endif // HABITTRACKER_H
