/*
 * gxy-auth-panel.h
 * Copyright (C) 2018 Adrian Perez <aperez@igalia.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <gtk/gtk.h>

#pragma once

#define GXY_TYPE_AUTH_PANEL  (gxy_auth_panel_get_type ())

G_DECLARE_FINAL_TYPE (GxyAuthPanel, gxy_auth_panel, GXY, AUTH_PANEL, GtkGrid)
