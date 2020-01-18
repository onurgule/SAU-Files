using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace G171210021_P
{
    class Altigen : Sekil
    {
        public Altigen(Color renk) : base(renk)
        {
            sekilTuru = sekiller.Altigen;
        }
        public override void Ciz(System.Windows.Forms.PaintEventArgs e, Point? bas, Point ana)
        {
            Brush br = new SolidBrush(renk);
            if (bas != null)
            {
                //merkez : bas olsun. ana'dan çıkaralım onu 3'e 60 derecelik açılarla bölelim.
                //int x = Math.Min(bas.Value.X, ana.X);
                int x = bas.Value.X;
                int y = bas.Value.Y;
                int rx = Math.Abs(bas.Value.X - ana.X);
                int ry = Math.Abs(bas.Value.Y - ana.Y);
                Sinir.SinirCek(ref x,ref y);
                var x_0 = x;
                var y_0 = y;
                var shape = new PointF[6];
                var r = rx;
                for (int a = 0; a < 6; a++)
                {
                    shape[a] = new PointF(
                        x_0 + r * (float)Math.Cos(a * 60 * Math.PI / 180f),
                        y_0 + r * (float)Math.Sin(a * 60 * Math.PI / 180f));
                    Point ch = (new Point(Convert.ToInt16(shape[a].X), Convert.ToInt16(shape[a].Y)));
                    if (!Sinir.Tasmadi(ch))
                    {
                        a = -1;
                        if (r <= 0) { r = rx; break; }
                        else r--;
                        continue;
                    }
                }
                SekilYerGoster(new Point(x, y), ana.X,ana.Y);
                e.Graphics.FillPolygon(br, shape);

            }
        }
        public override void Ciz(System.Windows.Forms.PaintEventArgs e)
        {//zaten olanları çiz
            Brush br = new SolidBrush(renk);
            Point? bas = sekilYeri;
            if (bas != null)
            {

                int x = bas.Value.X;
                int y = bas.Value.Y;
                int rx = Math.Abs(bas.Value.X - X);
                int ry = Math.Abs(bas.Value.Y - Y);
                var x_0 = x;
                var y_0 = y;
                var shape = new PointF[6];
                var r = rx;
                for (int a = 0; a < 6; a++)
                {
                    shape[a] = new PointF(
                        x_0 + r * (float)Math.Cos(a * 60 * Math.PI / 180f),
                        y_0 + r * (float)Math.Sin(a * 60 * Math.PI / 180f));
                    Point ch = (new Point(Convert.ToInt16(shape[a].X), Convert.ToInt16(shape[a].Y)));
                    if (!Sinir.Tasmadi(ch))
                    {
                        a = -1;
                        if (r <= 0) { r = rx; break; }
                        else r--;
                        continue;
                    }
                }
                e.Graphics.FillPolygon(br, shape);
            }
        }
        protected override void etrafCiz(object sender, System.Windows.Forms.PaintEventArgs e)
        {
            Brush br = new SolidBrush(Color.FromArgb(120, 125, 110, 125));
            int excp = (int)(Math.Abs(sekilYeri.X - X) * 0.1);
            //Rectangle rect = new Rectangle(sekilYeri.X - excp - (int)(sekilYeri.X+Math.Abs(sekilYeri.X - X) * (float)Math.Sin(3 * 60 * Math.PI / 180f))/4 , sekilYeri.Y - excp - (int)(sekilYeri.X + Math.Abs(sekilYeri.X - X) * (float)Math.Sin(3 * 60 * Math.PI / 180f)) / 4, Math.Abs(sekilYeri.X - X)+(int)(sekilYeri.X + Math.Abs(sekilYeri.X - X) * (float)Math.Sin(3 * 60 * Math.PI / 180f)) / 4 + excp, Y - sekilYeri.Y + excp + (int)(sekilYeri.X + Math.Abs(sekilYeri.X - X) * (float)Math.Sin(3 * 60 * Math.PI / 180f)) / 4);
            //Rectangle rect = new Rectangle(Math.Min(X, sekilYeri.X) - 10, Math.Min(Y, sekilYeri.Y) - 10, Math.Abs(sekilYeri.X - X) + 20, Math.Abs(sekilYeri.Y - Y) + 20);
            Rectangle rect = new Rectangle(Math.Min(sekilYeri.X,X) - 10 - Math.Abs(sekilYeri.X - X) / 2, Math.Min(sekilYeri.Y, Y) - 10 - Math.Abs(sekilYeri.Y - Y) / 2, 2*Math.Abs(X - sekilYeri.X) + 20, 2*Math.Abs(Y - sekilYeri.Y) + 20);

            e.Graphics.FillRectangle(br, rect);
        }
    }
}
