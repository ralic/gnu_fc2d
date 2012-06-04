/*
FDiamondEngine - Complete engine for 3D games development.
Copyright (C) 2012  Fabio J. Gonzalez <fabiojosue@gmail.com>

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

#ifndef __VIDEO_MESH_H__
#define __VIDEO_MESH_H__ 1

#include <video/image.h>
#include <utils/Vector3.h>
#include <glib.h>

extern GList* f_scene_meshes;

typedef enum {
	RENDER_NORMAL=0,
	RENDER_CARTOON
} fRenderMode;

typedef struct {
	fVector3 v1;
	fVector3 v2;
	fVector3 v3;
	fVector3 v1_tex;
	fVector3 v2_tex;
	fVector3 v3_tex;
} fTriangle;

typedef struct {
	fVector3 pos;
	fVector3 scale;
	fVector3 rot;
	GList* tri;
	fImage* tex;
	float opacity;
	float mirror;
	fRenderMode r;
} fMesh;

#endif