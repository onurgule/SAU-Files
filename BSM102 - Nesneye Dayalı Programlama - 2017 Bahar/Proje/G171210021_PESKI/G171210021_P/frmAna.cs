using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace G171210021_P
{
    public partial class frmAna : Form
    {
        GrafikIslemci grafikIslemci;
        public frmAna()
        {
            DoubleBuffered = true;
            InitializeComponent();
            grafikIslemci = new GrafikIslemci(panel);
            
        }

        private void frmAna_Load(object sender, EventArgs e)
        {
        }
        private void sekil_Click(object sender, EventArgs e)
        {
            grafikIslemci.CizilenSekil = SekilGetirici.SekilGetir(sender, gbSekil,grafikIslemci.SecilenRenk);
            grafikIslemci.IslemDegistir(0);
        }
        private void renk_Click(object sender, EventArgs e)
        {
            grafikIslemci.RenkDegistir(sender, gbRenkler);
            Invalidate();
            
        }
        private void panel_MouseMove(object sender, MouseEventArgs e)
        {
            grafikIslemci.FareOynat(e);
            Invalidate();
        }
       
        private void panel_MouseUp(object sender, MouseEventArgs e)
        {
            grafikIslemci.FareCek(e);
        }

        private void panel_MouseDown(object sender, MouseEventArgs e)
        {
            grafikIslemci.FareBas(e);
        }

        private void secimSec_Click(object sender, EventArgs e)
        {
            grafikIslemci.IslemDegistir(1);
        }

        private void secimSil_Click(object sender, EventArgs e)
        {
            grafikIslemci.SekliSil();
            Invalidate();
        }

        private void dosyaKaydet_Click(object sender, EventArgs e)
        {
            DosyaIslemleri.DosyaIndir(grafikIslemci.tumSekiller);
        }

        private void dosyaAc_Click(object sender, EventArgs e)
        {
            grafikIslemci.listeCizimi(DosyaIslemleri.DosyaIsle());
            Invalidate();
        }

    }
}
