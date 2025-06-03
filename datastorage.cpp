#include "datastorage.h"
#include <QDebug>
#include <QJsonObject>

bool DataStorage::saveToFile(const HabitTracker& tracker, const QString& filePath) {
    QJsonArray habitsArray;
    for (const Habit& habit : tracker.getHabits()) {
        habitsArray.append(habitToJson(habit));
    }

    QJsonDocument doc(habitsArray);
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << "Не удалось открыть файл для записи:" << filePath;
        return false;
    }
    file.write(doc.toJson());
    file.close();
    return true;
}

bool DataStorage::loadFromFile(HabitTracker& tracker, const QString& filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Не удалось открыть файл для чтения:" << filePath;
        return false;
    }

    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (doc.isNull()) {
        qWarning() << "Ошибка парсинга JSON";
        return false;
    }

    tracker = HabitTracker();  // Очищаем трекер перед загрузкой
    QJsonArray habitsArray = doc.array();
    for (const QJsonValue& value : habitsArray) {
        tracker.addHabit(jsonToHabit(value.toObject()));
    }

    file.close();
    return true;
}

// Преобразование Habit - JSON
QJsonObject DataStorage::habitToJson(const Habit& habit) {
    QJsonObject json;
    json["id"] = habit.getId();
    json["name"] = habit.getName();
    json["description"] = habit.getDescription();
    json["creationDate"] = habit.getCreationDate().toString(Qt::ISODate);

    QJsonArray targetDaysArray;
    for (int day : habit.getTargetDays()) {
        targetDaysArray.append(day);
    }
    json["targetDays"] = targetDaysArray;

    const QSet<QDate>& dates = habit.getCompletedDates();

    QJsonArray completedDatesArray;
    for (const QDate& date : dates) {
        completedDatesArray.append(date.toString(Qt::ISODate));
    }
    json["completedDates"] = completedDatesArray;

    return json;
}

// Преобразование JSON - Habit
Habit DataStorage::jsonToHabit(const QJsonObject& json) {
    int id = json["id"].toInt();
    QString name = json["name"].toString();
    QString description = json["description"].toString();
    QDate creationDate = QDate::fromString(json["creationDate"].toString(), Qt::ISODate);

    QSet<int> targetDays;
    for (const QJsonValue& day : json["targetDays"].toArray()) {
        targetDays.insert(day.toInt());
    }

    Habit habit(id, name, description, creationDate, targetDays);

    for (const QJsonValue& dateStr : json["completedDates"].toArray()) {
        habit.markCompleted(QDate::fromString(dateStr.toString(), Qt::ISODate));
    }

    return habit;
}
