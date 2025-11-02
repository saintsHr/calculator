#include <gtk/gtk.h>
#include <gdk/gdk.h>

int main(int argc, char *argv[]){
    // init gtk
    gtk_init(&argc, &argv);

    // creates window
    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

    // sets size and title
    gtk_window_set_title(GTK_WINDOW(window), "Calculator");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 150);

    // sets window icon
    GError *err = NULL;
    if (!gtk_window_set_icon_from_file(GTK_WINDOW(window), "icon.png", &err)) {
        g_warning("Erro ao carregar ícone: %s", err->message);
        g_error_free(err);
    }

    // creates grid
    GtkWidget* grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // creates de visor
    GtkWidget *display = gtk_entry_new();
    gtk_editable_set_editable(GTK_EDITABLE(display), FALSE);
    gtk_entry_set_alignment(GTK_ENTRY(display), 1.0);
    gtk_widget_set_can_focus(display, FALSE);

    // creates buttons
    GtkWidget* button0 = gtk_button_new_with_label("0");
    GtkWidget* button1 = gtk_button_new_with_label("1");
    GtkWidget* button2 = gtk_button_new_with_label("2");
    GtkWidget* button3 = gtk_button_new_with_label("3");
    GtkWidget* button4 = gtk_button_new_with_label("4");
    GtkWidget* button5 = gtk_button_new_with_label("5");
    GtkWidget* button6 = gtk_button_new_with_label("6");
    GtkWidget* button7 = gtk_button_new_with_label("7");
    GtkWidget* button8 = gtk_button_new_with_label("8");
    GtkWidget* button9 = gtk_button_new_with_label("9");
    
    GtkWidget* buttonplus = gtk_button_new_with_label("+");
    GtkWidget* buttonminus = gtk_button_new_with_label("-");
    GtkWidget* buttonmult = gtk_button_new_with_label("x");
    GtkWidget* buttondiv = gtk_button_new_with_label("/");
    GtkWidget* buttonequal = gtk_button_new_with_label("=");
    GtkWidget* buttonclear = gtk_button_new_with_label("C");

    // attaches everything the grid
    gtk_grid_attach(GTK_GRID(grid), button1, 0, 5, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button2, 1, 5, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button3, 2, 5, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button4, 0, 6, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button5, 1, 6, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button6, 2, 6, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button7, 0, 7, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button8, 1, 7, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button9, 2, 7, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button0, 1, 8, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), buttonplus, 3, 5, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), buttonminus, 3, 6, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), buttonmult, 3, 7, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), buttondiv, 3, 8, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), buttonequal, 2, 8, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), buttonclear, 0, 8, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), display, 0, 0, 4, 1);

    // binds close signal
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // shows window
    gtk_widget_show_all(window);

    // main function
    gtk_main();
    return 0;
}