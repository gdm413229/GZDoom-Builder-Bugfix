
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

        private GLContext context;

        internal GLContext context { get { return context; } }


        // Direct3D has its devices and GL has its contexts.
        public GLShaderManager(GLContext context)
        {
            this.context = context;

            GC.SuppressFinalize(this);
        }

        // The bin man!
        public void Dispose() 
        {
            if(!isdisposed)
            {

                this.context = null;
                this.isdisposed = true;
            }
        }

        public void UnloadResource()
        {
            display2dshader.Dispose();
            things2dshader.Dispose();
            world3dshader.Dispose();
        }

        // Load resources
        public void ReloadResource()
        {
            // Initialize effects
            display2dshader = new Display2DShader(this);
            things2dshader = new Things2DShader(this);
            world3dshader = new World3DShader(this);
        }


    }
}
