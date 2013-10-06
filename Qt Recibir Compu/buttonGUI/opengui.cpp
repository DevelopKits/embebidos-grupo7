#include "opengui.h"
#include "ui_opengui.h"
#include "mediacontrol.h"
#include <stdlib.h>
#include <QDebug>

MediaControl *admin = new MediaControl;

OpenGUI::OpenGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OpenGUI)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(handleButton()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(handleButtonPause()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(handleButtonUp()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(handleButtonDown()));
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

