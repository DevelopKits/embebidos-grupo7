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

OpenGUI::OpenGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OpenGUI)
{
    admin = new MediaControl();
    ui->setupUi(this);
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(handleButton()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(handleButtonPause()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(handleButtonUp()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(handleButtonDown()));
}

OpenGUI::~OpenGUI(){
    delete ui;
}

void OpenGUI::handleButton(){
    admin->statePlay();
}

void OpenGUI::handleButtonPause(){
    admin->statePause();
}

void OpenGUI::handleButtonUp(){
    admin->stateUp();
}

void OpenGUI::handleButtonDown(){
    admin->stateDown();
}
