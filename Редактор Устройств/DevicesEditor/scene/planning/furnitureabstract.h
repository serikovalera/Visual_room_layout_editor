#ifndef FURNITUREABSTRACT_H
#define FURNITUREABSTRACT_H

#include "constants.h"

#include <QGraphicsRectItem>
#include "xml/xmlitemabstract.h"

class FurnitureAbstract : public QGraphicsRectItem, public XMLItemAbstract
{
    QString type;

public:
    FurnitureAbstract(QString type);

    /**
     * @brief Преобразует объект в элемент XML для сохранения в файле.
     * @param doc Документ XML, в который нужно добавить элемент устройства.
     * @return Элемент объекта в формате XML.
     */
    QDomElement toXML(QDomDocument doc) override;
};

#endif // FURNITUREABSTRACT_H
