using System.Collections.Generic;
using System.Diagnostics;
#if Windows
using CodeImp.DoomBuilder.PlatformSpecific.Windows;
#elif Linux
using CodeImp.DoomBuilder.PlatformSpecific.Linux;
#endif

namespace CodeImp.DoomBuilder
{
    internal static class FileLockChecker
	{
        internal class FileLockCheckResult //mxd
        {
            public string Error;
            public List<Process> Processes = new List<Process>();
        }
        /// <summary>
        /// Find out what process(es) have a lock on the specified file.
        /// </summary>
        /// <param name="path">Path of the file.</param>
        /// <returns>Processes locking the file</returns>
        /// <remarks>See also:
        /// http://msdn.microsoft.com/en-us/library/windows/desktop/aa373661(v=vs.85).aspx
        /// http://wyupdate.googlecode.com/svn-history/r401/trunk/frmFilesInUse.cs (no copyright in code at time of viewing)
        /// 
        /// </remarks>
        public static FileLockCheckResult CheckFile(string path)
        {
#if Windows
            return FileLockCheckerWindows.CheckFile(path);
#elif Linux
            return FileLockCheckerLinux.CheckFile(path);
#endif
        }
    }
}
