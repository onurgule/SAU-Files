using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace G171210021_P
{
    class Ucgen : Sekil
    {
        List<Point> ucgenNoktalari = new List<Point>();
        public Ucgen(Color renk) : base(renk)
        {
            sekilTuru = sekiller.Ucgen;
        }
        public override void Ciz(System.Windows.Forms.PaintEventArgs e, Point? bas, Point ana)
        {
            Brush br = new SolidBrush(renk);
            if (bas != null)
            {
                //merkez : bas olsun. ana'dan çıkaralım onu 3'e 60 derecelik açılarla bölelim.
                ucgenNoktalari.Clear();
               // int x = Math.Min(bas.Value.X, ana.X);
                int x = bas.Value.X;
                int y = Math.Min(bas.Value.Y, ana.Y);
                int rx = Math.Abs(bas.Value.X - ana.X);
                int ry = Math.Abs(bas.Value.Y - ana.Y);
                Point f = new Point(x, y - (ry / 2));
                Sinir.SinirCek(ref f);
                ucgenNoktalari.Add(f);
                f = new Point(x - (ry / 2), y + ry);
                Sinir.SinirCek(ref f);
                ucgenNoktalari.Add(f);
                f = new Point(x + (ry / 2), y + ry);
                Sinir.SinirCek(ref f);
                ucgenNoktalari.Add(f);
                SekilYerGoster(new Point(bas.Value.X,bas.Value.Y), ana.X,ana.Y);
                e.Graphics.FillPolygon(br, ucgenNoktalari.ToArray());
            }
        }
        public override void Ciz(System.Windows.Forms.PaintEventArgs e)
        {
            Point? bas = sekilYeri;
            Brush br = new SolidBrush(renk);
            if (bas != null)
            {
                ucgenNoktalari.Clear();
                int x = bas.Value.X;
                int y = Math.Min(bas.Value.Y, Y);
                int rx = Math.Abs(bas.Value.X - X);
                int ry = Math.Abs(bas.Value.Y - Y);
                Point f = new Point(x, y - (ry / 2));
                Sinir.SinirCek(ref f);
                ucgenNoktalari.Add(f);
                f = new Point(x - (ry / 2), y + ry);
                Sinir.SinirCek(ref f);
                ucgenNoktalari.Add(f);
                f = new Point(x + (ry / 2), y + ry);
                Sinir.SinirCek(ref f);
                ucgenNoktalari.Add(f);
                if (2==2)
                {
                    //merkez : bas olsun. ana'dan çıkaralım onu 3'e 60 derecelik açılarla bölelim.
                    e.Graphics.FillPolygon(br,ucgenNoktalari.ToArray());
                }
            }
        }
        protected override void etrafCiz(object sender, System.Windows.Forms.PaintEventArgs e)
        {
            Brush br = new SolidBrush(Color.FromArgb(120, 125, 110, 125));
            Rectangle rect = new Rectangle(Math.Min(sekilYeri.X, X) - 10 - Math.Abs(sekilYeri.X - X)/2, Math.Min(sekilYeri.Y, Y) - 10, Math.Abs(X - sekilYeri.X) + 20, Math.Abs(Y - sekilYeri.Y) + 20);
            e.Graphics.FillRectangle(br, rect);
        }
        protected override bool Sinirli(System.Windows.Forms.PaintEventArgs e)
        {
            Point? bas = sekilYeri;
            int x = Math.Min(bas.Value.X, X);
            int y = Math.Min(bas.Value.Y, Y);
            int rx = Math.Abs(bas.Value.X - X);
            int ry = Math.Abs(bas.Value.Y - Y);
            bool sinirIcinde = false;
            for(int i = 0; i<3; i++)
            {
                if (ucgenNoktalari[i].X <= Sinir.sinirlar[0])
                    if (ucgenNoktalari[i].X >= Sinir.sinirlar[1])
                        if (ucgenNoktalari[i].Y >= Sinir.sinirlar[2])
                            if (ucgenNoktalari[i].Y <= Sinir.sinirlar[3]) sinirIcinde = true;
                            else { ucgenNoktalari[i] = new Point(ucgenNoktalari[i].X, Sinir.sinirlar[3]);  }
                        else { ucgenNoktalari[i] = new Point(ucgenNoktalari[i].X, Sinir.sinirlar[2]); }
                    else { ucgenNoktalari[i] = new Point(Sinir.sinirlar[1], ucgenNoktalari[i].Y); }
                else { ucgenNoktalari[i] = new Point(Sinir.sinirlar[0], ucgenNoktalari[i].Y); }
            }
            return sinirIcinde;
        }
    }
}
