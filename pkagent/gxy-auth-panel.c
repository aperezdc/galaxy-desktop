/*
 * gxy-auth-panel.c
 * Copyright (C) 2018 Adrian Perez <aperez@igalia.com>
 *
 * Distributed under terms of the MIT license.
 */

#include "gxy-auth-panel.h"

#define auto __auto_type


struct _GxyAuthPanel
{
    GtkGrid      parent;
    GtkComboBox *identities;
    GtkEntry    *password_entry;
    GtkLabel    *error;
};

G_DEFINE_TYPE (GxyAuthPanel, gxy_auth_panel, GTK_TYPE_GRID)


static void
gxy_auth_panel_class_init (GxyAuthPanelClass *klass)
{
    auto widget_class = GTK_WIDGET_CLASS (klass);
    gtk_widget_class_set_template_from_resource (widget_class, RSRC "auth-panel.ui");
    gtk_widget_class_bind_template_child (widget_class, GxyAuthPanel, identities);
    gtk_widget_class_bind_template_child (widget_class, GxyAuthPanel, password_entry);
    gtk_widget_class_bind_template_child (widget_class, GxyAuthPanel, error);
}


static void
gxy_auth_panel_init (GxyAuthPanel *panel)
{
    gtk_widget_init_template (GTK_WIDGET (panel));
}
