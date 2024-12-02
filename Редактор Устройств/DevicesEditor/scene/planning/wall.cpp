// представляет стену в графической сцене.
#include "wall.h"
#include "constants.h"

#include <QPainter>
#include <QPen>

Wall::Wall(QRectF rect)//принимает аргумент rect, представляющий геометрию стены
{
    this->setToolTip("Стена");//Устанавливается всплывающая подсказка для объекта стены

    QImage textureImage("://textures/pattern.jpg");//Загружается изображение текстуры стены
    textureImage = textureImage.scaled(80, 80);//Изображение текстуры масштабируется
//Создается кисть, которая использует текстурное изображение в качестве заполнения и устанавливается стиль заполнения
    QBrush patternBrush(textureImage);
    patternBrush.setStyle(Qt::TexturePattern);

    this->setPen(QPen(Qt::transparent));// прозрачное перо для объекта стены (контур стены будет невидимым.)
    this->setBrush(patternBrush);
    //Устанавливается позиция и размеры объекта стены
    this->setPos(rect.x(), rect.y());
    this->setRect(0, 0, rect.width(), rect.height());
}


