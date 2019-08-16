
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
using CodeImp.DoomBuilder.GZBuilder.Data;
using CodeImp.DoomBuilder.Map;
using CodeImp.DoomBuilder.Geometry;

namespace CodeImp.DoomBuilder.Rendering
{
    // Another step closer to casting SlimDX into the lake of fire
    internal abstract class GLRenderer : IGLResource
    {

        protected GLContext graphics;

        public GLRenderer(GLContext g)
        {
            g.RegisterResource(this);
            // No dtor for this class!
            GC.SuppressFinalize(this);
        }
        // Disposer
        public virtual void Dispose()
        {
            // Not already disposed?
            if (!isdisposed)
            {
                // Clean up

                // Destroy context
                // graphics.UnregisterResource(this);

                // Done
                graphics = null;
                isdisposed = true;
            }
        }

        // For GL resources
        public virtual void UnloadGLResource() { }
        public virtual void ReloadGLResource() { }
    }
}
