namespace G171210021_P
{
    partial class frmAna
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmAna));
            this.panel = new System.Windows.Forms.Panel();
            this.gbSekil = new System.Windows.Forms.GroupBox();
            this.sekilAltigen = new System.Windows.Forms.PictureBox();
            this.sekilUcgen = new System.Windows.Forms.PictureBox();
            this.sekilDaire = new System.Windows.Forms.PictureBox();
            this.sekilKare = new System.Windows.Forms.PictureBox();
            this.gbRenkler = new System.Windows.Forms.GroupBox();
            this.renkBeyaz = new System.Windows.Forms.PictureBox();
            this.renkKahve = new System.Windows.Forms.PictureBox();
            this.renkMor = new System.Windows.Forms.PictureBox();
            this.renkSari = new System.Windows.Forms.PictureBox();
            this.renkSiyah = new System.Windows.Forms.PictureBox();
            this.renkTuruncu = new System.Windows.Forms.PictureBox();
            this.renkYesil = new System.Windows.Forms.PictureBox();
            this.renkMavi = new System.Windows.Forms.PictureBox();
            this.renkKirmizi = new System.Windows.Forms.PictureBox();
            this.gbSecim = new System.Windows.Forms.GroupBox();
            this.secimSil = new System.Windows.Forms.PictureBox();
            this.secimSec = new System.Windows.Forms.PictureBox();
            this.gbDosya = new System.Windows.Forms.GroupBox();
            this.dosyaKaydet = new System.Windows.Forms.PictureBox();
            this.dosyaAc = new System.Windows.Forms.PictureBox();
            this.gbSekil.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.sekilAltigen)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.sekilUcgen)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.sekilDaire)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.sekilKare)).BeginInit();
            this.gbRenkler.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.renkBeyaz)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.renkKahve)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.renkMor)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.renkSari)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.renkSiyah)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.renkTuruncu)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.renkYesil)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.renkMavi)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.renkKirmizi)).BeginInit();
            this.gbSecim.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.secimSil)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.secimSec)).BeginInit();
            this.gbDosya.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dosyaKaydet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dosyaAc)).BeginInit();
            this.SuspendLayout();
            // 
            // panel
            // 
            this.panel.BackColor = System.Drawing.SystemColors.ControlDark;
            this.panel.Cursor = System.Windows.Forms.Cursors.Cross;
            this.panel.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.panel.Location = new System.Drawing.Point(8, 8);
            this.panel.Name = "panel";
            this.panel.Size = new System.Drawing.Size(690, 488);
            this.panel.TabIndex = 0;
            this.panel.MouseDown += new System.Windows.Forms.MouseEventHandler(this.panel_MouseDown);
            this.panel.MouseMove += new System.Windows.Forms.MouseEventHandler(this.panel_MouseMove);
            this.panel.MouseUp += new System.Windows.Forms.MouseEventHandler(this.panel_MouseUp);
            // 
            // gbSekil
            // 
            this.gbSekil.Controls.Add(this.sekilAltigen);
            this.gbSekil.Controls.Add(this.sekilUcgen);
            this.gbSekil.Controls.Add(this.sekilDaire);
            this.gbSekil.Controls.Add(this.sekilKare);
            this.gbSekil.Location = new System.Drawing.Point(707, 12);
            this.gbSekil.Name = "gbSekil";
            this.gbSekil.Size = new System.Drawing.Size(177, 152);
            this.gbSekil.TabIndex = 1;
            this.gbSekil.TabStop = false;
            this.gbSekil.Text = "Şekiller";
            // 
            // sekilAltigen
            // 
            this.sekilAltigen.Image = global::G171210021_P.Properties.Resources.altigen;
            this.sekilAltigen.Location = new System.Drawing.Point(100, 93);
            this.sekilAltigen.Name = "sekilAltigen";
            this.sekilAltigen.Size = new System.Drawing.Size(71, 53);
            this.sekilAltigen.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.sekilAltigen.TabIndex = 3;
            this.sekilAltigen.TabStop = false;
            this.sekilAltigen.Click += new System.EventHandler(this.sekil_Click);
            // 
            // sekilUcgen
            // 
            this.sekilUcgen.Image = global::G171210021_P.Properties.Resources.ucgen;
            this.sekilUcgen.Location = new System.Drawing.Point(6, 93);
            this.sekilUcgen.Name = "sekilUcgen";
            this.sekilUcgen.Size = new System.Drawing.Size(71, 53);
            this.sekilUcgen.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.sekilUcgen.TabIndex = 2;
            this.sekilUcgen.TabStop = false;
            this.sekilUcgen.Click += new System.EventHandler(this.sekil_Click);
            // 
            // sekilDaire
            // 
            this.sekilDaire.Image = global::G171210021_P.Properties.Resources.daire;
            this.sekilDaire.Location = new System.Drawing.Point(100, 21);
            this.sekilDaire.Name = "sekilDaire";
            this.sekilDaire.Size = new System.Drawing.Size(71, 53);
            this.sekilDaire.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.sekilDaire.TabIndex = 1;
            this.sekilDaire.TabStop = false;
            this.sekilDaire.Click += new System.EventHandler(this.sekil_Click);
            // 
            // sekilKare
            // 
            this.sekilKare.BackColor = System.Drawing.SystemColors.Control;
            this.sekilKare.Image = global::G171210021_P.Properties.Resources.kare;
            this.sekilKare.Location = new System.Drawing.Point(6, 21);
            this.sekilKare.Name = "sekilKare";
            this.sekilKare.Size = new System.Drawing.Size(71, 53);
            this.sekilKare.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.sekilKare.TabIndex = 0;
            this.sekilKare.TabStop = false;
            this.sekilKare.Click += new System.EventHandler(this.sekil_Click);
            // 
            // gbRenkler
            // 
            this.gbRenkler.Controls.Add(this.renkBeyaz);
            this.gbRenkler.Controls.Add(this.renkKahve);
            this.gbRenkler.Controls.Add(this.renkMor);
            this.gbRenkler.Controls.Add(this.renkSari);
            this.gbRenkler.Controls.Add(this.renkSiyah);
            this.gbRenkler.Controls.Add(this.renkTuruncu);
            this.gbRenkler.Controls.Add(this.renkYesil);
            this.gbRenkler.Controls.Add(this.renkMavi);
            this.gbRenkler.Controls.Add(this.renkKirmizi);
            this.gbRenkler.Location = new System.Drawing.Point(707, 170);
            this.gbRenkler.Name = "gbRenkler";
            this.gbRenkler.Size = new System.Drawing.Size(177, 142);
            this.gbRenkler.TabIndex = 4;
            this.gbRenkler.TabStop = false;
            this.gbRenkler.Text = "Renkler";
            // 
            // renkBeyaz
            // 
            this.renkBeyaz.BackColor = System.Drawing.Color.White;
            this.renkBeyaz.Location = new System.Drawing.Point(122, 95);
            this.renkBeyaz.Name = "renkBeyaz";
            this.renkBeyaz.Size = new System.Drawing.Size(36, 31);
            this.renkBeyaz.TabIndex = 8;
            this.renkBeyaz.TabStop = false;
            this.renkBeyaz.Click += new System.EventHandler(this.renk_Click);
            // 
            // renkKahve
            // 
            this.renkKahve.BackColor = System.Drawing.Color.Brown;
            this.renkKahve.Location = new System.Drawing.Point(71, 95);
            this.renkKahve.Name = "renkKahve";
            this.renkKahve.Size = new System.Drawing.Size(36, 31);
            this.renkKahve.TabIndex = 7;
            this.renkKahve.TabStop = false;
            this.renkKahve.Click += new System.EventHandler(this.renk_Click);
            // 
            // renkMor
            // 
            this.renkMor.BackColor = System.Drawing.Color.Purple;
            this.renkMor.Location = new System.Drawing.Point(20, 95);
            this.renkMor.Name = "renkMor";
            this.renkMor.Size = new System.Drawing.Size(36, 31);
            this.renkMor.TabIndex = 6;
            this.renkMor.TabStop = false;
            this.renkMor.Click += new System.EventHandler(this.renk_Click);
            // 
            // renkSari
            // 
            this.renkSari.BackColor = System.Drawing.Color.Yellow;
            this.renkSari.Location = new System.Drawing.Point(122, 58);
            this.renkSari.Name = "renkSari";
            this.renkSari.Size = new System.Drawing.Size(36, 31);
            this.renkSari.TabIndex = 5;
            this.renkSari.TabStop = false;
            this.renkSari.Click += new System.EventHandler(this.renk_Click);
            // 
            // renkSiyah
            // 
            this.renkSiyah.BackColor = System.Drawing.Color.Black;
            this.renkSiyah.Location = new System.Drawing.Point(71, 58);
            this.renkSiyah.Name = "renkSiyah";
            this.renkSiyah.Size = new System.Drawing.Size(36, 31);
            this.renkSiyah.TabIndex = 4;
            this.renkSiyah.TabStop = false;
            this.renkSiyah.Click += new System.EventHandler(this.renk_Click);
            // 
            // renkTuruncu
            // 
            this.renkTuruncu.BackColor = System.Drawing.Color.Orange;
            this.renkTuruncu.Location = new System.Drawing.Point(20, 58);
            this.renkTuruncu.Name = "renkTuruncu";
            this.renkTuruncu.Size = new System.Drawing.Size(36, 31);
            this.renkTuruncu.TabIndex = 3;
            this.renkTuruncu.TabStop = false;
            this.renkTuruncu.Click += new System.EventHandler(this.renk_Click);
            // 
            // renkYesil
            // 
            this.renkYesil.BackColor = System.Drawing.Color.Green;
            this.renkYesil.Location = new System.Drawing.Point(122, 21);
            this.renkYesil.Name = "renkYesil";
            this.renkYesil.Size = new System.Drawing.Size(36, 31);
            this.renkYesil.TabIndex = 2;
            this.renkYesil.TabStop = false;
            this.renkYesil.Click += new System.EventHandler(this.renk_Click);
            // 
            // renkMavi
            // 
            this.renkMavi.BackColor = System.Drawing.Color.Blue;
            this.renkMavi.Location = new System.Drawing.Point(71, 21);
            this.renkMavi.Name = "renkMavi";
            this.renkMavi.Size = new System.Drawing.Size(36, 31);
            this.renkMavi.TabIndex = 1;
            this.renkMavi.TabStop = false;
            this.renkMavi.Click += new System.EventHandler(this.renk_Click);
            // 
            // renkKirmizi
            // 
            this.renkKirmizi.BackColor = System.Drawing.Color.Red;
            this.renkKirmizi.Location = new System.Drawing.Point(20, 21);
            this.renkKirmizi.Name = "renkKirmizi";
            this.renkKirmizi.Size = new System.Drawing.Size(36, 31);
            this.renkKirmizi.TabIndex = 0;
            this.renkKirmizi.TabStop = false;
            this.renkKirmizi.Click += new System.EventHandler(this.renk_Click);
            // 
            // gbSecim
            // 
            this.gbSecim.Controls.Add(this.secimSil);
            this.gbSecim.Controls.Add(this.secimSec);
            this.gbSecim.Location = new System.Drawing.Point(707, 318);
            this.gbSecim.Name = "gbSecim";
            this.gbSecim.Size = new System.Drawing.Size(177, 86);
            this.gbSecim.TabIndex = 5;
            this.gbSecim.TabStop = false;
            this.gbSecim.Text = "Seçim İşlemleri";
            // 
            // secimSil
            // 
            this.secimSil.Image = global::G171210021_P.Properties.Resources.bin;
            this.secimSil.Location = new System.Drawing.Point(100, 21);
            this.secimSil.Name = "secimSil";
            this.secimSil.Size = new System.Drawing.Size(71, 53);
            this.secimSil.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.secimSil.TabIndex = 5;
            this.secimSil.TabStop = false;
            this.secimSil.Click += new System.EventHandler(this.secimSil_Click);
            // 
            // secimSec
            // 
            this.secimSec.Image = global::G171210021_P.Properties.Resources.secim;
            this.secimSec.Location = new System.Drawing.Point(6, 21);
            this.secimSec.Name = "secimSec";
            this.secimSec.Size = new System.Drawing.Size(71, 53);
            this.secimSec.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.secimSec.TabIndex = 4;
            this.secimSec.TabStop = false;
            this.secimSec.Click += new System.EventHandler(this.secimSec_Click);
            // 
            // gbDosya
            // 
            this.gbDosya.Controls.Add(this.dosyaKaydet);
            this.gbDosya.Controls.Add(this.dosyaAc);
            this.gbDosya.Location = new System.Drawing.Point(707, 410);
            this.gbDosya.Name = "gbDosya";
            this.gbDosya.Size = new System.Drawing.Size(177, 86);
            this.gbDosya.TabIndex = 6;
            this.gbDosya.TabStop = false;
            this.gbDosya.Text = "Dosya İşlemleri";
            // 
            // dosyaKaydet
            // 
            this.dosyaKaydet.Image = global::G171210021_P.Properties.Resources.kaydet;
            this.dosyaKaydet.Location = new System.Drawing.Point(100, 21);
            this.dosyaKaydet.Name = "dosyaKaydet";
            this.dosyaKaydet.Size = new System.Drawing.Size(71, 53);
            this.dosyaKaydet.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.dosyaKaydet.TabIndex = 5;
            this.dosyaKaydet.TabStop = false;
            this.dosyaKaydet.Click += new System.EventHandler(this.dosyaKaydet_Click);
            // 
            // dosyaAc
            // 
            this.dosyaAc.Image = global::G171210021_P.Properties.Resources.dosyaac;
            this.dosyaAc.Location = new System.Drawing.Point(6, 21);
            this.dosyaAc.Name = "dosyaAc";
            this.dosyaAc.Size = new System.Drawing.Size(71, 53);
            this.dosyaAc.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.dosyaAc.TabIndex = 4;
            this.dosyaAc.TabStop = false;
            this.dosyaAc.Click += new System.EventHandler(this.dosyaAc_Click);
            // 
            // frmAna
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(896, 512);
            this.Controls.Add(this.gbDosya);
            this.Controls.Add(this.gbSecim);
            this.Controls.Add(this.gbRenkler);
            this.Controls.Add(this.gbSekil);
            this.Controls.Add(this.panel);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "frmAna";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "G171210021 - Çizim Uygulaması";
            this.Load += new System.EventHandler(this.frmAna_Load);
            this.gbSekil.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.sekilAltigen)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.sekilUcgen)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.sekilDaire)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.sekilKare)).EndInit();
            this.gbRenkler.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.renkBeyaz)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.renkKahve)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.renkMor)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.renkSari)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.renkSiyah)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.renkTuruncu)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.renkYesil)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.renkMavi)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.renkKirmizi)).EndInit();
            this.gbSecim.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.secimSil)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.secimSec)).EndInit();
            this.gbDosya.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dosyaKaydet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dosyaAc)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panel;
        public System.Windows.Forms.GroupBox gbSekil;
        public System.Windows.Forms.PictureBox sekilAltigen;
        public System.Windows.Forms.PictureBox sekilUcgen;
        public System.Windows.Forms.PictureBox sekilDaire;
        public System.Windows.Forms.PictureBox sekilKare;
        public System.Windows.Forms.GroupBox gbRenkler;
        public System.Windows.Forms.PictureBox renkBeyaz;
        public System.Windows.Forms.PictureBox renkKahve;
        public System.Windows.Forms.PictureBox renkMor;
        public System.Windows.Forms.PictureBox renkSari;
        public System.Windows.Forms.PictureBox renkSiyah;
        public System.Windows.Forms.PictureBox renkTuruncu;
        public System.Windows.Forms.PictureBox renkYesil;
        public System.Windows.Forms.PictureBox renkMavi;
        public System.Windows.Forms.PictureBox renkKirmizi;
        public System.Windows.Forms.GroupBox gbSecim;
        public System.Windows.Forms.PictureBox secimSil;
        public System.Windows.Forms.PictureBox secimSec;
        public System.Windows.Forms.GroupBox gbDosya;
        public System.Windows.Forms.PictureBox dosyaKaydet;
        public System.Windows.Forms.PictureBox dosyaAc;
    }
}

