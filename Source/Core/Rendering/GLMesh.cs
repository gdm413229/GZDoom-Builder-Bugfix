using System;
using OpenGL;
namespace CodeImp.DoomBuilder.Rendering
{
    internal class GLMesh : IDisposable
    {


        public GLMesh(GLContext context,uint indexcnt,uint vertexcnt,,GLElementBuffer elements)
        {

        }

        public void Dispose()
        {
            GC.Collect(); // whip those bin men!
        }
    }

    internal class GLVertexElement
    {
        public uint vertex_id;

    }

    internal class GLVertexBuffer
    {
        public uint num_elements;
        GLVertexElement[] elements;

        public GLVertexBuffer(uint num_elems,uint vert_id)
        {
            this.num_elements = num_elems;
            uint cur_elem = 0;
            while(cur_elem < num_elems)
            {

                cur_elem++;
            }
        }

    }

}

