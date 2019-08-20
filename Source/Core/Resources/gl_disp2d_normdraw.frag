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

/* Display2D GL shader : Normal [without antialiasing!] drawing */

in vec2 g413229_gl_uvs;
in vec4 g413229_gl_vertcol; // x = red, y = green, z = blue, w = alpha

uniform sampler2D texture0;
attribute vec4 gl_Color;

/* Render settings
 * x = texel width
 * y = texel height
 * z = FSAA blend fac
 * w = transparency/opacity */
 
uniform sampler2D mrt_thirdbuf; // may need triple buffering!

uniform vec4 rendersettings;

uniform float desaturation;

vec4 desaturate(vec3 rgbtexel)
{
	float gzgrey=(rgbtexel.x*0.3 + rgbtexel.y * 0.56 + rgbtexel.z * 0.14);
	return mix(rgbtexel,vec3(gzgrey,gzgrey,gzgrey),desaturation);
}

void main() 
{
	vec2 scr_fragcoord = 1 - gl_FragPosition;
	
	vec4 c = texture2D(texture0,413229_gl_uvs);
	vec4 curfrag = texture2D(mrt_thirdbuf,scr_fragcoord.xy);
			
	gl_FragColor = vec4(desaturate(c.xyz),c.w*rendersettings.w)*curfrag;
}
