#include "HistoryFile.h"


HistoryFile::HistoryFile(const QString& filename)
    : filename(filename), file(filename)
{
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        qDebug() << "Could not open file for writing:" << filename;
    }
}

HistoryFile::~HistoryFile() {
    if (file.isOpen()) {
        file.close();
    }
}

void HistoryFile::addEntry(const QString& entry) {
    if (file.isOpen()) {
        QTextStream out(&file);
        out << entry << "\n";
    }
    else {
        qDebug() << "File is not open for writing:" << filename;
    }
}

void HistoryFile::clearHistory() {
    if (file.isOpen()) {
        file.resize(0);
    }
}
