#ifndef FILEREADER_H
#define FILEREADER_H

#include <QFile>
#include <QtXml>

#include "scene/planning/house.h"


/**
 * @brief Класс FileReader отвечает за чтение и запись схемы домов в файлы XML.
 */
class FileReader
{

private:
    /**
     * @brief Читает геометрию элементов из XML.
     * @param geometryEl Элемент XML, содержащий геометрию.
     * @return Прямоугольник, описывающий геометрию.
     */
    static QRectF readGeometry(QDomElement geometryEl);
    FileReader();
public:

    /**
     * @brief Читает схему дома из файла XML.
     *
     * @param path Путь к файлу.
     * @return Указатель на объект дома.
     */
    static House* readFile(QString path);

    /**
     * @brief Записывает схему дома в файл XML.
     *
     * @param house Указатель на объект дома.
     * @param customPath Пользовательский путь, по которому будет записан файл. По умолчанию пустая строка.
     * @return true, если запись прошла успешно, false в противном случае.
     */
    static bool writeFile(House* house, QString customPath = "");
};

#endif // FILEREADER_H
