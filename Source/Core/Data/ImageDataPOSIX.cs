
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

#region Includes

using System;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Drawing.Imaging;
using System.IO;
using System.Runtime.InteropServices;
using CodeImp.DoomBuilder.Geometry;
using CodeImp.DoomBuilder.IO;
using CodeImp.DoomBuilder.Rendering;
using CodeImp.DoomBuilder.Windows;

#endregion

namespace CodeImp.DoomBuilder.Data
{
    public abstract unsafe class ImageDataPOSIX
    {

        #region ================== Constants

        #endregion

        #region ================== Variables

        // Properties
        protected string name;
        protected long longname;
        protected int width;
        protected int height;
        protected Vector2D scale;
        protected bool worldpanning;
        private bool usecolorcorrection;
        // [gdm413229] In POSIX, the filenames have no drive letters and use forward slash dir. delimiters.
        protected string filepathname; //mxd. Absolute path to the image;
        protected string shortname; //mxd. Name in uppercase and clamped to DataManager.CLASIC_IMAGE_NAME_LENGTH
        protected string virtualname; //mxd. Path of this name is used in TextureBrowserForm
        protected string displayname; //mxd. Name to display in TextureBrowserForm
        protected bool isFlat; //mxd. If false, it's a texture
        protected bool istranslucent; //mxd. If true, has pixels with alpha > 0 && < 255 
        protected bool ismasked; //mxd. If true, has pixels with zero alpha
        protected bool hasLongName; //mxd. Texture name is longer than DataManager.CLASIC_IMAGE_NAME_LENGTH
        protected bool hasPatchWithSameName; //mxd
        protected int namewidth; // biwa
        protected int shortnamewidth; // biwa

        //mxd. Hashing
        private static int hashcounter;
        private readonly int hashcode;

        // Loading
        private volatile ImageLoadState previewstate;
        private volatile ImageLoadState imagestate;
        private volatile int previewindex;
        protected volatile bool loadfailed;
        private volatile bool allowunload;

        // References
        private volatile bool usedinmap;
        private volatile int references;

        // X11 pixmap
        protected Bitmap bitmap;

        // OpenGL texture
        private int mipmaplevels;   // 0 = all mipmaps
        protected bool dynamictexture;
        private GLTexture texture;

        // Disposing
        protected bool isdisposed;

        // Dummy object used when we don't have a bitmap for locking
        private object bitmapLocker = new object();

        #endregion

        #region ================== Properties

        public string Name { get { return name; } }
        public long LongName { get { return longname; } }
        public string ShortName { get { return shortname; } } //mxd
        public string FilePathName { get { return filepathname; } } //mxd
        public string VirtualName { get { return virtualname; } } //mxd
        public string DisplayName { get { return displayname; } } //mxd
        public bool IsFlat { get { return isFlat; } } //mxd
        public bool IsTranslucent { get { return istranslucent; } } //mxd
        public bool IsMasked { get { return ismasked; } } //mxd
        public bool HasPatchWithSameName { get { return hasPatchWithSameName; } } //mxd
        internal bool HasLongName { get { return hasLongName; } } //mxd
        public bool UseColorCorrection { get { return usecolorcorrection; } set { usecolorcorrection = value; } }
        public GLTexture Texture { get { lock (this) lock (bitmap ?? bitmapLocker) { return texture; } } }
        public bool IsPreviewLoaded { get { return (previewstate == ImageLoadState.Ready); } }
        public bool IsImageLoaded { get { return (imagestate == ImageLoadState.Ready); } }
        public bool LoadFailed { get { return loadfailed; } }
        public bool IsDisposed { get { return isdisposed; } }
        public bool AllowUnload { get { return allowunload; } set { allowunload = value; } }
        public ImageLoadState ImageState { get { return imagestate; } internal set { imagestate = value; } }
        public ImageLoadState PreviewState { get { return previewstate; } internal set { previewstate = value; } }
        public bool IsReferenced { get { return (references > 0) || usedinmap; } }
        public bool UsedInMap { get { return usedinmap; } }
        public int MipMapLevels { get { return mipmaplevels; } set { mipmaplevels = value; } }
        public virtual int Width { get { return width; } }
        public virtual int Height { get { return height; } }
        internal int PreviewIndex { get { return previewindex; } set { previewindex = value; } }
        //mxd. Scaled texture size is integer in ZDoom.
        public virtual float ScaledWidth { get { return (float)Math.Round(width * scale.x); } }
        public virtual float ScaledHeight { get { return (float)Math.Round(height * scale.y); } }
        public virtual Vector2D Scale { get { return scale; } }
        public bool WorldPanning { get { return worldpanning; } }
        public int NameWidth { get { return namewidth; } } // biwa
        public int ShortNameWidth { get { return shortnamewidth; } } // biwa

        #endregion

        #region ctor and disposer

        public ImageDataPOSIX()
        { 

        }

        #endregion

    }
}
