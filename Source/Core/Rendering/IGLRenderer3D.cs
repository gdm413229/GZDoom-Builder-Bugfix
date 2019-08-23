using System.Collections.Generic;
using CodeImp.DoomBuilder.Map;
using CodeImp.DoomBuilder.Geometry;
using CodeImp.DoomBuilder.VisualModes;

namespace CodeImp.DoomBuilder.Rendering
{
    public interface IGLRenderer3D
    {
        // Properties
        ProjectedFrustum2D Frustum2D { get; }
        bool DrawThingCages { get; set; }
        bool ShowSelection { get; set; }
        bool ShowHighlight { get; set; }

        // General methods
        void PositionAndLookAt(Vector3D pos, Vector3D lookat);

        // Presenting methods
        void Finish();
        bool Start();
        void StartGeometry();
        void FinishGeometry();

        // Rendering methods
        int CalculateBrightness(int level);
        int CalculateBrightness(int level, Sidedef sd); //mxd

        void SetHighlightedObject(IVisualPickable obj);
        void AddSectorGeometry(VisualGeometry g);
        void AddThingGeometry(VisualThing t);
        void SetVisualVertices(List<VisualVertex> verts);
        void SetEventLines(List<Line3D> lines);
        void RenderCrosshair();
        void SetFogMode(bool usefog);
        void SetCrosshairBusy(bool busy);
    }
}
