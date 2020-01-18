/****************************************************************************
**					SAKARYA �N�VERS�TES�
**		   B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**				B�LG�SAYAR M�HEND�SL��� B�L�M�
**			      PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI....:3
**				��RENC� ADI......:ONUR OSMAN G�LE
**				��RENC� NUMARASI.:G171210021
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
	cout << "### Ho�geldiniz ###"<<endl;
	cout << "Bir c�mle giriniz: ";
	Cumle cml;
	getline(cin,cml.cumle);
	cml.cumle += " ";
	cout <<endl << "\"" << cml.cumle << "\" C�mlesi �nceleniyor..." << endl <<endl;
	cout << "Harf Say�s�: " << HarfSayisi(cml) << endl;
	cout << "Kelime Say�s�: " << KelimeSayisi(cml) << endl;
	cout << "C�mledeki Noktalama ��aretleri: " << NoktalamaIsaretleri(cml) << endl;
	cout << "C�mle Palindrom" << ((IsPalindrom((cml.cumle).substr(0,cml.cumle.length()-1)) == true) ? "dur." : " De�ildir.") << endl;
	cout << "C�mledeki Kelimeler ve Harf Say�lar�:" << endl << KelimeHarfSayisi(cml)<<endl;
	cout << "C�mledeki Kelimeler ve Sesli Harf Say�lar�:" << endl << KelimelerinSesliHarfSayisi(cml) << endl;
	cout << "C�mledeki Palindrom Kelimeler:" << endl << (AnyPalindrom(cml) != "" ? AnyPalindrom(cml): "Yok") << endl;
	system("pause");

    return 0;
}
int HarfSayisi(Cumle c) {
	int hsayi = 0;
	for (int i = 0; i < c.cumle.length(); i++)
	{ // C�mlenin her karakterine bakal�m.
		if (c.cumle.substr(i, 1) != " " && c.cumle.substr(i,1) != "")
		{ //C�mlenin gelinen karakteri bo�luk de�ilse harf say�s�n� artt�ral�m.
			hsayi++;
		}
	}
	return hsayi;
}
int KelimeSayisi(Cumle c) {
	int ksayi = 0;
	int sayac = 0;
	for (int i = 0; i < c.cumle.length(); i++)
	{ //c�mlenin her karakterine bakal�m.
		if (c.cumle.substr(i, 1) == " ")
		{ //c�mlenin gelinen karakteri bo�luk ise kelime say�s�n� artt�ral�m.
			ksayi++;
		}
	}
	return (ksayi);
}
bool IsPalindrom(string c) {
	string terstenCumle = "";
	for (int i = 0; i < c.length(); i++)
	{ // parametreden gelen c�mlenin her karakterini alal�m.
		terstenCumle.append(c.substr(c.length()-1 - i, 1)); // son karakterini terstenCumle isimli stringe atayarak ba� karaktere kadar devam edelim ters c�mleyi elde edelim.
	}
	if (terstenCumle == c)
	{ // e�er elde etti�imiz ters c�mle bizim ilk c�mlemiz ise palindromdur.
		return true;
	}
	else return false;
}
string NoktalamaIsaretleri(Cumle c) {
	string noktalamalar = "";
	for (int i = 0; i < c.cumle.length(); i++)
	{ // c�mlenin her karakterine bakal�m. 4 adet noktalama i�areti s�zkonusu.
		if (c.cumle.substr(i, 1) == "." && noktalamalar.find(".") == -1)
		{ //E�er gelinen karakter nokta ve daha �nce noktay� bulmad�ysak noktay� ekleyelim.
			noktalamalar.append(" .");
		}
		if (c.cumle.substr(i, 1) == "," && noktalamalar.find(",") == -1)
		{//E�er gelinen karakter virg�l ve daha �nce virg�l� bulmad�ysak virg�l� ekleyelim.
			noktalamalar.append(" ,");
		}
		if (c.cumle.substr(i, 1) == "!" && noktalamalar.find("!") == -1)
		{//E�er gelinen karakter �nlem ve daha �nce �nlemi bulmad�ysak �nlemi ekleyelim.
			noktalamalar.append(" !");
		}
		if (c.cumle.substr(i, 1) == "?" && noktalamalar.find("?") == -1)
		{//E�er gelinen karakter soru i�areti ve daha �nce soru i�aretini bulmad�ysak soru i�aretini ekleyelim.
			noktalamalar.append(" ?");
		}
	}
	return (noktalamalar!="" ? noktalamalar : "Yok"); // noktalamalar isimli de�i�kende veri yoksa 'Yok' d�nd�relim.
}
string KelimeHarfSayisi(Cumle c) {
	int ksayi = 0;
	string harfler = "";
	int kharfsayisi;
	int checkpoint = 0;
	for (int i = 0; i < c.cumle.length(); i++)
	{ //C�mlenin her karakterine bakal�m.
		if (c.cumle.substr(i, 1) == " " || c.cumle.substr(i, 1) == c.cumle.substr((c.cumle.length()-1),1))
		{ // C�mlenin karakteri bo�luksa 
			if (c.cumle.substr(i, 1) == c.cumle.substr((c.cumle.length() - 1), 1)) // c�mlenin al�nan karakteri, c�mlenin son harfiyse yani bittiyse yaz�l�r.
				harfler += (c.cumle.substr(checkpoint, i - checkpoint)) + " : " + to_string(i - checkpoint) + "\n";
			checkpoint = i+1;
			//i'ye kadar 1 kelime var. i'yi checkpointle.
		}
	}
	return harfler;
}
bool SesliHarfMi(string harf) {
	string sesliler = "AEI�O�U�ae�io�u�";
	if (sesliler.find(harf) != -1) { // harfi sesliler stringinde arat�p varsa true d�nd�relim.
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
	{ // c�mlenin her karakterine bakal�m.
		if (c.cumle.substr(i, 1) == " " || c.cumle.substr(i, 1) == c.cumle.substr((c.cumle.length() - 1), 1))
		{ // C�mlenin al�nan karakteri bo�lu�a e�itse
			if (c.cumle.substr(i, 1) == c.cumle.substr((c.cumle.length() - 1), 1)) {
				//al�nan karakter son karaktere e�itse yani bittiyse kelime
				string kelime =  (c.cumle.substr(checkpoint, i - checkpoint )) ;
				int sesli = 0;
				for (int j = 0; j < kelime.length(); j++)
				{ // kelimenin her karakterini alal�m.
					if (SesliHarfMi(kelime.substr(j, 1))) { //kelimenin al�nan karakteri sesli harf mi diye kontrol ettirelim.
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
	{ // c�mlenin her karakterini alal�m.
		if (c.cumle.substr(i, 1) == " " || c.cumle.substr(i, 1) == c.cumle.substr((c.cumle.length() - 1), 1))
		{ // c�mlenin karakteri bo�luk ise 
			if (c.cumle.substr(i, 1) == c.cumle.substr((c.cumle.length() - 1), 1)) { //c�mlenin al�nan karakteri son karakteriyse yani bittiyse kelime
				string kelime = (c.cumle.substr(checkpoint, i - checkpoint));
				if (IsPalindrom(kelime)) { // kelimenin palindrom olup olmad���n� sorgulayal�m
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

