/*
FGameEngine - Complete tool kit for 3D games development.
Copyright (C) 2012  Fabio J. Gonzalez

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <utils/event-basis.h>
#include <glib.h>

GHashTable* f_connect_hash = NULL;

int f_signal_connect( const char* name, FCallback function ) {
	
	GHashTable** hash = &f_connect_hash;
	GList* l;
	
	if( *hash == NULL )
		*hash = g_hash_table_new( g_str_hash, g_str_equal );
	
	l = g_hash_table_lookup ( *hash, name );
	
	if( l != NULL )
		g_list_append( l, function );
	else {
		l = g_list_append( NULL, function );
		g_hash_table_insert( *hash, name, l );
	}
	
}

void f_signal_disconnect( const char* name, FCallback function ) {
	
	GHashTable** hash = &f_connect_hash;
	GList* l;
	
	l = g_hash_table_lookup ( *hash, name );
	
	if( l != NULL ) {
		l = g_list_remove( l, function );
		if( l == NULL ) 
			g_hash_table_remove( *hash, name );
	}
}

void f_signal_emit( const char* name, void* data ) {
	
	GHashTable** hash = &f_connect_hash;
	GList* l;
	
	l = g_hash_table_lookup ( *hash, name );
	
	if( l != NULL ) {
		for( ; l != NULL; l = l->next ) {
			FCALLBACK(l->data)(data);
		}
	}
}