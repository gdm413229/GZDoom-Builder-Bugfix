using OpenGL;

namespace CodeImp.DoomBuilder.Rendering
{
    internal class GLBlendState
    {

        // TODO: add blend presets.

        /* Suctractive is glBlendFunc(GL_ONE,GL_ONE) with glBlendEquation(GL_FUNC_SUBTRACT)
         * Additive is glBlendFunc(GL_ONE,GL_ONE) with glBlendEquation(GL_FUNC_ADD)
         * DOOM invulnerability is possibly glBlendFunc(GL_ONE_MINUS_SRC_COLOR,GL_ONE) */

        private BlendingFactor blendfunc_src;
        private BlendingFactor blendfunc_dst;
        private BlendEquationMode blendequation;

        public GLBlendState(BlendingFactor src,BlendingFactor dst,BlendEquationMode equation)
        {
            this.blendfunc_src = src;
            this.blendfunc_dst = dst;
            this.blendequation = equation;
        }

        public void UseMe() 
        {
            Gl.BlendFunc(this.blendfunc_src, this.blendfunc_dst);
            Gl.BlendEquation(this.blendequation);
        }

    }
}
