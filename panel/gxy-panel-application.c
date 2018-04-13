/*
 * gxy-panel-application.c
 * Copyright (C) 2018 Adrian Perez <aperez@igalia.com>
 *
 * Distributed under terms of the MIT license.
 */

#include "gxy-panel-application.h"

#include "nb-panel.h"


struct _GxyPanelApplication
{
    NbApplication parent;
};

G_DEFINE_TYPE (GxyPanelApplication, gxy_panel_application, NB_TYPE_APPLICATION)


static GtkWindow*
gxy_panel_application_create_window (NbApplication *app)
{
    return g_object_new (NB_TYPE_PANEL, NULL);
}


static void
gxy_panel_application_class_init (GxyPanelApplicationClass *klass)
{
    NbApplicationClass *nb_app_class = NB_APPLICATION_GET_CLASS (klass);
    nb_app_class->create_window = gxy_panel_application_create_window;
}


static void
gxy_panel_application_init (GxyPanelApplication *app)
{
}


NB_APPLICATION_DEFINE_SINGLETON (gxy_panel_application)
{
    return g_object_new (GXY_TYPE_PANEL_APPLICATION,
                         "application-id", "org.perezdecastro.galaxy.Panel",
                         "resource-base-path", "/org/perezdecastro/galaxy/panel",
                         NULL);
}
