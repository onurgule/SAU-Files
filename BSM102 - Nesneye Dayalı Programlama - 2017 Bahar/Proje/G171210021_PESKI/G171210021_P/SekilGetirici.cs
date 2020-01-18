using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace G171210021_P
{
    static class SekilGetirici
    {
        static string name = "sekilKare";
        public static Sekil SekilGetir(object sender, System.Windows.Forms.GroupBox gbSekil, Color renk)
        {
            foreach (var sekil in gbSekil.Controls.OfType<System.Windows.Forms.PictureBox>())
            {
                ((System.Windows.Forms.PictureBox)sekil).BorderStyle = System.Windows.Forms.BorderStyle.None;
            }
            ((System.Windows.Forms.PictureBox)sender).BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            switch (((System.Windows.Forms.PictureBox)sender).Name)
            {
                case "sekilKare":
                    name = "sekilKare";
                    return new Dikdortgen(renk);
                case "sekilDaire":
                    name = "sekilDaire";
                    return new Daire(renk);
                case "sekilUcgen":
                    name = "sekilUcgen";
                    return new Ucgen(renk);
                case "sekilAltigen":
                    name = "sekilAltigen";
                    return new Altigen(renk);
                default:
                    name = "sekilKare";
                    return new Dikdortgen(renk);
            }
        }
        public static Sekil SekilGetir(Color renk)
        {
            switch (name)
            {
                case "sekilKare":
                    return new Dikdortgen(renk);
                case "sekilDaire":
                    return new Daire(renk);
                case "sekilUcgen":
                    return new Ucgen(renk);
                case "sekilAltigen":
                    return new Altigen(renk);
                default:
                    return new Dikdortgen(renk);
            }
        }
    }
}
