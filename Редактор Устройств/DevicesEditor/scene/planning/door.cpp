#include "door.h"

#include "constants.h"

#include <QPen>
#include <QPainter>
#include <QDebug>

Door::Door(QRectF rect) : FurnitureAbstract("door")// rect - прямоугольник, определяющий положение и размеры двери.
{ 
    this->setToolTip("Дверь");

    this->setPos(rect.x(), rect.y());
    this->setRect(0, 0, rect.width(), rect.height());

    isVertical = rect.width() < rect.height(); // true, если ширина двери меньше высоты, иначе - в false.
} //устанавливаются подсказки, позиция с использование координат, размеры для двери

void Door::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{ //отрисовка двери на графической сцене.
    Q_UNUSED(option)
    Q_UNUSED(widget) //предотвращают появление предупреждений компилятора о неиспользуемых параметрах option и widget.

    painter->setPen(Qt::black); //задают параметры ручки и кисти для отрисовки двери
    painter->setBrush(QBrush(Qt::white));
    painter->drawRect(rect()); //отрисовка прямоугольника, который представляет дверь.

    painter->setPen(QPen(Qt::black, 1));
 //отрисовывается линия, представляющая направление открытия двери.
    if (isVertical) { //Если дверь вертикальная, то рисуется горизонтальная линия по центру двери.
        painter->drawLine(rect().left() - rect().width() / 2, rect().center().y(), rect().right() + rect().width() / 2, rect().center().y());
    } else { //если дверь горизонтальная, рисуется вертикальная линия по центру двери.
        painter->drawLine(rect().center().x(), rect().top(), rect().center().x(), rect().bottom());
    }
}
