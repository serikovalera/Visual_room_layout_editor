#ifndef DOOR_H
#define DOOR_H

#include <QGraphicsLineItem>
#include "scene/planning/furnitureabstract.h"

/**
 *@brief Класс, представляющий дверь.
 */
class Door : public FurnitureAbstract
{
private:
    bool isVertical;  ///< Флаг ориентации: true, если вертикальная
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

public:
    Door(QRectF rect);
};

#endif // DOOR_H
