#ifndef MEDIA_CTRL_H
#define MEDIA_CTRL_H

#include <gst/gst.h>

class MediaControl
{

public:
    MediaControl();
    void init();
    int statePlay(const char *);

};

#endif // MEDIA_CTRL_H
