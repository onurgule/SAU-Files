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
        static void DiliTani2()
        {
            //KULLANILMAYAN, OPTİMİZE EDİLMEMİŞ.
            string olculecek = genelifade.ToLower();
            int cikis = 1;
            foreach (var karakter in olculecek)
            {
                switch (cikis)
                {
                    case 1:
                        if (karakter == 'a') cikis = 4;
                        else if (karakter == 'b') cikis = 2;
                        break;
                    case 2:
                        if (karakter == 'a') cikis = 3;
                        else if (karakter == 'b') cikis = 2;
                        break;
                    case 3:
                        if (karakter == 'a') cikis = 5;
                        else if (karakter == 'b') cikis = 12;
                        break;
                    case 4:
                        if (karakter == 'a') cikis = 5;
                        else if (karakter == 'b') cikis = 6;
                        break;
                    case 5:
                        if (karakter == 'a') cikis = 4;
                        else if (karakter == 'b') cikis = 2;
                        break;
                    case 6:
                        if (karakter == 'a') cikis = 7;
                        else if (karakter == 'b') cikis = 0;
                        break;
                    case 7:
                        if (karakter == 'a') cikis = 8;
                        else if (karakter == 'b') cikis = 9;
                        break;
                    case 8:
                        if (karakter == 'a') cikis = 0;
                        else if (karakter == 'b') cikis = 6;
                        break;
                    case 9:
                        if (karakter == 'a') cikis = 10;
                        else if (karakter == 'b') cikis = 0;
                        break;
                    case 10:
                        if (karakter == 'a') cikis = 0;
                        else if (karakter == 'b') cikis = 11;
                        break;
                    case 11:
                        if (karakter == 'a') cikis = 0;
                        else if (karakter == 'b') cikis = 2;
                        break;
                    case 12:
                        if (karakter == 'a') cikis = 7;
                        else if (karakter == 'b') cikis = 9;
                        break;
                    default:
                        cikis = 0;
                        break;
                }

            }
            if (cikis == 1 || cikis == 2 || cikis == 5 || cikis == 12 || cikis == 11 || cikis == 7)
            {
                Console.ForegroundColor = ConsoleColor.Green;
            }
            else Console.ForegroundColor = ConsoleColor.White;

        }
        static void DiliTani()
        {
            //KULLANILAN
            string olculecek = genelifade.ToLower();
            int cikis = 1;
            int[,] arr = { { 4, 2 }, { 3, 2 }, { 5, 12 }, { 5, 6 }, { 4, 2 }, { 7, 0 }, { 8, 9 }, { 0, 6 }, { 10, 0 }, { 0, 11 }, { 0, 2 }, { 7, 9 }};
            foreach (var karakter in olculecek)
            {
                if (cikis > 0)
                    cikis = arr[cikis - 1, karakter == 'a' ? 0 : 1];
                else break;

            }
            int[] gecerli = { 1, 2, 5, 12, 11, 7 };
            if (gecerli.Any(x => x == cikis))
            {
                Console.ForegroundColor = ConsoleColor.Green;
            }
            else Console.ForegroundColor = ConsoleColor.White;

        }
        static void DiliTaniRegex()
        {
            //KULLANILMAYAN
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
