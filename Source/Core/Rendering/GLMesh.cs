using System;
using OpenGL; // Direct3D is a deadweight for the dying titan that is Windows!  Let the Builder break free from it's Windows prison!
namespace CodeImp.DoomBuilder.Rendering
{
    internal class GLMesh : IDisposable
    {

        public GLVertexBuffer vbo;

        public GLMesh(GLContext context, uint indexcnt, uint vertexcnt, GLElementBuffer elements)
        {

        }

        public void UseMe()
        {

        }

        public void Unlock()
        {

        }

        public void Dispose()
        {
            this.vbo = null; // flag the vertex buf as garbage
            GC.Collect(); // whip those bin men!
        }
    }

    internal class GLVertex
    {

    }

    internal class GLVertexElement
    {
        public uint vertex_id;

        public GLVertexElement(uint vertex_id)
        {
            this.vertex_id = vertex_id;
        }
    }

    internal class GLVertexBuffer
    {
        public GLElementBuffer elements;

        public GLVertex[] vertexes { get; set; } // using a bit of DOOM map format naming convention here!

        public GLVertexBuffer(uint num_elems, uint[] vert_id)
        {

        }

    }

    internal class GLElementBuffer
    {
        public uint num_elements;

        internal GLVertexElement[] element { get; set; }

        public GLElementBuffer(uint num_elems,uint[] vert_id)
        {
            this.num_elements = num_elems;
            uint cur_elem = 0;
            while (cur_elem < num_elems)
            {

                cur_elem++; // Advance the film
            }
        }

    }

}

