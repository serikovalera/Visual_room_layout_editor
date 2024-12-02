#ifndef LADDER_H
#define LADDER_H

#include "furnitureabstract.h"

/**
 *@brief Класс, представляющий лестницу.
 */
class Ladder : public FurnitureAbstract
{
    bool isVertical; ///< Флаг ориентации: true, если вертикальная
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

public:
    Ladder(QRectF rect, bool vertical);

    /**
     * @brief Метод для получения флага ориентации лестницы
     * @return Флаг ориентации лестницы: true, если вертикальная
     */
    bool getIsVertical() const;

    /**
     * @brief Метод для установки флага ориентации лестницы
     * @param value Значение флага ориентации лестницы
     */
    void setIsVertical(bool value);
};

#endif // LADDER_H
