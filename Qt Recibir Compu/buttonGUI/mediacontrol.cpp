#include "mediacontrol.h"
#define AUDIO_CAPS "application/x-rtp,media=audio, clock-rate=89000, width=16, height=16, encoding-name=L16, payload=96"

GMainLoop *loop;
GstCaps *caps;
GstElement *pipeline, *source, *decoder, *conv, *volume, *sink;

MediaControl::MediaControl()
{

}

void MediaControl::init()
{

}


int MediaControl::statePlay()
{
    loop = g_main_loop_new (NULL, FALSE);

    /* Pipeline description*/
    /* gst-launch-0.10 -v udpsrc port=5000 caps="application/x-rtp,media=audio, clock-rate=89000, width=16, height=16, encoding-name=L16, 		   payload=96" ! rtpL16depay ! audioconvert ! alsasink sync=false */

    gst_init (NULL, NULL);

    /* Create gstreamer elements */
    pipeline = gst_pipeline_new ("audio-player");
    source   = gst_element_factory_make ("udpsrc",       "file-source");
    decoder  = gst_element_factory_make ("rtpL16depay",  "rtp-decoder");
    conv     = gst_element_factory_make ("audioconvert", "converter");
    volume   = gst_element_factory_make ("volume",       "volume");
    sink     = gst_element_factory_make ("alsasink",     "audio-output");

    if (!pipeline || !source || !decoder || !conv || !volume || !sink) {
        g_printerr ("One element could not be created. Exiting.\n");
        return -1;
    }

    /* Set up the pipeline */
    /* we set the input filename to the source element */
    caps = gst_caps_from_string (AUDIO_CAPS);
    g_object_set (G_OBJECT (source), "port", 5000, NULL);
    g_object_set (G_OBJECT (source), "caps", caps , NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    /* we add all elements into the pipeline */
    gst_bin_add_many (GST_BIN (pipeline),source, decoder, conv, volume, sink, NULL);

    /* we link the elements together */
    gst_element_link_many (source, decoder, conv, volume, sink, NULL);










    /* Set the pipeline to "playing" state*/
    g_print ("Now playing...\n");
    gst_element_set_state (pipeline, GST_STATE_PLAYING);




    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 0.2,NULL);
    g_object_set (G_OBJECT (volume), "volume", 1.3,NULL);
    g_object_set (G_OBJECT (volume), "volume", 1.3,NULL);
    g_object_set (G_OBJECT (volume), "volume", 1.3,NULL);
    g_object_set (G_OBJECT (volume), "volume", 1.3,NULL);
    g_object_set (G_OBJECT (volume), "volume", 1.3,NULL);
    g_object_set (G_OBJECT (volume), "volume", 1.3,NULL);
    g_object_set (G_OBJECT (volume), "volume", 1.3,NULL);
    g_object_set (G_OBJECT (volume), "volume", 1.3,NULL);
    g_object_set (G_OBJECT (volume), "volume", 1.3,NULL);
    g_object_set (G_OBJECT (volume), "volume", 1.3,NULL);
    g_object_set (G_OBJECT (volume), "volume", 1.3,NULL);
    g_object_set (G_OBJECT (volume), "volume", 1.3,NULL);
    g_object_set (G_OBJECT (volume), "volume", 1.3,NULL);
    g_object_set (G_OBJECT (volume), "volume", 1.3,NULL);
    g_object_set (G_OBJECT (volume), "volume", 1.3,NULL);
    g_object_set (G_OBJECT (volume), "volume", 1.3,NULL);
    g_object_set (G_OBJECT (volume), "volume", 1.3,NULL);
    g_object_set (G_OBJECT (volume), "volume", 1.3,NULL);
    g_object_set (G_OBJECT (volume), "volume", 1.3,NULL);




    /* Iterate */
    g_print ("Running...\n");
    g_main_loop_run (loop);

    /* Out of the main loop, clean up nicely */
    g_print ("Returned, stopping playback\n");
    gst_element_set_state (pipeline, GST_STATE_NULL);

    g_print ("Deleting pipeline\n");
    gst_object_unref (GST_OBJECT (pipeline));
    g_main_loop_unref (loop);

    return 0;
}

int MediaControl::statePause()
{
    /* Out of the main lyhoop, clean up nicely */
    g_print ("Returned, stopping playback\n");
    gst_element_set_state (pipeline, GST_STATE_NULL);

    return 0;

}

/*int MediaControl::stateVolumen(int n)
{

}*/
