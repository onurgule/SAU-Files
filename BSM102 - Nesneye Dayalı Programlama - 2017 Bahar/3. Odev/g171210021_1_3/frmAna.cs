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
    public partial class frmMain : Form
    {
        public frmMain()
        {
            InitializeComponent();
        }
        void butonaktif(bool aktif)
        {
                btn_rgbto8bit.Enabled = aktif;
                btn_greytobin.Enabled = aktif;
                btn_greyhistorgram.Enabled = aktif;
            if (!aktif) pb_Resim.Image = null;
        }
        OpenFileDialog op = new OpenFileDialog();
        private void btn_resimYukle_Click(object sender, EventArgs e)
        {
            try
            {
                if (op.ShowDialog() == DialogResult.OK)
                {
                    Image<Bgr, Byte> resim = new Image<Bgr, byte>(op.FileName);
                    pb_Resim.Image = resim.ToBitmap();
                    butonaktif(true);
                }
            }
            catch (Exception a) { MessageBox.Show("Bir sorun oluştu, lütfen tekrar deneyiniz..."); butonaktif(false); }
        }

        private void btn_rgbto8bit_Click(object sender, EventArgs e)
        {
            try
            {
                if (op.FileName != null)
                {
                    Image<Gray, Byte> resim = new Image<Gray, byte>(op.FileName);
                    pb_Resim.Image = resim.ToBitmap();
                    butonaktif(true);
                }
            }
            catch (Exception a) { MessageBox.Show("Bir sorun oluştu, lütfen tekrar deneyiniz..."); butonaktif(false); }
        }

        private void btn_greyhistorgram_Click(object sender, EventArgs e)
        {
            frmHistogram histo = new frmHistogram();
            Image<Gray, Byte> resim = new Image<Gray, byte>(op.FileName);
            histo.resim = resim;
            histo.ShowDialog();
        }

        private void btn_greytobin_Click(object sender, EventArgs e)
        {
             try
            {
                if (op.FileName != null)
                {
                    Image<Gray, Byte> resim = new Image<Gray, byte>(op.FileName);
                    pb_Resim.Image = resim.Convert<Gray, byte>().ThresholdBinary(new Gray(80), new Gray(255)).ToBitmap();
                    butonaktif(true);
                }
            }
            catch (Exception a) { MessageBox.Show("Bir sorun oluştu, lütfen tekrar deneyiniz..."); butonaktif(false); }
        }
    }
}
