/****************************************************************************
**					SAKARYA ÜNÝVERSÝTESÝ
**		   BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**			      PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI....:2_2
**				ÖÐRENCÝ ADI......:ONUR OSMAN GÜLE
**				ÖÐRENCÝ NUMARASI.:G171210021
**				DERS GRUBU.......:B
****************************************************************************/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "turkish"); //Türkçe yap.
	int nDiziBoyutu = 0, simdikiSatir = 1; 
	char basilanTus = '0';
	int dizi[100]; // Tanýmlanan dizi boyutunun const olmasý gerektiðinden cin ile alýnan deðeri dizi boyutuna atayamadým.
	cout << "N boyutlu bir dizi oluþturmak için N deðerini giriniz:";
	cin >> nDiziBoyutu; //dizi boyutu alýndý.
	for (int i = 0; i <= nDiziBoyutu; i++)
	{ //dizi boyutu kadar döndürüldü, random sayý alýnýp 11 ile modunu aldýðýmýzda 0-10 arasý sayý elde ettik.
		dizi[i] = rand() % 11;
	}
	do {
		system("cls"); // Her döngüde console'u temizleyelim.
		for (int i = 1; i <= nDiziBoyutu; i++)
		{//Sayýlarý yazdýralým.
			if (simdikiSatir == i)
			{//A ve D ile kontrol ettiðimiz satýr sayýmýza geldiðimizde sol tarafýnda bir ok ekleyelim.
				cout << "-->" << right << setw(2) << dizi[i]<<endl;
			}
			else
				cout << setw(5) << right << dizi[i]<<endl;

		}
		cout << "(a veya A tuþu aþaðýya götürür.)" << endl << "(d veya D tuþu yukarýya götürür.)" << endl << "(c veya C tuþu programdan çýkarýr.)" << endl << "Ýstediðiniz tuþa þimdi basabilirsiniz...";
		basilanTus = _getch(); //Tuþ isteyelim.
		if (basilanTus == 68 || basilanTus == 100)
		{ //Alýnan tuþ D ise satýr sayýsýný arttýralým.
			if (simdikiSatir == nDiziBoyutu) simdikiSatir = 1; //eðer son satýrdaysak ilk satýra götürelim.
			else simdikiSatir++;
		}
		else if (basilanTus == 65 || basilanTus == 97)
		{ //Alýnan tuþ A ise satýr sayýsýný azaltalým.
			if (simdikiSatir == 1) simdikiSatir = nDiziBoyutu; // eðer ilk satýrdaysak son satýra götürelim.
			else simdikiSatir--;
		}
		else if (basilanTus == 67 || basilanTus == 99) // Alýnan tuþ C ise programý sonlandýralým.
			return 0;
	} while (1 == 1); //Sürekli çalýþan döngü.
    return 0;
}

