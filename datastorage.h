#ifndef DATASTORAGE_H
#define DATASTORAGE_H

#include "habittracker.h"
#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>

class DataStorage {
public:
    static bool saveToFile(const HabitTracker& tracker, const QString& filePath);
    static bool loadFromFile(HabitTracker& tracker, const QString& filePath);

private:
    static QJsonObject habitToJson(const Habit& habit);
    static Habit jsonToHabit(const QJsonObject& json);
};

#endif // DATASTORAGE_H
