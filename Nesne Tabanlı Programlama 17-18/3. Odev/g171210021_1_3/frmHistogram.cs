using Emgu.CV;
using Emgu.CV.Structure;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace g171210021_1_3
{
    public partial class frmHistogram : Form
    {
        public frmHistogram()
        {
            InitializeComponent();
        }
        public Image<Gray, Byte> resim;
        private void frmHistogram_Load(object sender, EventArgs e)
        {
            if (resim != null)
            {
                DenseHistogram Histo = new DenseHistogram(255, new RangeF(0, 255));
                histogramBox.ClearHistogram();
                histogramBox.GenerateHistograms(resim, 8);
                histogramBox.Refresh();
            }
            else this.Close();
        }
    }
}
