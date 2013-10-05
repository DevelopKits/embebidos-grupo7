/********************************************************************************
** Form generated from reading UI file 'opengui.ui'
**
** Created: Fri Oct 4 14:58:56 2013
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
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OpenGUI
{
public:
    QPushButton *pushButton_1;
    QLineEdit *lineEdit;
    QSlider *verticalSlider;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *OpenGUI)
    {
        if (OpenGUI->objectName().isEmpty())
            OpenGUI->setObjectName(QString::fromUtf8("OpenGUI"));
        OpenGUI->resize(708, 425);
        pushButton_1 = new QPushButton(OpenGUI);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(220, 300, 111, 31));
        lineEdit = new QLineEdit(OpenGUI);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 210, 541, 23));
        verticalSlider = new QSlider(OpenGUI);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setGeometry(QRect(600, 170, 29, 160));
        verticalSlider->setOrientation(Qt::Vertical);
        label = new QLabel(OpenGUI);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(580, 150, 66, 17));
        pushButton = new QPushButton(OpenGUI);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(77, 300, 111, 31));

        retranslateUi(OpenGUI);

        QMetaObject::connectSlotsByName(OpenGUI);
    } // setupUi

    void retranslateUi(QWidget *OpenGUI)
    {
        OpenGUI->setWindowTitle(QApplication::translate("OpenGUI", "OpenGUI", 0, QApplication::UnicodeUTF8));
        pushButton_1->setText(QApplication::translate("OpenGUI", "Stop", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("OpenGUI", "Volumen", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("OpenGUI", "Play", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OpenGUI: public Ui_OpenGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENGUI_H
