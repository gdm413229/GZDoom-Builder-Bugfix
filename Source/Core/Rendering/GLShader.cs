using System;
using System.IO; // For GLSL shader file loading.
using OpenGL;
using System.Xml; // for those *_glfx.xml files!

namespace CodeImp.DoomBuilder.Rendering
{
    internal abstract class GLShader : IDisposable
    {

        protected GLShaderManager manager;
        private bool isdisposed;

        protected GLShader(GLShaderManager manager) 
        { 

        }

        public virtual void Dispose()
        {
            // TODO: write disposal func
        }
    }
}
