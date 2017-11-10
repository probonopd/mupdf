/* Shows file chooser dialog and returns selected file. Compile: 
 * sudo apt install libgtk2.0-dev
 * gcc -Wl,--no-as-needed `pkg-config --cflags --libs gtk+-2.0` file_chooser.c -o file_chooser */

#include <gtk/gtk.h>
#include <string.h>

int main(int argc, char *argv[])
{
    gchar *path;
    GtkWidget *dialog;
    int dlg_ret = 0;

    gtk_init(&argc, &argv);
    dialog = gtk_file_chooser_dialog_new("Select file", NULL, GTK_FILE_CHOOSER_ACTION_OPEN, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT, NULL);
    dlg_ret = gtk_dialog_run(GTK_DIALOG(dialog));
    if(dlg_ret == GTK_RESPONSE_ACCEPT)
    {
	path = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
        if( path!=NULL )
        {
            return execlp("mupdf-gl", "mupdf-gl", path, NULL);
        }
    }
    gtk_widget_destroy(dialog);
    gtk_exit(0);
    return 0;
}
