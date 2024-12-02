#include "graphicsview.h"
//Это функция setDrag, которая устанавливает режим перетаскивания
void GraphicsView::setDrag(bool drag) {

    if (drag) {
        setDragMode(QGraphicsView::ScrollHandDrag);//устанавливает режим перетаскивания ScrollHandDrag для GraphicsView с помощью setDragMode
        setInteractive(false);//Отключает интерактивность
    }
    else {
        setInteractive(true);//включает интерактивность
        setDragMode(QGraphicsView::NoDrag);//Устанавливает режим перетаскивания
    }
}

//обрабатывает событие прокрутки колеса мыши
void GraphicsView::wheelEvent(QWheelEvent* event)
{
    //Получает текущий масштаб по оси X или Y
    //transform() возвращает текущую матрицу преобразования QTransform, а m11() возвращает элемент матрицы в первой строке и первом столбце.
    qreal scaleFactor = transform().m11();

    if (event->angleDelta().y() > 0) {
        scaleFactor = 1.1;//для увеличения масштаба.
    } else {
        scaleFactor = 0.9;//для уменьшения масштаба.
    }

    scale(scaleFactor, scaleFactor);// для изменения масштаба GraphicsView по обеим осям с использованием полученного scaleFactor.
}
