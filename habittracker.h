#ifndef HABITTRACKER_H
#define HABITTRACKER_H

#include "habit.h"
#include <QList>
#include <QDate>

class HabitTracker {
public:
    void addHabit(const Habit& habit);
    void removeHabit(int id);
    QList<Habit> getHabits() const;
    QList<Habit> getHabitsForDate(const QDate& date) const;

private:
    QList<Habit> m_habits;
    int generateId() const;
};

#endif // HABITTRACKER_H
