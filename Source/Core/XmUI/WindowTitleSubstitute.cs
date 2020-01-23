
// Window title substitute class for the Motif UI port of UDB



namespace CodeImp.DoomBuilder.G4_XmUI {

#region Includes

using System;

#endregion

public class WindowTitleSubstitute {

    #region Fields/Props

    private string old_windowtitle;
    private string new_windowtitle;

    #endregion

    #region Methods

    public void PickCandidate() {
        string[] candidates=
        {
            "Remember kid, Windows 10 hath Beelzebub!",
            "Satan is Cortana's father, not Bill!", // Rosemary's Baby
            "What have you done to Windows 10, YOU MANIACS?!", // Rosemary's Baby
            "Windows 10 is a sign of the End Times.",
            "Satan came up from Hell and slept with Microsoft!",
            "Seems like Cain's DNA has survived the great deluge.",
            "CodeImp should've seen Rev. Bob Larson in 2003!",
            "Windows 10's launch fulfills Bible prophecy!",
            "Nimrod and Semiramis have paved the road of Microsoft.",
            "God gave Microsoft over to a reprobate mind!", // Romans 1 (AKJV)
            "Thick lead walls surround the vaults of Redmond.", // 
            "Satan is her father, and her name is Cortana!", // Rosemary's Baby
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            ""
        };

        this.new_windowtitle = candidates[new Random().Next(0,candidates.Length-1)];
    }

    public WindowTitleSubstitute(string old_title) {
        // Back up old window title.
        this.old_windowtitle=old_title;
    }

    public string restore_oldtitle() {
        return this.old_windowtitle;
    }

    #endregion
}

}