using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace G171210021_P
{
    class GrafikIslemci
    {
        Panel panel;
        Point ana;
        public List<Sekil> tumSekiller = new List<Sekil>();
        Point? bas = null;
        PaintEventHandler secimHandler { get; set; } //sadece 1 tane olabilir.
        bool mousedown = false;
        public Sekil _mouseSecilenSekil { get; set; } //private
        public Color SecilenRenk { get; set; }
        public Sekil CizilenSekil { get; set; }

        public int Islem { get; set; } // çizim:0, seçim:1
        public GrafikIslemci(Panel panel)
        {
            this.panel = panel;
            Sinir.sinirlar.Add(panel.Width);
            Sinir.sinirlar.Add(0);
            Sinir.sinirlar.Add(0);
            Sinir.sinirlar.Add(panel.Height);
            panel.Paint += new PaintEventHandler(genelCizim);
        }
        private void genelCizim(object sender, PaintEventArgs e)
        {
            foreach (var sekil in tumSekiller)
            {
                sekil.Ciz(e);
            }
            if (CizilenSekil != null && mousedown == true)
                CizilenSekil.Ciz(e, bas, ana);


        }
        public void FareOynat(MouseEventArgs e)
        {
            if (!mousedown) return;
            if (Islem != 0) return;
            ana = e.Location;
            Sinir.SinirCek(ref ana);
            
            //panel.Paint += new PaintEventHandler(genelCizim);
            //panel.Refresh();
            panel.Invalidate();
        }
        public void FareCek(MouseEventArgs e)
        {
            if (Islem == 0 && CizilenSekil != null)
            {
                //CizilenSekil.SekilYerGoster(bas.Value, ana.X, ana.Y); //ana->e
                tumSekiller.Add(CizilenSekil);
                //CizilenSekil = SekilGetirici.SekilGetir(SecilenRenk);
                CizilenSekil = null;
                mousedown = false;
            }
            else if (Islem == 1)
            {

            }
        }
        public void FareBas(MouseEventArgs e)
        {
            if (Islem == 0)
            {
                mousedown = true;
                CizilenSekil = SekilGetirici.SekilGetir(SecilenRenk);
                bas = e.Location;
            }
            else if (Islem == 1)
            {

                foreach (var sekil in tumSekiller)
                {

                    if (sekil.icindeMi(new Point(e.X, e.Y)))
                    {
                        if (secimHandler != null) panel.Paint -= secimHandler;
                        secimHandler = sekil.Sec(panel);
                        _mouseSecilenSekil = sekil;
                    }
                    else { continue; }
                }
            }
        }
        public void SekliSil()
        {
            tumSekiller.Remove(_mouseSecilenSekil);
            if (secimHandler != null) panel.Paint -= secimHandler;
            _mouseSecilenSekil = null;
            //panel.Paint += new PaintEventHandler(genelCizim);
            //panel.Refresh();
            panel.Invalidate();
        }
        public void IslemDegistir(int islem)
        {
            Islem = islem;
            if (Islem == 0)
            {
                if (secimHandler != null) panel.Paint -= secimHandler;
            }
            else if (Islem == 1)
            {
                if (secimHandler != null) panel.Paint -= secimHandler;
                _mouseSecilenSekil = null;
                GroupBox gbSekil = (GroupBox)frmAna.ActiveForm.Controls.Find("gbSekil", false).FirstOrDefault();
                foreach (var sekil in gbSekil.Controls.OfType<System.Windows.Forms.PictureBox>())
                {
                    ((System.Windows.Forms.PictureBox)sekil).BorderStyle = System.Windows.Forms.BorderStyle.None;
                }
                GroupBox gbRenk = (GroupBox)frmAna.ActiveForm.Controls.Find("gbRenkler", false).FirstOrDefault();
                foreach (var sekil in gbRenk.Controls.OfType<System.Windows.Forms.PictureBox>())
                {
                    ((System.Windows.Forms.PictureBox)sekil).BorderStyle = System.Windows.Forms.BorderStyle.None;
                }
            }
        }
        public void RenkDegistir(object sender, GroupBox gb)
        {
            SecilenRenk = Renk.RenkGetir(sender, gb);
            if (CizilenSekil == null) CizilenSekil = SekilGetirici.SekilGetir(SecilenRenk);
            if (Islem == 0)
            {
                if (CizilenSekil != null)
                    CizilenSekil.RenkDegistir(SecilenRenk);
            }
            else if (Islem == 1)
                if (_mouseSecilenSekil != null)
                {
                    _mouseSecilenSekil.RenkDegistir(SecilenRenk);
                    /*
                     Yenile();*/
                    //panel.Paint += new PaintEventHandler(genelCizim);
                    //panel.Refresh();
                    panel.Invalidate();
                }
        }
        public void listeCizimi(List<Sekil> liste)
        {
            tumSekiller = liste;
            //panel.Paint += new PaintEventHandler(genelCizim);
            //panel.Refresh();
            panel.Invalidate();
        }
    }
    public static class Sinir{
        public static List<int> sinirlar = new List<int>();
        public static bool Tasmadi(PointF p)
        {
            bool tasmadi = true;
            if (p.X >= Sinir.sinirlar[0]) tasmadi = false;
            if (p.X <= Sinir.sinirlar[1]) tasmadi = false;
            if (p.Y <= Sinir.sinirlar[2]) tasmadi = false;
            if (p.Y >= Sinir.sinirlar[3]) tasmadi = false;
            return tasmadi;
        }
        public static void SinirCek(ref Point p)
        {
            if (p.X >= Sinir.sinirlar[0]) p.X = Sinir.sinirlar[0];
            if (p.X <= Sinir.sinirlar[1]) p.X = Sinir.sinirlar[1];
            if (p.Y <= Sinir.sinirlar[2]) p.Y = Sinir.sinirlar[2];
            if (p.Y >= Sinir.sinirlar[3]) p.Y = Sinir.sinirlar[3];
        }
        public static void SinirCek(ref PointF p)
        {
            if (p.X >= Sinir.sinirlar[0]) p.X = Sinir.sinirlar[0];
            if (p.X <= Sinir.sinirlar[1]) p.X = Sinir.sinirlar[1];
            if (p.Y <= Sinir.sinirlar[2]) p.Y = Sinir.sinirlar[2];
            if (p.Y >= Sinir.sinirlar[3]) p.Y = Sinir.sinirlar[3];
        }
        public static void SinirCek(ref int nokta, bool xMi)
        {
            if (xMi)
            {
                //X'tir.
                if (nokta >= Sinir.sinirlar[0]) nokta = Sinir.sinirlar[0];
                if (nokta <= Sinir.sinirlar[1]) nokta = Sinir.sinirlar[1];
            }
            else
            {
                if (nokta <= Sinir.sinirlar[2]) nokta = Sinir.sinirlar[2];
                if (nokta >= Sinir.sinirlar[3]) nokta = Sinir.sinirlar[3]; //Y'dir.
            }
        }
        public static void SinirCek(ref int noktaX, ref int noktaY)
        {
            
                if (noktaX >= Sinir.sinirlar[0]) noktaX = Sinir.sinirlar[0];
                if (noktaX <= Sinir.sinirlar[1]) noktaX = Sinir.sinirlar[1];
            
                if (noktaY <= Sinir.sinirlar[2]) noktaY = Sinir.sinirlar[2];
                if (noktaY >= Sinir.sinirlar[3]) noktaY = Sinir.sinirlar[3]; 
            
        }
    }
}
