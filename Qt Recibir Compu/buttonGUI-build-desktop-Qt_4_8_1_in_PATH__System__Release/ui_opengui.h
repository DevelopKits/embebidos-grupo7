/********************************************************************************
** Form generated from reading UI file 'opengui.ui'
**
** Created: Tue Oct 8 21:26:16 2013
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
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OpenGUI
{
public:
    QFrame *frame;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *OpenGUI)
    {
        if (OpenGUI->objectName().isEmpty())
            OpenGUI->setObjectName(QString::fromUtf8("OpenGUI"));
        OpenGUI->resize(810, 420);
        OpenGUI->setStyleSheet(QString::fromUtf8(""));
        frame = new QFrame(OpenGUI);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 811, 471));
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"     border-image: url(:/images/wallp.jpg);\n"
"\n"
" }"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(420, 30, 51, 51));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     border-style: outset;\n"
"	 image: url(:/images/play.png);\n"
" }\n"
" QPushButton:pressed {\n"
"     border-style: inset;\n"
" }"));
        pushButton_2->setFlat(false);
        pushButton_5 = new QPushButton(frame);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(710, 30, 51, 51));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     border-style: outset;\n"
"	 image: url(:/images/next.png);\n"
" }"));
        pushButton_3 = new QPushButton(frame);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(340, 30, 51, 51));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     border-style: outset;\n"
"	 image: url(:/images/pause.png);\n"
" }"));
        pushButton_6 = new QPushButton(frame);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(580, 30, 51, 51));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     border-style: outset;\n"
"	 image: url(:/images/prev.png);\n"
" }"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, -20, 291, 171));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-image:none;\n"
"}"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(640, 40, 61, 21));
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-image:none;\n"
"}"));

        retranslateUi(OpenGUI);

        QMetaObject::connectSlotsByName(OpenGUI);
    } // setupUi

    void retranslateUi(QWidget *OpenGUI)
    {
        OpenGUI->setWindowTitle(QApplication::translate("OpenGUI", "OpenGUI", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QString());
        pushButton_5->setText(QString());
        pushButton_3->setText(QString());
        pushButton_6->setText(QString());
        label->setText(QApplication::translate("OpenGUI", "Escuela de Ingenier\303\255a Electr\303\263nica\n"
"Introducci\303\263n a los Sistemas Embebidos\n"
"\n"
"Allan Calder\303\263n Aguilar\n"
"Diego Solano Monge\n"
"Fabian Solano Villalobos", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("OpenGUI", "Volumen", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OpenGUI: public Ui_OpenGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENGUI_H
