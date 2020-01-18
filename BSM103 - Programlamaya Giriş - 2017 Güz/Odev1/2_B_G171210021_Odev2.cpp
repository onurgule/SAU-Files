/****************************************************************************
**				SAKARYA ÜNÝVERSÝTESÝ
**		BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**		    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**	          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI....:2
**				ÖÐRENCÝ ADI......:ONUR OSMAN GÜLE
**				ÖÐRENCÝ NUMARASI.:G171210021
**				DERS GRUBU.......:B
****************************************************************************/


#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	setlocale(LC_ALL, "turkish");
	int a, b, sifir=0, eksibir=0, bir=0;
	cout << "A sayýsýný giriniz: ";
	cin >> a; // a sayýsý alýndý.
	if (cin) {
		cout << "\nB sayýsýný giriniz: ";
		cin >> b; // b sayýsý alýndý.
	}
	if (!cin) {
		cout << "\na ve b tam sayý olmalýdýr!\n";
		system("pause");
	}
	else if (!(a > b)) { // a'nýn b'den büyük olma kontrolü
		cout << "a her zaman b'den büyük olmalý.";
	}
	else {
		for (int x = 1; x <= 20; x++)
		{ // grafik 20 yýldýzdan oluþacaktýr.
			if (x < b) {
				eksibir++;
			}
			else if (b <= x && x <= a) {
				sifir++;
			}
			else {
				bir++;
			}
		}

		cout << " 1";
		for (int bos = 1; bos <= (sifir + eksibir); bos++)
		{// ne kadar boþluk býrakacak?
			cout << " ";
		}
		for (int i = 1; i <= bir; i++)
		{ //1'leri yazdýr.
			cout << "*";
		}
		cout << endl;
		cout << " 0";
		for (int bos = 1; bos <= (eksibir); bos++)
		{// ne kadar boþluk býrakacak?
			cout << " ";
		}
		for (int i = 1; i <= sifir; i++)
		{//0'lari yazdýr.
			cout << "*";
		}
		//Boþluk býrakýlmadý
		cout << endl;
		cout << "-1";
		for (int i = 1; i <= eksibir; i++)
		{//-1'leri yazdýr.
			cout << "*";
		}
	}
	cin>>a;
	
}

