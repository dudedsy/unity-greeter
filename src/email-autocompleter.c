/* email-autocompleter.c generated by valac 0.30.1, the Vala compiler
 * generated from email-autocompleter.vala, do not modify */

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
 */

#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <gobject/gvaluecollector.h>


#define TYPE_EMAIL_AUTOCOMPLETER (email_autocompleter_get_type ())
#define EMAIL_AUTOCOMPLETER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_EMAIL_AUTOCOMPLETER, EmailAutocompleter))
#define EMAIL_AUTOCOMPLETER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_EMAIL_AUTOCOMPLETER, EmailAutocompleterClass))
#define IS_EMAIL_AUTOCOMPLETER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_EMAIL_AUTOCOMPLETER))
#define IS_EMAIL_AUTOCOMPLETER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_EMAIL_AUTOCOMPLETER))
#define EMAIL_AUTOCOMPLETER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_EMAIL_AUTOCOMPLETER, EmailAutocompleterClass))

typedef struct _EmailAutocompleter EmailAutocompleter;
typedef struct _EmailAutocompleterClass EmailAutocompleterClass;
typedef struct _EmailAutocompleterPrivate EmailAutocompleterPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _Block1Data Block1Data;
#define _email_autocompleter_unref0(var) ((var == NULL) ? NULL : (var = (email_autocompleter_unref (var), NULL)))
typedef struct _ParamSpecEmailAutocompleter ParamSpecEmailAutocompleter;

struct _EmailAutocompleter {
	GTypeInstance parent_instance;
	volatile int ref_count;
	EmailAutocompleterPrivate * priv;
};

struct _EmailAutocompleterClass {
	GTypeClass parent_class;
	void (*finalize) (EmailAutocompleter *self);
};

struct _EmailAutocompleterPrivate {
	GtkEntry* entry;
	gchar** domains;
	gint domains_length1;
	gint _domains_size_;
	gchar* prevText;
};

struct _Block1Data {
	int _ref_count_;
	EmailAutocompleter* self;
	gchar* text_to_add;
};

struct _ParamSpecEmailAutocompleter {
	GParamSpec parent_instance;
};


static gpointer email_autocompleter_parent_class = NULL;

gpointer email_autocompleter_ref (gpointer instance);
void email_autocompleter_unref (gpointer instance);
GParamSpec* param_spec_email_autocompleter (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_email_autocompleter (GValue* value, gpointer v_object);
void value_take_email_autocompleter (GValue* value, gpointer v_object);
gpointer value_get_email_autocompleter (const GValue* value);
GType email_autocompleter_get_type (void) G_GNUC_CONST;
#define EMAIL_AUTOCOMPLETER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_EMAIL_AUTOCOMPLETER, EmailAutocompleterPrivate))
enum  {
	EMAIL_AUTOCOMPLETER_DUMMY_PROPERTY
};
static void email_autocompleter_entry_changed (EmailAutocompleter* self);
static Block1Data* block1_data_ref (Block1Data* _data1_);
static void block1_data_unref (void * _userdata_);
static gboolean ______lambda45_ (Block1Data* _data1_);
static gboolean _______lambda45__gsource_func (gpointer self);
EmailAutocompleter* email_autocompleter_new (GtkEntry* e, gchar** email_domains, int email_domains_length1);
EmailAutocompleter* email_autocompleter_construct (GType object_type, GtkEntry* e, gchar** email_domains, int email_domains_length1);
static gchar** _vala_array_dup3 (gchar** self, int length);
static void _email_autocompleter_entry_changed_gtk_editable_changed (GtkEditable* _sender, gpointer self);
static void email_autocompleter_finalize (EmailAutocompleter* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);


static gint string_index_of (const gchar* self, const gchar* needle, gint start_index) {
	gint result = 0;
	gchar* _result_ = NULL;
	gint _tmp0_ = 0;
	const gchar* _tmp1_ = NULL;
	gchar* _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	g_return_val_if_fail (self != NULL, 0);
	g_return_val_if_fail (needle != NULL, 0);
	_tmp0_ = start_index;
	_tmp1_ = needle;
	_tmp2_ = strstr (((gchar*) self) + _tmp0_, (gchar*) _tmp1_);
	_result_ = _tmp2_;
	_tmp3_ = _result_;
	if (_tmp3_ != NULL) {
		gchar* _tmp4_ = NULL;
		_tmp4_ = _result_;
		result = (gint) (_tmp4_ - ((gchar*) self));
		return result;
	} else {
		result = -1;
		return result;
	}
}


static gchar* string_slice (const gchar* self, glong start, glong end) {
	gchar* result = NULL;
	glong string_length = 0L;
	gint _tmp0_ = 0;
	gint _tmp1_ = 0;
	glong _tmp2_ = 0L;
	glong _tmp5_ = 0L;
	gboolean _tmp8_ = FALSE;
	glong _tmp9_ = 0L;
	gboolean _tmp12_ = FALSE;
	glong _tmp13_ = 0L;
	glong _tmp16_ = 0L;
	glong _tmp17_ = 0L;
	glong _tmp18_ = 0L;
	glong _tmp19_ = 0L;
	glong _tmp20_ = 0L;
	gchar* _tmp21_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = strlen (self);
	_tmp1_ = _tmp0_;
	string_length = (glong) _tmp1_;
	_tmp2_ = start;
	if (_tmp2_ < ((glong) 0)) {
		glong _tmp3_ = 0L;
		glong _tmp4_ = 0L;
		_tmp3_ = string_length;
		_tmp4_ = start;
		start = _tmp3_ + _tmp4_;
	}
	_tmp5_ = end;
	if (_tmp5_ < ((glong) 0)) {
		glong _tmp6_ = 0L;
		glong _tmp7_ = 0L;
		_tmp6_ = string_length;
		_tmp7_ = end;
		end = _tmp6_ + _tmp7_;
	}
	_tmp9_ = start;
	if (_tmp9_ >= ((glong) 0)) {
		glong _tmp10_ = 0L;
		glong _tmp11_ = 0L;
		_tmp10_ = start;
		_tmp11_ = string_length;
		_tmp8_ = _tmp10_ <= _tmp11_;
	} else {
		_tmp8_ = FALSE;
	}
	g_return_val_if_fail (_tmp8_, NULL);
	_tmp13_ = end;
	if (_tmp13_ >= ((glong) 0)) {
		glong _tmp14_ = 0L;
		glong _tmp15_ = 0L;
		_tmp14_ = end;
		_tmp15_ = string_length;
		_tmp12_ = _tmp14_ <= _tmp15_;
	} else {
		_tmp12_ = FALSE;
	}
	g_return_val_if_fail (_tmp12_, NULL);
	_tmp16_ = start;
	_tmp17_ = end;
	g_return_val_if_fail (_tmp16_ <= _tmp17_, NULL);
	_tmp18_ = start;
	_tmp19_ = end;
	_tmp20_ = start;
	_tmp21_ = g_strndup (((gchar*) self) + _tmp18_, (gsize) (_tmp19_ - _tmp20_));
	result = _tmp21_;
	return result;
}


static Block1Data* block1_data_ref (Block1Data* _data1_) {
	g_atomic_int_inc (&_data1_->_ref_count_);
	return _data1_;
}


static void block1_data_unref (void * _userdata_) {
	Block1Data* _data1_;
	_data1_ = (Block1Data*) _userdata_;
	if (g_atomic_int_dec_and_test (&_data1_->_ref_count_)) {
		EmailAutocompleter* self;
		self = _data1_->self;
		_g_free0 (_data1_->text_to_add);
		_email_autocompleter_unref0 (self);
		g_slice_free (Block1Data, _data1_);
	}
}


static gboolean ______lambda45_ (Block1Data* _data1_) {
	EmailAutocompleter* self;
	gboolean result = FALSE;
	GtkEntry* _tmp0_ = NULL;
	GtkEntry* _tmp1_ = NULL;
	const gchar* _tmp2_ = NULL;
	const gchar* _tmp3_ = NULL;
	gint _tmp4_ = 0;
	gint _tmp5_ = 0;
	const gchar* _tmp6_ = NULL;
	gint _tmp7_ = 0;
	gint _tmp8_ = 0;
	GtkEntry* _tmp9_ = NULL;
	const gchar* _tmp10_ = NULL;
	const gchar* _tmp11_ = NULL;
	gint _tmp12_ = 0;
	gint _tmp13_ = 0;
	self = _data1_->self;
	_tmp0_ = self->priv->entry;
	_tmp1_ = self->priv->entry;
	_tmp2_ = gtk_entry_get_text (_tmp1_);
	_tmp3_ = _tmp2_;
	_tmp4_ = strlen (_tmp3_);
	_tmp5_ = _tmp4_;
	_tmp6_ = _data1_->text_to_add;
	_tmp7_ = strlen (_tmp6_);
	_tmp8_ = _tmp7_;
	_tmp9_ = self->priv->entry;
	_tmp10_ = gtk_entry_get_text (_tmp9_);
	_tmp11_ = _tmp10_;
	_tmp12_ = strlen (_tmp11_);
	_tmp13_ = _tmp12_;
	gtk_editable_select_region ((GtkEditable*) _tmp0_, _tmp5_ - _tmp8_, _tmp13_);
	result = FALSE;
	return result;
}


static gboolean _______lambda45__gsource_func (gpointer self) {
	gboolean result;
	result = ______lambda45_ (self);
	return result;
}


static void email_autocompleter_entry_changed (EmailAutocompleter* self) {
	GtkEntry* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	const gchar* _tmp2_ = NULL;
	gint _tmp3_ = 0;
	gint _tmp4_ = 0;
	const gchar* _tmp5_ = NULL;
	gint _tmp6_ = 0;
	gint _tmp7_ = 0;
	GtkEntry* _tmp12_ = NULL;
	const gchar* _tmp13_ = NULL;
	const gchar* _tmp14_ = NULL;
	gchar* _tmp15_ = NULL;
	gint first_at = 0;
	GtkEntry* _tmp16_ = NULL;
	const gchar* _tmp17_ = NULL;
	const gchar* _tmp18_ = NULL;
	gint _tmp19_ = 0;
	gint _tmp20_ = 0;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->entry;
	_tmp1_ = gtk_entry_get_text (_tmp0_);
	_tmp2_ = _tmp1_;
	_tmp3_ = strlen (_tmp2_);
	_tmp4_ = _tmp3_;
	_tmp5_ = self->priv->prevText;
	_tmp6_ = strlen (_tmp5_);
	_tmp7_ = _tmp6_;
	if (_tmp4_ < _tmp7_) {
		GtkEntry* _tmp8_ = NULL;
		const gchar* _tmp9_ = NULL;
		const gchar* _tmp10_ = NULL;
		gchar* _tmp11_ = NULL;
		_tmp8_ = self->priv->entry;
		_tmp9_ = gtk_entry_get_text (_tmp8_);
		_tmp10_ = _tmp9_;
		_tmp11_ = g_strdup (_tmp10_);
		_g_free0 (self->priv->prevText);
		self->priv->prevText = _tmp11_;
		return;
	}
	_tmp12_ = self->priv->entry;
	_tmp13_ = gtk_entry_get_text (_tmp12_);
	_tmp14_ = _tmp13_;
	_tmp15_ = g_strdup (_tmp14_);
	_g_free0 (self->priv->prevText);
	self->priv->prevText = _tmp15_;
	_tmp16_ = self->priv->entry;
	_tmp17_ = gtk_entry_get_text (_tmp16_);
	_tmp18_ = _tmp17_;
	_tmp19_ = string_index_of (_tmp18_, "@", 0);
	first_at = _tmp19_;
	_tmp20_ = first_at;
	if (_tmp20_ != -1) {
		gint second_at = 0;
		GtkEntry* _tmp21_ = NULL;
		const gchar* _tmp22_ = NULL;
		const gchar* _tmp23_ = NULL;
		gint _tmp24_ = 0;
		gint _tmp25_ = 0;
		gint _tmp26_ = 0;
		_tmp21_ = self->priv->entry;
		_tmp22_ = gtk_entry_get_text (_tmp21_);
		_tmp23_ = _tmp22_;
		_tmp24_ = first_at;
		_tmp25_ = string_index_of (_tmp23_, "@", _tmp24_ + 1);
		second_at = _tmp25_;
		_tmp26_ = second_at;
		if (_tmp26_ == -1) {
			gchar* text_after_at = NULL;
			GtkEntry* _tmp27_ = NULL;
			const gchar* _tmp28_ = NULL;
			const gchar* _tmp29_ = NULL;
			gint _tmp30_ = 0;
			GtkEntry* _tmp31_ = NULL;
			const gchar* _tmp32_ = NULL;
			const gchar* _tmp33_ = NULL;
			gint _tmp34_ = 0;
			gint _tmp35_ = 0;
			gchar* _tmp36_ = NULL;
			gint match = 0;
			gint _tmp49_ = 0;
			_tmp27_ = self->priv->entry;
			_tmp28_ = gtk_entry_get_text (_tmp27_);
			_tmp29_ = _tmp28_;
			_tmp30_ = first_at;
			_tmp31_ = self->priv->entry;
			_tmp32_ = gtk_entry_get_text (_tmp31_);
			_tmp33_ = _tmp32_;
			_tmp34_ = strlen (_tmp33_);
			_tmp35_ = _tmp34_;
			_tmp36_ = string_slice (_tmp29_, (glong) (_tmp30_ + 1), (glong) _tmp35_);
			text_after_at = _tmp36_;
			match = -1;
			{
				gint i = 0;
				i = 0;
				{
					gboolean _tmp37_ = FALSE;
					_tmp37_ = TRUE;
					while (TRUE) {
						gboolean _tmp39_ = FALSE;
						gint _tmp40_ = 0;
						gchar** _tmp43_ = NULL;
						gint _tmp43__length1 = 0;
						gint _tmp44_ = 0;
						const gchar* _tmp45_ = NULL;
						const gchar* _tmp46_ = NULL;
						gboolean _tmp47_ = FALSE;
						if (!_tmp37_) {
							gint _tmp38_ = 0;
							_tmp38_ = i;
							i = _tmp38_ + 1;
						}
						_tmp37_ = FALSE;
						_tmp40_ = match;
						if (_tmp40_ == -1) {
							gint _tmp41_ = 0;
							gchar** _tmp42_ = NULL;
							gint _tmp42__length1 = 0;
							_tmp41_ = i;
							_tmp42_ = self->priv->domains;
							_tmp42__length1 = self->priv->domains_length1;
							_tmp39_ = _tmp41_ < _tmp42__length1;
						} else {
							_tmp39_ = FALSE;
						}
						if (!_tmp39_) {
							break;
						}
						_tmp43_ = self->priv->domains;
						_tmp43__length1 = self->priv->domains_length1;
						_tmp44_ = i;
						_tmp45_ = _tmp43_[_tmp44_];
						_tmp46_ = text_after_at;
						_tmp47_ = g_str_has_prefix (_tmp45_, _tmp46_);
						if (_tmp47_) {
							gint _tmp48_ = 0;
							_tmp48_ = i;
							match = _tmp48_;
						}
					}
				}
			}
			_tmp49_ = match;
			if (_tmp49_ != -1) {
				Block1Data* _data1_;
				gchar* best_match = NULL;
				gchar** _tmp50_ = NULL;
				gint _tmp50__length1 = 0;
				gint _tmp51_ = 0;
				const gchar* _tmp52_ = NULL;
				gchar* _tmp53_ = NULL;
				const gchar* _tmp54_ = NULL;
				const gchar* _tmp55_ = NULL;
				gint _tmp56_ = 0;
				gint _tmp57_ = 0;
				const gchar* _tmp58_ = NULL;
				gint _tmp59_ = 0;
				gint _tmp60_ = 0;
				gchar* _tmp61_ = NULL;
				const gchar* _tmp62_ = NULL;
				gint _tmp63_ = 0;
				gint _tmp64_ = 0;
				_data1_ = g_slice_new0 (Block1Data);
				_data1_->_ref_count_ = 1;
				_data1_->self = email_autocompleter_ref (self);
				_tmp50_ = self->priv->domains;
				_tmp50__length1 = self->priv->domains_length1;
				_tmp51_ = match;
				_tmp52_ = _tmp50_[_tmp51_];
				_tmp53_ = g_strdup (_tmp52_);
				best_match = _tmp53_;
				_tmp54_ = best_match;
				_tmp55_ = text_after_at;
				_tmp56_ = strlen (_tmp55_);
				_tmp57_ = _tmp56_;
				_tmp58_ = best_match;
				_tmp59_ = strlen (_tmp58_);
				_tmp60_ = _tmp59_;
				_tmp61_ = string_slice (_tmp54_, (glong) _tmp57_, (glong) _tmp60_);
				_data1_->text_to_add = _tmp61_;
				_tmp62_ = _data1_->text_to_add;
				_tmp63_ = strlen (_tmp62_);
				_tmp64_ = _tmp63_;
				if (_tmp64_ > 0) {
					GtkEntry* _tmp65_ = NULL;
					GtkEntry* _tmp66_ = NULL;
					const gchar* _tmp67_ = NULL;
					const gchar* _tmp68_ = NULL;
					const gchar* _tmp69_ = NULL;
					gchar* _tmp70_ = NULL;
					gchar* _tmp71_ = NULL;
					_tmp65_ = self->priv->entry;
					_tmp66_ = self->priv->entry;
					_tmp67_ = gtk_entry_get_text (_tmp66_);
					_tmp68_ = _tmp67_;
					_tmp69_ = _data1_->text_to_add;
					_tmp70_ = g_strconcat (_tmp68_, _tmp69_, NULL);
					_tmp71_ = _tmp70_;
					gtk_entry_set_text (_tmp65_, _tmp71_);
					_g_free0 (_tmp71_);
					g_timeout_add_full (G_PRIORITY_DEFAULT, (guint) 0, _______lambda45__gsource_func, block1_data_ref (_data1_), block1_data_unref);
				}
				_g_free0 (best_match);
				block1_data_unref (_data1_);
				_data1_ = NULL;
			}
			_g_free0 (text_after_at);
		}
	}
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static gchar** _vala_array_dup3 (gchar** self, int length) {
	gchar** result;
	int i;
	result = g_new0 (gchar*, length + 1);
	for (i = 0; i < length; i++) {
		gchar* _tmp0_ = NULL;
		_tmp0_ = g_strdup (self[i]);
		result[i] = _tmp0_;
	}
	return result;
}


static void _email_autocompleter_entry_changed_gtk_editable_changed (GtkEditable* _sender, gpointer self) {
	email_autocompleter_entry_changed ((EmailAutocompleter*) self);
}


EmailAutocompleter* email_autocompleter_construct (GType object_type, GtkEntry* e, gchar** email_domains, int email_domains_length1) {
	EmailAutocompleter* self = NULL;
	GtkEntry* _tmp0_ = NULL;
	GtkEntry* _tmp1_ = NULL;
	gchar** _tmp2_ = NULL;
	gint _tmp2__length1 = 0;
	gchar** _tmp3_ = NULL;
	gint _tmp3__length1 = 0;
	GtkEntry* _tmp4_ = NULL;
	g_return_val_if_fail (e != NULL, NULL);
	self = (EmailAutocompleter*) g_type_create_instance (object_type);
	_tmp0_ = e;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->entry);
	self->priv->entry = _tmp1_;
	_tmp2_ = email_domains;
	_tmp2__length1 = email_domains_length1;
	_tmp3_ = (_tmp2_ != NULL) ? _vala_array_dup3 (_tmp2_, _tmp2__length1) : ((gpointer) _tmp2_);
	_tmp3__length1 = _tmp2__length1;
	self->priv->domains = (_vala_array_free (self->priv->domains, self->priv->domains_length1, (GDestroyNotify) g_free), NULL);
	self->priv->domains = _tmp3_;
	self->priv->domains_length1 = _tmp3__length1;
	self->priv->_domains_size_ = self->priv->domains_length1;
	_tmp4_ = self->priv->entry;
	g_signal_connect ((GtkEditable*) _tmp4_, "changed", (GCallback) _email_autocompleter_entry_changed_gtk_editable_changed, self);
	return self;
}


EmailAutocompleter* email_autocompleter_new (GtkEntry* e, gchar** email_domains, int email_domains_length1) {
	return email_autocompleter_construct (TYPE_EMAIL_AUTOCOMPLETER, e, email_domains, email_domains_length1);
}


static void value_email_autocompleter_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void value_email_autocompleter_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		email_autocompleter_unref (value->data[0].v_pointer);
	}
}


static void value_email_autocompleter_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = email_autocompleter_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer value_email_autocompleter_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* value_email_autocompleter_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		EmailAutocompleter* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = email_autocompleter_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* value_email_autocompleter_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	EmailAutocompleter** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = email_autocompleter_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* param_spec_email_autocompleter (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	ParamSpecEmailAutocompleter* spec;
	g_return_val_if_fail (g_type_is_a (object_type, TYPE_EMAIL_AUTOCOMPLETER), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer value_get_email_autocompleter (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_EMAIL_AUTOCOMPLETER), NULL);
	return value->data[0].v_pointer;
}


void value_set_email_autocompleter (GValue* value, gpointer v_object) {
	EmailAutocompleter* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_EMAIL_AUTOCOMPLETER));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TYPE_EMAIL_AUTOCOMPLETER));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		email_autocompleter_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		email_autocompleter_unref (old);
	}
}


void value_take_email_autocompleter (GValue* value, gpointer v_object) {
	EmailAutocompleter* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_EMAIL_AUTOCOMPLETER));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TYPE_EMAIL_AUTOCOMPLETER));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		email_autocompleter_unref (old);
	}
}


static void email_autocompleter_class_init (EmailAutocompleterClass * klass) {
	email_autocompleter_parent_class = g_type_class_peek_parent (klass);
	((EmailAutocompleterClass *) klass)->finalize = email_autocompleter_finalize;
	g_type_class_add_private (klass, sizeof (EmailAutocompleterPrivate));
}


static void email_autocompleter_instance_init (EmailAutocompleter * self) {
	gchar* _tmp0_ = NULL;
	self->priv = EMAIL_AUTOCOMPLETER_GET_PRIVATE (self);
	_tmp0_ = g_strdup ("");
	self->priv->prevText = _tmp0_;
	self->ref_count = 1;
}


static void email_autocompleter_finalize (EmailAutocompleter* obj) {
	EmailAutocompleter * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_EMAIL_AUTOCOMPLETER, EmailAutocompleter);
	g_signal_handlers_destroy (self);
	_g_object_unref0 (self->priv->entry);
	self->priv->domains = (_vala_array_free (self->priv->domains, self->priv->domains_length1, (GDestroyNotify) g_free), NULL);
	_g_free0 (self->priv->prevText);
}


GType email_autocompleter_get_type (void) {
	static volatile gsize email_autocompleter_type_id__volatile = 0;
	if (g_once_init_enter (&email_autocompleter_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { value_email_autocompleter_init, value_email_autocompleter_free_value, value_email_autocompleter_copy_value, value_email_autocompleter_peek_pointer, "p", value_email_autocompleter_collect_value, "p", value_email_autocompleter_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (EmailAutocompleterClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) email_autocompleter_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (EmailAutocompleter), 0, (GInstanceInitFunc) email_autocompleter_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType email_autocompleter_type_id;
		email_autocompleter_type_id = g_type_register_fundamental (g_type_fundamental_next (), "EmailAutocompleter", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&email_autocompleter_type_id__volatile, email_autocompleter_type_id);
	}
	return email_autocompleter_type_id__volatile;
}


gpointer email_autocompleter_ref (gpointer instance) {
	EmailAutocompleter* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void email_autocompleter_unref (gpointer instance) {
	EmailAutocompleter* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		EMAIL_AUTOCOMPLETER_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}



