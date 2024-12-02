#ifndef HOUSE_H
#define HOUSE_H

#include <QPen>
#include <QVector>

#include "scene/devices/deviceabstract.h"
#include "wall.h"
#include "door.h"
#include "ladder.h"

/**
 * @brief Класс, представляющий объект схемы дома.
 */
class House
{
private:
    QString filePath;  ///< Путь к файлу с информацией о доме

    QVector<Wall*> walls; ///< Вектор с объектами стен
    QVector<FurnitureAbstract*> furniture; ///< Вектор с объектами мебели
    QVector<DeviceAbstract*> devices; ///< Список устройств.
    QVector<Ladder*> ladders; ///< Список лестниц

public:
    /**
     * @brief Конструктор класса House.
     * @param path Путь к файлу с информацией о доме.
     */
    House(QString path);

    /**
     * @brief Добавляет стену в список стен дома.
     * @param wall Указатель на стену.
     */
    void addWall(Wall* wall) {
        walls.push_back(wall);
    }

    /**
     * @brief Добавляет лестницу в список лестниц дома.
     * @param ladder Указатель на лестницу.
     */
    void addLadder(Ladder* ladder) {
        ladders.push_back(ladder);
    }

    /**
     * @brief Добавляет объект мебели в список мебели в доме.
     * @param item Указатель на объект мебели.
     */
    void addFurniture(FurnitureAbstract* item) {
        furniture.push_back(item);
    }

    /**
     * @brief Добавляет устройство в список устройств в доме.
     * @param item Указатель на устройство.
     */
    void addDevice(DeviceAbstract* item) {
        devices.push_back(item);
    }

    /**
     * @brief Удаляет устройство из списка.
     * @param device Указатель на удаляемое устройство.
     */
    void deleteDevice(DeviceAbstract* device) {
        for (auto item : devices)
            item->deleteColliding(device);

        devices.removeAll(device);
        delete device;
    }

    /**
     * @brief Удаляет все объекты дома.
     */
    void deleteAll() {
        for (auto item : devices)
            delete item;
        for (auto item : walls)
            delete item;
        for (auto item : furniture)
            delete item;
    }

    /**
     * @brief Возвращает список мебели в доме.
     * @return Список мебели.
     */
    QVector<FurnitureAbstract*> getFurniture() {
        return furniture;
    }

    /**
     * @brief Возвращает список стен дома.
     * @return Список стен.
     */
    QVector<Wall*> getWalls() {
        return walls;
    }

    /**
     * @brief Возвращает список устройств в доме.
     * @return Список устройств.
     */
    QVector<DeviceAbstract*> getDevices() {
        return devices;
    }

    /**
     * @brief Возвращает указатель на список устройств в доме.
     * @return Указатель на список.
     */
    QVector<DeviceAbstract*>* getDevicesPtr() {
        return &devices;
    }

    /**
     * @brief Возвращает список лестниц.
     * @return Список лестниц.
     */
    QVector<Ladder*> getLadders() {
        return ladders;
    }

    QString getFilePath() const;
    void setFilePath(const QString &value);
};

#endif // HOUSE_H
