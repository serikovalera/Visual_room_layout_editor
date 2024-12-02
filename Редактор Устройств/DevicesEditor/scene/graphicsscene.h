#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>

#include "deviceeditdialog.h"
#include "planning/house.h"

/**
 * @brief Класс GraphicsScene - класс графической сцены, наследник класса QGraphicsScene.
 *
 * Осуществляет отображение элементов графической сцены, а также обработку различных событий,
 * связанных с мышью и клавиатурой.
*/
class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT

    House* planning = nullptr; ///< Указатель на объект House.
    bool drag = false; ///< Флаг для определения, является ли текущая операция перетаскиванием.

    QGraphicsItemGroup* wallGroup; /// < Группа стен
    QGraphicsItemGroup* wallOutlineGroup; /// < Группа линий стен
    QGraphicsItemGroup* grid; /// < Сетка

    DeviceEditDialog* deviceDialog = nullptr; ///< Диалоговое окно редактирования устройств.

    /**
     * @brief Метод для проверки на пересечение с другими объектами.
     * @param device - указатель на объект DeviceAbstract.
     * @return true - если объект пересекается с другими объектами, иначе false.
    */
    bool checkColliding(DeviceAbstract* device);

public:

    /**
     * @brief Устанавливает планировку дома для сцены
     * @param h Указатель на объект класса House, представляющий планировку дома
     */
    void setPlanning(House* h);

    /**
     * @brief Возвращает указатель на объект класса House, представляющий планировку дома
     * @return Указатель на объект класса House, представляющий планировку дома
     */
    House* getPlanning() {
        return this->planning;
    }

    GraphicsScene();
    ~GraphicsScene();

    /**
     * @brief Рисует полосы на фоне сцены
     */
    void drawStripes();

    void keyPressEvent(QKeyEvent *event) override;
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // GRAPHICSSCENE_H
