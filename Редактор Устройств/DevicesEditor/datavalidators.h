#ifndef DATAVALIDATORS_H
#define DATAVALIDATORS_H

#include <QRegularExpression>
#include <QString>

/**
 * @brief Класс для проверки валидности данных.
 */
class DataValidators
{
    DataValidators();

public:
    /**
     * @brief Проверяет, является ли переданный IP-адрес валидным.
     * @param ip - строка, содержащая IP-адрес.
     * @return true, если IP-адрес валидный, иначе - false.
     */
    static bool validateIP(QString ip) {
        QRegularExpression ipRegex("^(?:[0-9]{1,3}\\.){3}[0-9]{1,3}$");
        return ipRegex.match(ip).hasMatch();
    }
};

#endif // DATAVALIDATORS_H
