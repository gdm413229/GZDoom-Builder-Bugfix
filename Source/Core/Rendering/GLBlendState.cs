using System;
using OpenGL;
namespace CodeImp.DoomBuilder.Rendering
{
    internal class GLBlendState
    {

        private uint blendfunc_src;
        private uint blendfunc_dst;
        private uint blendequation;

        public GLBlendState(uint src,uint dst,uint equation)
        {
            this.blendfunc_src = src;
            this.blendfunc_dst = dst;
            this.blendequation = equation;
        }

        public void UseMe() 
        { 

        }

    }
}
