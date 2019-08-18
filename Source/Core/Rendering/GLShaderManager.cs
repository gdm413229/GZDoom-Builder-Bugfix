
#region © 2019 Pascal vd Heiden, MaxED, gdm413229, Talon1024 and ZZYZX.

/*
 * Copyright (c) 2007 Pascal vd Heiden, www.codeimp.com
 * This program is released under GNU General Public License
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 */

#endregion

using System;
namespace CodeImp.DoomBuilder.Rendering
{
    // [gdm413229] OpenGL version of ShaderManager class
    internal class GLShaderManager : IGLResource, IDisposable
    {

        // Manages GL shader programs.

        private bool isdisposed;
        private GLDisp2DShader display2dshader;
        private GLThings2DShader things2dshader;
        private GLWorld3DShader world3dshader;

        internal GLContext context { get { return context; } }

        public GLShaderManager()
        {


        }



    }
}
