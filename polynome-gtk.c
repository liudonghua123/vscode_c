#include <gtk/gtk.h>

// create global widget variable for easy use in callback of event handler
// type GtkWindow
GtkWidget *window;
// type GtkButton
GtkWidget *calculateButton;
// type GtkLabel
GtkWidget *resultLabel;
// type GtkEntry
GtkWidget *coefficientEntry;
// type GtkEntry
GtkWidget *exponentEntry;
// type GtkButton
GtkWidget *insertButton;
// type GtkButton
GtkWidget *deleteButton;
// type GtkButton
GtkWidget *printButton;

/**
 * use GtkBuilder to parse, initialize widgets and connect signals
 */
void initializationWidgets() {
    // create a GtkBuilder to parse xml format ui file
    GtkBuilder *builder = gtk_builder_new();
    // see https://developer.gnome.org/gtk3/stable/GtkBuilder.html#gtk-builder-add-from-file
    gtk_builder_add_from_file(builder, "polynome.glade", NULL);
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
    calculateButton = GTK_WIDGET(gtk_builder_get_object(builder, "calculateButton"));
    resultLabel = GTK_WIDGET(gtk_builder_get_object(builder, "resultLabel"));
    coefficientEntry = GTK_WIDGET(gtk_builder_get_object(builder, "coefficientEntry"));
    exponentEntry = GTK_WIDGET(gtk_builder_get_object(builder, "exponentEntry"));
    insertButton = GTK_WIDGET(gtk_builder_get_object(builder, "insertButton"));
    deleteButton = GTK_WIDGET(gtk_builder_get_object(builder, "deleteButton"));
    printButton = GTK_WIDGET(gtk_builder_get_object(builder, "printButton"));
    // connect all signals
    // see https://developer.gnome.org/gtk3/stable/GtkBuilder.html#gtk-builder-connect-signals
    gtk_builder_connect_signals(builder, NULL);
    // decrease the reference count like free/delete operation
    // see https://developer.gnome.org/gobject/stable/gobject-memory.html
    g_object_unref(builder);
    // see https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-show
    gtk_widget_show(window);
}


G_MODULE_EXPORT void on_calculateButton_clicked() {
    // g_print("running on_calculateButton_clicked\n");
    // ToDo
}
G_MODULE_EXPORT void on_insertButton_clicked() {
    // g_print("running on_insertButton_clicked\n");
    // ToDo
}
G_MODULE_EXPORT void on_deleteButton_clicked() {
    // g_print("running on_deleteButton_clicked\n");
    // ToDo
}
G_MODULE_EXPORT void on_printButton_clicked() {
    // g_print("running on_printButton_clicked\n");
    // ToDo
}

int main(int argc, char *argv[]) {
    // see https://developer.gnome.org/gtk3/stable/gtk3-General.html#gtk-init
    gtk_init(&argc, &argv);
    initializationWidgets();
    // see https://developer.gnome.org/gtk3/stable/gtk3-General.html#gtk-main
    gtk_main();
    return 0;
}