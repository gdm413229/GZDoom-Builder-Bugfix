#if Linux
using System;
using System.Runtime.InteropServices;
using Mono.Unix;

namespace CodeImp.DoomBuilder.PlatformSpecific.Linux
{
    internal static class FileLockCheckerLinux
    {
        [DllImport("libc", EntryPoint = "makedev")]
        private static extern uint GetDeviceID(uint major, uint minor);

        private static readonly string UnixLocksFile = "/proc/locks";

        public static FileLockChecker.FileLockCheckResult CheckFile(string path)
        {
            FileLockChecker.FileLockCheckResult result = new FileLockChecker.FileLockCheckResult();
            if (UnixFileSystemInfo.TryGetFileSystemEntry(path, out UnixFileSystemInfo finfo))
            {
                long wadInode = finfo.Inode;
                string[] LockInfos = File.ReadAllLines(UnixLocksFile);
                foreach (string LockLine in LockInfos)
                {
                    // Each line is in this format:
                    //                           PID major:minor:inode
                    // 1: POSIX  ADVISORY  READ  5433 08:01:7864448 128 128
                    string[] LockInfo = LockLine.Split(new char[]{' ', '\t'});
                    int pid = int.Parse(LockInfo[4]);
                    long[] nodeInfo = (long[])LockInfo[5].Split(':').Select((n) => long.Parse(n));
                    uint lockDevice = GetDeviceID((uint)nodeInfo[0], (uint)nodeInfo[1]);
                    long lockInode = nodeInfo[2];
                    if (lockInode == wadInode && lockDevice == finfo.Device)
                    {
                        // It's locked!
                        result.Processes.Add(Process.GetProcessById(pid));
                    }
                }
            }
            if (result.Processes.Count > 0)
            {
                result.Error = "Unable to save the map: target file is locked by the following process"
                                           + (result.Processes.Count > 1 ? "es" : "") + ":"
                                           + Environment.NewLine + Environment.NewLine;
                foreach (var proc in result.Processes)
                {
                    result.Error += $"{proc.ProcessName} ({proc.Id})" + Environment.NewLine;
                }
            }
            return result;
        }
    }
}
#endif