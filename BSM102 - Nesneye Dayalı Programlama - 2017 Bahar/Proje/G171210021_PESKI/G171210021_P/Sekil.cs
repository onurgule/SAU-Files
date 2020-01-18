using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace G171210021_P
{
    public enum sekiller { Dikdortgen = 1,Daire,Ucgen,Altigen }
    public enum renkler { Kirmizi = 1, Mavi, Yesil, Turuncu, Siyah, Sari, Mor, Kahve, Beyaz}
    public abstract class Sekil
    {
        //public bool gecici = false;
        public sekiller sekilTuru;
        public Point sekilYeri; //Başlangıç noktası left-top (mouse down ile gelir)
        public Color renk;
        public bool Secildi { get;set; }
        private int x; //mouse'un son x koordinatı
        private int y; //mouse'un son y koordinatı
        public int X
        {
            get { return x; }
            set { x = (value > 0) ? value : 0; }
        }
        public int Y
        {
            get { return y; }
            set { y = (value > 0) ? value : 0; }
        }
        public Sekil(Color renk)
        {
            this.renk = renk;
        }
        public Sekil(Color renk, Point sekilYeri, int x, int y)
        {
            this.renk = renk;
            this.sekilYeri = sekilYeri;
            this.x = x;
            this.y = y;
        }
        public void SekilYerGoster(Point bas, int x, int y)
        {
            //this.sekilYeri = new Point(Math.Min(x,bas.X),Math.Min(y,bas.Y));
            this.sekilYeri = new Point((bas.X),(bas.Y));
            Sinir.SinirCek(ref this.sekilYeri);
            this.x = (this.sekilYeri.X == x) ? bas.X : x;
            this.y = (this.sekilYeri.Y == y) ? bas.Y : y;
            Sinir.SinirCek(ref this.x, ref this.y);
        }
        public bool icindeMi(Point p)
            {
            if (p.X < Math.Min(sekilYeri.X,X) || p.X > Math.Max(X,sekilYeri.X) || p.Y < Math.Min(sekilYeri.Y,Y) || p.Y > Math.Max(Y,sekilYeri.Y))
            {
                return false;
            }
            else return true;
        }
        protected virtual void etrafCiz(object sender, System.Windows.Forms.PaintEventArgs e) //private -> public for virtual
        {
            Brush br = new SolidBrush(Color.FromArgb(120, 125, 110, 125));
            Rectangle rect = new Rectangle(Math.Min(x,sekilYeri.X)-10,Math.Min(y,sekilYeri.Y)-10,Math.Abs(sekilYeri.X - x)+20,Math.Abs(sekilYeri.Y-y)+20);
            e.Graphics.FillRectangle(br, rect);
        }
        protected virtual bool Sinirli(System.Windows.Forms.PaintEventArgs e)
        {
            bool sinirIcinde = true;

            return sinirIcinde;
        }
        public virtual System.Windows.Forms.PaintEventHandler Sec(System.Windows.Forms.Panel panel)
        {
            Secildi = true;
            System.Windows.Forms.PaintEventHandler a=  new System.Windows.Forms.PaintEventHandler(etrafCiz);
            panel.Paint += a;
            panel.Refresh();
            return a;
        }
        public virtual void Ciz(System.Windows.Forms.PaintEventArgs e, Point? bas, Point ana)
        {

        }
        public virtual void Ciz(System.Windows.Forms.PaintEventArgs e)
        {

        }
        public void RenkDegistir(Color a)
        {
            renk = a;
        }
        
    }
   
    
   
    
}
