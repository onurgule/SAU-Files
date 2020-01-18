/****************************************************************************
**				SAKARYA �N�VERS�TES�
**		B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**		    B�LG�SAYAR M�HEND�SL��� B�L�M�
**	          PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI....:1
**				��RENC� ADI......:ONUR OSMAN G�LE
**				��RENC� NUMARASI.:G171210021
**				DERS GRUBU.......:B
****************************************************************************/


#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	setlocale(LC_ALL, "turkish");
	const int disKareEn = 24; // D�k�mandan al�nd�.
	const int disKareBoy = 20; // D�k�mandan al�nd�.
	int gereksizSatirSayilari[disKareBoy]; // Hangi d�ng� par�ac�klar� ��genlerin uzunluklar� y�z�nden k�r�l�yor tespit etme dizisi. {D�Z�YE �Z�N VER�LMED�}
	for (int i = 0; i < disKareBoy; i++)
	{//D�� kare olu�tururkenki sat�rlar� teker teker d�nd�r�r.
		if (i == 0 || i == disKareBoy - 1)
		{ // D�� kare olu�tururkenki �st ve alt k��eleri kontrol etme.
			for (int j = 0; j < disKareEn; j++) // D�� kare olu�tururkenki �st ve alt k��eleri kontrol d�ng�s�.
				cout << "*";
			cout << endl;
		}
		else { // k��e de�ilse
			if (i == 1) { // ikinci sat�rsa sa� bilgisayar yaz.
				cout << "*";
				cout << setw(disKareEn - 2) << left << "SA� B�LG�SAYAR" << right << "*" << endl;
			}
			else if (i == 8) // SA� B�LG�SAYAR'�n �st�nde bo�luk olmay�p, M�HEND�SL��� B�L�M�'n�n �st�nde bo�luk olaca��ndan bo�luk eklendi.
			{
				cout << "*";
				cout << setw(disKareEn - 1) << "*" << endl;
			}
			else if (i == 9) // Onuncu sat�rsa m�hendisli�i b�l�m� yaz.
			{
				cout << "*";
				cout << setw(disKareEn - 2) << left << "M�HEND�SL��� B�L�M�" << right << "*" << endl;
			}
			else if (i == 3 || i == 11) // ��genleri �izmeye ba�lama kontrol�
			{//6l�k ��gen olu�tur.
				const int ucgenUzunluk = 6; // PDFdeki her bir ��genin uzunlu�u 6 birimdir.
				for (int z = 1; z <= 6; z++) { // ��genlerin her sat�r�n�n d�ng�s�
					bool satirAtlandiMi = false; // sat�r�n atlan�p atlanmad���n� kontrol ediyoruz.
					gereksizSatirSayilari[i + z] = 1; // ��gen olu�turulurken atlanan sat�rlar� dizimize ekliyoruz. {D�Z�YE �Z�N VER�LMED�}
					cout << "*";
					int ucgenMaxEn = (2 * z - 1); //��genlerin enlerini bulal�m.
					for (int kacUcgen = 1; kacUcgen <= 2; kacUcgen++)
					{ // Yanyana eklenen ��genleri ekliyoruz(2 adet) 
						for (int a = (ucgenUzunluk - 1); a >= z; a--) {   //��genlerin bo�luklar�n� belirtiyoruz.
							if (kacUcgen == 1) // Birinci ��gende her bir bo�lu�u tek bo�luk yap�yoruz.
								cout << " ";
							else if (kacUcgen == 2 && ((z != 1 && z != 2) || i == 3)) // Birinci Sat�rdaki �kinci ��genin her bir bo�lu�unu �ift bo�luk yap�yoruz.
								cout << "  ";
							else if (kacUcgen == 2 && (z == 1 || z == 2) && i == 11) // �kinci Sat�rdaki �kinci ��genin Bo�luklar�n� bir bo�luk yap�yoruz.
							{
								cout << " ";
								if (a == z && z == 2) // �kinci Sat�r �kinci ��gende fazladan semboldeki (*) eklendi�inden kaymamas� i�in bir bo�luk ekliyoruz.
									cout << " ";     // Burada kontrol etmemizin nedeni sa� k��e ��gen olmad���ndand�r.

							}
						}


						for (int h = 1; h <= ucgenMaxEn; h++) {  //��gen Y�ld�zlar�n� ekliyoruz. 
							cout << "*";

						}
						if ((i == 3 && kacUcgen == 2)) // �lk Sat�r�n �kinci ��geninin Ek Sembol�n� Ekleyelim.
						{
							if (z == 1) //Sembol�n ilk k�sm�.
							{
								for (int b = 1; b <= 2; b++)
								{ //Sembol�n bo�luklar�n� belirtelim.
									cout << " ";
								}
								for (int y = 1; y <= 3; y++)
								{ //Sembol� �izelim.
									cout << "*";
								}
								cout << setw(disKareEn - z - ucgenUzunluk * 3 - 5) << "*" << endl; // Sembol� ekledikten sonra karenin bo�luklar�n�n kaymamas� i�in ek d�zenleme yap�ld�.
								satirAtlandiMi = true; //��gen olu�turdu�umuzda Sat�r� atlad���m�z i�in karenin fazla uzamas� engellendi.
							}
							else if (z == 2)
							{//Sembol�n ikinci k�sm�
								for (int b = 1; b <= 2; b++)
								{ // Sembol�n ikinci k�sm� i�in bo�luk b�rakal�m.
									cout << " ";
								}
								cout << "*";
								cout << setw(disKareEn - z - ucgenUzunluk * 3 - 2) << "*" << endl;
								satirAtlandiMi = true; //��gen y�z�nden kare sat�r�n�n i�inde artt�rd���m�z� s�yleyelim.
							}
						}
						if (i == 11 && kacUcgen == 1)
						{ // �kinci Sat�r�n Birinci ��geninin Ek Sembol�n� Ekleyelim.
							if (z == 1)
							{ // Sembol�n ilk k�sm�
								for (int b = 1; b <= 2; b++)
								{ // Sembol�n ilk k�sm�n�n bo�luklar�n� ekleyelim.
									cout << " ";
								}
								for (int y = 1; y <= 3; y++)
								{// Sembol�n ilk k�sm�n�n y�ld�zlar�n� ekleyelim.
									cout << "*";
								}
							}
							else if (z == 2)
							{// Sembol�n ikinci k�sm�
								for (int b = 1; b <= 2; b++)
								{// Sembol�n ilk k�sm�n�n bo�luklar�n� ekleyelim.
									cout << " ";
								}
								cout << "*";
							}
							// 3l�leri yap
						}
					}
					if (satirAtlandiMi != true) // E�er sat�r ��gen eklenip atlanmad�ysa sonuna y�ld�z ekleyelim.
						cout << setw(disKareEn - z - ucgenUzunluk * 3 + 1) << "*" << endl;
				}


			}
			else if ((i>=4 && i<=9) || (i>=12 && i<=17)) // ��gen �izim y�z�nden karenin k��elerinin bozulmamas� i�in olu�turdu�umuz dizinin sat�r�nda m�y�z kontrol edilir. {D�Z�YE �Z�N VER�LMED�} ��genin b�t�n es ge�ti�i sat�rlar yaz�ld�.
			{
				continue;
			}
			else
			{ // E�er hi�bir �zel i�lem yap�lmayacaksa bo� kare sat�r� eklenir.
				cout << "*";
				cout << setw(disKareEn - 1) << "*" << endl;
			}
		}
	}
	cin.get(); // Program�n hemen kapanmas�n� engelleyen komut.
	return 0;
}

