#pragma once

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>

class HistoryFile {
public:
    HistoryFile(const QString& filename);
    ~HistoryFile();

    void addEntry(const QString& entry);
    void clearHistory();

private:
    QString filename;
    QFile file;
};

