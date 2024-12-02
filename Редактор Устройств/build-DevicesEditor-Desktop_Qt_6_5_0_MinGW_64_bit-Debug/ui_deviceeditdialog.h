/********************************************************************************
** Form generated from reading UI file 'deviceeditdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICEEDITDIALOG_H
#define UI_DEVICEEDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DeviceEditDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *ipEdit;
    QLabel *label_2;
    QLineEdit *nameEdit;
    QLabel *label_3;
    QLineEdit *brandEdit;
    QLabel *label_4;
    QLineEdit *serialEdit;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout;
    QSpinBox *widthSpin;
    QLabel *label_6;
    QSpinBox *lengthSpin;
    QLabel *label_7;
    QSpinBox *heightSpin;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DeviceEditDialog)
    {
        if (DeviceEditDialog->objectName().isEmpty())
            DeviceEditDialog->setObjectName("DeviceEditDialog");
        DeviceEditDialog->resize(400, 316);
        verticalLayout = new QVBoxLayout(DeviceEditDialog);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(DeviceEditDialog);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        ipEdit = new QLineEdit(DeviceEditDialog);
        ipEdit->setObjectName("ipEdit");

        verticalLayout->addWidget(ipEdit);

        label_2 = new QLabel(DeviceEditDialog);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        nameEdit = new QLineEdit(DeviceEditDialog);
        nameEdit->setObjectName("nameEdit");

        verticalLayout->addWidget(nameEdit);

        label_3 = new QLabel(DeviceEditDialog);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        brandEdit = new QLineEdit(DeviceEditDialog);
        brandEdit->setObjectName("brandEdit");

        verticalLayout->addWidget(brandEdit);

        label_4 = new QLabel(DeviceEditDialog);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        serialEdit = new QLineEdit(DeviceEditDialog);
        serialEdit->setObjectName("serialEdit");

        verticalLayout->addWidget(serialEdit);

        label_5 = new QLabel(DeviceEditDialog);
        label_5->setObjectName("label_5");

        verticalLayout->addWidget(label_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        widthSpin = new QSpinBox(DeviceEditDialog);
        widthSpin->setObjectName("widthSpin");
        widthSpin->setMinimum(1);
        widthSpin->setMaximum(1000);

        horizontalLayout->addWidget(widthSpin);

        label_6 = new QLabel(DeviceEditDialog);
        label_6->setObjectName("label_6");

        horizontalLayout->addWidget(label_6);

        lengthSpin = new QSpinBox(DeviceEditDialog);
        lengthSpin->setObjectName("lengthSpin");
        lengthSpin->setMinimum(1);
        lengthSpin->setMaximum(10000);

        horizontalLayout->addWidget(lengthSpin);

        label_7 = new QLabel(DeviceEditDialog);
        label_7->setObjectName("label_7");

        horizontalLayout->addWidget(label_7);

        heightSpin = new QSpinBox(DeviceEditDialog);
        heightSpin->setObjectName("heightSpin");
        heightSpin->setMinimum(1);
        heightSpin->setMaximum(10000);

        horizontalLayout->addWidget(heightSpin);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(DeviceEditDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DeviceEditDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DeviceEditDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DeviceEditDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DeviceEditDialog);
    } // setupUi

    void retranslateUi(QDialog *DeviceEditDialog)
    {
        DeviceEditDialog->setWindowTitle(QCoreApplication::translate("DeviceEditDialog", "\320\232\320\276\320\275\321\204\320\270\320\263\321\203\321\200\320\260\321\206\320\270\321\217 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260", nullptr));
        label->setText(QCoreApplication::translate("DeviceEditDialog", "IP \320\260\320\264\321\200\320\265\321\201 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260:", nullptr));
        label_2->setText(QCoreApplication::translate("DeviceEditDialog", "\320\230\320\274\321\217 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260:", nullptr));
        label_3->setText(QCoreApplication::translate("DeviceEditDialog", "\320\237\321\200\320\276\320\270\320\267\320\262\320\276\320\264\320\270\321\202\320\265\320\273\321\214:", nullptr));
        label_4->setText(QCoreApplication::translate("DeviceEditDialog", "\320\241\320\265\321\200\320\270\320\271\320\275\321\213\320\271 \320\275\320\276\320\274\320\265\321\200:", nullptr));
        label_5->setText(QCoreApplication::translate("DeviceEditDialog", "\320\223\320\260\320\261\320\260\321\200\320\270\321\202\321\213:", nullptr));
        widthSpin->setSuffix(QCoreApplication::translate("DeviceEditDialog", " \321\201\320\274", nullptr));
        label_6->setText(QCoreApplication::translate("DeviceEditDialog", "x", nullptr));
        lengthSpin->setSuffix(QCoreApplication::translate("DeviceEditDialog", " \321\201\320\274", nullptr));
        label_7->setText(QCoreApplication::translate("DeviceEditDialog", "x", nullptr));
        heightSpin->setSuffix(QCoreApplication::translate("DeviceEditDialog", " \321\201\320\274", nullptr));
        heightSpin->setPrefix(QString());
    } // retranslateUi

};

namespace Ui {
    class DeviceEditDialog: public Ui_DeviceEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICEEDITDIALOG_H
