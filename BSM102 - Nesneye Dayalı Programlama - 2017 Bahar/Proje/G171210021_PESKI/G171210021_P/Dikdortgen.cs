using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace G171210021_P
{
    class Dikdortgen : Sekil
    {
        public Dikdortgen(Color renk) : base(renk)
        {
            sekilTuru = sekiller.Dikdortgen;
        }
        public override void Ciz(System.Windows.Forms.PaintEventArgs e, Point? bas, Point ana)
        {//yeni bir şey çiz.
            Brush br = new SolidBrush(renk);
            if (bas != null)
            {
                Rectangle rect = new Rectangle(Math.Min(bas.Value.X, ana.X),
                               Math.Min(ana.Y, bas.Value.Y),
                               Math.Abs(ana.X - bas.Value.X),
                               Math.Abs(ana.Y - bas.Value.Y));
                SekilYerGoster(new Point(bas.Value.X, bas.Value.Y), ana.X, ana.Y);
                e.Graphics.FillRectangle(br, rect);
            }
        }
        public override void Ciz(System.Windows.Forms.PaintEventArgs e)
        {//zaten olanları çiz
            Brush br = new SolidBrush(renk);
            Point? bas = sekilYeri;
            if (bas != null)
            {
                Rectangle rect = new Rectangle(Math.Min(bas.Value.X, X),
                               Math.Min(Y, bas.Value.Y),
                               Math.Abs(X - bas.Value.X),
                               Math.Abs(Y - bas.Value.Y));

                e.Graphics.FillRectangle(br, rect);
            }
        }
    }
}
