#ifndef WINDOW_H
#define WINDOW_H

#include "scene/planning/furnitureabstract.h"

/**
 *@brief Класс, представляющий окно.
 */
class Window : public FurnitureAbstract
{
    bool isVertical;  ///< Флаг ориентации: true, если вертикальная
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

public:
    Window(QRectF rect);
};

#endif // WINDOW_H
