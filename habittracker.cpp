#include "habittracker.h"

void HabitTracker::addHabit(const Habit& habit) {
    m_habits.append(habit);
}

void HabitTracker::removeHabit(int id) {
    auto it = std::remove_if(m_habits.begin(), m_habits.end(), [id](const Habit& h) { return h.getId() == id; });
    m_habits.erase(it, m_habits.end());
}

QList<Habit> HabitTracker::getHabitsForDate(const QDate& date) const {
    QList<Habit> result;
    for (const auto& habit : m_habits) {
        if (habit.getTargetDays().contains(date.dayOfWeek())) {
            result.append(habit);
        }
    }
    return result;
}

int HabitTracker::generateId() const {
    static int nextId = 1;
    return nextId++;
}
