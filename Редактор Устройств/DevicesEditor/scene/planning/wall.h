#ifndef WALL_H
#define WALL_H

#include "scene/planning/furnitureabstract.h"

/**
 *@brief Класс, представляющий стену.
 */
class Wall : public XMLItemAbstract, public QGraphicsRectItem
{
public:
    Wall(QRectF rect);

    /**
     * @brief Возвращает элемент XML, соответствующий текущей стене.
     * @param doc QDomDocument, в которую нужно добавить элемент.
     * @return QDomElement, представляющий текущую стену в XML.
     */
    virtual QDomElement toXML(QDomDocument doc) override {
        QDomElement rootEl = doc.createElement("wall");

        QDomElement geomEl = doc.createElement("geometry");
        geomEl.setAttribute("x", this->x() - PLAN_PADDING);
        geomEl.setAttribute("y", this->y() - PLAN_PADDING);
        geomEl.setAttribute("w", this->rect().width());
        geomEl.setAttribute("h", this->rect().height());

        rootEl.appendChild(geomEl);

        return rootEl;
    };
};

#endif // WALL_H
