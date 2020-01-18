/****************************************************************************
**					SAKARYA �N�VERS�TES�
**		   B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**				B�LG�SAYAR M�HEND�SL��� B�L�M�
**			      PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI....:2_2
**				��RENC� ADI......:ONUR OSMAN G�LE
**				��RENC� NUMARASI.:G171210021
**				DERS GRUBU.......:B
****************************************************************************/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "turkish"); //T�rk�e yap.
	int nDiziBoyutu = 0, simdikiSatir = 1; 
	char basilanTus = '0';
	int dizi[100]; // Tan�mlanan dizi boyutunun const olmas� gerekti�inden cin ile al�nan de�eri dizi boyutuna atayamad�m.
	cout << "N boyutlu bir dizi olu�turmak i�in N de�erini giriniz:";
	cin >> nDiziBoyutu; //dizi boyutu al�nd�.
	for (int i = 0; i <= nDiziBoyutu; i++)
	{ //dizi boyutu kadar d�nd�r�ld�, random say� al�n�p 11 ile modunu ald���m�zda 0-10 aras� say� elde ettik.
		dizi[i] = rand() % 11;
	}
	do {
		system("cls"); // Her d�ng�de console'u temizleyelim.
		for (int i = 1; i <= nDiziBoyutu; i++)
		{//Say�lar� yazd�ral�m.
			if (simdikiSatir == i)
			{//A ve D ile kontrol etti�imiz sat�r say�m�za geldi�imizde sol taraf�nda bir ok ekleyelim.
				cout << "-->" << right << setw(2) << dizi[i]<<endl;
			}
			else
				cout << setw(5) << right << dizi[i]<<endl;

		}
		cout << "(a veya A tu�u a�a��ya g�t�r�r.)" << endl << "(d veya D tu�u yukar�ya g�t�r�r.)" << endl << "(c veya C tu�u programdan ��kar�r.)" << endl << "�stedi�iniz tu�a �imdi basabilirsiniz...";
		basilanTus = _getch(); //Tu� isteyelim.
		if (basilanTus == 68 || basilanTus == 100)
		{ //Al�nan tu� D ise sat�r say�s�n� artt�ral�m.
			if (simdikiSatir == nDiziBoyutu) simdikiSatir = 1; //e�er son sat�rdaysak ilk sat�ra g�t�relim.
			else simdikiSatir++;
		}
		else if (basilanTus == 65 || basilanTus == 97)
		{ //Al�nan tu� A ise sat�r say�s�n� azaltal�m.
			if (simdikiSatir == 1) simdikiSatir = nDiziBoyutu; // e�er ilk sat�rdaysak son sat�ra g�t�relim.
			else simdikiSatir--;
		}
		else if (basilanTus == 67 || basilanTus == 99) // Al�nan tu� C ise program� sonland�ral�m.
			return 0;
	} while (1 == 1); //S�rekli �al��an d�ng�.
    return 0;
}

