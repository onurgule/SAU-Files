namespace g171210021_1_3
{
    partial class frmMain
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmMain));
            this.btn_resimYukle = new System.Windows.Forms.Button();
            this.btn_rgbto8bit = new System.Windows.Forms.Button();
            this.btn_greyhistorgram = new System.Windows.Forms.Button();
            this.btn_greytobin = new System.Windows.Forms.Button();
            this.pb_Resim = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.pb_Resim)).BeginInit();
            this.SuspendLayout();
            // 
            // btn_resimYukle
            // 
            this.btn_resimYukle.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.btn_resimYukle.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F);
            this.btn_resimYukle.Location = new System.Drawing.Point(24, 292);
            this.btn_resimYukle.Name = "btn_resimYukle";
            this.btn_resimYukle.Size = new System.Drawing.Size(175, 102);
            this.btn_resimYukle.TabIndex = 0;
            this.btn_resimYukle.Text = "Resim Yükle";
            this.btn_resimYukle.UseVisualStyleBackColor = true;
            this.btn_resimYukle.Click += new System.EventHandler(this.btn_resimYukle_Click);
            // 
            // btn_rgbto8bit
            // 
            this.btn_rgbto8bit.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.btn_rgbto8bit.Enabled = false;
            this.btn_rgbto8bit.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.btn_rgbto8bit.Location = new System.Drawing.Point(265, 293);
            this.btn_rgbto8bit.Name = "btn_rgbto8bit";
            this.btn_rgbto8bit.Size = new System.Drawing.Size(175, 102);
            this.btn_rgbto8bit.TabIndex = 1;
            this.btn_rgbto8bit.Text = "RGB -> 8Bit";
            this.btn_rgbto8bit.UseVisualStyleBackColor = true;
            this.btn_rgbto8bit.Click += new System.EventHandler(this.btn_rgbto8bit_Click);
            // 
            // btn_greyhistorgram
            // 
            this.btn_greyhistorgram.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.btn_greyhistorgram.Enabled = false;
            this.btn_greyhistorgram.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.btn_greyhistorgram.Location = new System.Drawing.Point(446, 293);
            this.btn_greyhistorgram.Name = "btn_greyhistorgram";
            this.btn_greyhistorgram.Size = new System.Drawing.Size(175, 102);
            this.btn_greyhistorgram.TabIndex = 2;
            this.btn_greyhistorgram.Text = "Gri Image Histogram";
            this.btn_greyhistorgram.UseVisualStyleBackColor = true;
            this.btn_greyhistorgram.Click += new System.EventHandler(this.btn_greyhistorgram_Click);
            // 
            // btn_greytobin
            // 
            this.btn_greytobin.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.btn_greytobin.Enabled = false;
            this.btn_greytobin.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.btn_greytobin.Location = new System.Drawing.Point(627, 292);
            this.btn_greytobin.Name = "btn_greytobin";
            this.btn_greytobin.Size = new System.Drawing.Size(175, 102);
            this.btn_greytobin.TabIndex = 3;
            this.btn_greytobin.Text = "Gri Image -> Binary Image";
            this.btn_greytobin.UseVisualStyleBackColor = true;
            this.btn_greytobin.Click += new System.EventHandler(this.btn_greytobin_Click);
            // 
            // pb_Resim
            // 
            this.pb_Resim.Location = new System.Drawing.Point(24, 13);
            this.pb_Resim.Name = "pb_Resim";
            this.pb_Resim.Size = new System.Drawing.Size(778, 260);
            this.pb_Resim.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pb_Resim.TabIndex = 4;
            this.pb_Resim.TabStop = false;
            // 
            // frmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(827, 407);
            this.Controls.Add(this.pb_Resim);
            this.Controls.Add(this.btn_greytobin);
            this.Controls.Add(this.btn_greyhistorgram);
            this.Controls.Add(this.btn_rgbto8bit);
            this.Controls.Add(this.btn_resimYukle);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "frmMain";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "G171210021 - 1. Ödev 3. Kısım";
            ((System.ComponentModel.ISupportInitialize)(this.pb_Resim)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btn_resimYukle;
        private System.Windows.Forms.Button btn_rgbto8bit;
        private System.Windows.Forms.Button btn_greyhistorgram;
        private System.Windows.Forms.Button btn_greytobin;
        private System.Windows.Forms.PictureBox pb_Resim;
    }
}

