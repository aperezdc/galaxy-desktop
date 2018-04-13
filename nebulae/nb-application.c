/*
 * nb-application.c
 * Copyright (C) 2018 Adrian Perez <aperez@igalia.com>
 *
 * Distributed under terms of the MIT license.
 */

#include "nb-application.h"

#define auto __auto_type

G_DEFINE_TYPE (NbApplication, nb_application, DZL_TYPE_APPLICATION)

G_DEFINE_QUARK (org.perezdecastro.galaxy.nebulae.NbApplicationWindowWarning,
                create_window_warning)

enum
{
    CREATE_WINDOW,
    N_SIGNALS,
};

static int s_signals[N_SIGNALS] = { 0, };


static inline GtkApplicationWindow*
nb_application_create_window_default (NbApplication *app)
{
    // Try using the signal
    GtkApplicationWindow *new_window = NULL;

    g_signal_emit (app, s_signals[CREATE_WINDOW], 0, &new_window);
    if (new_window)
        return new_window;

    // Warn if the signal wasn't handled.
    GType app_type = G_TYPE_FROM_INSTANCE (app);
    void *flag = g_type_get_qdata (app_type, create_window_warning_quark ());
    if (!flag) {
        g_warning ("Class %s does not override create_window(),"
                   " nor the ::create-window signal was handled",
                   g_type_name (app_type));

        // Do not warn again for this particular application type.
        flag = (void*) 0x1;
        g_type_set_qdata (app_type, create_window_warning_quark (), flag);
    }
    return NULL;
}

static inline GtkWindow*
nb_application_create_window (NbApplication *app)
{
    return GTK_WINDOW (NB_APPLICATION_GET_CLASS (app)->create_window (app));
}


static void
nb_application_quit_activate (G_GNUC_UNUSED GSimpleAction *action,
                              G_GNUC_UNUSED GVariant      *variant,
                              gpointer                     userdata)
{
    g_application_quit (G_APPLICATION (userdata));
}


static void
nb_application_constructed (GObject *object)
{
    G_OBJECT_CLASS (nb_application_parent_class)->constructed (object);

    dzl_application_add_resources (DZL_APPLICATION (object), "gresource://" RSRC);

    static const GActionEntry entries[] = {
        { .name = "quit", .activate = nb_application_quit_activate },
    };
    g_action_map_add_action_entries (G_ACTION_MAP (object),
                                     entries,
                                     G_N_ELEMENTS (entries),
                                     object);
}


static void
nb_application_activate (GApplication *app)
{
    GtkWindow *window = gtk_application_get_active_window (GTK_APPLICATION (app));

    // Try to create a window.
    if (!window)
        window = nb_application_create_window (NB_APPLICATION (app));

    if (window)
        gtk_window_present (window);
}


static void
nb_application_class_init (NbApplicationClass *klass)
{
    auto object_class = G_OBJECT_CLASS (klass);
    object_class->constructed = nb_application_constructed;

    auto app_class = G_APPLICATION_CLASS (klass);
    app_class->activate = nb_application_activate;

    klass->create_window = nb_application_create_window_default;

    s_signals[CREATE_WINDOW] =
        g_signal_new ("create-window",
                      NB_TYPE_APPLICATION,
                      G_SIGNAL_RUN_LAST,
                      0,
                      NULL,
                      NULL,
                      NULL,
                      GTK_TYPE_APPLICATION_WINDOW,
                      0);
}


static void
nb_application_init (G_GNUC_UNUSED NbApplication *app)
{
}
