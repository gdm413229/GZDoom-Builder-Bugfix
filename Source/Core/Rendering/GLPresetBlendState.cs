using OpenGL; // No need to DllImport(libGL.so)! :D

namespace CodeImp.DoomBuilder.Rendering
{
    internal sealed class GLPresetBlendState
    {
        public void SetAlphaBlend()
        {
            Gl.BlendFunc(BlendingFactor.SrcAlpha,BlendingFactor.One);
            Gl.BlendEquation(BlendEquationMode.FuncAdd);
        }

        public void SetAddBlend()
        {
            Gl.BlendFunc(BlendingFactor.One, BlendingFactor.One);
            Gl.BlendEquation(BlendEquationMode.FuncAdd);
        }

        public void SetMulBlend()
        {
            Gl.BlendFunc(BlendingFactor.One,BlendingFactor.OneMinusSrcColor);
            Gl.BlendEquation(BlendEquationMode.FuncAdd);
        }
    }
}
