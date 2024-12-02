#include "house.h"

QString House::getFilePath() const
{
    return filePath;
}

void House::setFilePath(const QString &value)
{
    filePath = value;
}

House::House(QString path) : filePath(path)
{}
