#include "opengui.h"
#include <QApplication>
#include <gst/gst.h>
#include <stdio.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OpenGUI w;
    w.show();

    return a.exec();
}
