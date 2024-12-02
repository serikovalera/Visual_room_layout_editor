#include "deviceabstract.h"

DeviceAbstract::DeviceAbstract(QString type, QPixmap pixmap, float w, float l, float h) : QGraphicsPixmapItem(pixmap)
{
    updateTooltip();

    this->type = type;
    this->setRealSize(w, l, h);
    this->setFlag(ItemIsMovable, true);
    this->setFlag(ItemIsFocusable);
    this->setShapeMode(BoundingRectShape);

    this->setFocus();
} //конструктор класса, которая принимает тип устройства, изображение устройства, ширину, длину и высоту

QString DeviceAbstract::getType() const //метод возвращает тип устройства
{
    return type;
}

void DeviceAbstract::updateTooltip() { //метод обновляет подсказку (tooltip) для устройства в зависимости от значений переменных
    if (ip.isEmpty())
        this->setToolTip("Укажите IP адрес устройства!");
    else
        this->setToolTip(
                    "Имя: " + getName() +
                    "\nIP: " + getIp() +
                    "\nПроизводитель: " + getBrand() +
                    "\nСерийный номер: " + getSerialNumber());
}

//2 метода предоставляют доступ к переменной ip и обновляют подсказку после изменения значения.
QString DeviceAbstract::getIp() const
{
    return ip;
}

void DeviceAbstract::setIp(const QString &value)
{
    ip = value;
    updateTooltip();
}

//предоставляют доступ к переменной name и обновляют подсказку после изменения значения.
QString DeviceAbstract::getName() const
{
    return name;
}

void DeviceAbstract::setName(const QString &value)
{
    name = value;
    updateTooltip();
}

//предоставляют доступ к переменной brand и обновляют подсказку после изменения значения.
QString DeviceAbstract::getBrand() const
{
    return brand;
}

void DeviceAbstract::setBrand(const QString &value)
{
    brand = value;
    updateTooltip();
}

//предоставляют доступ к переменной serialNumber и обновляют подсказку после изменения значения.
QString DeviceAbstract::getSerialNumber() const
{
    return serialNumber;
}

void DeviceAbstract::setSerialNumber(const QString &value)
{
    serialNumber = value;
    updateTooltip();
}

//3 метода, которые возвращают реальные размеры устройства (ширина, высота и длина).
float DeviceAbstract::getRealWidth() const
{
    return realW;
}

float DeviceAbstract::getRealHeight() const
{
    return realH;
}

float DeviceAbstract::getRealLength() const
{
    return realL;
}

//метод выполняет отрисовку устройства на графической сцене.
void DeviceAbstract::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QGraphicsPixmapItem::paint(painter, option, widget);

    if (!colliding.empty())
        painter->setPen(QPen(Qt::red, 5));
    else if (hasFocus())
        painter->setPen(QPen(QColor(0, 0, 0, 100), 5));
    else
        painter->setPen(Qt::transparent);

    painter->drawRect(boundingRect());
    painter->setRenderHint(QPainter::Antialiasing);

    if (ip.isEmpty()) {
        int warn = this->boundingRect().width() * 0.2;

        if (warn < 20) warn = 20;

        QPixmap warningPixmap(":/icons/warning.png");
        QSize iconSize(warn, warn);
        QPoint iconPos(0, 0);
        warningPixmap = warningPixmap.scaled(iconSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        painter->drawPixmap(iconPos, warningPixmap);
    } else {
        painter->setPen(Qt::black);

        QFont font;
        font.setPointSize(10);
        painter->setFont(font);

        QRectF pixmapRect = boundingRect();

        // Calculate the bounding rectangle of the text based on the font and text content
        QFontMetrics fontMetrics(font);
        QRectF textRect = fontMetrics.boundingRect(ip);

        // Adjust the rectangle to be centered above the pixmap and ensure that the entire text is visible
        textRect.translate(pixmapRect.center() - textRect.center());
        textRect.translate(0, -textRect.top() - 20);

        painter->drawText(textRect, Qt::AlignCenter, ip);
    }
}

//Этот метод преобразует объект DeviceAbstract в XML-элемент и возвращает его. Используется для сохранения данных устройства в XML-файле.
QDomElement DeviceAbstract::toXML(QDomDocument doc) {
    QDomElement rootEl;

    rootEl = doc.createElement("device");
    rootEl.setAttribute("type", type);

    QDomElement geomEl = doc.createElement("geometry");

    geomEl.setAttribute("x", this->x() - PLAN_PADDING);
    geomEl.setAttribute("y", this->y() - PLAN_PADDING);
    geomEl.setAttribute("w", this->realW);
    geomEl.setAttribute("h", this->realL);

    rootEl.appendChild(geomEl);

    QDomElement realSizeEl = doc.createElement("realsize");
    realSizeEl.setAttribute("w", QString::number(realW));
    realSizeEl.setAttribute("h", QString::number(realH));
    realSizeEl.setAttribute("l", QString::number(realL));
    rootEl.appendChild(realSizeEl);

    QDomElement infoEl = doc.createElement("info");

    infoEl.setAttribute("ip", ip);
    infoEl.setAttribute("name", name);
    infoEl.setAttribute("serialNumber", serialNumber);
    infoEl.setAttribute("brand", brand);
    rootEl.appendChild(infoEl);

    return rootEl;
}
