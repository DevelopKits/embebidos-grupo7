#ifndef MEDIA_CTRL_H
#define MEDIA_CTRL_H

#include <gst/gst.h>

class MediaControl
{

public:
    MediaControl();
    void init();
    int statePlay();
    int statePause();

};

#endif // MEDIA_CTRL_H
