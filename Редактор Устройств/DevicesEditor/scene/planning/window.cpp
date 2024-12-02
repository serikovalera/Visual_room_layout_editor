#include "window.h"

#include <QPainter>
//геометрия окна.
Window::Window(QRectF rect) : FurnitureAbstract("window")
{
    this->setToolTip("Окно");//Устанавливается всплывающая подсказка для объекта окна
//Устанавливается позиция и размеры объекта окна
    this->setPos(rect.x(), rect.y());
    this->setRect(0, 0, rect.width(), rect.height());
//Определяется ориентация окна на основе ширины и высоты прямоугольника
    isVertical = rect.width() < rect.height();
}

void Window::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{//отрисовывает объект окна
    Q_UNUSED(option)
    Q_UNUSED(widget)
//Устанавливается перо для рисования контура и заполнения окна.
    painter->setPen(Qt::black);
    painter->setBrush(QBrush(Qt::white));
    painter->drawRect(rect());//Рисуется прямоугольник

    painter->setPen(QPen(Qt::black, 1)); //Устанавливается перо Qt::black с толщиной 1 пиксель для рисования линии границы окна

    if (isVertical) {//Если окно вертикальное
        //рисуется вертикальная линия, проходящая через центр окна и соединяющая верхнюю и нижнюю границы.
        painter->drawLine(rect().center().x(), rect().top(), rect().center().x(), rect().bottom());
    } else {//Если окно горизонтальное
        //рисуется горизонтальная линия, проходящая через центр окна и соединяющая левую и правую границы.
        painter->drawLine(rect().left(), rect().center().y(), rect().right(), rect().center().y());
    }
}
