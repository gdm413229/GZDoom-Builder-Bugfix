
#region © 2019 Pascal vd Heiden, MaxED, gdm413229, Talon1024 and ZZYZX.

/*
 * Copyright (c) 2007 Pascal vd Heiden, www.codeimp.com
 * This program is released under GNU General Public License
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 */

#endregion

using System;
namespace CodeImp.DoomBuilder.Rendering
{
    // [gdm413229] OpenGL unsigned byte element pixel color format class
    public class GLPixColor
    {
        // Useful for multiplicative blending. Equivalent to glBlendFunc(GL_DST_COLOR, GL_ZERO)
        public const float BYTE_TO_FLOAT = 0.00392156862745098f;

        // D3D pix col = little endian : GL pix col = big endian for RGB values
        public byte r, g, b, a; // D3D9 pix col is bgra, GL pix col is rgba!

        // Pass no values, you get pitch black with full opacity.
        public GLPixColor()
        {
            this.r = 0;
            this.g = 0;
            this.b = 0;
            this.a = 255;
        }
        // Pass an RGB val, you get the same RGB but with full opacity.
        public GLPixColor(byte r, byte g, byte b)
        {
            this.r = r;
            this.g = g;
            this.b = b;
            this.a = 255;
        }
        // Pass those to glColor4ub()
        public GLPixColor(byte r,byte g,byte b,byte a)
        {
            this.r = r;
            this.g = g;
            this.b = b;
            this.a = a;
        }
        public GLPixColor(GLPixColor src,byte a) 
        {
            this.r = src.r;
            this.g = src.g;
            this.b = src.b;
            this.a = a;
        }
        // ＣＯＰＹ　ＴＨＡＴ　ＰＩＸＥＬ　ＣＯＬＯＲ！
        public GLPixColor(GLPixColor src) => this = src;

        // Color crunchers!

        // Add two cols together
        public static GLPixColor Add(GLPixColor lhs,GLPixColor rhs)
        {
            return new GLPixColor
            {
                a = (byte)(Math.Min(lhs.a+rhs.a,255)),
                r = (byte)(Math.Min(lhs.r+rhs.r,255)),
                g = (byte)(Math.Min(lhs.g+rhs.g,255)),
                b = (byte)(Math.Min(lhs.b+rhs.b,255))
            };
        }
        // Subtract two cols
        public static GLPixColor Subtract(GLPixColor lhs, GLPixColor rhs)
        {
            return new GLPixColor
            {
                a = (byte)(Math.Max()),
                r = (byte)(Math.Max()),
                g = (byte)(Math.Max()),
                b = (byte)(Math.Max())
            };
        }

        public static GLPixColor Modulate(GLPixColor lhs, GLPixColor rhs)
        {
            float aa = lhs.a * BYTE_TO_FLOAT;
            float ar = lhs.r * BYTE_TO_FLOAT;
            float ag = lhs.g * BYTE_TO_FLOAT;
            float ab = lhs.b * BYTE_TO_FLOAT;
            float ba = rhs.a * BYTE_TO_FLOAT;
            float br = rhs.r * BYTE_TO_FLOAT;
            float bg = rhs.g * BYTE_TO_FLOAT;
            float bb = rhs.b * BYTE_TO_FLOAT;

            return new GLPixColor
            {
                a = (byte)((aa * ba) * 255.0f),
                r = (byte)((ar * br) * 255.0f),
                g = (byte)((ag * bg) * 255.0f),
                b = (byte)((ab * bb) * 255.0f)
            };
        }

        //mxd. Handy while debugging
        //[gdm413229] this method is compatible! :D (PixelColor and GLPixColor has the same class field names!)
        public override string ToString()
        {
            return "[A=" + a + ", R=" + r + ", G=" + g + ", B=" + b + "]";
        }

        //Original by mxd, transferred to GLPixColor by gdm413229
        // Pixel color mover
        public bool Equals(GLPixColor src)
        {
            return (r == src.r && g == src.g && b == src.b && a == src.a);
        }

    }
}
