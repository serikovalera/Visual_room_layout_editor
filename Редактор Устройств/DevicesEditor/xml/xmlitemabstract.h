#ifndef XMLITEMABSTRACT_H
#define XMLITEMABSTRACT_H

#include <QDomElement>

/**
 * @brief Вспомогательный абстрактный класс для конвертации элементов в XML
 */
class XMLItemAbstract
{
public:
    XMLItemAbstract();

    virtual QDomElement toXML(QDomDocument doc) = 0;
};

#endif // XMLITEMABSTRACT_H
