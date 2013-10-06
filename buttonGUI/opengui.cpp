#include "opengui.h"
#include "ui_opengui.h"
#include "mediacontrol.h"
#include <stdlib.h>
#include <QDebug>
#include <dirent.h>



MediaControl *admin = new MediaControl;
int actualIndex = 0;


OpenGUI::OpenGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OpenGUI)
{
    ui->setupUi(this);
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(handleButton()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(handlePlay()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(handlePause()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(handleSeek()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(handleNext()));
    admin->init();
}

OpenGUI::~OpenGUI()
{
    delete ui;
}

void OpenGUI::handlePlay()
{

    qDebug("Current index: %d", ui->comboBox_1->currentIndex());

    //QString root = "/media/sda1/";
    QString root = "/home/ldiego/Incrustados/";
    int index = ui->comboBox_1->currentIndex();
    actualIndex = index;
    root.append(ComboList.at(index));
    ui->label_1->setText(root);

    QByteArray byteArray = root.toUtf8();
    const char* song_name = byteArray.constData();


    qDebug() << "file name: " << song_name << " in handlePlay()";
    admin->statePlay(song_name);
}

void OpenGUI::handlePause()
{
    admin->statePause();
}

void OpenGUI::handleButton()
{
    DIR *dir;
    struct dirent *ent;
    //if ((dir = opendir ("/media/sda1/")) != NULL) {
    if ((dir = opendir ("/home/ldiego/Incrustados/")) != NULL) {
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

void OpenGUI::handleSeek()
{
    int test = 30;
    admin->seekTime(test);
}

void OpenGUI::handleNext()
{
    if((ui->comboBox_1->count() - 1) > actualIndex){
        actualIndex += 1;
        QString root = "/home/ldiego/Incrustados/";
        //int index = ui->comboBox_1->currentIndex();
        //actualIndex = index;
        root.append(ComboList.at(actualIndex));
        ui->label_1->setText(root);

        QByteArray byteArray = root.toUtf8();
        const char* song_route = byteArray.constData();

        qDebug() << "file name: " << song_route;
        admin->statePlay(song_route);

    } else {
        qDebug() << "NO MORE SONGS";
    }
}

