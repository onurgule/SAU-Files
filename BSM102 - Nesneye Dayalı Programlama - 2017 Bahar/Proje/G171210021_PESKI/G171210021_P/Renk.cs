using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace G171210021_P
{
    static class Renk
    {
        public static System.Drawing.Color RenkGetir(object sender, GroupBox gbRenkler)
        {
            System.Drawing.Color secilenRenk = System.Drawing.Color.Red;
            foreach (var item in gbRenkler.Controls.OfType<PictureBox>())
            {
                ((System.Windows.Forms.PictureBox)item).BorderStyle = BorderStyle.None;
            }
            ((System.Windows.Forms.PictureBox)sender).BorderStyle = BorderStyle.Fixed3D;
            switch (((System.Windows.Forms.PictureBox)sender).Name)
            {
                case "renkKirmizi":
                    secilenRenk = Color.Red;
                    break;
                case "renkMavi":
                    secilenRenk = Color.Blue;
                    break;
                case "renkYesil":
                    secilenRenk = Color.Green;
                    break;
                case "renkTuruncu":
                    secilenRenk = Color.Orange;
                    break;
                case "renkSiyah":
                    secilenRenk = Color.Black;
                    break;
                case "renkSari":
                    secilenRenk = Color.Yellow;
                    break;
                case "renkMor":
                    secilenRenk = Color.Purple;
                    break;
                case "renkKahve":
                    secilenRenk = Color.Brown;
                    break;
                case "renkBeyaz":
                    secilenRenk = Color.White;
                    break;
                default:
                    break;
            }
            return secilenRenk;
        }
        public static renkler renkHangiSayi(Color color)
        {
            if (color == Color.Red) return renkler.Kirmizi;
            else if (color == Color.Blue) return renkler.Mavi;
            else if (color == Color.Green) return renkler.Yesil;
            else if (color == Color.Orange) return renkler.Turuncu;
            else if (color == Color.Black) return renkler.Siyah;
            else if (color == Color.Yellow) return renkler.Sari;
            else if (color == Color.Purple) return renkler.Mor;
            else if (color == Color.Brown) return renkler.Kahve;
            else if (color == Color.White) return renkler.Beyaz;
            else return renkler.Kirmizi;

        }
        public static Color sayiHangiRenk(renkler renk)
        {
            if (renk == renkler.Kirmizi) return Color.Red;
            else if (renk == renkler.Mavi) return Color.Blue;
            else if (renk == renkler.Yesil) return Color.Green;
            else if (renk == renkler.Turuncu) return Color.Orange;
            else if (renk == renkler.Siyah) return Color.Black;
            else if (renk == renkler.Sari) return Color.Yellow;
            else if (renk == renkler.Mor) return Color.Purple;
            else if (renk == renkler.Kahve) return Color.Brown;
            else if (renk == renkler.Beyaz) return Color.White;
            else return Color.Red;
        }
    }
}
