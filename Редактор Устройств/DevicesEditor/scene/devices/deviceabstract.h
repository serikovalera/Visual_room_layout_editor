#ifndef DEVICEABSTRACT_H
#define DEVICEABSTRACT_H

#include "xml/xmlitemabstract.h"
#include "constants.h"

#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QDebug>
#include <QBitmap>

/**
 * @brief Абстрактный класс для устройств, наследующий от QGraphicsPixmapItem и XMLItemAbstract.
 */
class DeviceAbstract : public XMLItemAbstract, public QGraphicsPixmapItem
{

private:
    QString type; ///< Тип устройства.
    QString ip = "", name = ""; ///< IP-адрес и имя устройства.
    QString brand = "";  ///< Марка устройства.
    QString serialNumber = ""; ///< Серийный номер устройства.

    QSet<QGraphicsItem*> colliding; ///< Множество столкновений устройства с другими элементами сцены.
    float realW, realH, realL; ///< Реальные габариты устройства.

    /**
     * @brief Обновляет всплывающую подсказку устройства.
     */
    void updateTooltip();

public:
    /**
     * @brief Конструктор устройства.
     *
     * @param type Тип устройства.
     * @param pixmap Картинка устройства.
     * @param w Ширина устройства.
     * @param l Длина устройства.
     * @param h Высота устройства.
     */
    DeviceAbstract(QString type, QPixmap pixmap, float w, float l, float h = 0);

    /**
     * @brief Устанавливает реальные размеры устройства.
     * @param w Ширина устройства.
     * @param l Длина устройства.
     * @param h Высота устройства.
     */
    void setRealSize(float w, float l, float h) {
        realW = w;
        realH = h;
        realL = l;

        this->setPixmap(this->pixmap().scaled(w, l));
    }

    /**
     * @brief Добавляет элемент, с которым устройство столкнулось, в множество столкновений.
     * @param item Элемент, с которым устройство столкнулось.
     */
    void addColliding(QGraphicsItem* item) {
        colliding.insert(item);
    }

    /**
     * @brief Удаляет элемент, с которым устройство столкнулось, из множества столкновений.
     * @param item Элемент, с которым устройство столкнулось.
     */
    void deleteColliding(QGraphicsItem* item) {
        colliding.remove(item);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    bool isColliding() {
        return !colliding.isEmpty();
    }

    QString getIp() const;
    void setIp(const QString &value);

    QString getName() const;
    void setName(const QString &value);

    QString getBrand() const;
    void setBrand(const QString &value);

    QString getSerialNumber() const;
    void setSerialNumber(const QString &value);
    float getRealWidth() const;
    float getRealHeight() const;
    float getRealLength() const;
    QString getType() const;

    /**
     * @brief Преобразует устройство в элемент XML для сохранения в файле.
     * @param doc Документ XML, в который нужно добавить элемент устройства.
     * @return Элемент устройства в формате XML.
     */
    QDomElement toXML(QDomDocument doc) override;
};

#endif // DEVICEABSTRACT_H
