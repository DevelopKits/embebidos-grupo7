#include "opengui.h"
#include "ui_opengui.h"
#include "mediacontrol.h"
#include <stdlib.h>
#include <QDebug>
#include <dirent.h>
#include <QMovie>
#include <QtCore/QTimer>
#include <QtCore/QTime>

MediaControl *admin;
int actualIndex = 0;
QMovie *movie;
QTimer m_positionTimer;
bool USB_in = false;
bool IP_set = false;


OpenGUI::OpenGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OpenGUI)
{
    this->setWindowFlags(Qt::CustomizeWindowHint); //Set window with no title bar
    this->setWindowFlags(Qt::FramelessWindowHint); //Set a frameless window
    admin = new MediaControl();
    ui->setupUi(this);
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(handleButton()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(handlePlay()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(handlePause()));
    //connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(handleSeek()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(handleNext()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(handlePrev()));
    connect(ui->horizontalSlider, SIGNAL(sliderMoved(int)), this, SLOT(handleSlider(int)));
    connect(ui->horizontalSlider_2, SIGNAL(valueChanged(int)), this, SLOT(handlePipeline(int)));
    connect(ui->verticalSlider, SIGNAL(valueChanged(int)), this, SLOT(handleVol(int)));
    connect(&m_positionTimer, SIGNAL(timeout()), this, SLOT(handleUpdate()));
    admin->init();

    movie = new QMovie(":/images/equ.gif");
    //QLabel *processLabel = new QLabel(this);
    ui->gif_label->setMovie(movie);
    movie->start();
    movie->setPaused(true);
    handleButton();
}

OpenGUI::~OpenGUI()
{

    delete ui;
}

void OpenGUI::updateSlider(bool is_playing)
{
    if(is_playing){
        m_positionTimer.start(1000);
    } else {
        m_positionTimer.stop();
    }
}

void OpenGUI::handlePlay()
{
    if(USB_in){
        qDebug("Current index: %d", ui->comboBox_1->currentIndex());

        QString root = "/media/sda1/";
        //QString root = "/home/ldiego/Incrustados/";
        int index = ui->comboBox_1->currentIndex();
        actualIndex = index;
        root.append(ComboList.at(index));

        QByteArray byteArray = root.toUtf8();
        const char* song_name = byteArray.constData();

        qDebug() << "file name:" << song_name << "in handlePlay()";
        admin->statePlay(song_name);

        ui->label_1->setText("Playing: " + ComboList.at(actualIndex));
        movie->setPaused(false);

        for(int i = 0; i < 1000000; i++){}

        int max_len = admin->getSongLen();
        qDebug() << "song length:" << max_len << "seconds.";
        if(max_len > 0) ui->horizontalSlider->setMaximum(max_len);
        updateSlider(true);
    } else {
        ui->label_1->setText("Please connect USB data");
    }
}

void OpenGUI::handlePause()
{
    if(USB_in){
        admin->statePause();
        ui->label_1->setText("Paused...");
        updateSlider(false);
        movie->setPaused(true);
    } else {
        ui->label_1->setText("Please connect USB data");
    }
}

void OpenGUI::handleButton()
{
    ComboList.clear();
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir ("/media/sda1/")) != NULL) {
    //if ((dir = opendir ("/home/ldiego/Incrustados/")) != NULL) {
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
        USB_in = false;
        qDebug("ERROR NO OPEN DIR");
    }
    ui->comboBox_1->clear();
    ui->comboBox_1->addItems(ComboList);
    if(ui->comboBox_1->count() > 0) USB_in = true;
    else USB_in = false;

}

void OpenGUI::handleSeek()
{
    if(USB_in){
        int test = 30;
        admin->seekTime(test);
    } else {
        ui->label_1->setText("Please connect USB data");
    }
}

void OpenGUI::handleNext()
{
    if(((ui->comboBox_1->count() - 1) > actualIndex) && USB_in){
        actualIndex += 1;
        QString root = "/media/sda1/";
        //QString root = "/home/ldiego/Incrustados/";
        root.append(ComboList.at(actualIndex));
        ui->label_1->setText("Playing: " + ComboList.at(actualIndex));

        QByteArray byteArray = root.toUtf8();
        const char* song_route = byteArray.constData();

        ui->comboBox_1->setCurrentIndex(actualIndex);
        qDebug() << "file name: " << song_route;
        admin->statePlay(song_route);
        movie->setPaused(false);
        updateSlider(true);
    } else {
        qDebug() << "NO MORE SONGS";
    }
}

void OpenGUI::handlePrev()
{
    if((actualIndex > 0) && USB_in){
        actualIndex -= 1;
        QString root = "/media/sda1/";
        //QString root = "/home/ldiego/Incrustados/";
        root.append(ComboList.at(actualIndex));
        ui->label_1->setText("Playing: " + ComboList.at(actualIndex));

        QByteArray byteArray = root.toUtf8();
        const char* song_route = byteArray.constData();

        ui->comboBox_1->setCurrentIndex(actualIndex);
        qDebug() << "file name: " << song_route;
        admin->statePlay(song_route);
        movie->setPaused(false);
        updateSlider(true);
    } else {
        qDebug() << "NO MORE SONGS";
    }
}

void OpenGUI::handleVol(int value)
{
    value += 2;
    float vol = (float)value / 100;
    qDebug() << "NO MORE SONGS" << vol;
    admin->newVol(vol);
}

void OpenGUI::handleUpdate()
{
    int pos = admin->getSongPos();
    ui->horizontalSlider->setSliderPosition(pos);
    ui->label_2->setText(QString::number(pos/60) + " : " + QString::number(pos%60));
    //qDebug() << "Song second:" << pos;
}

void OpenGUI::handleSlider(int value)
{
    if(USB_in){
        admin->seekTime(value);
        qDebug() << "New pos:" << value;
    } else {
        ui->label_1->setText("Please connect USB data");
    }

}

void OpenGUI::handlePipeline(int value)
{
    if(!IP_set){
        QString q_ip = ui->lineEdit->text();
        if(q_ip.compare("") != 0){
            QByteArray byteArray = q_ip.toUtf8();
            const char* ip = byteArray.constData();
            admin->setIP(ip);
            IP_set = true;

            bool send = value;
            qDebug() << "Value from slider" << send;
            admin->changePipe(send);
            updateSlider(false);
            movie->setPaused(true);

        } else {
            ui->label_1->setText("Please write a valid IP");
            ui->horizontalSlider_2->setSliderPosition(0);
        }
    } else {
        bool send = value;
        qDebug() << "Value from slider" << send;
        admin->changePipe(send);
        updateSlider(false);
        movie->setPaused(true);
    }



}

