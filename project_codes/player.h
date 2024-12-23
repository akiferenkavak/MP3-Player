
#ifndef PLAYER_H
#define PLAYER_H

#include "playlist.h"

typedef struct {
    Playlist *playlist;
    gboolean is_playing;
} Player;

Player* player_new();
void player_set_playlist(Player *player, Playlist *playlist);
void player_play(Player *player);
void player_stop(Player *player);
void player_free(Player *player);

#endif