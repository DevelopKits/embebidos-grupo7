#ifndef MEDIA_CTRL_H
#define MEDIA_CTRL_H

#include <gst/gst.h>


class MediaControl
{
    void onStateChange(bool);

public:
    MediaControl();
    void init();
    int statePlay();
    int statePause();
    int stateUp();
    int stateDown();

};

#endif // MEDIA_CTRL_H
