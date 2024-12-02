#include "graphicsscene.h"
#include "constants.h"
#include "devices/deviceabstract.h"

#include <QMenu>
#include <QDebug>
#include <QKeyEvent>
#include <QWidget>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

#include <scene/devices/pc.h>
#include <scene/devices/phone.h>
#include <scene/devices/printer.h>
#include <scene/devices/server.h>

GraphicsScene::GraphicsScene() {}

void GraphicsScene::drawStripes() {//рисует сетку с полосами на сцене
    qDebug() << this->height();//Выводит высоту сцены в отладочной информации
    //Создает два объекта пера pen и pen2 для рисования полос
    QPen pen(QColor(0, 0, 0, 100), 1, Qt::PenStyle::DotLine);
    QPen pen2(QColor(0, 0, 0, 150), 1, Qt::PenStyle::SolidLine);

    grid = new QGraphicsItemGroup;
//В цикле создает горизонтальные и вертикальные линии
    for (int i = 0; i < this->height(); i += GRID_SIZE) {
        QGraphicsLineItem* horizontalLine = new QGraphicsLineItem(0, i, this->width(), i);
        QGraphicsLineItem* verticalLine = new QGraphicsLineItem(i, 0, i, this->height());
//Устанавливает перо для каждой линии в зависимости от позиции в сетке
        if (i % (int)(GRID_SIZE * 5) == 0)
        {
            horizontalLine->setPen(pen2);
            verticalLine->setPen(pen2);
        } else {
            horizontalLine->setPen(pen);
            verticalLine->setPen(pen);
        }
//Добавляет линии в группу grid
        grid->addToGroup(horizontalLine);
        grid->addToGroup(verticalLine);
    }
//Добавляет группу grid на сцену
    this->addItem(grid);
}

GraphicsScene::~GraphicsScene() {
}

//обрабатывает событие перемещения мыши по сцене
void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if (drag) {
//Получает элемент сцены, на котором находится курсор мыши
        QGraphicsItem *item = itemAt(event->scenePos(), QTransform());
        //Преобразует элемент в объект DeviceAbstract
        auto device = qgraphicsitem_cast<DeviceAbstract*>(item);

        if (device) {//Если объект является устройством
            checkColliding(device);//проверить столкновение с другими элементами
        }
    }
    QGraphicsScene::mouseMoveEvent(event);
}

//обрабатывает событие нажатия кнопки мыши на сцене
void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    //Получает элемент сцены, на котором находится курсор мыши
    QGraphicsItem *item = itemAt(event->scenePos(), QTransform());
// если элемент находится под курсором мыши и является объектом типа DeviceAbstract
    if (item->isUnderMouse() && qgraphicsitem_cast<DeviceAbstract*>(item))
        drag = true;

    QGraphicsScene::mousePressEvent(event);
}

//обрабатывает событие отпускания кнопки мыши на сцене
void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    drag = false;

    QGraphicsScene::mouseReleaseEvent(event);
};

//обрабатывает событие открытия контекстного меню на сцене
void GraphicsScene::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)  {
    if (planning == nullptr)
        return; //прерывает выполнение функции.

    //Получает элемент сцены, на котором находится контекстное меню
    QGraphicsItem *item = itemAt(event->scenePos(), QTransform());
    //Преобразует элемент в объект DeviceAbstract
    auto device = qgraphicsitem_cast<DeviceAbstract*>(item);

    QMenu menu;
    QMenu deviceMenu("Добавить устройство");
//Добавляет пункты меню "Сервер", "ПК", "Смартфон" и "Принтер" в меню deviceMenu.
    deviceMenu.addAction("Сервер");
    deviceMenu.addAction("ПК");
    deviceMenu.addAction("Смартфон");
    deviceMenu.addAction("Принтер");

    menu.addMenu(&deviceMenu);

    if (device) {//Если элемент является устройством
        menu.addAction("Настроить устройство");
        menu.addAction("Удалить устройство");
    }

    DeviceAbstract* newDevice = nullptr;
    QAction* selected = menu.exec(event->screenPos());//Вызывает меню

    if (selected) {//Если был выбран пункт меню
        if (selected->parentWidget() == &deviceMenu) {//проверяет его родительский виджет:
            if (selected->text() == "Сервер") {
                newDevice = new Server();
            }
            else if (selected->text() == "ПК")
                newDevice = new PC();
            else if (selected->text() == "Смартфон")
                newDevice = new Phone();
            else if (selected->text() == "Принтер")
                newDevice = new Printer();

            if (newDevice) {//Если новое устройство было успешно создано
                newDevice->setPos(event->scenePos());
//устанавливает его позицию на сцене и добавляет в объект planning и на сцену.
                this->planning->addDevice(newDevice);
                this->addItem(newDevice);
                checkColliding(newDevice);//проверить столкновение с другими элементами.
            }
        } else if (selected->text() == "Настроить устройство") {
            deviceDialog->exec(device);//вызывает диалоговое окно редактирования устройства
        } else if (selected->text() == "Удалить устройство") {
            planning->deleteDevice(device);
        }
    }
}

//обрабатывает событие двойного щелчка кнопкой мыши на сцене
void GraphicsScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) {

    if (event->button() != Qt::LeftButton)// если кнопка мыши не является левой кнопкой
        return;//прерывает выполнение функции.
//Получает элемент сцены, на котором произошел двойной щелчок
    QGraphicsItem *item = itemAt(event->scenePos(), QTransform());
    //Преобразует элемент в объект DeviceAbstract
    auto device = qgraphicsitem_cast<DeviceAbstract*>(item);

    if (device)//Если элемент является устройством
    {
        deviceDialog->exec(device);// вызывает диалоговое окно редактирования устройства
    }

    QGraphicsScene::mouseDoubleClickEvent(event);
}

void GraphicsScene::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Delete) {

        QGraphicsItem *item = focusItem();
        auto device = qgraphicsitem_cast<DeviceAbstract*>(item);

        if (device) {
            planning->deleteDevice(device);
        }

    } else {
        QGraphicsScene::keyPressEvent(event);
    }
}

void GraphicsScene::setPlanning(House *h) {
    if (planning != nullptr) {
        this->planning->deleteAll();
        delete this->wallOutlineGroup;
        delete this->planning;
    }

    this->planning = h;

    if (deviceDialog == nullptr)
        deviceDialog = new DeviceEditDialog(planning->getDevicesPtr());
    else {}
        deviceDialog->setDevicesPtr(planning->getDevicesPtr());

    wallGroup = new QGraphicsItemGroup();
    wallOutlineGroup = new QGraphicsItemGroup();

    for (auto wall : h->getWalls()) {
        auto wallOutline = new QGraphicsRectItem(0, 0, wall->rect().width(), wall->rect().height());
        wallOutline->setPos(wall->x(), wall->y());
        wallOutline->setBrush(Qt::transparent);

        wallOutlineGroup->addToGroup(wallOutline);
        wallGroup->addToGroup(wall);
    }

    this->addItem(wallOutlineGroup);
    this->addItem(wallGroup);

    for (auto item : h->getFurniture())
        this->addItem(item);

    for (auto item : h->getLadders())
        this->addItem(item);

    for (auto device : h->getDevices())
        this->addItem(device);
}

//проверяет столкновение устройства device с другими элементами на сцене
bool GraphicsScene::checkColliding(DeviceAbstract* device) {
    bool collides = false;

    for (auto item : planning->getWalls()) {
        if (device->collidesWithItem(item)) {
            device->addColliding(item);
            break;
        } else {
            device->deleteColliding(item);
        }
    }

    for (auto item : planning->getLadders()) {
        if (device->collidesWithItem(item)) {
            device->addColliding(item);
            break;
        } else {
            device->deleteColliding(item);
        }
    }

    for (auto item : planning->getDevices()) {
        if (item != device && device->collidesWithItem(item)) {
            collides = true;
            item->addColliding(device);
            device->addColliding(item);
            break;
        } else {
            item->deleteColliding(device);
            device->deleteColliding(item);
        }
    }


    return collides;
}
