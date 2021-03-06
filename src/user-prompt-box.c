/* user-prompt-box.c generated by valac 0.30.1, the Vala compiler
 * generated from user-prompt-box.vala, do not modify */

/* -*- Mode: Vala; indent-tabs-mode: nil; tab-width: 4 -*-
 *
 * Copyright (C) 2011,2012 Canonical Ltd
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authors: Robert Ancell <robert.ancell@canonical.com>
 *          Michael Terry <michael.terry@canonical.com>
 */

#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <cairo.h>
#include <stdlib.h>
#include <string.h>


#define TYPE_FADABLE (fadable_get_type ())
#define FADABLE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_FADABLE, Fadable))
#define IS_FADABLE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_FADABLE))
#define FADABLE_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), TYPE_FADABLE, FadableIface))

typedef struct _Fadable Fadable;
typedef struct _FadableIface FadableIface;

#define TYPE_FADE_TRACKER (fade_tracker_get_type ())
#define FADE_TRACKER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_FADE_TRACKER, FadeTracker))
#define FADE_TRACKER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_FADE_TRACKER, FadeTrackerClass))
#define IS_FADE_TRACKER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_FADE_TRACKER))
#define IS_FADE_TRACKER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_FADE_TRACKER))
#define FADE_TRACKER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_FADE_TRACKER, FadeTrackerClass))

typedef struct _FadeTracker FadeTracker;
typedef struct _FadeTrackerClass FadeTrackerClass;

#define TYPE_FADABLE_BOX (fadable_box_get_type ())
#define FADABLE_BOX(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_FADABLE_BOX, FadableBox))
#define FADABLE_BOX_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_FADABLE_BOX, FadableBoxClass))
#define IS_FADABLE_BOX(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_FADABLE_BOX))
#define IS_FADABLE_BOX_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_FADABLE_BOX))
#define FADABLE_BOX_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_FADABLE_BOX, FadableBoxClass))

typedef struct _FadableBox FadableBox;
typedef struct _FadableBoxClass FadableBoxClass;
typedef struct _FadableBoxPrivate FadableBoxPrivate;

#define TYPE_PROMPT_BOX (prompt_box_get_type ())
#define PROMPT_BOX(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PROMPT_BOX, PromptBox))
#define PROMPT_BOX_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PROMPT_BOX, PromptBoxClass))
#define IS_PROMPT_BOX(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PROMPT_BOX))
#define IS_PROMPT_BOX_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PROMPT_BOX))
#define PROMPT_BOX_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PROMPT_BOX, PromptBoxClass))

typedef struct _PromptBox PromptBox;
typedef struct _PromptBoxClass PromptBoxClass;
typedef struct _PromptBoxPrivate PromptBoxPrivate;

#define TYPE_FADING_LABEL (fading_label_get_type ())
#define FADING_LABEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_FADING_LABEL, FadingLabel))
#define FADING_LABEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_FADING_LABEL, FadingLabelClass))
#define IS_FADING_LABEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_FADING_LABEL))
#define IS_FADING_LABEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_FADING_LABEL))
#define FADING_LABEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_FADING_LABEL, FadingLabelClass))

typedef struct _FadingLabel FadingLabel;
typedef struct _FadingLabelClass FadingLabelClass;

#define TYPE_FLAT_BUTTON (flat_button_get_type ())
#define FLAT_BUTTON(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_FLAT_BUTTON, FlatButton))
#define FLAT_BUTTON_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_FLAT_BUTTON, FlatButtonClass))
#define IS_FLAT_BUTTON(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_FLAT_BUTTON))
#define IS_FLAT_BUTTON_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_FLAT_BUTTON))
#define FLAT_BUTTON_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_FLAT_BUTTON, FlatButtonClass))

typedef struct _FlatButton FlatButton;
typedef struct _FlatButtonClass FlatButtonClass;

#define TYPE_USER_PROMPT_BOX (user_prompt_box_get_type ())
#define USER_PROMPT_BOX(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_USER_PROMPT_BOX, UserPromptBox))
#define USER_PROMPT_BOX_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_USER_PROMPT_BOX, UserPromptBoxClass))
#define IS_USER_PROMPT_BOX(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_USER_PROMPT_BOX))
#define IS_USER_PROMPT_BOX_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_USER_PROMPT_BOX))
#define USER_PROMPT_BOX_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_USER_PROMPT_BOX, UserPromptBoxClass))

typedef struct _UserPromptBox UserPromptBox;
typedef struct _UserPromptBoxClass UserPromptBoxClass;
typedef struct _UserPromptBoxPrivate UserPromptBoxPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))

struct _FadableIface {
	GTypeInterface parent_iface;
	FadeTracker* (*get_fade_tracker) (Fadable* self);
	void (*set_fade_tracker) (Fadable* self, FadeTracker* value);
};

struct _FadableBox {
	GtkEventBox parent_instance;
	FadableBoxPrivate * priv;
};

struct _FadableBoxClass {
	GtkEventBoxClass parent_class;
	void (*draw_full_alpha) (FadableBox* self, cairo_t* c);
};

struct _PromptBox {
	FadableBox parent_instance;
	PromptBoxPrivate * priv;
	GtkGrid* box_grid;
	GtkGrid* name_grid;
	FadingLabel* name_label;
	FlatButton* option_button;
	GtkWidget* small_box_widget;
	FadingLabel* small_name_label;
	gint start_row;
	gint last_row;
};

struct _PromptBoxClass {
	FadableBoxClass parent_class;
	GtkGrid* (*create_name_grid) (PromptBox* self);
	GtkGrid* (*create_small_name_grid) (PromptBox* self);
	void (*set_start_row) (PromptBox* self);
	void (*reset_last_row) (PromptBox* self);
	void (*add_static_prompts) (PromptBox* self);
};

struct _UserPromptBox {
	PromptBox parent_instance;
	UserPromptBoxPrivate * priv;
	gchar* background;
	gchar* session;
	gboolean is_active;
};

struct _UserPromptBoxClass {
	PromptBoxClass parent_class;
};


static gpointer user_prompt_box_parent_class = NULL;

GType fade_tracker_get_type (void) G_GNUC_CONST;
GType fadable_get_type (void) G_GNUC_CONST;
GType fadable_box_get_type (void) G_GNUC_CONST;
GType prompt_box_get_type (void) G_GNUC_CONST;
GType fading_label_get_type (void) G_GNUC_CONST;
GType flat_button_get_type (void) G_GNUC_CONST;
GType user_prompt_box_get_type (void) G_GNUC_CONST;
enum  {
	USER_PROMPT_BOX_DUMMY_PROPERTY
};
UserPromptBox* user_prompt_box_new (const gchar* name);
UserPromptBox* user_prompt_box_construct (GType object_type, const gchar* name);
static void user_prompt_box_finalize (GObject* obj);


UserPromptBox* user_prompt_box_construct (GType object_type, const gchar* name) {
	UserPromptBox * self = NULL;
	const gchar* _tmp0_ = NULL;
	g_return_val_if_fail (name != NULL, NULL);
	_tmp0_ = name;
	self = (UserPromptBox*) g_object_new (object_type, "id", _tmp0_, NULL);
	return self;
}


UserPromptBox* user_prompt_box_new (const gchar* name) {
	return user_prompt_box_construct (TYPE_USER_PROMPT_BOX, name);
}


static void user_prompt_box_class_init (UserPromptBoxClass * klass) {
	user_prompt_box_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->finalize = user_prompt_box_finalize;
}


static void user_prompt_box_instance_init (UserPromptBox * self) {
}


static void user_prompt_box_finalize (GObject* obj) {
	UserPromptBox * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_USER_PROMPT_BOX, UserPromptBox);
	_g_free0 (self->background);
	_g_free0 (self->session);
	G_OBJECT_CLASS (user_prompt_box_parent_class)->finalize (obj);
}


GType user_prompt_box_get_type (void) {
	static volatile gsize user_prompt_box_type_id__volatile = 0;
	if (g_once_init_enter (&user_prompt_box_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UserPromptBoxClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) user_prompt_box_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UserPromptBox), 0, (GInstanceInitFunc) user_prompt_box_instance_init, NULL };
		GType user_prompt_box_type_id;
		user_prompt_box_type_id = g_type_register_static (TYPE_PROMPT_BOX, "UserPromptBox", &g_define_type_info, 0);
		g_once_init_leave (&user_prompt_box_type_id__volatile, user_prompt_box_type_id);
	}
	return user_prompt_box_type_id__volatile;
}



