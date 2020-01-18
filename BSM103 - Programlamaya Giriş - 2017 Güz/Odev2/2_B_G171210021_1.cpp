/****************************************************************************
**					SAKARYA �N�VERS�TES�
**		   B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**				B�LG�SAYAR M�HEND�SL��� B�L�M�
**			      PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI....:2_1
**				��RENC� ADI......:ONUR OSMAN G�LE
**				��RENC� NUMARASI.:G171210021
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
	setlocale(LC_ALL, "turkish"); // T�rk�e karakter sorunu d�zeltildi.
	double vize, odev1, odev2, kSinav1, kSinav2, yVize = 0, yOdev = 0, yKSinav = 0, yYilici = 0, genelOrtalama, finalSinavi; // De�i�kenler tan�mland�.
	do {
		int boslukSayisi = 53; // Gerekli . say�s� i�in bo�luk say�s� eklendi.
		cout << setw(boslukSayisi) << left << setfill('.') << "Vize notunu giriniz" << ":"; // Ekran ��kt�s� al�nd�.
		cin >> vize; // istenilen de�er al�nd�.
		cout << setw(boslukSayisi) << left << setfill('.') << "1. �dev notunu giriniz" << ":";
		cin >> odev1;
		cout << setw(boslukSayisi) << left << setfill('.') << "2. �dev notunu giriniz" << ":";
		cin >> odev2;
		cout << setw(boslukSayisi) << left << setfill('.') << "1. k�sa s�nav notunu giriniz" << ":";
		cin >> kSinav1;
		cout << setw(boslukSayisi) << left << setfill('.') << "2. k�sa s�nav notunu giriniz" << ":";
		cin >> kSinav2;
		cout << setw(boslukSayisi) << left << setfill('.') << "Final s�nav� notunu giriniz" << ":";
		cin >> finalSinavi;
		cout << setw(boslukSayisi - 1) << left << setfill('.') << "Vizenin y�l i�ine etkisi y�zde ka� olacakt�r" << ":%";
		cin >> yVize;
		cout << setw(boslukSayisi - 1) << left << setfill('.') << "�devlerin y�l i�ine etkisi y�zde ka� olacakt�r" << ":%";
		cin >> yOdev;
		cout << setw(boslukSayisi - 1) << left << setfill('.') << "K�sa S�navlar�n y�l i�ine etkisi y�zde ka� olacakt�r" << ":%";
		cin >> yKSinav;
		cout << setw(boslukSayisi - 1) << left << setfill('.') << "Y�l i�i puan�n�n etkisi y�zde ka� olacakt�r" << ":%";
		cin >> yYilici;
		if ((yOdev + yKSinav + yVize) != 100)
		{ // istenilen y�zdelik de�erler 100'den farkl�ysa bir daha yap.
			system("Color 4"); // Hata verdi�i i�in yaz�lar� k�rm�z� yap.
			cout << "Vize, K�sa S�nav, �dev y�zdelikleri toplam� 100 olmal�d�r!\nTekrar denemek i�in herhangi bir tu�a bas�n...";
			_getch(); //Bir karaktere basana kadar bekle.
			system("Color 7"); // Yaz� renklerini normale �evir.
			system("cls"); // Console'u temizle.
		}
	} while ((yOdev + yKSinav + yVize) != 100); // �stenilen y�zdelik de�erler 100 olmad�k�a s�rekli yap.
	genelOrtalama = ((vize*yVize + (odev1*yOdev + odev2*yOdev)/2 + (kSinav1*yKSinav + kSinav2*yKSinav)/2)*yYilici/100 + finalSinavi*(100-yYilici))/100; // genel ortalamay� bul.
	cout << "Ortalaman�z: " << setprecision(4) << genelOrtalama << endl; // Ortalamay� max. virg�lden sonra 2 haneli yaz.
	if (genelOrtalama <= 100 && genelOrtalama >= 90) // Harf notlar�n� yazd�r.
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
	system("pause"); // Ekranda durmas�n� sa�la.
    return 0;
}

