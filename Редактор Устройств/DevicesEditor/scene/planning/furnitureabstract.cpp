#include "furnitureabstract.h"

FurnitureAbstract::FurnitureAbstract(QString type)
{
    this->type = type;
}

//Метод преобразует объект FurnitureAbstract в XML-элемент и возвращает его.
QDomElement FurnitureAbstract::toXML(QDomDocument doc) {
    QDomElement rootEl = doc.createElement("furnitureitem");
    rootEl.setAttribute("type", type);

    QDomElement geomEl = doc.createElement("geometry");

    geomEl.setAttribute("x", this->x() - PLAN_PADDING);
    geomEl.setAttribute("y", this->y() - PLAN_PADDING);
    geomEl.setAttribute("w", this->rect().width());
    geomEl.setAttribute("h", this->rect().height());

    rootEl.appendChild(geomEl);

    return rootEl;
}
