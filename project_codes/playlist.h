
#ifndef PLAYLIST_H
#define PLAYLIST_H

typedef struct {
    char **songs; //dynamic array of strings (points to the pointer of the first char array)
    int count; //number of songs in the playlist
    int current_index; //index of the current song
} Playlist;

Playlist* playlist_new();
void playlist_add_song(Playlist *playlist, const char *song);
const char* playlist_get_next_song(Playlist *playlist);
const char* playlist_get_previous_song(Playlist *playlist);
const char* playlist_get_current_song(Playlist *playlist);
void playlist_free(Playlist *playlist);

#endif