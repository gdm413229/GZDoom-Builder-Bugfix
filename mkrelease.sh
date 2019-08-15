#!/bin/sh

# This shell script is a POSIX reincarnation of the `Make Release.bat` batch file.
# This is very WIP!

cat mkrelease_scriptstart.txt

# SYNOPSIS: env IDEDIR=(where your MonoDevelop is) ./mkrelease.sh

# A .chm compiler for Linux is what we will need for getting GZDB-BF into Linux without dusting off unused copies of Windows.

mkdir dist

cd libsrc/DevIL

git checkout Source/Core/Properties/AssemblyInfo.cs > /dev/null
git checkout Source/Plugins/BuilderModes/Properties/AssemblyInfo.cs > /dev/null

# TODO: make POSIX compliant version of the git changelog maker from batch file.
