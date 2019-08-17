using System;
using System.IO; // For shader file loading.

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
