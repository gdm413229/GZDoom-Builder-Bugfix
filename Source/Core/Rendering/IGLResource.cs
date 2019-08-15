
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

namespace CodeImp.DoomBuilder.Rendering
{
    // [gdm413229] One step closer to removing Windows' grasp on the editor.
    // Not sure if this would work.
    public interface IGLResource
    {
        // This is used to unload the resouce
        void UnloadResource();

        // This is used to reload the resource
        void ReloadResource();
    }
}
