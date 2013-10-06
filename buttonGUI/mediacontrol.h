#ifndef MEDIA_CTRL_H
#define MEDIA_CTRL_H

#include <gst/gst.h>

class MediaControl
{

public:
    MediaControl();
    int init();
    int statePlay(const char*);
    int statePause();
    int seekTime(int);
};

#endif // MEDIA_CTRL_H
