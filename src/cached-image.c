/* cached-image.c generated by valac 0.30.1, the Vala compiler
 * generated from cached-image.vala, do not modify */

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

#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <cairo.h>
#include <gdk/gdk.h>
#include <float.h>
#include <math.h>


#define TYPE_CACHED_IMAGE (cached_image_get_type ())
#define CACHED_IMAGE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_CACHED_IMAGE, CachedImage))
#define CACHED_IMAGE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_CACHED_IMAGE, CachedImageClass))
#define IS_CACHED_IMAGE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_CACHED_IMAGE))
#define IS_CACHED_IMAGE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_CACHED_IMAGE))
#define CACHED_IMAGE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_CACHED_IMAGE, CachedImageClass))

typedef struct _CachedImage CachedImage;
typedef struct _CachedImageClass CachedImageClass;
typedef struct _CachedImagePrivate CachedImagePrivate;
#define _g_hash_table_unref0(var) ((var == NULL) ? NULL : (var = (g_hash_table_unref (var), NULL)))
#define _cairo_surface_destroy0(var) ((var == NULL) ? NULL : (var = (cairo_surface_destroy (var), NULL)))
#define _cairo_destroy0(var) ((var == NULL) ? NULL : (var = (cairo_destroy (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _CachedImage {
	GtkImage parent_instance;
	CachedImagePrivate * priv;
};

struct _CachedImageClass {
	GtkImageClass parent_class;
};


static gpointer cached_image_parent_class = NULL;
static GHashTable* cached_image_surface_table;
static GHashTable* cached_image_surface_table = NULL;

GType cached_image_get_type (void) G_GNUC_CONST;
enum  {
	CACHED_IMAGE_DUMMY_PROPERTY
};
cairo_surface_t* cached_image_get_cached_surface (cairo_t* c, GdkPixbuf* pixbuf);
static void _g_object_unref0_ (gpointer var);
static void _cairo_surface_destroy0_ (gpointer var);
CachedImage* cached_image_new (GdkPixbuf* pixbuf);
CachedImage* cached_image_construct (GType object_type, GdkPixbuf* pixbuf);
static gboolean cached_image_real_draw (GtkWidget* base, cairo_t* c);
static void cached_image_finalize (GObject* obj);


static void _g_object_unref0_ (gpointer var) {
	(var == NULL) ? NULL : (var = (g_object_unref (var), NULL));
}


static void _cairo_surface_destroy0_ (gpointer var) {
	(var == NULL) ? NULL : (var = (cairo_surface_destroy (var), NULL));
}


static gpointer _cairo_surface_reference0 (gpointer self) {
	return self ? cairo_surface_reference (self) : NULL;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


cairo_surface_t* cached_image_get_cached_surface (cairo_t* c, GdkPixbuf* pixbuf) {
	cairo_surface_t* result = NULL;
	GHashTable* _tmp0_ = NULL;
	cairo_surface_t* surface = NULL;
	GHashTable* _tmp4_ = NULL;
	GdkPixbuf* _tmp5_ = NULL;
	gconstpointer _tmp6_ = NULL;
	cairo_surface_t* _tmp7_ = NULL;
	cairo_surface_t* _tmp8_ = NULL;
	g_return_val_if_fail (c != NULL, NULL);
	g_return_val_if_fail (pixbuf != NULL, NULL);
	_tmp0_ = cached_image_surface_table;
	if (_tmp0_ == NULL) {
		GHashFunc _tmp1_ = NULL;
		GEqualFunc _tmp2_ = NULL;
		GHashTable* _tmp3_ = NULL;
		_tmp1_ = g_direct_hash;
		_tmp2_ = g_direct_equal;
		_tmp3_ = g_hash_table_new_full (_tmp1_, _tmp2_, _g_object_unref0_, _cairo_surface_destroy0_);
		_g_hash_table_unref0 (cached_image_surface_table);
		cached_image_surface_table = _tmp3_;
	}
	_tmp4_ = cached_image_surface_table;
	_tmp5_ = pixbuf;
	_tmp6_ = g_hash_table_lookup (_tmp4_, _tmp5_);
	_tmp7_ = _cairo_surface_reference0 ((cairo_surface_t*) _tmp6_);
	surface = _tmp7_;
	_tmp8_ = surface;
	if (_tmp8_ == NULL) {
		cairo_t* _tmp9_ = NULL;
		cairo_surface_t* _tmp10_ = NULL;
		GdkPixbuf* _tmp11_ = NULL;
		gint _tmp12_ = 0;
		gint _tmp13_ = 0;
		GdkPixbuf* _tmp14_ = NULL;
		gint _tmp15_ = 0;
		gint _tmp16_ = 0;
		cairo_surface_t* _tmp17_ = NULL;
		cairo_t* new_c = NULL;
		cairo_surface_t* _tmp18_ = NULL;
		cairo_t* _tmp19_ = NULL;
		cairo_t* _tmp20_ = NULL;
		GdkPixbuf* _tmp21_ = NULL;
		cairo_t* _tmp22_ = NULL;
		GHashTable* _tmp23_ = NULL;
		GdkPixbuf* _tmp24_ = NULL;
		GdkPixbuf* _tmp25_ = NULL;
		cairo_surface_t* _tmp26_ = NULL;
		cairo_surface_t* _tmp27_ = NULL;
		_tmp9_ = c;
		_tmp10_ = cairo_get_target (_tmp9_);
		_tmp11_ = pixbuf;
		_tmp12_ = gdk_pixbuf_get_width (_tmp11_);
		_tmp13_ = _tmp12_;
		_tmp14_ = pixbuf;
		_tmp15_ = gdk_pixbuf_get_height (_tmp14_);
		_tmp16_ = _tmp15_;
		_tmp17_ = cairo_surface_create_similar (_tmp10_, CAIRO_CONTENT_COLOR_ALPHA, _tmp13_, _tmp16_);
		_cairo_surface_destroy0 (surface);
		surface = _tmp17_;
		_tmp18_ = surface;
		_tmp19_ = cairo_create (_tmp18_);
		new_c = _tmp19_;
		_tmp20_ = new_c;
		_tmp21_ = pixbuf;
		gdk_cairo_set_source_pixbuf (_tmp20_, _tmp21_, (gdouble) 0, (gdouble) 0);
		_tmp22_ = new_c;
		cairo_paint (_tmp22_);
		_tmp23_ = cached_image_surface_table;
		_tmp24_ = pixbuf;
		_tmp25_ = _g_object_ref0 (_tmp24_);
		_tmp26_ = surface;
		_tmp27_ = _cairo_surface_reference0 (_tmp26_);
		g_hash_table_insert (_tmp23_, _tmp25_, _tmp27_);
		_cairo_destroy0 (new_c);
	}
	result = surface;
	return result;
}


CachedImage* cached_image_construct (GType object_type, GdkPixbuf* pixbuf) {
	CachedImage * self = NULL;
	GdkPixbuf* _tmp0_ = NULL;
	_tmp0_ = pixbuf;
	self = (CachedImage*) g_object_new (object_type, "pixbuf", _tmp0_, NULL);
	return self;
}


CachedImage* cached_image_new (GdkPixbuf* pixbuf) {
	return cached_image_construct (TYPE_CACHED_IMAGE, pixbuf);
}


static gboolean cached_image_real_draw (GtkWidget* base, cairo_t* c) {
	CachedImage * self;
	gboolean result = FALSE;
	GdkPixbuf* _tmp0_ = NULL;
	GdkPixbuf* _tmp1_ = NULL;
	GdkPixbuf* _tmp2_ = NULL;
	gboolean _tmp3_ = FALSE;
	self = (CachedImage*) base;
	g_return_val_if_fail (c != NULL, FALSE);
	g_object_get ((GtkImage*) self, "pixbuf", &_tmp0_, NULL);
	_tmp1_ = _tmp0_;
	_tmp2_ = _tmp1_;
	_tmp3_ = _tmp2_ != NULL;
	_g_object_unref0 (_tmp2_);
	if (_tmp3_) {
		cairo_surface_t* cached_surface = NULL;
		cairo_t* _tmp4_ = NULL;
		GdkPixbuf* _tmp5_ = NULL;
		GdkPixbuf* _tmp6_ = NULL;
		GdkPixbuf* _tmp7_ = NULL;
		cairo_surface_t* _tmp8_ = NULL;
		cairo_surface_t* _tmp9_ = NULL;
		cairo_surface_t* _tmp10_ = NULL;
		_tmp4_ = c;
		g_object_get ((GtkImage*) self, "pixbuf", &_tmp5_, NULL);
		_tmp6_ = _tmp5_;
		_tmp7_ = _tmp6_;
		_tmp8_ = cached_image_get_cached_surface (_tmp4_, _tmp7_);
		_tmp9_ = _tmp8_;
		_g_object_unref0 (_tmp7_);
		cached_surface = _tmp9_;
		_tmp10_ = cached_surface;
		if (_tmp10_ != NULL) {
			cairo_t* _tmp11_ = NULL;
			cairo_surface_t* _tmp12_ = NULL;
			cairo_t* _tmp13_ = NULL;
			_tmp11_ = c;
			_tmp12_ = cached_surface;
			cairo_set_source_surface (_tmp11_, _tmp12_, (gdouble) 0, (gdouble) 0);
			_tmp13_ = c;
			cairo_paint (_tmp13_);
		}
		_cairo_surface_destroy0 (cached_surface);
	}
	result = FALSE;
	return result;
}


static void cached_image_class_init (CachedImageClass * klass) {
	cached_image_parent_class = g_type_class_peek_parent (klass);
	((GtkWidgetClass *) klass)->draw = cached_image_real_draw;
	G_OBJECT_CLASS (klass)->finalize = cached_image_finalize;
}


static void cached_image_instance_init (CachedImage * self) {
}


static void cached_image_finalize (GObject* obj) {
	CachedImage * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_CACHED_IMAGE, CachedImage);
	G_OBJECT_CLASS (cached_image_parent_class)->finalize (obj);
}


GType cached_image_get_type (void) {
	static volatile gsize cached_image_type_id__volatile = 0;
	if (g_once_init_enter (&cached_image_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (CachedImageClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) cached_image_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (CachedImage), 0, (GInstanceInitFunc) cached_image_instance_init, NULL };
		GType cached_image_type_id;
		cached_image_type_id = g_type_register_static (gtk_image_get_type (), "CachedImage", &g_define_type_info, 0);
		g_once_init_leave (&cached_image_type_id__volatile, cached_image_type_id);
	}
	return cached_image_type_id__volatile;
}


