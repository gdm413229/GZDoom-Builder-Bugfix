#version 120

/* This GL shader is © gdm413229 under the terms of the GNU General
 * Public License, see license notice below for details.
 * 
 * Applicable Tools: GZDoom Builder 413229 Edition */

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 */

/* 2D xform shader translated from D3D9 SM2 HLSL :D */

uniform vec3 VERTEX_POS; uniform vec2 VERTEX_UV;
uniform vec4 VERTEX_COL;
uniform mat4 VIEWXFRM_MAT;

out vec2 413229_gl_uvs;
out vec4 413229_gl_vertcol;

void main()
{
	gl_Position = VERTEX_POS*VIEWXFRM_MAT; // Mul. that matrix!
	413229_gl_vertcol = VERTEX_COL;
	413229_gl_uvs = VERTEX_UV;
}
