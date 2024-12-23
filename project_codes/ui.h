
#ifndef UI_H
#define UI_H

#include "player.h"

typedef struct {
    GtkWidget *main_window;
    GtkWidget *play_button;
    GtkWidget *stop_button;
    GtkWidget *next_button; //for next song
    Player *player;
} UI;

UI* ui_new();
void ui_set_player(UI *ui, Player *player);
void ui_show(UI *ui);
void ui_free(UI *ui);

#endif