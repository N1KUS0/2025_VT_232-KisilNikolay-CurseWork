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
    QSet<int> getTargetDays() const;
    void markCompleted(const QDate& date);
    bool isCompleted(const QDate& date) const;

private:
    int m_id;
    QString m_name;
    QString m_description;
    QDate m_creationDate;
    QSet<int> m_targetDays;
    QSet<QDate> m_completedDates;
};

#endif // HABIT_H
