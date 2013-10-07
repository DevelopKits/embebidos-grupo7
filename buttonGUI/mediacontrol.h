#ifndef MEDIA_CTRL_H
#define MEDIA_CTRL_H

#include <gst/gst.h>


class MediaControl
{
    void onStateChange(bool);

public:
    MediaControl();
    ~MediaControl();

    int init();
    int statePlay(const char*);
    int statePause();
    int seekTime(int);
    int getSongPos();
    int getSongLen();


};

#endif // MEDIA_CTRL_H
