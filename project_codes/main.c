
#include <gtk/gtk.h>
#include <gst/gst.h>
#include "ui.h"
#include "player.h"
#include "playlist.h"

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);
    gst_init(&argc, &argv);

    Playlist *playlist = playlist_new();
    playlist_add_song(playlist, "file:///home/vboxuser/Downloads/song1.mp3");

    Player *player = player_new();
    player_set_playlist(player, playlist);

    UI *ui = ui_new();
    ui_set_player(ui, player);

    ui_show(ui);
    gtk_main();

    playlist_free(playlist);
    player_free(player);
    ui_free(ui);

    return 0;
}