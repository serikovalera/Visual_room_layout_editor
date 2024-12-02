#ifndef DEVICEEDITDIALOG_H
#define DEVICEEDITDIALOG_H

#include <QDialog>

#include <scene/devices/deviceabstract.h>

namespace Ui {
class DeviceEditDialog;
}

/**
 * @brief Диалоговое окно для редактирования свойств устройства.
 */
class DeviceEditDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса.
     *
     * @param devices Указатель на вектор устройств.
     * @param parent Указатель на родительский виджет.
     */
    explicit DeviceEditDialog(QVector<DeviceAbstract*>* devices, QWidget *parent = nullptr);
    ~DeviceEditDialog();

    /**
     * @brief Выполняет диалоговое окно редактирования устройства.
     *
     * @param device Указатель на устройство.
     * @return int Результат выполнения диалогового окна.
     */
    int exec(DeviceAbstract* device);

    /**
     * @brief Проверяет, используется ли IP-адрес устройством.
     *
     * @param ip IP-адрес устройства.
     * @param device Указатель на устройство.
     * @return true Если IP-адрес используется устройством.
     * @return false Если IP-адрес не используется устройством.
     */
    bool isIpUsed(QString ip, DeviceAbstract* device);

    /**
     * @brief Устанавливает указатель на вектор устройств.
     *
     * @param value Указатель на вектор устройств.
     */
    void setDevicesPtr(QVector<DeviceAbstract *> *value);

private:
    /**
    * @brief Переопределяет метод exec().
    *
    * @return int Результат выполнения диалогового окна.
    */
    int exec() override {
        return QDialog::exec();
    }

    QVector<DeviceAbstract*> * devicesPtr; /**< Указатель на вектор устройств. */
    Ui::DeviceEditDialog *ui; /**< Указатель на графический интерфейс диалогового окна. */
};

#endif // DEVICEEDITDIALOG_H
