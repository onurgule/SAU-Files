using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace G171210021_P
{
    static class DosyaIslemleri
    {
        static public void DosyaIndir(List<Sekil> sekiller)
        {
            SaveFileDialog sfd = new SaveFileDialog();
            sfd.ShowDialog();
            if(sfd.FileName != "")
            {
                StreamWriter sw = new StreamWriter(sfd.FileName,true);
                foreach (var item in sekiller)
                {
                    sw.WriteLine((int)item.sekilTuru + "_" + (int)Renk.renkHangiSayi(item.renk) + "_" + item.sekilYeri.X + "_"+ item.sekilYeri.Y + "_" + item.X + "_" + item.Y );
                }
                sw.Close();
            }
            
        }
        static public List<Sekil> DosyaIsle()
        {
            List<Sekil> tumSekiller = new List<Sekil>();
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.ShowDialog();
            if(ofd.FileName != "")
            {
                StreamReader sr = new StreamReader(ofd.FileName);
                while (!sr.EndOfStream)
                {
                    string[] skl = sr.ReadLine().Split('_');
                    if (skl[0] == ((int)sekiller.Dikdortgen).ToString())
                    {
                        Dikdortgen dk = new Dikdortgen(Renk.sayiHangiRenk((renkler)Convert.ToInt16(skl[1])));
                        dk.sekilYeri = new System.Drawing.Point(Convert.ToInt16(skl[2]), Convert.ToInt16(skl[3]));
                        dk.X = Convert.ToInt16(skl[4]);
                        dk.Y = Convert.ToInt16(skl[5]);
                        tumSekiller.Add(dk);
                    }
                    else if (skl[0] == ((int)sekiller.Daire).ToString())
                    {
                        Daire dk = new Daire(Renk.sayiHangiRenk((renkler)Convert.ToInt16(skl[1])));
                        dk.sekilYeri = new System.Drawing.Point(Convert.ToInt16(skl[2]), Convert.ToInt16(skl[3]));
                        dk.X = Convert.ToInt16(skl[4]);
                        dk.Y = Convert.ToInt16(skl[5]);
                        tumSekiller.Add(dk);
                    }
                    else if (skl[0] == ((int)sekiller.Ucgen).ToString())
                    {
                        Ucgen dk = new Ucgen(Renk.sayiHangiRenk((renkler)Convert.ToInt16(skl[1])));
                        dk.sekilYeri = new System.Drawing.Point(Convert.ToInt16(skl[2]), Convert.ToInt16(skl[3]));
                        dk.X = Convert.ToInt16(skl[4]);
                        dk.Y = Convert.ToInt16(skl[5]);
                        tumSekiller.Add(dk);
                    }
                    else if (skl[0] == ((int)sekiller.Altigen).ToString())
                    {
                        Altigen dk = new Altigen(Renk.sayiHangiRenk((renkler)Convert.ToInt16(skl[1])));
                        dk.sekilYeri = new System.Drawing.Point(Convert.ToInt16(skl[2]), Convert.ToInt16(skl[3]));
                        dk.X = Convert.ToInt16(skl[4]);
                        dk.Y = Convert.ToInt16(skl[5]);
                        tumSekiller.Add(dk);
                    }
                    else continue;
                }
            }
            return tumSekiller;
        }
    }
}
