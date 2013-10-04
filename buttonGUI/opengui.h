#ifndef OPENGUI_H
#define OPENGUI_H

#include <QWidget>
#include <stdlib.h>

namespace Ui {
class OpenGUI;
}

class OpenGUI : public QWidget
{
    Q_OBJECT

public:
    explicit OpenGUI(QWidget *parent = 0);
    void getName(const char*);
    ~OpenGUI();


private slots:
    void handleButton();

private:
    Ui::OpenGUI *ui;
};

#endif // OPENGUI_H
