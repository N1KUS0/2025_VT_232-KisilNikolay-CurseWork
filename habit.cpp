#include "habit.h"

Habit::Habit(int id, const QString& name, const QString& description, const QDate& creationDate, const QSet<int>& targetDays)
    : m_id(id), m_name(name), m_description(description), m_creationDate(creationDate), m_targetDays(targetDays) {}

void Habit::markCompleted(const QDate& date) {
    m_completedDates.insert(date);
}

bool Habit::isCompleted(const QDate& date) const {
    return m_completedDates.contains(date);
}

// Геттеры
int Habit::getId() const { return m_id; }
QString Habit::getName() const { return m_name; }
QString Habit::getDescription() const { return m_description; }
QDate Habit::getCreationDate() const { return m_creationDate; }
QSet<int> Habit::getTargetDays() const { return m_targetDays; }
