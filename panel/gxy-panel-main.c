/*
 * gxy-panel-main.c
 * Copyright (C) 2018 Adrian Perez <aperez@igalia.com>
 *
 * Distributed under terms of the MIT license.
 */

#include "gxy-config.h"
#include "gxy-panel-application.h"


static gboolean opt_replace = FALSE;
static gboolean opt_version = FALSE;

static const GOptionEntry cli_options[] =
{
    {
        .long_name = "replace",
        .arg = G_OPTION_ARG_NONE, .arg_data = &opt_replace,
        .description = "Replace currently running panel.",
    },
    {
        .long_name = "version",
        .arg = G_OPTION_ARG_NONE, .arg_data = &opt_version,
        .description = "Show version and exit.",
    },
    { NULL }
};


static int
on_handle_local_options (GApplication *app,
                         GVariantDict *options,
                         G_GNUC_UNUSED void *userdata)
{
    if (opt_version) {
        g_print ("%s\n", VERSION_STRING);
        return EXIT_SUCCESS;
    }

    return -1;  // Continue startup.
}


int
main (int argc, char *argv[])
{
    g_autoptr(GApplication) app = G_APPLICATION (gxy_panel_application_get ());
    g_application_add_main_option_entries (app, cli_options);
    g_signal_connect (app, "handle-local-options",
                      G_CALLBACK (on_handle_local_options), NULL);
    return g_application_run (app, argc, argv);
}
