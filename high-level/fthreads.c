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

#include <glib.h>
#include "fthreads.h"

fThread* current_threads;

inline void fth_tree-insert( fThread* tree, fThread* data ) {
     fThread *x, *y;

        x = tree;

        while (x != NULL) {
                y = x;

                if ( data->thread < x->thread )
                        x = x->left;
                else
                        x = x->right;
        }

        data->parent = y;
	data->left = NULL;
	data->right = NULL;

        if ( data->thread < y->thread )
                y->left = d;
        else
                y->right = d;

}

inline void fth_rotate-right( fThread* node ) {
  
}

inline void fth_rotate-left( fThread* node ) {
  
}