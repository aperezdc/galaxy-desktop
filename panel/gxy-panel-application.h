/*
 * gxy-panel-application.h
 * Copyright (C) 2018 Adrian Perez <aperez@igalia.com>
 *
 * Distributed under terms of the MIT license.
 */

#pragma once

#include "nb-application.h"

G_BEGIN_DECLS

#define GXY_TYPE_PANEL_APPLICATION  (gxy_panel_application_get_type ())

G_DECLARE_FINAL_TYPE (GxyPanelApplication,
                      gxy_panel_application,
                      GXY, PANEL_APPLICATION,
                      NbApplication)

struct _NbPanelApplicationClass
{
    NbApplicationClass parent_class;
};

NB_APPLICATION_DECLARE_SINGLETON (gxy_panel_application);

G_END_DECLS
