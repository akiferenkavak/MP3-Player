#include <gtk/gtk.h>
#include "ui.h"

static void on_play_button_clicked(GtkWidget *button, gpointer user_data) {
    Player *player = (Player *)user_data;
    player_play(player);
}

static void on_stop_button_clicked(GtkWidget *button, gpointer user_data) {
    Player *player = (Player *)user_data;
    player_stop(player);
}

static void on_next_button_clicked(tkWidget *button, gpointer user_data) {
    Player *player = (Player *)user_data;

    playlist_get_next_song(player->playlist)
    player_play(player);
}

UI* ui_new() {
    UI *ui = malloc(sizeof(UI));

    ui->main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(ui->main_window), "MP3 Player");
    gtk_window_set_default_size(GTK_WINDOW(ui->main_window), 300, 100);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(ui->main_window), box);

    ui->play_button = gtk_button_new_with_label("Play");
    ui->stop_button = gtk_button_new_with_label("Stop");
    ui->next_button = gtk_button_new_with_label("Next");

    gtk_box_pack_start(GTK_BOX(box), ui->play_button, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), ui->stop_button, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), ui->next_button, TRUE, TRUE, 0);


    g_signal_connect(ui->main_window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    return ui;
}

void ui_set_player(UI *ui, Player *player) {
    ui->player = player;

    g_signal_connect(ui->play_button, "clicked", G_CALLBACK(on_play_button_clicked), player);
    g_signal_connect(ui->stop_button, "clicked", G_CALLBACK(on_stop_button_clicked), player);
    g_signal_connect(ui->stop_button, "clicked", G_CALLBACK(on_next_button_clicked), player);
}

void ui_show(UI *ui) {
    gtk_widget_show_all(ui->main_window);
}

void ui_free(UI *ui) {
    free(ui);
}