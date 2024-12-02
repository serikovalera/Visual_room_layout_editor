#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>
#include <QScrollBar>
#include <QWheelEvent>

class GraphicsView : public QGraphicsView
{
    QPoint m_lastMousePos; //хранение последней позиции мыши

public:
    GraphicsView(QGraphicsScene* scene, QWidget* parent = nullptr) : QGraphicsView(scene, parent)
    {
        setRenderHint(QPainter::Antialiasing); //включение сглаживания графики
        setViewportUpdateMode(QGraphicsView::FullViewportUpdate); //обновление всего вида при изменении
    }

    void setDrag(bool drag);

protected:
    void wheelEvent(QWheelEvent* event) override;
};

#endif // GRAPHICSVIEW_H
