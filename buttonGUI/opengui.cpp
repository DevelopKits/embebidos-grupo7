#include "opengui.h"
#include "ui_opengui.h"
#include "mediacontrol.h"
#include <stdlib.h>
#include <QDebug>

OpenGUI::OpenGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OpenGUI)
{
    ui->setupUi(this);
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(handleButton()));
}

OpenGUI::~OpenGUI()
{
    delete ui;
}

void OpenGUI::getName(const char *name)
{

}

void OpenGUI::handleButton()
{
    QString new_txt = "Example";
    MediaControl *admin = new MediaControl;
    char song_route[80];

    QString txt_read = ui->lineEdit->text();
    QByteArray byteArray = txt_read.toUtf8();
    const char* cString = byteArray.constData();

    strcat(song_route,"/media/sda1/");
    strcat(song_route,cString);
    ui->label_1->setText(new_txt);
    qDebug() << "file name: " << song_route;
    //admin->statePlay(cString);

}

