/****************************************************************************
**					SAKARYA ÜNÝVERSÝTESÝ
**		   BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**			      PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI....:2_3
**				ÖÐRENCÝ ADI...... : ONUR OSMAN GÜLE
**				ÖÐRENCÝ NUMARASI. : G171210021
**				DERS GRUBU....... : B
****************************************************************************/


#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	setlocale(LC_ALL, "turkish");
	int xkare, x, sabit;
	double kok1, kok2, diskriminant;
	string denklem = "";
		cout << "x² deðerini giriniz:";
		cin >> xkare;
		cout << "x deðerini giriniz:";
		cin >> x;
		cout << "c deðerini giriniz:";
		cin >> sabit;
		system("cls"); // Konsol temizlendi.
		denklem = to_string(xkare) + "x²"; //xkare yazýldý.
		denklem += (to_string(x).find("-")) ? "+" : ""; // Eðer x'in içinde - varsa bir þey yazma, yoksa + yaz.
		denklem += to_string(x) + "x"; //x yaz.
		denklem += (sabit > 0) ? "+" : ""; // sabit 0'dan büyükse + yaz deðilse bir þey yazma.  Farklý iki yoldan yapýldý.
		denklem += to_string(sabit); //sabit yaz.
		cout << "Çözülmek istenen denklem: " << denklem << endl; //Denklemi yazdýr.
		diskriminant = pow(x, 2) - 4 * xkare*sabit; //b^2-4ac formülünden bul.
		if (diskriminant < 0) // 0'dan küçükse karmaþýk.
			cout << "Kökler karmaþýktýr!"<<endl;
		else { //deðilse formülden bul.
			kok1 = (-x + sqrt(diskriminant)) / 2 * xkare;
			kok2 = (-x - sqrt(diskriminant)) / 2 * xkare;
			if (kok1 == kok2) //eþitse çakýþýk.
				cout << "Kökler çakýþýktýr ve " <<setprecision(2)<<fixed<< kok1 << "'dir.";
			else cout << "1. Kök:" << setprecision(2) << fixed << kok1 << endl <<"2. Kök:" << setprecision(2) << fixed << kok2 <<endl; //deðilse ikisini de yazdýr.
			}
		system("pause");
    return 0;
}

