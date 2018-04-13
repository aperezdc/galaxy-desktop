/*
 * nb-attention-dialog.c
 * Copyright (C) 2018 Adrian Perez <aperez@igalia.com>
 *
 * Distributed under terms of the MIT license.
 */

#include "nb-attention-dialog.h"

#define auto __auto_type


typedef struct
{
    GtkGrid   *grid;
    GtkLabel  *title;
    GtkLabel  *message;
    GtkImage  *image_icon;
    GtkButton *cancel_button;
    GtkButton *accept_button;
    GtkWidget *extra_widget;
} NbAttentionDialogPrivate;


G_DEFINE_TYPE_WITH_PRIVATE (NbAttentionDialog,
                            nb_attention_dialog,
                            GTK_TYPE_APPLICATION_WINDOW)

#define PRIV(n, o) \
    NbAttentionDialogPrivate *n = nb_attention_dialog_get_instance_private (o)

enum
{
    PROP_0,
    PROP_MESSAGE,
    PROP_EXTRA_WIDGET,
    N_PROPERTIES
};

static GParamSpec *s_properties[N_PROPERTIES] = { NULL, };


static void
nb_attention_dialog_get_property (GObject    *object,
                                  unsigned    prop_id,
                                  GValue     *value,
                                  GParamSpec *pspec)
{
    __auto_type dlg = NB_ATTENTION_DIALOG (object);
    switch (prop_id) {
        case PROP_MESSAGE:
            g_value_set_string (value, nb_attention_dialog_get_message (dlg));
            break;
        case PROP_EXTRA_WIDGET:
            g_value_set_object (value, nb_attention_dialog_get_extra_widget (dlg));
            break;
        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}


static void
nb_attention_dialog_set_property (GObject      *object,
                                  unsigned      prop_id,
                                  const GValue *value,
                                  GParamSpec   *pspec)
{
    __auto_type dlg = NB_ATTENTION_DIALOG (object);
    switch (prop_id) {
        case PROP_MESSAGE:
            nb_attention_dialog_set_message (dlg, g_value_get_string (value));
            break;
        case PROP_EXTRA_WIDGET:
            nb_attention_dialog_set_extra_widget (dlg, g_value_get_object (value));
            break;
        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}


static void
nb_attention_dialog_constructed (GObject *object)
{
    gtk_window_set_skip_taskbar_hint (GTK_WINDOW (object), TRUE);
    gtk_window_set_keep_above (GTK_WINDOW (object), TRUE);
    gtk_application_window_set_show_menubar (GTK_APPLICATION_WINDOW (object), FALSE);

    PRIV (priv, NB_ATTENTION_DIALOG (object));
    g_object_bind_property (object, "title", priv->title, "label",
                            G_BINDING_SYNC_CREATE);
    g_object_bind_property (object, "icon-name", priv->image_icon, "icon-name",
                            G_BINDING_SYNC_CREATE);

    G_OBJECT_CLASS (nb_attention_dialog_parent_class)->constructed (object);
}


static void
on_accept_button_clicked (GtkButton *button, NbAttentionDialog *dialog)
{
    g_print ("%s\n", __func__);
}


static void
on_cancel_button_clicked (GtkButton *button, NbAttentionDialog *dialog)
{
    g_print ("%s\n", __func__);
}


static void
nb_attention_dialog_class_init (NbAttentionDialogClass *klass)
{
    auto widget_class = GTK_WIDGET_CLASS (klass);
    gtk_widget_class_set_css_name (widget_class, "nb-attention-dialog");

    gtk_widget_class_set_template_from_resource (widget_class, RSRC "attention-dialog.ui");
    gtk_widget_class_bind_template_child_private (widget_class, NbAttentionDialog, grid);
    gtk_widget_class_bind_template_child_private (widget_class, NbAttentionDialog, title);
    gtk_widget_class_bind_template_child_private (widget_class, NbAttentionDialog, message);
    gtk_widget_class_bind_template_child_private (widget_class, NbAttentionDialog, image_icon);
    gtk_widget_class_bind_template_child_private (widget_class, NbAttentionDialog, cancel_button);
    gtk_widget_class_bind_template_child_private (widget_class, NbAttentionDialog, accept_button);
    gtk_widget_class_bind_template_callback (widget_class, on_accept_button_clicked);
    gtk_widget_class_bind_template_callback (widget_class, on_cancel_button_clicked);

    auto object_class = G_OBJECT_CLASS (klass);
    object_class->constructed = nb_attention_dialog_constructed;
    object_class->get_property = nb_attention_dialog_get_property;
    object_class->set_property = nb_attention_dialog_set_property;

    s_properties[PROP_MESSAGE] =
        g_param_spec_string ("message",
                             "Message",
                             "Message shown on the dialog",
                             "",
                             G_PARAM_READWRITE |
                             G_PARAM_STATIC_STRINGS);

    s_properties[PROP_EXTRA_WIDGET] =
        g_param_spec_object ("extra-widget",
                             "Extra widget",
                             "Additional widget shown on the dialog",
                             GTK_TYPE_WIDGET,
                             G_PARAM_READWRITE |
                             G_PARAM_STATIC_STRINGS);

    g_object_class_install_properties (object_class,
                                       N_PROPERTIES,
                                       s_properties);
}


static void
nb_attention_dialog_init (NbAttentionDialog *dlg)
{
    gtk_widget_init_template (GTK_WIDGET (dlg));
}


const char*
nb_attention_dialog_get_message (NbAttentionDialog *dialog)
{
    g_return_val_if_fail (NB_IS_ATTENTION_DIALOG (dialog), NULL);

    PRIV (priv, dialog);
    return gtk_label_get_text (priv->message);
}


void
nb_attention_dialog_set_message (NbAttentionDialog *dialog,
                                 const char        *message)
{
    g_return_if_fail (NB_IS_ATTENTION_DIALOG (dialog));

    PRIV (priv, dialog);
    if (g_strcmp0 (gtk_label_get_text (priv->message), message) == 0)
        return;

    gtk_label_set_text (priv->message, message);
    g_object_notify_by_pspec (G_OBJECT (dialog), s_properties[PROP_MESSAGE]);
}


GtkWidget*
nb_attention_dialog_get_extra_widget (NbAttentionDialog *dialog)
{
    g_return_val_if_fail (NB_IS_ATTENTION_DIALOG (dialog), NULL);

    PRIV (priv, dialog);
    return priv->extra_widget;
}


void
nb_attention_dialog_set_extra_widget (NbAttentionDialog *dialog,
                                      GtkWidget         *widget)
{
    g_return_if_fail (NB_IS_ATTENTION_DIALOG (dialog));

    PRIV (priv, dialog);

    if (priv->extra_widget == widget)
        return;

    g_clear_object (&priv->extra_widget);
    priv->extra_widget = widget;
    g_object_add_weak_pointer (G_OBJECT (widget),
                               (void**) &priv->extra_widget);
    gtk_grid_attach_next_to (priv->grid,
                             priv->extra_widget,
                             GTK_WIDGET (priv->message),
                             GTK_POS_BOTTOM, 1, 1);

    g_object_notify_by_pspec (G_OBJECT (dialog), s_properties[PROP_EXTRA_WIDGET]);
}
