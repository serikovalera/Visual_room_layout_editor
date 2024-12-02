/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QToolButton *arrowBtn;
    QToolButton *dragBtn;
    QFrame *frame;
    QPushButton *openBtn;
    QPushButton *saveBtn;
    QPushButton *saveAsBtn;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *editorLayout;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        verticalLayout_2 = new QVBoxLayout(Widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        arrowBtn = new QToolButton(Widget);
        arrowBtn->setObjectName("arrowBtn");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        arrowBtn->setIcon(icon);
        arrowBtn->setCheckable(true);
        arrowBtn->setChecked(true);

        horizontalLayout->addWidget(arrowBtn);

        dragBtn = new QToolButton(Widget);
        dragBtn->setObjectName("dragBtn");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/drag.png"), QSize(), QIcon::Normal, QIcon::Off);
        dragBtn->setIcon(icon1);
        dragBtn->setCheckable(true);
        dragBtn->setChecked(false);

        horizontalLayout->addWidget(dragBtn);

        frame = new QFrame(Widget);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::VLine);
        frame->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(frame);

        openBtn = new QPushButton(Widget);
        openBtn->setObjectName("openBtn");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        openBtn->setIcon(icon2);

        horizontalLayout->addWidget(openBtn);

        saveBtn = new QPushButton(Widget);
        saveBtn->setObjectName("saveBtn");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveBtn->setIcon(icon3);

        horizontalLayout->addWidget(saveBtn);

        saveAsBtn = new QPushButton(Widget);
        saveAsBtn->setObjectName("saveAsBtn");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/saveas.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveAsBtn->setIcon(icon4);

        horizontalLayout->addWidget(saveAsBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);

        editorLayout = new QHBoxLayout();
        editorLayout->setObjectName("editorLayout");

        verticalLayout_2->addLayout(editorLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\320\240\320\265\320\264\320\260\320\272\321\202\320\276\321\200 \321\201\321\205\320\265\320\274\321\213 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262", nullptr));
#if QT_CONFIG(tooltip)
        arrowBtn->setToolTip(QCoreApplication::translate("Widget", "\320\240\320\265\320\266\320\270\320\274 \320\262\321\213\320\264\320\265\320\273\320\265\320\275\320\270\321\217", nullptr));
#endif // QT_CONFIG(tooltip)
        arrowBtn->setText(QCoreApplication::translate("Widget", "Hand", nullptr));
#if QT_CONFIG(tooltip)
        dragBtn->setToolTip(QCoreApplication::translate("Widget", "\320\240\320\265\320\266\320\270\320\274 \320\277\320\265\321\200\320\265\321\202\320\260\321\201\320\272\320\270\320\262\320\260\320\275\320\270\321\217", nullptr));
#endif // QT_CONFIG(tooltip)
        dragBtn->setText(QCoreApplication::translate("Widget", "Drag", nullptr));
#if QT_CONFIG(tooltip)
        openBtn->setToolTip(QCoreApplication::translate("Widget", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
#endif // QT_CONFIG(tooltip)
        openBtn->setText(QString());
#if QT_CONFIG(tooltip)
        saveBtn->setToolTip(QCoreApplication::translate("Widget", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
#endif // QT_CONFIG(tooltip)
        saveBtn->setText(QString());
#if QT_CONFIG(tooltip)
        saveAsBtn->setToolTip(QCoreApplication::translate("Widget", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\204\320\260\320\271\320\273 \320\272\320\260\320\272", nullptr));
#endif // QT_CONFIG(tooltip)
        saveAsBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
