/*
 * gxy-pkagent-main.c
 * Copyright (C) 2018 Adrian Perez <aperez@igalia.com>
 *
 * Distributed under terms of the MIT license.
 */

#define POLKIT_AGENT_I_KNOW_API_IS_SUBJECT_TO_CHANGE 1

#include "gxy-auth-panel.h"

#include "nb-application.h"
#include "nb-attention-dialog.h"

#include <polkitagent/polkitagent.h>
#include <unistd.h>

G_DEFINE_AUTOPTR_CLEANUP_FUNC (PolkitAgentListener, g_object_unref)


#define GXY_TYPE_AGENT  (gxy_agent_get_type ())

G_DECLARE_FINAL_TYPE (GxyAgent, gxy_agent, GXY, AGENT, PolkitAgentListener)

struct _GxyAgent
{
};

G_DEFINE_TYPE (GxyAgent, gxy_agent, POLKIT_AGENT_TYPE_LISTENER)


static void
gxy_agent_initiate_authentication (PolkitAgentListener *listener,
                                   const char          *action_id,
                                   const char          *message,
                                   const char          *icon_name,
                                   PolkitDetails       *details,
                                   const char          *cookie,
                                   GList               *identities,
                                   GCancellable        *cancellable,
                                   void                *userdata)
{
}


static gboolean
gxy_agent_initiate_authentication_finish (PolkitAgentListener *listener,
                                          GAsyncResult        *result,
                                          GError             **error)
{
}


static void
gxy_agent_class_init (GxyAgentClass *klass)
{
    PolkitAgentListenerClass *listener_class = POLKIT_AGENT_LISTENER_CLASS (klass);
    listener_class->initiate_authentication = gxy_agent_initiate_authentication;
    listener_class->initiate_authentication_finish = gxy_agent_initiate_authentication_finish;
}

static void
gxy_agent_init (GxyAgent *agent)
{
}


static GtkApplicationWindow*
on_create_window (NbApplication *app, G_GNUC_UNUSED void* userdata)
{
    GtkWidget *panel = g_object_new (GXY_TYPE_AUTH_PANEL, NULL);
    g_autoptr(NbAttentionDialog) window =
        g_object_new (NB_TYPE_ATTENTION_DIALOG,
                      "title", "Authentication Required",
                      "message", "Authentication is required for this resource",
                      "icon-name", "dialog-password",
                      "extra-widget", panel,
                      NULL);

    gtk_application_add_window (GTK_APPLICATION (app), GTK_WINDOW (window));
    gtk_widget_grab_focus (panel);

    return g_steal_pointer (&window);
}


int
main (int argc, char *argv[])
{
    g_autoptr(GApplication) app = g_object_new (NB_TYPE_APPLICATION, NULL);
    g_signal_connect (app, "create-window", G_CALLBACK (on_create_window), NULL);
    return g_application_run (app, argc, argv);
}
