/*
 * gxy-panel-application.h
 * Copyright (C) 2018 Adrian Perez <aperez@igalia.com>
 *
 * Distributed under terms of the MIT license.
 */

#pragma once

#include <dazzle.h>

G_BEGIN_DECLS

#define GXY_TYPE_PANEL_APPLICATION  (gxy_panel_application_get_type ())

G_DECLARE_FINAL_TYPE (GxyPanelApplication,
                      gxy_panel_application,
                      GXY, PANEL_APPLICATION,
                      DzlApplication)

struct _GxyPanelApplicationClass
{
    DzlApplicationClass parent_class;
};

GxyPanelApplication* gxy_panel_application_get (void);

G_END_DECLS
