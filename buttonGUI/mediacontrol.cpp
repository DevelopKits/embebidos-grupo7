#include "mediacontrol.h"
#include <string.h>


GstElement *source1, *mad1, *audioconvert1, *volume;
GstElement *source2, *mad2, *audioconvert2;
GstElement *rtpL16pay, *udpsink, *alsasink;
GstElement *pipeline, *local, *remote;
//GMainLoop *loop;

float var_vol = 0.5;
char song_pipe1[128];
char song_pipe2[128];
char *actual_song;

MediaControl::MediaControl()
{
}

MediaControl::~MediaControl()
{
    g_print ("END APP\n");
}


int MediaControl::getSongPos()
{
    gint64 pos;
    GstFormat fmt = GST_FORMAT_TIME;
    if (gst_element_query_position (pipeline, &fmt, &pos)){
        return pos / GST_SECOND;
    }
    g_print ("getSongPos() Failed\n");
    return -1;
}

int MediaControl::getSongLen()
{
    gint64 len;
    GstFormat fmt = GST_FORMAT_TIME;
    if (gst_element_query_duration (pipeline, &fmt, &len)){
        return len / GST_SECOND;
    }
    g_print ("getSongLen() Failed\n");
    return -1;
}

int MediaControl::init()
{
    gst_init (NULL, NULL);

    //loop = g_main_loop_new (NULL, FALSE);

    //gst-launch filesrc location=get_lucky.mp3 ! mad ! audioconvert ! rtpL16pay ! udpsink host=192.168.0.100 port=5000

    //primero es le verdadero, el segundo es un sobrenombre
    //pipeline    = gst_pipeline_new ("audio-player");
    local           = gst_pipeline_new ("audio-player");
    remote          = gst_pipeline_new ("audio-player");
    source1         = gst_element_factory_make ("filesrc","file-source");
    mad1            = gst_element_factory_make ("mad","mad");
    volume         = gst_element_factory_make ("volume","volume");
    audioconvert1   = gst_element_factory_make ("audioconvert","audioconvert");
    source2         = gst_element_factory_make ("filesrc","file-source");
    mad2            = gst_element_factory_make ("mad","mad");
    audioconvert2   = gst_element_factory_make ("audioconvert","audioconvert");
    rtpL16pay       = gst_element_factory_make ("rtpL16pay","rtpL16pay");
    udpsink         = gst_element_factory_make ("udpsink","udpsink");
    alsasink        = gst_element_factory_make ("alsasink","alsasink");

    if (!local || !remote || !source1 || !volume || !mad1 || !audioconvert1 || !source2 ||
            !mad2 || !audioconvert2 || !rtpL16pay || !udpsink || !alsasink) {
        g_printerr ("One element could not be created. Exiting.\n");
        return -1;
    }

    gst_bin_add_many (GST_BIN (local), source1, mad1, volume, audioconvert1, alsasink, NULL);
    gst_element_link_many (source1, mad1, audioconvert1, volume, alsasink, NULL);

    gst_bin_add_many (GST_BIN (remote), source2, mad2, audioconvert2, rtpL16pay, udpsink, NULL);
    gst_element_link_many (source2, mad2, audioconvert2, rtpL16pay, udpsink, NULL);


    g_object_set (G_OBJECT(volume), "volume", var_vol, NULL);

    pipeline = local;
    actual_song = song_pipe1;

    //gst_bin_add_many (GST_BIN (pipeline), source, mad, audioconvert, rtpL16pay, udpsink, NULL);
    //gst_element_link_many (source, mad, audioconvert, rtpL16pay, udpsink, NULL);
    //g_object_set( udpsink, "host", "127.0.0.1", "port", 5000, NULL );

    return 0;
}

int MediaControl::changePipe(bool is_local)
{
    if(is_local){
        gst_element_set_state (pipeline, GST_STATE_PAUSED);
        pipeline = remote;
        actual_song = song_pipe2;
    } else {
        gst_element_set_state (pipeline, GST_STATE_PAUSED);
        pipeline = local;
        actual_song = song_pipe1;
    }
    return 0;
}

int MediaControl::statePause()
{
    g_print ("PAUSED\n");
    gst_element_set_state (pipeline, GST_STATE_PAUSED);
    return 0;
}

int MediaControl::statePlay(const char *song_name)
{
    if(strcmp(actual_song,song_name) != 0){
        strcpy(actual_song,song_name);
        g_print ("NEW SONG: %s\n",song_name);
        seekTime(0);
        gst_element_set_state (pipeline, GST_STATE_NULL);
        g_object_set (G_OBJECT (source1), "location", song_name, NULL);
        g_object_set (G_OBJECT (source2), "location", song_name, NULL);
    }

    g_print ("Now playing: %s\n", song_name);
    gst_element_set_state (pipeline, GST_STATE_PLAYING);

    //g_print ("Running...\n");
    //g_main_loop_run (loop);

    //g_print ("Returned, stopping playback\n");
    //gst_element_set_state (pipeline, GST_STATE_NULL);

    //g_print ("Deleting pipeline\n");
    //gst_object_unref (GST_OBJECT (pipeline));
    //g_main_loop_unref (loop);

    return 0;
}

int MediaControl::newVol(float vol)
{
    if (vol <= 1.0 && vol > 0.01){
        g_print ("in newVol(): %f\n", vol);
        g_object_set (G_OBJECT(volume), "volume", vol, NULL);
    }
    return 0;
}

int MediaControl::seekTime(int second)
{
    gst_element_set_state (pipeline, GST_STATE_PAUSED);
    gint64 time_nanoseconds = second * GST_SECOND;
    g_print ("seek: %llu!\n", time_nanoseconds);
    if (!gst_element_seek (pipeline, 1.0, GST_FORMAT_TIME, GST_SEEK_FLAG_FLUSH,
        GST_SEEK_TYPE_SET, time_nanoseconds,
        GST_SEEK_TYPE_NONE, GST_CLOCK_TIME_NONE)) {
        g_print ("Seek failed!\n");
        return -1;
    }
    gst_element_set_state (pipeline, GST_STATE_PLAYING);
    g_print ("Seek done\n");
    return 0;
}

int MediaControl::setIP(const char *ip)
{
    g_object_set( udpsink, "host", ip, "port", 5000, NULL );
    return 0;
}
