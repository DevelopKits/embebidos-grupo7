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
    connect(ui->horizontalSlider, SIGNAL(sliderMoved(int)), this, SLOT(controlvolumen(int)));
}

OpenGUI::~OpenGUI()
{
    delete ui;
}

void OpenGUI::handleButton()
{

    admin->statePlay();
}

void OpenGUI::handleButtonPause()
{
    admin->statePause();
}

/*void OpenGUI::controlvolumen(int n)
{
    admin->stateVolumen(n);
}*/
