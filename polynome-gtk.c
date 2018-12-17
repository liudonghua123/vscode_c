#include <gtk/gtk.h>
#include "polynome-linkedlist.h"

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
// type GtkEntry
GtkWidget *ploynomeEntry;
// type GtkEntry
GtkWidget *valueEntry;
// type GtkButton
GtkWidget *insertButton;
// type GtkButton
GtkWidget *deleteButton;
// type GtkButton
GtkWidget *printButton;

// 定义一个带头节点的多项式列表
polynome_node_tp head;

/**
 * use GtkBuilder to parse, initialize widgets and connect signals
 */
void initializationWidgets() {
  // create a GtkBuilder to parse xml format ui file
  GtkBuilder *builder = gtk_builder_new();
  // see
  // https://developer.gnome.org/gtk3/stable/GtkBuilder.html#gtk-builder-add-from-file
  gtk_builder_add_from_file(builder, "polynome.glade", NULL);
  window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
  calculateButton =
      GTK_WIDGET(gtk_builder_get_object(builder, "calculateButton"));
  resultLabel = GTK_WIDGET(gtk_builder_get_object(builder, "resultLabel"));
  coefficientEntry =
      GTK_WIDGET(gtk_builder_get_object(builder, "coefficientEntry"));
  exponentEntry = GTK_WIDGET(gtk_builder_get_object(builder, "exponentEntry"));
  valueEntry = GTK_WIDGET(gtk_builder_get_object(builder, "valueEntry"));
  ploynomeEntry = GTK_WIDGET(gtk_builder_get_object(builder, "ploynomeEntry"));
  insertButton = GTK_WIDGET(gtk_builder_get_object(builder, "insertButton"));
  deleteButton = GTK_WIDGET(gtk_builder_get_object(builder, "deleteButton"));
  printButton = GTK_WIDGET(gtk_builder_get_object(builder, "printButton"));
  // connect all signals
  // see
  // https://developer.gnome.org/gtk3/stable/GtkBuilder.html#gtk-builder-connect-signals
  gtk_builder_connect_signals(builder, NULL);
  // decrease the reference count like free/delete operation
  // see https://developer.gnome.org/gobject/stable/gobject-memory.html
  g_object_unref(builder);
  // see https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-show
  gtk_widget_show(window);

  init(&head);
}

G_MODULE_EXPORT void on_calculateButton_clicked() {
  // https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-get-text
  // https://stackoverflow.com/questions/7021725/how-to-convert-a-string-to-integer-in-c
  int value = atoi(gtk_entry_get_text(valueEntry));
  int result = calculate(head, value);
  // https://developer.gnome.org/gtk3/stable/GtkLabel.html#gtk-label-set-text
  char resultStr[10];
  itoa(result, resultStr, 10);
  g_print("calculate value: %d, result: %d\n", value, result);
  gtk_label_set_text(GTK_LABEL(resultLabel), resultStr);
}
G_MODULE_EXPORT void on_insertButton_clicked() {
  int coefficient = atoi(gtk_entry_get_text(GTK_ENTRY(coefficientEntry)));
  int exponent = atoi(gtk_entry_get_text(GTK_ENTRY(exponentEntry)));
  g_print("insert coefficient: %d, exponent: %d\n", coefficient, exponent);
  insert(head, coefficient, exponent);
}
G_MODULE_EXPORT void on_deleteButton_clicked() {
  int exponent = atoi(gtk_entry_get_text(GTK_ENTRY(exponentEntry)));
  delete (head, exponent);
  g_print("delete exponent: %d\n", exponent);
}
G_MODULE_EXPORT void on_printButton_clicked() {
  char result[1000];
  toString(head, result);
  gtk_entry_set_text(GTK_ENTRY(ploynomeEntry), result);
}

int main(int argc, char *argv[]) {
  // see https://developer.gnome.org/gtk3/stable/gtk3-General.html#gtk-init
  gtk_init(&argc, &argv);
  initializationWidgets();
  // see https://developer.gnome.org/gtk3/stable/gtk3-General.html#gtk-main
  gtk_main();
  return 0;
}