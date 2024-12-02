//диалоговое окно для редактирования информации об устройстве
#include "datavalidators.h"
#include "deviceeditdialog.h"
#include "ui_deviceeditdialog.h"

#include <QMessageBox>

//инициализация пользовательского интерфейса ui
DeviceEditDialog::DeviceEditDialog(QVector<DeviceAbstract*>* devices, QWidget *parent) : QDialog(parent), ui(new Ui::DeviceEditDialog)
{
    this->devicesPtr = devices;//инициализация указателя
    ui->setupUi(this);//настройка пользовательского интерфейса
}

// удаляет объект ui.
DeviceEditDialog::~DeviceEditDialog()
{
    delete ui;
}

//диалоговое окно редактирования устройства
int DeviceEditDialog::exec(DeviceAbstract* device) {

    this->ui->ipEdit->setFocus();//установка фокуса на поле ввода IP-адреса

    //Заполнение полей ввода информацией об устройстве
    this->ui->ipEdit->setText(device->getIp());
    this->ui->nameEdit->setText(device->getName());
    this->ui->brandEdit->setText(device->getBrand());
    this->ui->serialEdit->setText(device->getSerialNumber());

    this->ui->widthSpin->setValue(device->getRealWidth());
    this->ui->heightSpin->setValue(device->getRealHeight());
    this->ui->lengthSpin->setValue(device->getRealLength());

    int ret = 0; // хранение результата выполнения диалога.

    //для выполнения диалога
    while (ret == QDialog::Rejected) {
        ret = QDialog::exec();

        if (ret) {

            QString newIp = this->ui->ipEdit->text().trimmed();
//Проверка корректности введенного IP-адреса
            if (!DataValidators::validateIP(newIp)) {
                QMessageBox::warning(this, tr("Некорректный IP адрес"), tr("Некорректный IP адрес! Введите валидный (Пример: 192.168.0.1)"));
                ret = 0;
                continue;
            }

            if (isIpUsed(newIp, device)) {
                QMessageBox::warning(this, tr("IP занят"), tr("Заданный IP адрес используется другим устройством!"));
                ret = 0;
                continue;
            }
//Установка новых значений IP-адреса, имени, бренда и серийного номера для объекта device.
            device->setIp(newIp);
            device->setName(this->ui->nameEdit->text().trimmed());
            device->setBrand(this->ui->brandEdit->text().trimmed());
            device->setSerialNumber(this->ui->serialEdit->text().trimmed());
//Получение значений ширины, высоты и длины устройства и установка их в объект device.
            float wcm = this->ui->widthSpin->value();
            float hcm = this->ui->heightSpin->value();
            float lcm = this->ui->lengthSpin->value();

            device->setRealSize(wcm, lcm, hcm);
        } else {
            break;
        }

    }
    return ret;
}

//проверяет, используется ли указанный IP-адрес другим устройством в векторе devicesPtr
bool DeviceEditDialog::isIpUsed(QString ip, DeviceAbstract* device) {
    for (auto item : *devicesPtr) {
        if (item->getIp() == ip && item != device)
            return true;
    }
    return false;
}

void DeviceEditDialog::setDevicesPtr(QVector<DeviceAbstract *> *value)
{
    devicesPtr = value;
}
