
#include <gst/gst.h>
#include <stdlib.h>
#include "player.h"

static GstElement *pipeline = NULL;

Player* player_new() {
    Player *player = malloc(sizeof(Player));
    player->playlist = NULL;
    player->is_playing = FALSE;
    return player;
}

void player_set_playlist(Player *player, Playlist *playlist) {
    player->playlist = playlist;
}

void player_play(Player *player) {
    if (!pipeline) {
        pipeline = gst_element_factory_make("playbin", "playbin");
    }

    const char *current_song = playlist_get_current_song(player->playlist);
    if (current_song) {
        g_object_set(pipeline, "uri", current_song, NULL);
        gst_element_set_state(pipeline, GST_STATE_PLAYING);
        player->is_playing = TRUE;
    }
}

void player_stop(Player *player) {
    if (pipeline) {
        gst_element_set_state(pipeline, GST_STATE_NULL);
        player->is_playing = FALSE;
    }
}

void player_free(Player *player) {
    if (pipeline) {
        gst_element_set_state(pipeline, GST_STATE_NULL);
        gst_object_unref(pipeline);
    }
    free(player);
}