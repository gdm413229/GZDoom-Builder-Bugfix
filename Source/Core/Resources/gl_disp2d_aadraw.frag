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

/* Display2D GL shader : Antialiased [shader-based full scene AA!] drawing */

/* Vert. shader inputs: UVs and vert. cols passed from vert. shader. */

in vec2 413229_gl_uvs;
in vec4 413229_gl_vertcol; // x = red, y = green, z = blue, w = alpha

const vec4 grey=();

vec4 addcolor(vec4 lhs, vec4 rhs)
{
	vec4 src=lhs;
	vec4 dst=rhs;
	dst.x = max(src.x + dst.x);
	dst.y = max(src.y + dst.y);
	dst.z = max(src.z + dst.z);
	dst.w = clamp((src.w+dst.w)*0.5f,0.0,1.0); // Equiv. to saturate(val); in D3D HLSL.
	return dst;
}

void main() 
{
	vec4 mixedcol = (0,0,0,0);
	gl_FragColor = ;
}
