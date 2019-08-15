
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

#region Third-Party Namespaces

using System;
using Khronos;
using OpenGL; // The bane of the beast that is SlimDX!

#endregion

namespace CodeImp.DoomBuilder.Rendering
{
    // [gdm413229] GL context helper class
    internal class GLContext : IGLResource
    {

        #region Properties

        private string GLVendor; // GL_VENDOR goes here
        private string GLDevice; // GL_RENDERER goes here
        private string GLVersion;
        private uint GLExtensionCnt; // Number of probed GL extensions
        private string[GLExtensionCnt] GLExtensions; // OpenGL counterpart to D3D device caps

        public IntPtr context;

        public string[] GLExtensions1 { get => GLExtensions; set => GLExtensions = value; }

        #endregion

        private ProbeExtensions()
        {
            //TODO: write GL extension probe
        }

        public GLContext()
        {
            //Fix the line below if you have any experience with GL contexts.
            this.context = Glx.CreateContextWithConfigSGIX();
        }

        public ~GLContext()
        {
            // TODO: write suitable dtor
        }
    }
}
