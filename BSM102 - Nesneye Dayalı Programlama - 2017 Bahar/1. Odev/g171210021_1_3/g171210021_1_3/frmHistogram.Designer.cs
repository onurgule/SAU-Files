namespace g171210021_1_3
{
    partial class frmHistogram
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
            this.histogramBox = new Emgu.CV.UI.HistogramBox();
            this.SuspendLayout();
            // 
            // histogramBox
            // 
            this.histogramBox.Location = new System.Drawing.Point(13, 13);
            this.histogramBox.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.histogramBox.Name = "histogramBox";
            this.histogramBox.Size = new System.Drawing.Size(618, 283);
            this.histogramBox.TabIndex = 0;
            // 
            // frmHistogram
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(644, 315);
            this.Controls.Add(this.histogramBox);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "frmHistogram";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Histogram";
            this.Load += new System.EventHandler(this.frmHistogram_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private Emgu.CV.UI.HistogramBox histogramBox;
    }
}