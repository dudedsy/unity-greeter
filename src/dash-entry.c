/* dash-entry.c generated by valac 0.30.1, the Vala compiler
 * generated from dash-entry.vala, do not modify */

/* -*- Mode: Vala; indent-tabs-mode: nil; tab-width: 4 -*-
 *
 * Copyright (C) 2012 Canonical Ltd
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
 * Authors: Michael Terry <michael.terry@canonical.com>
 */
/* Vala's vapi for gtk3 is broken for lookup_color (it forgets the out keyword) */

#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <gdk/gdk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <cairo.h>
#include <float.h>
#include <math.h>
#include <pango/pango.h>
#include <pango/pangocairo.h>
#include "config.h"


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

#define TYPE_DASH_ENTRY (dash_entry_get_type ())
#define DASH_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_DASH_ENTRY, DashEntry))
#define DASH_ENTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_DASH_ENTRY, DashEntryClass))
#define IS_DASH_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_DASH_ENTRY))
#define IS_DASH_ENTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_DASH_ENTRY))
#define DASH_ENTRY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_DASH_ENTRY, DashEntryClass))

typedef struct _DashEntry DashEntry;
typedef struct _DashEntryClass DashEntryClass;
typedef struct _DashEntryPrivate DashEntryPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define __vala_PangoFontDescription_free0(var) ((var == NULL) ? NULL : (var = (_vala_PangoFontDescription_free (var), NULL)))

#define TYPE_UNITY_GREETER (unity_greeter_get_type ())
#define UNITY_GREETER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_UNITY_GREETER, UnityGreeter))
#define UNITY_GREETER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_UNITY_GREETER, UnityGreeterClass))
#define IS_UNITY_GREETER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_UNITY_GREETER))
#define IS_UNITY_GREETER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_UNITY_GREETER))
#define UNITY_GREETER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_UNITY_GREETER, UnityGreeterClass))

typedef struct _UnityGreeter UnityGreeter;
typedef struct _UnityGreeterClass UnityGreeterClass;
typedef struct _UnityGreeterPrivate UnityGreeterPrivate;
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _FadableIface {
	GTypeInterface parent_iface;
	FadeTracker* (*get_fade_tracker) (Fadable* self);
	void (*set_fade_tracker) (Fadable* self, FadeTracker* value);
};

struct _DashEntry {
	GtkEntry parent_instance;
	DashEntryPrivate * priv;
};

struct _DashEntryClass {
	GtkEntryClass parent_class;
};

struct _DashEntryPrivate {
	gchar* _constant_placeholder_text;
	gboolean _can_respond;
	gboolean _did_respond;
	FadeTracker* _fade_tracker;
	GdkWindow* arrow_win;
};

struct _UnityGreeter {
	GTypeInstance parent_instance;
	volatile int ref_count;
	UnityGreeterPrivate * priv;
	gboolean test_mode;
	gboolean orca_needs_kick;
};

struct _UnityGreeterClass {
	GTypeClass parent_class;
	void (*finalize) (UnityGreeter *self);
};


static gpointer dash_entry_parent_class = NULL;
extern gchar* dash_entry_font;
gchar* dash_entry_font = NULL;
static GdkPixbuf* dash_entry_arrow_pixbuf;
static GdkPixbuf* dash_entry_arrow_pixbuf = NULL;
extern UnityGreeter* unity_greeter_singleton;
static FadableIface* dash_entry_fadable_parent_iface = NULL;

gboolean gtk_style_context_lookup_color (GtkStyleContext* ctx, const gchar* color_name, GdkRGBA* color);
GType fade_tracker_get_type (void) G_GNUC_CONST;
GType fadable_get_type (void) G_GNUC_CONST;
GType dash_entry_get_type (void) G_GNUC_CONST;
#define DASH_ENTRY_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_DASH_ENTRY, DashEntryPrivate))
enum  {
	DASH_ENTRY_DUMMY_PROPERTY,
	DASH_ENTRY_CONSTANT_PLACEHOLDER_TEXT,
	DASH_ENTRY_CAN_RESPOND,
	DASH_ENTRY_DID_RESPOND,
	DASH_ENTRY_FADE_TRACKER
};
static gboolean dash_entry_real_draw (GtkWidget* base, cairo_t* c);
FadeTracker* fadable_get_fade_tracker (Fadable* self);
gdouble fade_tracker_get_alpha (FadeTracker* self);
const gchar* dash_entry_get_constant_placeholder_text (DashEntry* self);
static void dash_entry_draw_prompt_text (DashEntry* self, cairo_t* c);
gboolean dash_entry_get_did_respond (DashEntry* self);
static void dash_entry_draw_spinner (DashEntry* self, cairo_t* c);
gboolean dash_entry_get_can_respond (DashEntry* self);
static void dash_entry_draw_arrow (DashEntry* self, cairo_t* c);
static gint dash_entry_get_arrow_size (DashEntry* self);
static void _vala_PangoFontDescription_free (PangoFontDescription* self);
static void dash_entry_real_activate (GtkEntry* base);
void dash_entry_set_did_respond (DashEntry* self, gboolean value);
gboolean dash_entry_button_press_event_cb (DashEntry* self, GdkEventButton* event);
static void dash_entry_get_arrow_location (DashEntry* self, gint* x, gint* y);
static void dash_entry_real_size_allocate (GtkWidget* base, GtkAllocation* allocation);
static void dash_entry_real_realize (GtkWidget* base);
static void dash_entry_real_unrealize (GtkWidget* base);
static void dash_entry_real_map (GtkWidget* base);
static void dash_entry_real_unmap (GtkWidget* base);
static gboolean dash_entry_real_key_press_event (GtkWidget* base, GdkEventKey* event);
gpointer unity_greeter_ref (gpointer instance);
void unity_greeter_unref (gpointer instance);
GParamSpec* param_spec_unity_greeter (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_unity_greeter (GValue* value, gpointer v_object);
void value_take_unity_greeter (GValue* value, gpointer v_object);
gpointer value_get_unity_greeter (const GValue* value);
GType unity_greeter_get_type (void) G_GNUC_CONST;
DashEntry* dash_entry_new (void);
DashEntry* dash_entry_construct (GType object_type);
void dash_entry_set_constant_placeholder_text (DashEntry* self, const gchar* value);
void dash_entry_set_can_respond (DashEntry* self, gboolean value);
static GObject * dash_entry_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
FadeTracker* fade_tracker_new (GtkWidget* widget);
FadeTracker* fade_tracker_construct (GType object_type, GtkWidget* widget);
void fadable_set_fade_tracker (Fadable* self, FadeTracker* value);
static void _gtk_widget_queue_draw_g_object_notify (GObject* _sender, GParamSpec* pspec, gpointer self);
static gboolean _dash_entry_button_press_event_cb_gtk_widget_button_press_event (GtkWidget* _sender, GdkEventButton* event, gpointer self);
static void dash_entry_finalize (GObject* obj);
static void _vala_dash_entry_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_dash_entry_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static gboolean dash_entry_real_draw (GtkWidget* base, cairo_t* c) {
	DashEntry * self;
	gboolean result = FALSE;
	GtkStyleContext* style_ctx = NULL;
	GtkStyleContext* _tmp0_ = NULL;
	GtkStyleContext* _tmp1_ = NULL;
	GtkStyleContext* _tmp2_ = NULL;
	cairo_t* _tmp3_ = NULL;
	cairo_t* _tmp4_ = NULL;
	cairo_t* _tmp5_ = NULL;
	cairo_t* _tmp6_ = NULL;
	cairo_t* _tmp7_ = NULL;
	FadeTracker* _tmp8_ = NULL;
	FadeTracker* _tmp9_ = NULL;
	gdouble _tmp10_ = 0.0;
	gdouble _tmp11_ = 0.0;
	cairo_t* _tmp12_ = NULL;
	GtkStyleContext* _tmp13_ = NULL;
	gboolean _tmp14_ = FALSE;
	guint16 _tmp15_ = 0U;
	gboolean _tmp20_ = FALSE;
	gboolean _tmp21_ = FALSE;
	self = (DashEntry*) base;
	g_return_val_if_fail (c != NULL, FALSE);
	_tmp0_ = gtk_widget_get_style_context ((GtkWidget*) self);
	_tmp1_ = _g_object_ref0 (_tmp0_);
	style_ctx = _tmp1_;
	_tmp2_ = style_ctx;
	gtk_style_context_save (_tmp2_);
	_tmp3_ = c;
	cairo_save (_tmp3_);
	_tmp4_ = c;
	cairo_push_group (_tmp4_);
	_tmp5_ = c;
	GTK_WIDGET_CLASS (dash_entry_parent_class)->draw ((GtkWidget*) G_TYPE_CHECK_INSTANCE_CAST (self, gtk_entry_get_type (), GtkEntry), _tmp5_);
	_tmp6_ = c;
	cairo_pop_group_to_source (_tmp6_);
	_tmp7_ = c;
	_tmp8_ = fadable_get_fade_tracker ((Fadable*) self);
	_tmp9_ = _tmp8_;
	_tmp10_ = fade_tracker_get_alpha (_tmp9_);
	_tmp11_ = _tmp10_;
	cairo_paint_with_alpha (_tmp7_, _tmp11_);
	_tmp12_ = c;
	cairo_restore (_tmp12_);
	_tmp13_ = style_ctx;
	gtk_style_context_restore (_tmp13_);
	_tmp15_ = gtk_entry_get_text_length ((GtkEntry*) self);
	if (((gint) _tmp15_) == 0) {
		const gchar* _tmp16_ = NULL;
		gint _tmp17_ = 0;
		gint _tmp18_ = 0;
		_tmp16_ = self->priv->_constant_placeholder_text;
		_tmp17_ = strlen (_tmp16_);
		_tmp18_ = _tmp17_;
		_tmp14_ = _tmp18_ > 0;
	} else {
		_tmp14_ = FALSE;
	}
	if (_tmp14_) {
		cairo_t* _tmp19_ = NULL;
		_tmp19_ = c;
		dash_entry_draw_prompt_text (self, _tmp19_);
	}
	_tmp20_ = dash_entry_get_did_respond (self);
	_tmp21_ = _tmp20_;
	if (_tmp21_) {
		cairo_t* _tmp22_ = NULL;
		_tmp22_ = c;
		dash_entry_draw_spinner (self, _tmp22_);
	} else {
		gboolean _tmp23_ = FALSE;
		gboolean _tmp24_ = FALSE;
		_tmp24_ = self->priv->_can_respond;
		if (_tmp24_) {
			guint16 _tmp25_ = 0U;
			_tmp25_ = gtk_entry_get_text_length ((GtkEntry*) self);
			_tmp23_ = ((gint) _tmp25_) > 0;
		} else {
			_tmp23_ = FALSE;
		}
		if (_tmp23_) {
			cairo_t* _tmp26_ = NULL;
			_tmp26_ = c;
			dash_entry_draw_arrow (self, _tmp26_);
		}
	}
	result = FALSE;
	_g_object_unref0 (style_ctx);
	return result;
}


static void dash_entry_draw_spinner (DashEntry* self, cairo_t* c) {
	cairo_t* _tmp0_ = NULL;
	GtkStyleContext* style_ctx = NULL;
	GtkStyleContext* _tmp1_ = NULL;
	GtkStyleContext* _tmp2_ = NULL;
	gint arrow_size = 0;
	gint _tmp3_ = 0;
	cairo_t* _tmp4_ = NULL;
	GdkWindow* _tmp5_ = NULL;
	cairo_t* _tmp6_ = NULL;
	cairo_t* _tmp7_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (c != NULL);
	_tmp0_ = c;
	cairo_save (_tmp0_);
	_tmp1_ = gtk_widget_get_style_context ((GtkWidget*) self);
	_tmp2_ = _g_object_ref0 (_tmp1_);
	style_ctx = _tmp2_;
	_tmp3_ = dash_entry_get_arrow_size (self);
	arrow_size = _tmp3_;
	_tmp4_ = c;
	_tmp5_ = self->priv->arrow_win;
	gtk_cairo_transform_to_window (_tmp4_, (GtkWidget*) self, _tmp5_);
	_tmp6_ = c;
	gtk_render_activity (style_ctx, _tmp6_, (gdouble) 0, (gdouble) 0, (gdouble) arrow_size, (gdouble) arrow_size);
	_tmp7_ = c;
	cairo_restore (_tmp7_);
	_g_object_unref0 (style_ctx);
}


static void dash_entry_draw_arrow (DashEntry* self, cairo_t* c) {
	GdkPixbuf* _tmp0_ = NULL;
	cairo_t* _tmp1_ = NULL;
	gint arrow_size = 0;
	gint _tmp2_ = 0;
	cairo_t* _tmp3_ = NULL;
	GdkWindow* _tmp4_ = NULL;
	cairo_t* _tmp5_ = NULL;
	gint _tmp6_ = 0;
	GdkPixbuf* _tmp7_ = NULL;
	gint _tmp8_ = 0;
	cairo_t* _tmp9_ = NULL;
	GdkPixbuf* _tmp10_ = NULL;
	cairo_t* _tmp11_ = NULL;
	cairo_t* _tmp12_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (c != NULL);
	_tmp0_ = dash_entry_arrow_pixbuf;
	if (_tmp0_ == NULL) {
		return;
	}
	_tmp1_ = c;
	cairo_save (_tmp1_);
	_tmp2_ = dash_entry_get_arrow_size (self);
	arrow_size = _tmp2_;
	_tmp3_ = c;
	_tmp4_ = self->priv->arrow_win;
	gtk_cairo_transform_to_window (_tmp3_, (GtkWidget*) self, _tmp4_);
	_tmp5_ = c;
	_tmp6_ = arrow_size;
	_tmp7_ = dash_entry_arrow_pixbuf;
	_tmp8_ = gdk_pixbuf_get_width (_tmp7_);
	cairo_translate (_tmp5_, (gdouble) ((_tmp6_ - _tmp8_) - 1), (gdouble) 0);
	_tmp9_ = c;
	_tmp10_ = dash_entry_arrow_pixbuf;
	gdk_cairo_set_source_pixbuf (_tmp9_, _tmp10_, (gdouble) 0, (gdouble) 0);
	_tmp11_ = c;
	cairo_paint (_tmp11_);
	_tmp12_ = c;
	cairo_restore (_tmp12_);
}


static void _vala_PangoFontDescription_free (PangoFontDescription* self) {
	g_boxed_free (pango_font_description_get_type (), self);
}


static void dash_entry_draw_prompt_text (DashEntry* self, cairo_t* c) {
	cairo_t* _tmp0_ = NULL;
	gint x = 0;
	gint y = 0;
	gint _tmp1_ = 0;
	gint _tmp2_ = 0;
	cairo_t* _tmp3_ = NULL;
	gint _tmp4_ = 0;
	gint _tmp5_ = 0;
	GdkRGBA fg = {0};
	GtkStyleContext* context = NULL;
	GtkStyleContext* _tmp6_ = NULL;
	GtkStyleContext* _tmp7_ = NULL;
	GtkStyleContext* _tmp8_ = NULL;
	GdkRGBA _tmp9_ = {0};
	gboolean _tmp10_ = FALSE;
	cairo_t* _tmp11_ = NULL;
	GdkRGBA _tmp12_ = {0};
	gdouble _tmp13_ = 0.0;
	GdkRGBA _tmp14_ = {0};
	gdouble _tmp15_ = 0.0;
	GdkRGBA _tmp16_ = {0};
	gdouble _tmp17_ = 0.0;
	GdkRGBA _tmp18_ = {0};
	gdouble _tmp19_ = 0.0;
	PangoLayout* layout = NULL;
	const gchar* _tmp20_ = NULL;
	PangoLayout* _tmp21_ = NULL;
	PangoFontDescription* _tmp22_ = NULL;
	PangoFontDescription* _tmp23_ = NULL;
	cairo_t* _tmp24_ = NULL;
	cairo_t* _tmp25_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (c != NULL);
	_tmp0_ = c;
	cairo_save (_tmp0_);
	gtk_entry_get_layout_offsets ((GtkEntry*) self, &_tmp1_, &_tmp2_);
	x = _tmp1_;
	y = _tmp2_;
	_tmp3_ = c;
	_tmp4_ = x;
	_tmp5_ = y;
	cairo_move_to (_tmp3_, (gdouble) _tmp4_, (gdouble) _tmp5_);
	memset (&fg, 0, sizeof (GdkRGBA));
	_tmp6_ = gtk_widget_get_style_context ((GtkWidget*) self);
	_tmp7_ = _g_object_ref0 (_tmp6_);
	context = _tmp7_;
	_tmp8_ = context;
	_tmp10_ = gtk_style_context_lookup_color (_tmp8_, "placeholder_text_color", &_tmp9_);
	fg = _tmp9_;
	if (!_tmp10_) {
		gdk_rgba_parse (&fg, "#888");
	}
	_tmp11_ = c;
	_tmp12_ = fg;
	_tmp13_ = _tmp12_.red;
	_tmp14_ = fg;
	_tmp15_ = _tmp14_.green;
	_tmp16_ = fg;
	_tmp17_ = _tmp16_.blue;
	_tmp18_ = fg;
	_tmp19_ = _tmp18_.alpha;
	cairo_set_source_rgba (_tmp11_, _tmp13_, _tmp15_, _tmp17_, _tmp19_);
	_tmp20_ = self->priv->_constant_placeholder_text;
	_tmp21_ = gtk_widget_create_pango_layout ((GtkWidget*) self, _tmp20_);
	layout = _tmp21_;
	_tmp22_ = pango_font_description_from_string ("Ubuntu 13");
	_tmp23_ = _tmp22_;
	pango_layout_set_font_description (layout, _tmp23_);
	__vala_PangoFontDescription_free0 (_tmp23_);
	_tmp24_ = c;
	pango_cairo_show_layout (_tmp24_, layout);
	_tmp25_ = c;
	cairo_restore (_tmp25_);
	_g_object_unref0 (layout);
	_g_object_unref0 (context);
}


static void dash_entry_real_activate (GtkEntry* base) {
	DashEntry * self;
	gboolean _tmp0_ = FALSE;
	self = (DashEntry*) base;
	GTK_ENTRY_CLASS (dash_entry_parent_class)->activate (G_TYPE_CHECK_INSTANCE_CAST (self, gtk_entry_get_type (), GtkEntry));
	_tmp0_ = self->priv->_can_respond;
	if (_tmp0_) {
		dash_entry_set_did_respond (self, TRUE);
		g_signal_emit_by_name (self, "respond");
	} else {
		GtkWidget* _tmp1_ = NULL;
		_tmp1_ = gtk_widget_get_toplevel ((GtkWidget*) self);
		gtk_widget_child_focus (_tmp1_, GTK_DIR_TAB_FORWARD);
	}
}


gboolean dash_entry_button_press_event_cb (DashEntry* self, GdkEventButton* event) {
	gboolean result = FALSE;
	gboolean _tmp0_ = FALSE;
	GdkEventButton* _tmp1_ = NULL;
	GdkWindow* _tmp2_ = NULL;
	GdkWindow* _tmp3_ = NULL;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (event != NULL, FALSE);
	_tmp1_ = event;
	_tmp2_ = _tmp1_->window;
	_tmp3_ = self->priv->arrow_win;
	if (_tmp2_ == _tmp3_) {
		guint16 _tmp4_ = 0U;
		_tmp4_ = gtk_entry_get_text_length ((GtkEntry*) self);
		_tmp0_ = ((gint) _tmp4_) > 0;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		g_signal_emit_by_name ((GtkEntry*) self, "activate");
		result = TRUE;
		return result;
	} else {
		result = FALSE;
		return result;
	}
}


static gint dash_entry_get_arrow_size (DashEntry* self) {
	gint result = 0;
	GdkPixbuf* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = dash_entry_arrow_pixbuf;
	if (_tmp0_ != NULL) {
		GdkPixbuf* _tmp1_ = NULL;
		gint _tmp2_ = 0;
		_tmp1_ = dash_entry_arrow_pixbuf;
		_tmp2_ = gdk_pixbuf_get_height (_tmp1_);
		result = _tmp2_;
		return result;
	} else {
		result = 20;
		return result;
	}
}


static void dash_entry_get_arrow_location (DashEntry* self, gint* x, gint* y) {
	gint _vala_x = 0;
	gint _vala_y = 0;
	gint arrow_size = 0;
	gint _tmp0_ = 0;
	GtkAllocation allocation = {0};
	GtkAllocation _tmp1_ = {0};
	gint margin = 0;
	GtkAllocation _tmp2_ = {0};
	gint _tmp3_ = 0;
	GtkAllocation _tmp4_ = {0};
	gint _tmp5_ = 0;
	GtkAllocation _tmp6_ = {0};
	gint _tmp7_ = 0;
	GtkAllocation _tmp8_ = {0};
	gint _tmp9_ = 0;
	g_return_if_fail (self != NULL);
	_tmp0_ = dash_entry_get_arrow_size (self);
	arrow_size = _tmp0_;
	gtk_widget_get_allocation ((GtkWidget*) self, &_tmp1_);
	allocation = _tmp1_;
	_tmp2_ = allocation;
	_tmp3_ = _tmp2_.height;
	margin = (_tmp3_ - arrow_size) / 2;
	_tmp4_ = allocation;
	_tmp5_ = _tmp4_.x;
	_tmp6_ = allocation;
	_tmp7_ = _tmp6_.width;
	_vala_x = ((_tmp5_ + _tmp7_) - margin) - arrow_size;
	_tmp8_ = allocation;
	_tmp9_ = _tmp8_.y;
	_vala_y = _tmp9_ + margin;
	if (x) {
		*x = _vala_x;
	}
	if (y) {
		*y = _vala_y;
	}
}


static void dash_entry_real_size_allocate (GtkWidget* base, GtkAllocation* allocation) {
	DashEntry * self;
	GtkAllocation _tmp0_ = {0};
	GdkWindow* _tmp1_ = NULL;
	gint arrow_x = 0;
	gint arrow_y = 0;
	gint _tmp2_ = 0;
	gint _tmp3_ = 0;
	gint arrow_size = 0;
	gint _tmp4_ = 0;
	GdkWindow* _tmp5_ = NULL;
	gint _tmp6_ = 0;
	gint _tmp7_ = 0;
	gint _tmp8_ = 0;
	gint _tmp9_ = 0;
	self = (DashEntry*) base;
	g_return_if_fail (allocation != NULL);
	_tmp0_ = *allocation;
	GTK_WIDGET_CLASS (dash_entry_parent_class)->size_allocate ((GtkWidget*) G_TYPE_CHECK_INSTANCE_CAST (self, gtk_entry_get_type (), GtkEntry), &_tmp0_);
	_tmp1_ = self->priv->arrow_win;
	if (_tmp1_ == NULL) {
		return;
	}
	dash_entry_get_arrow_location (self, &_tmp2_, &_tmp3_);
	arrow_x = _tmp2_;
	arrow_y = _tmp3_;
	_tmp4_ = dash_entry_get_arrow_size (self);
	arrow_size = _tmp4_;
	_tmp5_ = self->priv->arrow_win;
	_tmp6_ = arrow_x;
	_tmp7_ = arrow_y;
	_tmp8_ = arrow_size;
	_tmp9_ = arrow_size;
	gdk_window_move_resize (_tmp5_, _tmp6_, _tmp7_, _tmp8_, _tmp9_);
}


static void dash_entry_real_realize (GtkWidget* base) {
	DashEntry * self;
	GdkCursor* cursor = NULL;
	GdkDisplay* _tmp0_ = NULL;
	GdkCursor* _tmp1_ = NULL;
	GdkWindowAttr attrs = {0};
	gint _tmp2_ = 0;
	GdkWindow* _tmp3_ = NULL;
	GdkWindowAttr _tmp4_ = {0};
	GdkWindow* _tmp5_ = NULL;
	GdkWindow* _tmp6_ = NULL;
	GdkWindow* _tmp7_ = NULL;
	self = (DashEntry*) base;
	GTK_WIDGET_CLASS (dash_entry_parent_class)->realize ((GtkWidget*) G_TYPE_CHECK_INSTANCE_CAST (self, gtk_entry_get_type (), GtkEntry));
	_tmp0_ = gtk_widget_get_display ((GtkWidget*) self);
	_tmp1_ = gdk_cursor_new_for_display (_tmp0_, GDK_LEFT_PTR);
	cursor = _tmp1_;
	memset (&attrs, 0, sizeof (GdkWindowAttr));
	attrs.x = 0;
	attrs.y = 0;
	attrs.width = 1;
	attrs.height = 1;
	attrs.cursor = cursor;
	attrs.wclass = GDK_INPUT_ONLY;
	attrs.window_type = GDK_WINDOW_CHILD;
	_tmp2_ = gtk_widget_get_events ((GtkWidget*) self);
	attrs.event_mask = _tmp2_ | GDK_BUTTON_PRESS_MASK;
	_tmp3_ = gtk_widget_get_window ((GtkWidget*) self);
	_tmp4_ = attrs;
	_tmp5_ = gdk_window_new (_tmp3_, &_tmp4_, (GDK_WA_X | GDK_WA_Y) | GDK_WA_CURSOR);
	_g_object_unref0 (self->priv->arrow_win);
	self->priv->arrow_win = _tmp5_;
	_tmp6_ = self->priv->arrow_win;
	g_object_ref ((GObject*) _tmp6_);
	_tmp7_ = self->priv->arrow_win;
	gdk_window_set_user_data (_tmp7_, (GObject*) self);
	_g_object_unref0 (cursor);
}


static void dash_entry_real_unrealize (GtkWidget* base) {
	DashEntry * self;
	GdkWindow* _tmp0_ = NULL;
	self = (DashEntry*) base;
	_tmp0_ = self->priv->arrow_win;
	if (_tmp0_ != NULL) {
		GdkWindow* _tmp1_ = NULL;
		GdkWindow* _tmp2_ = NULL;
		_tmp1_ = self->priv->arrow_win;
		_tmp2_ = _g_object_ref0 (_tmp1_);
		gdk_window_destroy (_tmp2_);
		_g_object_unref0 (self->priv->arrow_win);
		self->priv->arrow_win = NULL;
	}
	GTK_WIDGET_CLASS (dash_entry_parent_class)->unrealize ((GtkWidget*) G_TYPE_CHECK_INSTANCE_CAST (self, gtk_entry_get_type (), GtkEntry));
}


static void dash_entry_real_map (GtkWidget* base) {
	DashEntry * self;
	GdkWindow* _tmp0_ = NULL;
	self = (DashEntry*) base;
	GTK_WIDGET_CLASS (dash_entry_parent_class)->map ((GtkWidget*) G_TYPE_CHECK_INSTANCE_CAST (self, gtk_entry_get_type (), GtkEntry));
	_tmp0_ = self->priv->arrow_win;
	if (_tmp0_ != NULL) {
		GdkWindow* _tmp1_ = NULL;
		_tmp1_ = self->priv->arrow_win;
		gdk_window_show (_tmp1_);
	}
}


static void dash_entry_real_unmap (GtkWidget* base) {
	DashEntry * self;
	GdkWindow* _tmp0_ = NULL;
	self = (DashEntry*) base;
	_tmp0_ = self->priv->arrow_win;
	if (_tmp0_ != NULL) {
		GdkWindow* _tmp1_ = NULL;
		_tmp1_ = self->priv->arrow_win;
		gdk_window_hide (_tmp1_);
	}
	GTK_WIDGET_CLASS (dash_entry_parent_class)->unmap ((GtkWidget*) G_TYPE_CHECK_INSTANCE_CAST (self, gtk_entry_get_type (), GtkEntry));
}


static gboolean dash_entry_real_key_press_event (GtkWidget* base, GdkEventKey* event) {
	DashEntry * self;
	gboolean result = FALSE;
	UnityGreeter* _tmp0_ = NULL;
	gboolean _tmp1_ = FALSE;
	GdkEventKey* _tmp4_ = NULL;
	gboolean _tmp5_ = FALSE;
	self = (DashEntry*) base;
	g_return_val_if_fail (event != NULL, FALSE);
	_tmp0_ = unity_greeter_singleton;
	_tmp1_ = _tmp0_->orca_needs_kick;
	if (_tmp1_) {
		AtkObject* _tmp2_ = NULL;
		UnityGreeter* _tmp3_ = NULL;
		_tmp2_ = gtk_widget_get_accessible ((GtkWidget*) self);
		g_signal_emit_by_name (_tmp2_, "focus-event", TRUE, NULL);
		_tmp3_ = unity_greeter_singleton;
		_tmp3_->orca_needs_kick = FALSE;
	}
	_tmp4_ = event;
	_tmp5_ = GTK_WIDGET_CLASS (dash_entry_parent_class)->key_press_event ((GtkWidget*) G_TYPE_CHECK_INSTANCE_CAST (self, gtk_entry_get_type (), GtkEntry), _tmp4_);
	result = _tmp5_;
	return result;
}


DashEntry* dash_entry_construct (GType object_type) {
	DashEntry * self = NULL;
	self = (DashEntry*) g_object_new (object_type, NULL);
	return self;
}


DashEntry* dash_entry_new (void) {
	return dash_entry_construct (TYPE_DASH_ENTRY);
}


const gchar* dash_entry_get_constant_placeholder_text (DashEntry* self) {
	const gchar* result;
	const gchar* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_constant_placeholder_text;
	result = _tmp0_;
	return result;
}


void dash_entry_set_constant_placeholder_text (DashEntry* self, const gchar* value) {
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->priv->_constant_placeholder_text);
	self->priv->_constant_placeholder_text = _tmp1_;
	g_object_notify ((GObject *) self, "constant-placeholder-text");
}


gboolean dash_entry_get_can_respond (DashEntry* self) {
	gboolean result;
	gboolean _tmp0_ = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->_can_respond;
	result = _tmp0_;
	return result;
}


void dash_entry_set_can_respond (DashEntry* self, gboolean value) {
	gboolean _tmp0_ = FALSE;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_can_respond = _tmp0_;
	g_object_notify ((GObject *) self, "can-respond");
}


gboolean dash_entry_get_did_respond (DashEntry* self) {
	gboolean result;
	gboolean _tmp0_ = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->_did_respond;
	result = _tmp0_;
	return result;
}


void dash_entry_set_did_respond (DashEntry* self, gboolean value) {
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_did_respond = _tmp0_;
	_tmp1_ = value;
	if (_tmp1_) {
		gtk_widget_set_state_flags ((GtkWidget*) self, GTK_STATE_FLAG_ACTIVE, FALSE);
	} else {
		gtk_widget_unset_state_flags ((GtkWidget*) self, GTK_STATE_FLAG_ACTIVE);
	}
	gtk_widget_queue_draw ((GtkWidget*) self);
	g_object_notify ((GObject *) self, "did-respond");
}


static FadeTracker* dash_entry_real_get_fade_tracker (Fadable* base) {
	FadeTracker* result;
	DashEntry* self;
	FadeTracker* _tmp0_ = NULL;
	self = (DashEntry*) base;
	_tmp0_ = self->priv->_fade_tracker;
	result = _tmp0_;
	return result;
}


static void dash_entry_real_set_fade_tracker (Fadable* base, FadeTracker* value) {
	DashEntry* self;
	FadeTracker* _tmp0_ = NULL;
	FadeTracker* _tmp1_ = NULL;
	self = (DashEntry*) base;
	_tmp0_ = value;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->_fade_tracker);
	self->priv->_fade_tracker = _tmp1_;
	g_object_notify ((GObject *) self, "fade-tracker");
}


static void _gtk_widget_queue_draw_g_object_notify (GObject* _sender, GParamSpec* pspec, gpointer self) {
	gtk_widget_queue_draw ((GtkWidget*) self);
}


static gboolean _dash_entry_button_press_event_cb_gtk_widget_button_press_event (GtkWidget* _sender, GdkEventButton* event, gpointer self) {
	gboolean result;
	result = dash_entry_button_press_event_cb ((DashEntry*) self, event);
	return result;
}


static GObject * dash_entry_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	DashEntry * self;
	FadeTracker* _tmp0_ = NULL;
	FadeTracker* _tmp1_ = NULL;
	GdkPixbuf* _tmp2_ = NULL;
	const gchar* _tmp10_ = NULL;
	PangoFontDescription* _tmp11_ = NULL;
	PangoFontDescription* _tmp12_ = NULL;
	GtkStyleContext* style_ctx = NULL;
	GtkStyleContext* _tmp13_ = NULL;
	GtkStyleContext* _tmp14_ = NULL;
	GError * _inner_error_ = NULL;
	parent_class = G_OBJECT_CLASS (dash_entry_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_DASH_ENTRY, DashEntry);
	_tmp0_ = fade_tracker_new ((GtkWidget*) self);
	_tmp1_ = _tmp0_;
	fadable_set_fade_tracker ((Fadable*) self, _tmp1_);
	_g_object_unref0 (_tmp1_);
	g_signal_connect_object ((GObject*) self, "notify::can-respond", (GCallback) _gtk_widget_queue_draw_g_object_notify, (GtkWidget*) self, 0);
	g_signal_connect_object ((GtkWidget*) self, "button-press-event", (GCallback) _dash_entry_button_press_event_cb_gtk_widget_button_press_event, self, 0);
	_tmp2_ = dash_entry_arrow_pixbuf;
	if (_tmp2_ == NULL) {
		gchar* filename = NULL;
		gchar* _tmp3_ = NULL;
		_tmp3_ = g_build_filename (PKGDATADIR, "arrow_right.png", NULL);
		filename = _tmp3_;
		{
			GdkPixbuf* _tmp4_ = NULL;
			const gchar* _tmp5_ = NULL;
			GdkPixbuf* _tmp6_ = NULL;
			GdkPixbuf* _tmp7_ = NULL;
			_tmp5_ = filename;
			_tmp6_ = gdk_pixbuf_new_from_file (_tmp5_, &_inner_error_);
			_tmp4_ = _tmp6_;
			if (G_UNLIKELY (_inner_error_ != NULL)) {
				goto __catch5_g_error;
			}
			_tmp7_ = _tmp4_;
			_tmp4_ = NULL;
			_g_object_unref0 (dash_entry_arrow_pixbuf);
			dash_entry_arrow_pixbuf = _tmp7_;
			_g_object_unref0 (_tmp4_);
		}
		goto __finally5;
		__catch5_g_error:
		{
			GError* e = NULL;
			GError* _tmp8_ = NULL;
			const gchar* _tmp9_ = NULL;
			e = _inner_error_;
			_inner_error_ = NULL;
			_tmp8_ = e;
			_tmp9_ = _tmp8_->message;
			g_debug ("dash-entry.vala:70: Internal error loading arrow icon: %s", _tmp9_);
			_g_error_free0 (e);
		}
		__finally5:
		if (G_UNLIKELY (_inner_error_ != NULL)) {
			_g_free0 (filename);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
		}
		_g_free0 (filename);
	}
	_tmp10_ = dash_entry_font;
	_tmp11_ = pango_font_description_from_string (_tmp10_);
	_tmp12_ = _tmp11_;
	gtk_widget_override_font ((GtkWidget*) self, _tmp12_);
	__vala_PangoFontDescription_free0 (_tmp12_);
	_tmp13_ = gtk_widget_get_style_context ((GtkWidget*) self);
	_tmp14_ = _g_object_ref0 (_tmp13_);
	style_ctx = _tmp14_;
	{
		GtkCssProvider* padding_provider = NULL;
		GtkCssProvider* _tmp15_ = NULL;
		gchar* css = NULL;
		gint _tmp16_ = 0;
		gchar* _tmp17_ = NULL;
		GtkCssProvider* _tmp18_ = NULL;
		const gchar* _tmp19_ = NULL;
		GtkStyleContext* _tmp20_ = NULL;
		GtkCssProvider* _tmp21_ = NULL;
		_tmp15_ = gtk_css_provider_new ();
		padding_provider = _tmp15_;
		_tmp16_ = dash_entry_get_arrow_size (self);
		_tmp17_ = g_strdup_printf ("* {padding-right: %dpx;}", _tmp16_);
		css = _tmp17_;
		_tmp18_ = padding_provider;
		_tmp19_ = css;
		gtk_css_provider_load_from_data (_tmp18_, _tmp19_, (gssize) -1, &_inner_error_);
		if (G_UNLIKELY (_inner_error_ != NULL)) {
			_g_free0 (css);
			_g_object_unref0 (padding_provider);
			goto __catch6_g_error;
		}
		_tmp20_ = style_ctx;
		_tmp21_ = padding_provider;
		gtk_style_context_add_provider (_tmp20_, (GtkStyleProvider*) _tmp21_, (guint) GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
		_g_free0 (css);
		_g_object_unref0 (padding_provider);
	}
	goto __finally6;
	__catch6_g_error:
	{
		GError* e = NULL;
		GError* _tmp22_ = NULL;
		const gchar* _tmp23_ = NULL;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp22_ = e;
		_tmp23_ = _tmp22_->message;
		g_debug ("dash-entry.vala:88: Internal error loading padding style: %s", _tmp23_);
		_g_error_free0 (e);
	}
	__finally6:
	if (G_UNLIKELY (_inner_error_ != NULL)) {
		_g_object_unref0 (style_ctx);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
	}
	_g_object_unref0 (style_ctx);
	return obj;
}


static void dash_entry_class_init (DashEntryClass * klass) {
	gchar* _tmp0_ = NULL;
	dash_entry_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (DashEntryPrivate));
	((GtkWidgetClass *) klass)->draw = dash_entry_real_draw;
	((GtkEntryClass *) klass)->activate = dash_entry_real_activate;
	((GtkWidgetClass *) klass)->size_allocate = dash_entry_real_size_allocate;
	((GtkWidgetClass *) klass)->realize = dash_entry_real_realize;
	((GtkWidgetClass *) klass)->unrealize = dash_entry_real_unrealize;
	((GtkWidgetClass *) klass)->map = dash_entry_real_map;
	((GtkWidgetClass *) klass)->unmap = dash_entry_real_unmap;
	((GtkWidgetClass *) klass)->key_press_event = dash_entry_real_key_press_event;
	G_OBJECT_CLASS (klass)->get_property = _vala_dash_entry_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_dash_entry_set_property;
	G_OBJECT_CLASS (klass)->constructor = dash_entry_constructor;
	G_OBJECT_CLASS (klass)->finalize = dash_entry_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), DASH_ENTRY_CONSTANT_PLACEHOLDER_TEXT, g_param_spec_string ("constant-placeholder-text", "constant-placeholder-text", "constant-placeholder-text", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), DASH_ENTRY_CAN_RESPOND, g_param_spec_boolean ("can-respond", "can-respond", "can-respond", TRUE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), DASH_ENTRY_DID_RESPOND, g_param_spec_boolean ("did-respond", "did-respond", "did-respond", FALSE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), DASH_ENTRY_FADE_TRACKER, g_param_spec_object ("fade-tracker", "fade-tracker", "fade-tracker", TYPE_FADE_TRACKER, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_signal_new ("respond", TYPE_DASH_ENTRY, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
	_tmp0_ = g_strdup ("Ubuntu 14");
	dash_entry_font = _tmp0_;
}


static void dash_entry_fadable_interface_init (FadableIface * iface) {
	dash_entry_fadable_parent_iface = g_type_interface_peek_parent (iface);
	iface->get_fade_tracker = dash_entry_real_get_fade_tracker;
	iface->set_fade_tracker = dash_entry_real_set_fade_tracker;
}


static void dash_entry_instance_init (DashEntry * self) {
	self->priv = DASH_ENTRY_GET_PRIVATE (self);
	self->priv->_can_respond = TRUE;
}


static void dash_entry_finalize (GObject* obj) {
	DashEntry * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_DASH_ENTRY, DashEntry);
	_g_free0 (self->priv->_constant_placeholder_text);
	_g_object_unref0 (self->priv->_fade_tracker);
	_g_object_unref0 (self->priv->arrow_win);
	G_OBJECT_CLASS (dash_entry_parent_class)->finalize (obj);
}


GType dash_entry_get_type (void) {
	static volatile gsize dash_entry_type_id__volatile = 0;
	if (g_once_init_enter (&dash_entry_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (DashEntryClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) dash_entry_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (DashEntry), 0, (GInstanceInitFunc) dash_entry_instance_init, NULL };
		static const GInterfaceInfo fadable_info = { (GInterfaceInitFunc) dash_entry_fadable_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		GType dash_entry_type_id;
		dash_entry_type_id = g_type_register_static (gtk_entry_get_type (), "DashEntry", &g_define_type_info, 0);
		g_type_add_interface_static (dash_entry_type_id, TYPE_FADABLE, &fadable_info);
		g_once_init_leave (&dash_entry_type_id__volatile, dash_entry_type_id);
	}
	return dash_entry_type_id__volatile;
}


static void _vala_dash_entry_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	DashEntry * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, TYPE_DASH_ENTRY, DashEntry);
	switch (property_id) {
		case DASH_ENTRY_CONSTANT_PLACEHOLDER_TEXT:
		g_value_set_string (value, dash_entry_get_constant_placeholder_text (self));
		break;
		case DASH_ENTRY_CAN_RESPOND:
		g_value_set_boolean (value, dash_entry_get_can_respond (self));
		break;
		case DASH_ENTRY_DID_RESPOND:
		g_value_set_boolean (value, dash_entry_get_did_respond (self));
		break;
		case DASH_ENTRY_FADE_TRACKER:
		g_value_set_object (value, fadable_get_fade_tracker ((Fadable*) self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_dash_entry_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	DashEntry * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, TYPE_DASH_ENTRY, DashEntry);
	switch (property_id) {
		case DASH_ENTRY_CONSTANT_PLACEHOLDER_TEXT:
		dash_entry_set_constant_placeholder_text (self, g_value_get_string (value));
		break;
		case DASH_ENTRY_CAN_RESPOND:
		dash_entry_set_can_respond (self, g_value_get_boolean (value));
		break;
		case DASH_ENTRY_DID_RESPOND:
		dash_entry_set_did_respond (self, g_value_get_boolean (value));
		break;
		case DASH_ENTRY_FADE_TRACKER:
		fadable_set_fade_tracker ((Fadable*) self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



