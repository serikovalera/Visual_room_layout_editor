// реализация функций чтения и записи файла для представления дома в виде XML-документа
#include "filereader.h"
#include "constants.h"

#include <scene/planning/door.h>
#include <scene/planning/window.h>

#include <scene/devices/pc.h>
#include <scene/devices/phone.h>
#include <scene/devices/server.h>
#include <scene/devices/printer.h>

#include <qmessagebox.h>

FileReader::FileReader() {}
// возвращает объект QRectF с геометрией, считанной из элемента DOM
QRectF FileReader::readGeometry(QDomElement geometryEl) {
    float x = geometryEl.attribute("x").toFloat() + PLAN_PADDING;
    float y = geometryEl.attribute("y").toFloat() + PLAN_PADDING;
    float w = geometryEl.attribute("w").toFloat();
    float h = geometryEl.attribute("h").toFloat();

    return QRectF(x, y, w, h);
}
//принимает путь path к XML-файлу и возвращает указатель на объект House, созданный на основе данных из XML-файла
House* FileReader::readFile(QString path) {
    QFile xmlFile(path);// создание объекта QFile с указанным путем path

    //проверка открытия файла для чтения
    if (!xmlFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw std::invalid_argument("Failed to open XML file");
    }

    QDomDocument xmlDoc;//для представления XML-документа.
    //загрузка XML-документа из файла
    if (!xmlDoc.setContent(&xmlFile)) {
        throw std::invalid_argument("Failed to load XML document");
        xmlFile.close();
    }
//создание объекта House с указанным путем path.
    House* house = new House(path);
    QDomNodeList walls = xmlDoc.elementsByTagName("wall");
    //для обхода списка элементов DOM "wall" и создания объектов Wall на основе геометрии, считанной из элементов DOM. Эти объекты добавляются в объект house.
    for (int i = 0; i < walls.size(); ++i) {
        QDomElement wall = walls.at(i).toElement();
        house->addWall(new Wall(readGeometry(wall.firstChildElement("geometry"))));
    }

    QDomNodeList furniture = xmlDoc.elementsByTagName("furnitureitem");
    for (int i = 0; i < furniture.size(); ++i) {
        QDomElement item = furniture.at(i).toElement();
        bool isVertical = item.attribute("vertical").toInt();

        QRectF geom = readGeometry(item.firstChildElement("geometry"));

        QString type = item.attribute("type");

        FurnitureAbstract* newFur = nullptr;

        if (type == "door")
            newFur = new Door(geom);
        else if (type == "window")
            newFur = new Window(geom);
        else if (type == "ladder") {
            house->addLadder(new Ladder(geom, isVertical));
            continue;
        }

        house->addFurniture(newFur);
    }

    QDomNodeList devices = xmlDoc.elementsByTagName("device");
    for (int i = 0; i < devices.size(); ++i) {
        QDomElement device = devices.at(i).toElement();
        QRectF geom = readGeometry(device.firstChildElement("geometry"));

        float w = device.firstChildElement("realsize").attribute("w").toFloat();
        float h = device.firstChildElement("realsize").attribute("h").toFloat();
        float l = device.firstChildElement("realsize").attribute("l").toFloat();

        QString type = device.attribute("type");

        DeviceAbstract* newDevice = nullptr;

        if (type == "pc")
            newDevice = new PC();
        else if (type == "phone")
            newDevice = new Phone();
        else if (type == "printer")
            newDevice = new Printer();
        else if (type == "server")
            newDevice = new Server();

        QString ip = device.firstChildElement("info").attribute("ip");
        QString name = device.firstChildElement("info").attribute("name");
        QString brand = device.firstChildElement("info").attribute("brand");
        QString serial = device.firstChildElement("info").attribute("serialNumber");

        newDevice->setIp(ip);
        newDevice->setName(name);
        newDevice->setBrand(brand);
        newDevice->setSerialNumber(serial);

        newDevice->setRealSize(w, l, h);
        newDevice->setPos(geom.x(), geom.y());
        house->addDevice(newDevice);
    }

    xmlFile.close();// закрытие файла после чтения.

    return house;
}
// принимает указатель на объект House и (необязательный) пользовательский путь customPath для сохранения XML-файла.
bool FileReader::writeFile(House* house, QString customPath) {
//выбор пути для сохранения файла
    QString path = (customPath == "") ? house->getFilePath() : customPath;

    QDomDocument doc;
    QDomElement root = doc.createElement("house");
    doc.appendChild(root);

    //////////////////////////

    QDomElement wallsEl = doc.createElement("walls");
    QVector<Wall*> walls = house->getWalls();

    for (Wall* wall : walls) {
        QDomElement wallEl = wall->toXML(doc);
        wallsEl.appendChild(wallEl);
    }
    root.appendChild(wallsEl);

    ///////////////////////////

    QDomElement furnitureEl = doc.createElement("furniture");
    QVector<FurnitureAbstract*> furniture = house->getFurniture();
    for (auto ladder : house->getLadders())
        furniture.append(ladder);

    for (FurnitureAbstract* item : furniture) {
        QDomElement itemEl = item->toXML(doc);
        furnitureEl.appendChild(itemEl);
    }
    root.appendChild(furnitureEl);

    ////////////////////////////

    QDomElement devicesEl = doc.createElement("devices");
    QVector<DeviceAbstract*> devices = house->getDevices();

    for (DeviceAbstract* device : devices) {
        QDomElement deviceEl = device->toXML(doc);
        devicesEl.appendChild(deviceEl);
    }
    root.appendChild(devicesEl);
//Создание объекта QFile для записи файла с указанным путем path.
    QFile file(path);
    //проверка открытия файла для записи
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return false;
    }

    QTextStream stream(&file);//для записи данных в файл
    stream << doc.toString();//запись содержимого объекта doc в файл
    file.close();//закрытие файла после записи.

    return true;
}
