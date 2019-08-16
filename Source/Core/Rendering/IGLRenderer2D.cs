
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
        // Can anyone give me a GL equivalent of those funcs???
        bool StartPlotter(bool clear);
        bool StartThings(bool clear);
        bool StartOverlay(bool clear);
        void Finish(); // Will have glFlush or glFinish.  Explicit synchronization!
        void SetPresentation(Presentation present);
        void Present();

        // Drawing methods, now GL-ified
        // D3D DrawIndexed calls will be turned into glDrawElements
        void PlotLine(Vector2D start, Vector2D end, GLPixColor c);
        void PlotLine(Vector2D start, Vector2D end, GLPixColor c, float lengthscaler); //mxd
        void PlotLinedef(Linedef l, GLPixColor c);
        void PlotLinedefSet(ICollection<Linedef> linedefs);
        void PlotSector(Sector s);
        void PlotSector(Sector s, GLPixColor c);
        void PlotVertex(Vertex v, int colorindex);
        void PlotVertexAt(Vector2D v, int colorindex);
        void PlotVerticesSet(ICollection<Vertex> vertices);
        void RenderThing(Thing t, GLPixColor c, float alpha);
        void RenderThingSet(ICollection<Thing> things, float alpha);
        void RenderRectangle(RectangleF rect, float bordersize, GLPixColor c, bool transformrect);
        void RenderRectangleFilled(RectangleF rect, GLPixColor c, bool transformrect);
        void RenderRectangleFilled(RectangleF rect, GLPixColor c, bool transformrect, ImageData texture);
        void RenderLine(Vector2D start, Vector2D end, float thickness, GLPixColor c, bool transformcoords);
        void RenderArrows(ICollection<Line3D> line); //mxd
        void RenderArrows(ICollection<Line3D> line, bool transformcoords); //mxd
        void RenderText(TextLabel text); //mxd, DB2 compatibility
        void RenderText(ITextLabel text); //mxd
        void RenderText(IList<ITextLabel> labels); //mxd
        void RenderGeometry(FlatVertex[] vertices, ImageData texture, bool transformcoords);
        void RenderHighlight(FlatVertex[] vertices, int color); //mxd
        void RedrawSurface();
    }
}
