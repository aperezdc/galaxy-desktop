/*
 * gxy-panel-application.c
 * Copyright (C) 2018 Adrian Perez <aperez@igalia.com>
 *
 * Distributed under terms of the MIT license.
 */

#include "gxy-panel-application.h"


struct _GxyPanelApplication
{
    DzlApplication parent;
};

G_DEFINE_TYPE (GxyPanelApplication, gxy_panel_application, DZL_TYPE_APPLICATION)


static void
gxy_panel_application_class_init (GxyPanelApplicationClass *klass)
{
}


static void
gxy_panel_application_init (GxyPanelApplication *app)
{
}


static void*
create_app_instance (G_GNUC_UNUSED void* userdata)
{
    return g_object_new (GXY_TYPE_PANEL_APPLICATION,
                         "application-id", "org.perezdecastro.galaxy.Panel",
                         NULL);
}

GxyPanelApplication*
gxy_panel_application_get (void)
{
    static GOnce create_app_instance_once = G_ONCE_INIT;
    g_once (&create_app_instance_once, create_app_instance, NULL);
    g_assert_nonnull (create_app_instance_once.retval);
    return create_app_instance_once.retval;
}
