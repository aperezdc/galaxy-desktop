/*
 * test-attention-dialog.c
 * Copyright (C) 2018 Adrian Perez <aperez@igalia.com>
 *
 * Distributed under terms of the MIT license.
 */

#include "nb-application.h"
#include "nb-attention-dialog.h"


static GtkApplicationWindow*
on_create_window (NbApplication *app, G_GNUC_UNUSED void* userdata)
{
    g_autoptr(GtkWidget) window =
        g_object_new (NB_TYPE_ATTENTION_DIALOG,
                      "title", "Authentication Required",
                      "message", "Authentication is required for this resource",
                      "icon-name", "dialog-password",
                      NULL);

    gtk_application_add_window (GTK_APPLICATION (app), GTK_WINDOW (window));
    return g_steal_pointer (&window);
}


int
main (int argc, char *argv[])
{
    g_autoptr(GApplication) app = g_object_new (NB_TYPE_APPLICATION, NULL);
    g_signal_connect (app, "create-window", G_CALLBACK (on_create_window), NULL);
    return g_application_run (app, argc, argv);
}
