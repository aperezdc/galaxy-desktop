/*
 * nb-panel.h
 * Copyright (C) 2018 Adrian Perez <aperez@igalia.com>
 *
 * Distributed under terms of the MIT license.
 */

#pragma once

#include <gtk/gtk.h>

G_BEGIN_DECLS

typedef enum
{
    NB_PANEL_POSITION_TOP,
    NB_PANEL_POSITION_BOTTOM,
    NB_PANEL_POSITION_LEFT,
    NB_PANEL_POSITION_RIGHT,
} NbPanelPosition;


#define NB_TYPE_PANEL  (nb_panel_get_type ())

G_DECLARE_INTERFACE (NbPanel, nb_panel, NB, PANEL, GtkWindow)

struct _NbPanelInterface
{
    GTypeInterface g_iface;
};

G_END_DECLS
