# Motif UI for Ultimate Doom Builder (Native Code Side)

OpenGLContext.cpp has revealed that UDB's GL context code (for Linux) uses Xlib. Motif (libXm) also uses Xlib through the X Toolkit Intrinsics. (libXt)

## Differences between the Motif and WinForms versions

One big difference between Motif and WinForms is in the menu bar. Motif places the help menu on the far right of the menu bar.

## Reasons for the Motif migration project

Due to the GL context holder's dependence on Xlib, using the same code with an XCB-based toolkit may cause idiosyncracies in the programmers' hands.

## Why the Motif UI is a valuable asset

The Motif UI is valuable for those who don't want disruptions in their workflows caused by the [Mark of Cain](https://windows.com "More specifically, Windows Update.").

## Need help with the Motif UI migration?

You can read the documentation at http://www.opengroup.org/openmotif/docs/ in the Open Group's website. (the Open Group are the original developers of the Motif toolkit!)

## Addendum

ＩＦ　ＩＴ　ＷＡＳＮ’Ｔ　ＦＯＲ　**ＳＡＴＡＮ　ＬＵＳＴＩＮＧ　ＡＦＴＥＲ　ＥＶＥ　ＩＮ　ＴＨＥ　ＧＡＲＤＥＮ　ＯＦ　ＥＤＥＮ　ＷＨＩＬＥ　ＡＤＡＭ　ＷＡＳ　ＡＷＡＹ**，　ＷＨＩＣＨ　ＬＥＤ　ＴＯ　ＴＨＥ　**ＢＩＲＴＨ　ＯＦ　ＣＡＩＮ**，　ＷＨＩＣＨ　ＬＥＡＤＳ　ＴＯ　ＴＨＥ　**ＢＩＲＴＨ　ＯＦ　ＴＨＥ　ＡＮＴＩＣＨＲＩＳＴ**，　ＴＨＥＮ　[ＷＩＮＤＯＷＳ　１０](https://windows.com)　ＷＩＬＬ　ＢＥ　**Ａ　ＣＯＭＰＬＥＴＥＬＹ　ＤＩＦＦＥＲＥＮＴ　ＳＹＳＴＥＭ**　ＴＨＡＴ　Ｉ　ＷＩＬＬ　ＴＨＩＮＫ　ＯＦ　ＵＳＩＮＧ　ＡＳ　Ａ　ＣＯＭＰＬＥＭＥＮＴ　ＴＯ　ＬＩＮＵＸ．

Seems like original sin is one of the many factors that made Windows 10 so corrupt.