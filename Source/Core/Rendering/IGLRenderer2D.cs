
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

#region Includes

using System.Collections.Generic;
using System.Drawing;
using CodeImp.DoomBuilder.Map;
using CodeImp.DoomBuilder.Geometry;
using CodeImp.DoomBuilder.Data;

#endregion

namespace CodeImp.DoomBuilder.Rendering
{
    // [gdm413229] OpenGL counterpart to IRenderer2D interface
    public interface IGLRenderer2D
    {
        // Properties
        float OffsetX { get; }
        float OffsetY { get; }
        float TranslateX { get; }
        float TranslateY { get; }
        float Scale { get; }
        int VertexSize { get; }
        bool DrawMapCenter { get; set; } //mxd
        ViewMode ViewMode { get; }

        // View methods
        Vector2D DisplayToMap(Vector2D mousepos);
        Vector2D MapToDisplay(Vector2D mappos);

        // Color methods
        GLPixColor DetermineLinedefColor(Linedef l);
        GLPixColor DetermineThingColor(Thing t);
        int DetermineVertexColor(Vertex v);
        int CalculateBrightness(int level);
        void UpdateExtraFloorFlag(); //mxd

        // Rendering management methods
        bool StartPlotter(bool clear);
        bool StartThings(bool clear);
        bool StartOverlay(bool clear);
        void Finish();
        void SetPresentation(Presentation present);
        void Present();
    }
}
