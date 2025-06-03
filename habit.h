#ifndef HABIT_H
#define HABIT_H

#include <QString>
#include <QDate>
#include <QSet>

class Habit {
public:
    Habit(int id, const QString& name, const QString& description, const QDate& creationDate, const QSet<int>& targetDays);

    int getId() const;
    QString getName() const;
    QString getDescription() const;
    QDate getCreationDate() const;
    QSet<int> getTargetDays() const;  // Дни недели
    const QSet<QDate>& getCompletedDates() const { return m_completedDates; } // Для константных объектов
    QSet<QDate>& getCompletedDates() { return m_completedDates; } // Для обычных объектов
    void markCompleted(const QDate& date) { m_completedDates.insert(date); }
    bool isCompleted(const QDate& date) const { return m_completedDates.contains(date); }

private:
    int m_id;
    QString m_name;
    QString m_description;
    QDate m_creationDate;
    QSet<int> m_targetDays;  // Например: {1, 3, 5} — Пн, Ср, Пт
    QSet<QDate> m_completedDates;  // Даты, когда привычка была выполнена
};

#endif // HABIT_H
