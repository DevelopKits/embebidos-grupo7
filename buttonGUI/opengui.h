#ifndef OPENGUI_H
#define OPENGUI_H

#include <QWidget>
#include <stdlib.h>
#include <QStringList>

namespace Ui {
    class OpenGUI;
}

class OpenGUI : public QWidget
{
    Q_OBJECT
    QStringList ComboList;

public:
    explicit OpenGUI(QWidget *parent = 0);
    ~OpenGUI();


private slots:
    void handleButton();
    void handlePlay();

private:
    Ui::OpenGUI *ui;
};

#endif // OPENGUI_H
