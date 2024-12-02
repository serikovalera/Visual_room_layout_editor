//пользовательский виджет в графическом интерфейсе приложения
#include "widget.h"
#include "ui_widget.h"
#include "xml/filereader.h"
//предоставляют функциональность отладочного вывода, диалоговых окон выбора файлов, обработки горячих клавиш и диалоговых окон сообщений соответственно в библиотеке Qt.
#include <QDebug>
#include <QFileDialog>
#include <QShortcut>
#include <qmessagebox.h>

//принимает указатель на родительский виджет parent и инициализирует пользовательский интерфейс ui.
Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);//настройка пользовательского интерфейса

    graphicsScene = new GraphicsScene();
    graphicsView = new GraphicsView(graphicsScene);
    graphicsView->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

    graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    graphicsView->setScene(graphicsScene);
    graphicsView->setSceneRect(0, 0, SCENE_SIZE, SCENE_SIZE);
    graphicsScene->setSceneRect(0, 0, SCENE_SIZE, SCENE_SIZE);
//для отображения полос на сцене.
    this->graphicsScene->drawStripes();
    this->ui->editorLayout->addWidget(graphicsView);
// для горячих клавиш открытия файла, сохранения файла и сохранения файла как.
    QShortcut *openShortcut = new QShortcut(QKeySequence::Open, this);
    QShortcut *saveAsShortcut = new QShortcut(QKeySequence::SaveAs, this);
    QShortcut *saveShortcut = new QShortcut(QKeySequence::Save, this);
// установка соединений между горячими клавишами и соответствующими слотами (функциями)
    connect(openShortcut, &QShortcut::activated, this, &Widget::on_openBtn_pressed);
    connect(saveAsShortcut, &QShortcut::activated, this, &Widget::on_saveAsBtn_pressed);
    connect(saveShortcut, &QShortcut::activated, this, &Widget::on_saveBtn_pressed);
}

//освобождает память, выделенную для объекта ui
Widget::~Widget()
{
    delete ui;
}

//вызывается, когда кнопка arrowBtn переключается в состояние "включено/выключено".
void Widget::on_arrowBtn_toggled(bool checked)
{
    this->ui->dragBtn->setChecked(!checked);
    this->graphicsView->setDrag(!checked);
}

//, который вызывается, когда кнопка dragBtn переключается в состояние "включено/выключено".
void Widget::on_dragBtn_toggled(bool checked)
{
    this->ui->arrowBtn->setChecked(!checked);
    this->graphicsView->setDrag(checked);
}

//открытие диалогового окна выбора файла, чтение файла
void Widget::on_openBtn_pressed()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Открытие файла"), "", tr("XML Файлы (*.xml)"));

    if (!fileName.isEmpty()) {
        try {
            House* house = FileReader::readFile(fileName);
            this->graphicsScene->setPlanning(house);
            QMessageBox::information(this, tr("Загрузка файла"), tr("Файл успешно загружен!"));

        } catch (const std::exception& e) {
            QMessageBox::critical(this, tr("Ошибка"), tr("Ошибка при загрузке файла: %1").arg(e.what()));
        }
    }
}

void Widget::on_saveAsBtn_pressed()
{
    //проверка наличия планировки на сцене
    if (this->graphicsScene->getPlanning() == nullptr)
        return;
//открытие диалогового окна выбора файла для сохранения и вызов функции savePlanning(), которая сохраняет планировку в файл.
    QString fileName = QFileDialog::getSaveFileName(this, tr("Сохранение файла"), "", tr("XML Файлы (*.xml)"));

    if (fileName.isEmpty()) {
        return;
    }

    savePlanning(fileName);
}

// проверка наличия планировки на сцене graphicsScene и вызов функции savePlanning() для сохранения планировки в файл
void Widget::on_saveBtn_pressed()
{
    if (this->graphicsScene->getPlanning() == nullptr)
        return;

    savePlanning();
}

// сохраняет планировку на сцене graphicsScene в файл с указанным именем filename.
void Widget::savePlanning(QString filename)
{
    auto devices = this->graphicsScene->getPlanning()->getDevices();

    bool ipUnset = false;
//проверка наличия IP-адресов у устройств планировки, проверка на корректное расположение устройств
    for (auto device : devices) {
        if (device->getIp().isEmpty())
            ipUnset = true;

        if (device->isColliding()) {
            QMessageBox::critical(this, "Ошибка", "Невозможно сохранить схему! Некоторые устройства расположены некорректно.");
            return;
        }
    }

    if (ipUnset) {
        QMessageBox::StandardButton reply = QMessageBox::question(this, "Подтверждение", "Некоторые устройства не имеют IP-адресов. Вы действительно хотите сохранить схему?", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::No) {
            return;
        }
    }

    if (!FileReader::writeFile(this->graphicsScene->getPlanning(), filename)) {
        QMessageBox::critical(this, tr("Ошибка"), tr("Не удалось сохранить файл!"));
    } else {
        QMessageBox::information(this, "Успех", "Файл успешно сохранен!");
    }
}
