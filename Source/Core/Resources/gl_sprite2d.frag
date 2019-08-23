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

/* Things2D GL shader : Sprite drawing shader, now GLSL-ified! */

in vec2 g413229_gl_uvs;
in vec4 g413229_gl_vertcol; // x = red, y = green, z = blue, w = alpha

uniform sampler2D texture0;

uniform sampler2D mrt_thirdbuf; // may need triple buffering!

uniform vec4 rendersettings;

uniform float desaturation;

// Ported from ZZYZX's HLSL shader code (from GLSL to HLSL and back to GLSL.)
vec3 desaturate(vec3 rgbtexel)
{
	float gzgrey=(rgbtexel.x*0.3 + rgbtexel.y * 0.56 + rgbtexel.z * 0.14);
	return mix(rgbtexel,vec3(gzgrey,gzgrey,gzgrey),desaturation); // Think of this line like Blender Cycles' MixRGB node.
}

void main()
{
	vec2 scr_fragcoord = vec2(gl_FragPosition.x,1-gl_FragPosition.y); // Y flip that buffer!
	
	vec4 c=texture2D(texture0,g413229_gl_uvs);
	vec4 curfrag=texture2D(mrt_thirdbuf,scr_fragcoord); // get current fragment's color
	
	// Modulate it by the selection color
	if(curfrag.w>0)
	{
		vec3 cr=desaturate(c.xyz);
		gl_FragColor=vec4((cr.x+curfrag.x)/2.0f,(cr.y+curfrag.y)/2.0f,(cr.z+curfrag.z)/2.0f,c.w*rendersettings.w*curfrag.w);
	}
	
	// Or leave the color as is
	gl_FragColor=vec4(desaturate(c.xyz),c.w*rendersettings.w)*curfrag;
}
