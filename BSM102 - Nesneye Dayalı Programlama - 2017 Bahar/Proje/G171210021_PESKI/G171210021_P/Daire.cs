using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace G171210021_P
{
    class Daire : Sekil
    {
        public Daire(Color renk) : base(renk)
        {
            sekilTuru = sekiller.Daire;
        }
        public override void Ciz(System.Windows.Forms.PaintEventArgs e, Point? bas, Point ana)
        {
            Brush br = new SolidBrush(renk);
            if (bas != null)
            {
                int val = Math.Max(Math.Abs(ana.Y - bas.Value.Y), Math.Abs(ana.X - bas.Value.X));
                SekilYerGoster(new Point(bas.Value.X,bas.Value.Y), ana.X,ana.Y);
                e.Graphics.FillEllipse(br, Math.Min(bas.Value.X, ana.X), Math.Min(ana.Y, bas.Value.Y), val, val);
                //neden sağ sol?
            }
        }
        public override void Ciz(System.Windows.Forms.PaintEventArgs e)
        {
            Brush br = new SolidBrush(renk);
            Point? bas = sekilYeri;
            if (bas != null)
            {
                int val = Math.Max(Math.Abs(Y - bas.Value.Y), Math.Abs(X - bas.Value.X));
                e.Graphics.FillEllipse(br, Math.Min(bas.Value.X, X), Math.Min(Y, bas.Value.Y), val, val);
            }
        }
        protected override void etrafCiz(object sender, System.Windows.Forms.PaintEventArgs e)
        {
            Brush br = new SolidBrush(Color.FromArgb(120, 125, 110, 125));
            //Rectangle rect = new Rectangle(sekilYeri.X - 10- Math.Abs(X - sekilYeri.X)/2, sekilYeri.Y - 10 - Math.Abs(Y - sekilYeri.Y)/2, Math.Abs(X - sekilYeri.X)+20, Math.Abs(Y - sekilYeri.Y) + 20);
            Rectangle rect = new Rectangle(Math.Min(sekilYeri.X, X)-10, Math.Min(Y, sekilYeri.Y), Math.Abs(X - sekilYeri.X)+20, Math.Abs(Y - sekilYeri.Y) + 20);
            e.Graphics.FillRectangle(br, rect);
        }

    }
}
