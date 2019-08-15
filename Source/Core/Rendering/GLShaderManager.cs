using System;
namespace CodeImp.DoomBuilder.Rendering
{
    // [gdm413229] OpenGL version of ShaderManager class
    internal class GLShaderManager : IDisposable
    {

        private readonly string ShaderTechnique;

        private GLDisp2DShader display2dshader;
        private GLThings2DShader things2dshader;
        private GLWorld3DShader world3dshader;

        public GLShaderManager()
        {


        }
    }
}
