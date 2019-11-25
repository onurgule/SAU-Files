/****************************************************************************
**					SAKARYA ÜNÝVERSÝTESÝ
**		   BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**			      PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI....:3
**				ÖÐRENCÝ ADI......:ONUR OSMAN GÜLE
**				ÖÐRENCÝ NUMARASI.:G171210021
**				DERS GRUBU.......:B
****************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <string>

using namespace std;
struct Cumle {
	string cumle;

};
int HarfSayisi(Cumle c);
int KelimeSayisi(Cumle c);
string NoktalamaIsaretleri(Cumle c);
bool IsPalindrom(string c);
string KelimeHarfSayisi(Cumle c);
bool SesliHarfMi(string harf);
string KelimelerinSesliHarfSayisi(Cumle c);
string AnyPalindrom(Cumle c);

int main()
{
	setlocale(LC_ALL, "turkish");
	cout << "### Hoþgeldiniz ###"<<endl;
	cout << "Bir cümle giriniz: ";
	Cumle cml;
	getline(cin,cml.cumle);
	cml.cumle += " ";
	cout <<endl << "\"" << cml.cumle << "\" Cümlesi Ýnceleniyor..." << endl <<endl;
	cout << "Harf Sayýsý: " << HarfSayisi(cml) << endl;
	cout << "Kelime Sayýsý: " << KelimeSayisi(cml) << endl;
	cout << "Cümledeki Noktalama Ýþaretleri: " << NoktalamaIsaretleri(cml) << endl;
	cout << "Cümle Palindrom" << ((IsPalindrom((cml.cumle).substr(0,cml.cumle.length()-1)) == true) ? "dur." : " Deðildir.") << endl;
	cout << "Cümledeki Kelimeler ve Harf Sayýlarý:" << endl << KelimeHarfSayisi(cml)<<endl;
	cout << "Cümledeki Kelimeler ve Sesli Harf Sayýlarý:" << endl << KelimelerinSesliHarfSayisi(cml) << endl;
	cout << "Cümledeki Palindrom Kelimeler:" << endl << (AnyPalindrom(cml) != "" ? AnyPalindrom(cml): "Yok") << endl;
	system("pause");

    return 0;
}
int HarfSayisi(Cumle c) {
	int hsayi = 0;
	for (int i = 0; i < c.cumle.length(); i++)
	{ // Cümlenin her karakterine bakalým.
		if (c.cumle.substr(i, 1) != " " && c.cumle.substr(i,1) != "")
		{ //Cümlenin gelinen karakteri boþluk deðilse harf sayýsýný arttýralým.
			hsayi++;
		}
	}
	return hsayi;
}
int KelimeSayisi(Cumle c) {
	int ksayi = 0;
	int sayac = 0;
	for (int i = 0; i < c.cumle.length(); i++)
	{ //cümlenin her karakterine bakalým.
		if (c.cumle.substr(i, 1) == " ")
		{ //cümlenin gelinen karakteri boþluk ise kelime sayýsýný arttýralým.
			ksayi++;
		}
	}
	return (ksayi);
}
bool IsPalindrom(string c) {
	string terstenCumle = "";
	for (int i = 0; i < c.length(); i++)
	{ // parametreden gelen cümlenin her karakterini alalým.
		terstenCumle.append(c.substr(c.length()-1 - i, 1)); // son karakterini terstenCumle isimli stringe atayarak baþ karaktere kadar devam edelim ters cümleyi elde edelim.
	}
	if (terstenCumle == c)
	{ // eðer elde ettiðimiz ters cümle bizim ilk cümlemiz ise palindromdur.
		return true;
	}
	else return false;
}
string NoktalamaIsaretleri(Cumle c) {
	string noktalamalar = "";
	for (int i = 0; i < c.cumle.length(); i++)
	{ // cümlenin her karakterine bakalým. 4 adet noktalama iþareti sözkonusu.
		if (c.cumle.substr(i, 1) == "." && noktalamalar.find(".") == -1)
		{ //Eðer gelinen karakter nokta ve daha önce noktayý bulmadýysak noktayý ekleyelim.
			noktalamalar.append(" .");
		}
		if (c.cumle.substr(i, 1) == "," && noktalamalar.find(",") == -1)
		{//Eðer gelinen karakter virgül ve daha önce virgülü bulmadýysak virgülü ekleyelim.
			noktalamalar.append(" ,");
		}
		if (c.cumle.substr(i, 1) == "!" && noktalamalar.find("!") == -1)
		{//Eðer gelinen karakter ünlem ve daha önce ünlemi bulmadýysak ünlemi ekleyelim.
			noktalamalar.append(" !");
		}
		if (c.cumle.substr(i, 1) == "?" && noktalamalar.find("?") == -1)
		{//Eðer gelinen karakter soru iþareti ve daha önce soru iþaretini bulmadýysak soru iþaretini ekleyelim.
			noktalamalar.append(" ?");
		}
	}
	return (noktalamalar!="" ? noktalamalar : "Yok"); // noktalamalar isimli deðiþkende veri yoksa 'Yok' döndürelim.
}
string KelimeHarfSayisi(Cumle c) {
	int ksayi = 0;
	string harfler = "";
	int kharfsayisi;
	int checkpoint = 0;
	for (int i = 0; i < c.cumle.length(); i++)
	{ //Cümlenin her karakterine bakalým.
		if (c.cumle.substr(i, 1) == " " || c.cumle.substr(i, 1) == c.cumle.substr((c.cumle.length()-1),1))
		{ // Cümlenin karakteri boþluksa 
			if (c.cumle.substr(i, 1) == c.cumle.substr((c.cumle.length() - 1), 1)) // cümlenin alýnan karakteri, cümlenin son harfiyse yani bittiyse yazýlýr.
				harfler += (c.cumle.substr(checkpoint, i - checkpoint)) + " : " + to_string(i - checkpoint) + "\n";
			checkpoint = i+1;
			//i'ye kadar 1 kelime var. i'yi checkpointle.
		}
	}
	return harfler;
}
bool SesliHarfMi(string harf) {
	string sesliler = "AEIÝOÖUÜaeýioöuü";
	if (sesliler.find(harf) != -1) { // harfi sesliler stringinde aratýp varsa true döndürelim.
		return true;
	}
	else return false;
}
string KelimelerinSesliHarfSayisi(Cumle c) {
	int ksayi = 0;
	string harfler = "";
	int sesliharfsayisi = 0;
	int kharfsayisi;
	int checkpoint = 0;
	for (int i = 0; i < c.cumle.length(); i++)
	{ // cümlenin her karakterine bakalým.
		if (c.cumle.substr(i, 1) == " " || c.cumle.substr(i, 1) == c.cumle.substr((c.cumle.length() - 1), 1))
		{ // Cümlenin alýnan karakteri boþluða eþitse
			if (c.cumle.substr(i, 1) == c.cumle.substr((c.cumle.length() - 1), 1)) {
				//alýnan karakter son karaktere eþitse yani bittiyse kelime
				string kelime =  (c.cumle.substr(checkpoint, i - checkpoint )) ;
				int sesli = 0;
				for (int j = 0; j < kelime.length(); j++)
				{ // kelimenin her karakterini alalým.
					if (SesliHarfMi(kelime.substr(j, 1))) { //kelimenin alýnan karakteri sesli harf mi diye kontrol ettirelim.
						sesli++;
					}
				}
				harfler += (c.cumle.substr(checkpoint, i - checkpoint)) + " : " + to_string(sesli) + "\n";
			}
			checkpoint = i + 1;
			//i'ye kadar 1 kelime var. i'yi checkpointle.
		}
	}
	return harfler;
}
string AnyPalindrom(Cumle c) {
	int ksayi = 0;
	string harfler = "";
	int sesliharfsayisi = 0;
	int kharfsayisi;
	int checkpoint = 0;
	for (int i = 0; i < c.cumle.length(); i++)
	{ // cümlenin her karakterini alalým.
		if (c.cumle.substr(i, 1) == " " || c.cumle.substr(i, 1) == c.cumle.substr((c.cumle.length() - 1), 1))
		{ // cümlenin karakteri boþluk ise 
			if (c.cumle.substr(i, 1) == c.cumle.substr((c.cumle.length() - 1), 1)) { //cümlenin alýnan karakteri son karakteriyse yani bittiyse kelime
				string kelime = (c.cumle.substr(checkpoint, i - checkpoint));
				if (IsPalindrom(kelime)) { // kelimenin palindrom olup olmadýðýný sorgulayalým
					harfler += (c.cumle.substr(checkpoint, i - checkpoint)) + "\n";
				}
			}
			else {
				string kelime = (c.cumle.substr(checkpoint, i - checkpoint));
				if (IsPalindrom(kelime)) {
					harfler += (c.cumle.substr(checkpoint, i - checkpoint)) + "\n";
				}
			}
			checkpoint = i + 1;
			//i'ye kadar 1 kelime var. i'yi checkpointle.
		}
	}
	return harfler;
}

