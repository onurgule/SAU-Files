using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace Reguler_G171210021_1
{
    class Program
    {
        static string genelifade = "";
        static void GirisEkrani()
        {
            DiliTani();
            Console.WriteLine("G171210021 - Onur Osman Güle - 2A Grubu");
            Console.WriteLine("Biçimsel Diller ve Soyut Makineler Ödevi");
            Console.WriteLine("∑=(a,b) simgesinde tanımlı ve L=(aa+b)*(aba)*(bab)* regüler ifadesiyle sunulan dil için bir dil tanıyıcı program gerçekleyiniz.");
            Console.WriteLine("Eğer ifade uygunsa yazılar yeşile, değilse beyaza döner.");
            Console.WriteLine("Aşağıya ifadenizi giriniz, çıkış için Enter'a basınız.");
            Console.Write("> ");
        }
        static void YenidenYazdir()
        {
            Console.Clear();
            GirisEkrani();
            Console.Write(genelifade.ToLower());
        }
        static void DiliTani()
        {
            var regex3 = ("^(aa|b)*(aba)*(bab)*$");
            Regex r = new Regex(regex3, RegexOptions.IgnoreCase | RegexOptions.Singleline);
            Match m = r.Match(genelifade.ToLower());
            if (m.Success)
            {
                Console.ForegroundColor = ConsoleColor.Green;
            }
            else Console.ForegroundColor = ConsoleColor.White;
        }
        static void KarakterAl(ConsoleKeyInfo ifade)
        {
            if (ifade.Key == ConsoleKey.A || ifade.Key == ConsoleKey.B)
            {
                genelifade += ifade.Key;
                DiliTani();
                YenidenYazdir();
            }
            else if(ifade.Key == ConsoleKey.Backspace)
            {
                if (genelifade != "")
                {
                    genelifade = genelifade.Replace(genelifade,genelifade.Substring(0,genelifade.Length - 1));
                    DiliTani();
                    YenidenYazdir();
                }
            }
            else if(ifade.Key == ConsoleKey.Enter)
            {
                Environment.Exit(0);
            }
            else
            {
                Console.Write("\b \b");
            }
        }
        static void Main(string[] args)
        {
            GirisEkrani();
            while (true)
            {
                if (Console.KeyAvailable)
                {
                    ConsoleKeyInfo karakter = Console.ReadKey();
                    KarakterAl(karakter);
                }
            }
        }
    }
}
