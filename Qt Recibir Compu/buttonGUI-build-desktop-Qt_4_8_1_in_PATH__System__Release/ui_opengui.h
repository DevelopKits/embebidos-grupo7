/********************************************************************************
** Form generated from reading UI file 'opengui.ui'
**
** Created: Fri Oct 4 18:33:48 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENGUI_H
#define UI_OPENGUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OpenGUI
{
public:
    QLabel *label_1;
    QPushButton *pushButton_1;
    QPushButton *pushButton;
    QSlider *horizontalSlider;

    void setupUi(QWidget *OpenGUI)
    {
        if (OpenGUI->objectName().isEmpty())
            OpenGUI->setObjectName(QString::fromUtf8("OpenGUI"));
        OpenGUI->resize(832, 411);
        label_1 = new QLabel(OpenGUI);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(280, 250, 131, 51));
        QFont font;
        font.setPointSize(14);
        label_1->setFont(font);
        pushButton_1 = new QPushButton(OpenGUI);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(370, 170, 121, 31));
        pushButton = new QPushButton(OpenGUI);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 170, 98, 27));
        horizontalSlider = new QSlider(OpenGUI);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(240, 230, 160, 29));
        horizontalSlider->setOrientation(Qt::Horizontal);

        retranslateUi(OpenGUI);

        QMetaObject::connectSlotsByName(OpenGUI);
    } // setupUi

    void retranslateUi(QWidget *OpenGUI)
    {
        OpenGUI->setWindowTitle(QApplication::translate("OpenGUI", "OpenGUI", 0, QApplication::UnicodeUTF8));
        label_1->setText(QApplication::translate("OpenGUI", "Volumen", 0, QApplication::UnicodeUTF8));
        pushButton_1->setText(QApplication::translate("OpenGUI", "Pause", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("OpenGUI", "Play", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OpenGUI: public Ui_OpenGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENGUI_H
