/*
 * nb-application.h
 * Copyright (C) 2018 Adrian Perez <aperez@igalia.com>
 *
 * Distributed under terms of the MIT license.
 */

#pragma once

#include <dazzle.h>

#define NB_TYPE_APPLICATION  (nb_application_get_type ())

G_DECLARE_DERIVABLE_TYPE (NbApplication,
                          nb_application,
                          NB, APPLICATION,
                          DzlApplication)

struct _NbApplicationClass
{
    DzlApplicationClass parent_class;

    GtkApplicationWindow* (*create_window) (NbApplication* app);
};


#define NB_APPLICATION_DECLARE_SINGLETON(_t_c_name) \
    NbApplication* _t_c_name ## _get_instance (void)

#define NB_APPLICATION_DEFINE_SINGLETON(_t_c_name)                  \
    static void* _t_c_name ## _create_instance (void*);             \
                                                                    \
    NbApplication*                                                  \
    _t_c_name ## _get_instance (void)                               \
    {                                                               \
        static GOnce create_once = G_ONCE_INIT;                     \
        g_once (&create_once, _t_c_name ## _create_instance, NULL); \
        return create_once.retval;                                  \
    }                                                               \
                                                                    \
    static void*                                                    \
    _t_c_name ## _create_instance (G_GNUC_UNUSED void *__unused_arg)

G_END_DECLS
