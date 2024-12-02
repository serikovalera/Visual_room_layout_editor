//главное окно программы
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "scene/graphicsscene.h"
#include "scene/graphicsview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

/**
 * @brief Главное окно программы
 */
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots: //объявление приватных слотов(обработчиков сигналов)

    void on_arrowBtn_toggled(bool checked);
    void on_dragBtn_toggled(bool checked);

    void on_openBtn_pressed();
    void on_saveAsBtn_pressed();
    void on_saveBtn_pressed();

    void savePlanning(QString filename = "");

private:
    Ui::Widget *ui;

    GraphicsScene* graphicsScene; ///< Графическая сцена
    GraphicsView* graphicsView; ///< Графический виджет
};
#endif // WIDGET_H
