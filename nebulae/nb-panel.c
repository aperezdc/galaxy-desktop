/*
 * nb-panel.c
 * Copyright (C) 2018 Adrian Perez <aperez@igalia.com>
 *
 * Distributed under terms of the MIT license.
 */

#include "nb-enums.h"
#include "nb-panel.h"


G_DEFINE_INTERFACE (NbPanel, nb_panel, GTK_TYPE_WINDOW)


static void
nb_panel_default_init (NbPanelInterface *iface)
{
    g_object_interface_install_property (iface,
                                         g_param_spec_enum ("position",
                                                            "Panel position",
                                                            "Position of the panel on the screen",
                                                            NB_TYPE_PANEL_POSITION,
                                                            NB_PANEL_POSITION_TOP,
                                                            G_PARAM_READWRITE |
                                                            G_PARAM_CONSTRUCT |
                                                            G_PARAM_STATIC_STRINGS));
}
