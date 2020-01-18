/****************************************************************************
**					SAKARYA ÜNÝVERSÝTESÝ
**		   BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**			      PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI....:2_1
**				ÖÐRENCÝ ADI......:ONUR OSMAN GÜLE
**				ÖÐRENCÝ NUMARASI.:G171210021
**				DERS GRUBU.......:B
****************************************************************************/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include<conio.h>
#include<stdio.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "turkish"); // Türkçe karakter sorunu düzeltildi.
	double vize, odev1, odev2, kSinav1, kSinav2, yVize = 0, yOdev = 0, yKSinav = 0, yYilici = 0, genelOrtalama, finalSinavi; // Deðiþkenler tanýmlandý.
	do {
		int boslukSayisi = 53; // Gerekli . sayýsý için boþluk sayýsý eklendi.
		cout << setw(boslukSayisi) << left << setfill('.') << "Vize notunu giriniz" << ":"; // Ekran çýktýsý alýndý.
		cin >> vize; // istenilen deðer alýndý.
		cout << setw(boslukSayisi) << left << setfill('.') << "1. ödev notunu giriniz" << ":";
		cin >> odev1;
		cout << setw(boslukSayisi) << left << setfill('.') << "2. ödev notunu giriniz" << ":";
		cin >> odev2;
		cout << setw(boslukSayisi) << left << setfill('.') << "1. kýsa sýnav notunu giriniz" << ":";
		cin >> kSinav1;
		cout << setw(boslukSayisi) << left << setfill('.') << "2. kýsa sýnav notunu giriniz" << ":";
		cin >> kSinav2;
		cout << setw(boslukSayisi) << left << setfill('.') << "Final sýnavý notunu giriniz" << ":";
		cin >> finalSinavi;
		cout << setw(boslukSayisi - 1) << left << setfill('.') << "Vizenin yýl içine etkisi yüzde kaç olacaktýr" << ":%";
		cin >> yVize;
		cout << setw(boslukSayisi - 1) << left << setfill('.') << "Ödevlerin yýl içine etkisi yüzde kaç olacaktýr" << ":%";
		cin >> yOdev;
		cout << setw(boslukSayisi - 1) << left << setfill('.') << "Kýsa Sýnavlarýn yýl içine etkisi yüzde kaç olacaktýr" << ":%";
		cin >> yKSinav;
		cout << setw(boslukSayisi - 1) << left << setfill('.') << "Yýl içi puanýnýn etkisi yüzde kaç olacaktýr" << ":%";
		cin >> yYilici;
		if ((yOdev + yKSinav + yVize) != 100)
		{ // istenilen yüzdelik deðerler 100'den farklýysa bir daha yap.
			system("Color 4"); // Hata verdiði için yazýlarý kýrmýzý yap.
			cout << "Vize, Kýsa Sýnav, Ödev yüzdelikleri toplamý 100 olmalýdýr!\nTekrar denemek için herhangi bir tuþa basýn...";
			_getch(); //Bir karaktere basana kadar bekle.
			system("Color 7"); // Yazý renklerini normale çevir.
			system("cls"); // Console'u temizle.
		}
	} while ((yOdev + yKSinav + yVize) != 100); // Ýstenilen yüzdelik deðerler 100 olmadýkça sürekli yap.
	genelOrtalama = ((vize*yVize + (odev1*yOdev + odev2*yOdev)/2 + (kSinav1*yKSinav + kSinav2*yKSinav)/2)*yYilici/100 + finalSinavi*(100-yYilici))/100; // genel ortalamayý bul.
	cout << "Ortalamanýz: " << setprecision(4) << genelOrtalama << endl; // Ortalamayý max. virgülden sonra 2 haneli yaz.
	if (genelOrtalama <= 100 && genelOrtalama >= 90) // Harf notlarýný yazdýr.
		cout << "Harf Notunuz: " << "AA" << endl;
	else if (genelOrtalama < 90 && genelOrtalama >= 85)
		cout << "Harf Notunuz: " << "BA" << endl;
	else if (genelOrtalama < 85 && genelOrtalama >= 80)
		cout << "Harf Notunuz: " << "BB" << endl;
	else if (genelOrtalama < 80 && genelOrtalama >= 75)
		cout << "Harf Notunuz: " << "CB" << endl;
	else if (genelOrtalama < 75 && genelOrtalama >= 65)
		cout << "Harf Notunuz: " << "CC" << endl;
	else if (genelOrtalama < 65 && genelOrtalama >= 58)
		cout << "Harf Notunuz: " << "DC" << endl;
	else if (genelOrtalama < 58 && genelOrtalama >= 50)
		cout << "Harf Notunuz: " << "DD" << endl;
	else if (genelOrtalama < 50 && genelOrtalama >= 0)
		cout << "Harf Notunuz: " << "FF" << endl;
	else 
		cout << "Harf Notunuz: " << "HESAPLANAMADI!" << endl;
	system("pause"); // Ekranda durmasýný saðla.
    return 0;
}

