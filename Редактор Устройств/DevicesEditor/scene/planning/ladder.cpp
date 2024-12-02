#include "ladder.h"

#include <QPainter>

Ladder::Ladder(QRectF rect, bool vertical) : FurnitureAbstract("ladder")
{
    this->setToolTip("Лестница"); // устанавливается всплывающая подсказка для объекта лестницы

    setIsVertical(vertical);
    //устанавливаются геометрические параметры объекта
    this->setPos(rect.x(), rect.y());
    this->setRect(0, 0, rect.width(), rect.height());
}

bool Ladder::getIsVertical() const
{
    return isVertical;
}

void Ladder::setIsVertical(bool value)
{
    isVertical = value;
}

void Ladder::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{//отрисовывает лестницу
    Q_UNUSED(option) //используется для подавления предупреждений компилятора о неиспользуемых параметрах option и widget.
    Q_UNUSED(widget)

    painter->save(); // сохраняется текущее состояние рисования
   // рисуется прямоугольник, представляющий форму лестницы,
    painter->setBrush(Qt::white);
    painter->drawRect(boundingRect());
    painter->restore(); //восстанавливается предыдущее состояние рисования

    QPen pen; // устанавливается перо для рисования линий
    pen.setColor(Qt::black);
    pen.setWidth(2); //ширина линии - 2 пикселя
    painter->setPen(pen); //Перо применяется к рисованию

    int lineCount = 5; //пределяется количество линий
    float lineSpacing = isVertical ? rect().height() / (lineCount - 1) : rect().width() / (lineCount - 1);//расстояние между линиями
// в цикле отрисовываются линии лестницы
    for (int i = 0; i < lineCount; ++i) {
        QPointF lineStart, lineEnd;

        if (isVertical) {
            lineStart = QPointF(0, i * lineSpacing);
            lineEnd = QPointF(rect().width(), i * lineSpacing);
        } else {
            lineStart = QPointF(i * lineSpacing, 0);
            lineEnd = QPointF(i * lineSpacing, rect().height());
        }

        painter->drawLine(lineStart, lineEnd);
    }
}
