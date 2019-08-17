using System;
namespace CodeImp.DoomBuilder.Rendering
{
    public enum GLRenderStateEnum
    {
        LineDrawing = 0,
        PolyDrawing = 1, // when drawing filled polys
        ShadedPolyDrawing = 2, // when drawing shaded filled polys
        SkyDrawing = 16383,
    };
}
