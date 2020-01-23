/* [gdm413229] X Logical Font Description helper class */

using System;

namespace CodeImp.DoomBuilder.G4_XmUI {

internal sealed class XLFD {
    /* An X logical font description describes a font's producer, name, styling, sizes, spacing and
     * encoding. Motif (libXm) uses these for font rendering. */

    /* As an example, Segoe UI's XLFD is :
     * "-microsoft-segoe ui-medium-*-*-*-*-*-96-96-p-*-iso10646-*" */

    #region Fields and Properties

    string foundry_name;
    string family_name;
    string weight;
    string slant;
    string set_width;
    string add_style;
    string pix_siz_str;
    string point_siz_str;
    string dpi_str;
    string spacing;
    string avg_width_str;
    string registry;
    string encoding;

    uint pix_siz;
    uint point_siz;
    uint dpi;
    uint avg_width;

    #endregion

    #region Methods

    private void refresh_XLFD_strings() {
        if(this.pix_siz==0) {
            this.pix_siz_str = "*";
        }
        else {
            this.pix_siz_str = this.pix_siz.ToString();
        }
        if(this.point_siz==0) {
            this.point_siz_str = "*";
        }
        else {
            this.point_siz_str = this.point_siz.ToString();
        }
        if(this.dpi==0) {
            this.dpi_str = "*";
        }
        else {
            this.dpi_str = this.dpi.ToString();
        }
        if(this.avg_width==0) {
            this.avg_width_str = "*";
        }
        else {
            this.avg_width_str = this.avg_width.ToString();
        }
    }

    public XLFD(string foundry,string family,string wght,string slant,string swdth,
                string adstyl,uint pxlsiz,uint ptsz,uint dpi,
                string spc,uint avgwdth,string rgstry,string encdng) {
                    // Fills in the XLFD's fields.
                    this.foundry_name = foundry;
                    this.family_name = family;
                    this.weight = wght;
                    this.slant=slant;
                    this.set_width=swdth;
                    this.add_style=adstyl;
                    this.pix_siz=pxlsiz;
                    this.point_siz=ptsz;
                    this.dpi=dpi;
                    this.spacing=spc;
                    this.avg_width=avgwdth;
                    this.registry=rgstry;
                    this.encoding=encdng;
                }
    public string generate_full_XLFD() {
        string final_str;
        string xlfd_separator="-"; // XLFD's use minuses as separators.
        final_str = xlfd_separator+this.foundry_name;
        final_str += xlfd_separator+this.family_name;
        final_str += xlfd_separator+this.weight;
        final_str += xlfd_separator+this.slant;
        final_str += xlfd_separator+this.add_style;
        final_str += xlfd_separator+this.pix_siz_str;
        final_str += xlfd_separator+this.point_siz_str;
        final_str += xlfd_separator+this.dpi_str;
        final_str += xlfd_separator+this.dpi_str;
        final_str += xlfd_separator+this.spacing;
        final_str += xlfd_separator+this.avg_width_str;
        final_str += xlfd_separator+this.registry;
        final_str += xlfd_separator+this.encoding;
        return final_str;
    }

    #endregion
}

}