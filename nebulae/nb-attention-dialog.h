/*
 * nb-attention-dialog.h
 * Copyright (C) 2018 Adrian Perez <aperez@igalia.com>
 *
 * Distributed under terms of the MIT license.
 */

#pragma once

#include <gtk/gtk.h>

#define NB_TYPE_ATTENTION_DIALOG  (nb_attention_dialog_get_type ())

G_BEGIN_DECLS

G_DECLARE_DERIVABLE_TYPE (NbAttentionDialog,
                          nb_attention_dialog,
                          NB, ATTENTION_DIALOG,
                          GtkApplicationWindow)

struct _NbAttentionDialogClass
{
    GtkApplicationWindowClass parent_class;
};


GtkWidget*  nb_attention_dialog_new              (void);
const char* nb_attention_dialog_get_message      (NbAttentionDialog *dialog);
void        nb_attention_dialog_set_message      (NbAttentionDialog *dialog,
                                                  const char        *message);

GtkWidget*  nb_attention_dialog_get_extra_widget (NbAttentionDialog *dialog);
void        nb_attention_dialog_set_extra_widget (NbAttentionDialog *dialog,
                                                  GtkWidget         *widget);

G_END_DECLS
