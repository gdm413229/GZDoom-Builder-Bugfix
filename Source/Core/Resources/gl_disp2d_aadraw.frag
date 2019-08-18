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

in vec2 g413229_gl_uvs;
in vec4 g413229_gl_vertcol; // x = red, y = green, z = blue, w = alpha

uniform sampler2D texture0;
attribute vec4 gl_Color;

const vec4 grey=(0.5,0.5,0.5,1.0);

/* Render settings
 * x = texel width
 * y = texel height
 * z = FSAA blend fac
 * w = transparency/opacity */
 
uniform sampler2D mrt_thirdbuf; // may need triple buffering!

uniform vec4 rendersettings;

uniform mat4 transformsettings;

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
	vec4 c = texture2D(texture0,413229_gl_uvs);
	
	if(c.w < 0.1f){
		vec4 mixedcol = (0,0,0,0);
		mixedcol = addcolor(mixedcol,texture2D(texture0, vec2(g413229_gl_uvs.x+rendersettings.x,g413229_gl_uvs.y)));
		mixedcol = addcolor(mixedcol,texture2D(texture0, vec2(g413229_gl_uvs.x-rendersettings.x,g413229_gl_uvs.y)));
		mixedcol = addcolor(mixedcol,texture2D(texture0, vec2(g413229_gl_uvs.x,g413229_gl_uvs.y+rendersettings.y)));
		mixedcol = addcolor(mixedcol,texture2D(texture0, vec2(g413229_gl_uvs.x,g413229_gl_uvs.y-rendersettings.y)));
				
		gl_FragColor=desaturate(c.xyz,c.w*rendersettings.w)*texture2D(mrt_thirdbuf,gl_FragCoord.xy); // best used with multiplicative blending!
	}
	else gl_FragColor = ;
}
