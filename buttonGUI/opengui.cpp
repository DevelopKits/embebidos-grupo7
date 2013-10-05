#include "opengui.h"
#include "ui_opengui.h"
#include "mediacontrol.h"
#include <stdlib.h>
#include <QDebug>
#include <dirent.h>





OpenGUI::OpenGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OpenGUI)
{
    ui->setupUi(this);
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(handleButton()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(handlePlay()));



}

OpenGUI::~OpenGUI()
{
    delete ui;
}

void OpenGUI::handlePlay()
{
    qDebug("Current index: %d", ui->comboBox_1->currentIndex());

    MediaControl *admin = new MediaControl;
    //char song_route[80];

    QString root = "/media/sda1/";
    int index = ui->comboBox_1->currentIndex();
    root.append(ComboList.at(index));
    ui->label_1->setText(root);

    QByteArray byteArray = root.toUtf8();
    const char* song_route = byteArray.constData();

    qDebug() << "file name: " << song_route;
    admin->statePlay(song_route);
}


void OpenGUI::handleButton()
{
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir ("/media/sda1/")) != NULL) {
        /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != NULL) {
            qDebug("%s\n", ent->d_name);
            QString str = ent->d_name;
            if(str.contains(".mp3")) ComboList.append(str);
            //ComboList.append(str);
        }
        closedir (dir);
    } else {
        /* could not open directory */
        qDebug("ERROR NO OPEN DIR");
    }
    ui->comboBox_1->clear();
    ui->comboBox_1->addItems(ComboList);

}

