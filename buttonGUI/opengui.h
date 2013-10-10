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
    void updateSlider(bool);

public:
    explicit OpenGUI(QWidget *parent = 0);
    ~OpenGUI();


private slots:
    void handleButton();
    void handlePause();
    void handlePlay();
    void handleSeek();
    void handleNext();
    void handlePrev();
    void handleSlider(int);
    void handleUpdate();
    void handlePipeline(int);
    void handleVol(int);

private:
    Ui::OpenGUI *ui;
};

#endif // OPENGUI_H
