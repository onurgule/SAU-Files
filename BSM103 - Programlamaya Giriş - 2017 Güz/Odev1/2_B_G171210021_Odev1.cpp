/****************************************************************************
**				SAKARYA ÜNÝVERSÝTESÝ
**		BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**		    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**	          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI....:1
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
	const int disKareEn = 24; // Dökümandan alýndý.
	const int disKareBoy = 20; // Dökümandan alýndý.
	int gereksizSatirSayilari[disKareBoy]; // Hangi döngü parçacýklarý üçgenlerin uzunluklarý yüzünden kýrýlýyor tespit etme dizisi. {DÝZÝYE ÝZÝN VERÝLMEDÝ}
	for (int i = 0; i < disKareBoy; i++)
	{//Dýþ kare oluþtururkenki satýrlarý teker teker döndürür.
		if (i == 0 || i == disKareBoy - 1)
		{ // Dýþ kare oluþtururkenki üst ve alt köþeleri kontrol etme.
			for (int j = 0; j < disKareEn; j++) // Dýþ kare oluþtururkenki üst ve alt köþeleri kontrol döngüsü.
				cout << "*";
			cout << endl;
		}
		else { // köþe deðilse
			if (i == 1) { // ikinci satýrsa saü bilgisayar yaz.
				cout << "*";
				cout << setw(disKareEn - 2) << left << "SAÜ BÝLGÝSAYAR" << right << "*" << endl;
			}
			else if (i == 8) // SAÜ BÝLGÝSAYAR'ýn üstünde boþluk olmayýp, MÜHENDÝSLÝÐÝ BÖLÜMÜ'nün üstünde boþluk olacaðýndan boþluk eklendi.
			{
				cout << "*";
				cout << setw(disKareEn - 1) << "*" << endl;
			}
			else if (i == 9) // Onuncu satýrsa mühendisliði bölümü yaz.
			{
				cout << "*";
				cout << setw(disKareEn - 2) << left << "MÜHENDÝSLÝÐÝ BÖLÜMÜ" << right << "*" << endl;
			}
			else if (i == 3 || i == 11) // Üçgenleri çizmeye baþlama kontrolü
			{//6lýk üçgen oluþtur.
				const int ucgenUzunluk = 6; // PDFdeki her bir üçgenin uzunluðu 6 birimdir.
				for (int z = 1; z <= 6; z++) { // Üçgenlerin her satýrýnýn döngüsü
					bool satirAtlandiMi = false; // satýrýn atlanýp atlanmadýðýný kontrol ediyoruz.
					gereksizSatirSayilari[i + z] = 1; // Üçgen oluþturulurken atlanan satýrlarý dizimize ekliyoruz. {DÝZÝYE ÝZÝN VERÝLMEDÝ}
					cout << "*";
					int ucgenMaxEn = (2 * z - 1); //Üçgenlerin enlerini bulalým.
					for (int kacUcgen = 1; kacUcgen <= 2; kacUcgen++)
					{ // Yanyana eklenen üçgenleri ekliyoruz(2 adet) 
						for (int a = (ucgenUzunluk - 1); a >= z; a--) {   //Üçgenlerin boþluklarýný belirtiyoruz.
							if (kacUcgen == 1) // Birinci üçgende her bir boþluðu tek boþluk yapýyoruz.
								cout << " ";
							else if (kacUcgen == 2 && ((z != 1 && z != 2) || i == 3)) // Birinci Satýrdaki Ýkinci üçgenin her bir boþluðunu çift boþluk yapýyoruz.
								cout << "  ";
							else if (kacUcgen == 2 && (z == 1 || z == 2) && i == 11) // Ýkinci Satýrdaki Ýkinci Üçgenin Boþluklarýný bir boþluk yapýyoruz.
							{
								cout << " ";
								if (a == z && z == 2) // Ýkinci Satýr Ýkinci Üçgende fazladan semboldeki (*) eklendiðinden kaymamasý için bir boþluk ekliyoruz.
									cout << " ";     // Burada kontrol etmemizin nedeni sað köþe üçgen olmadýðýndandýr.

							}
						}


						for (int h = 1; h <= ucgenMaxEn; h++) {  //Üçgen Yýldýzlarýný ekliyoruz. 
							cout << "*";

						}
						if ((i == 3 && kacUcgen == 2)) // Ýlk Satýrýn Ýkinci Üçgeninin Ek Sembolünü Ekleyelim.
						{
							if (z == 1) //Sembolün ilk kýsmý.
							{
								for (int b = 1; b <= 2; b++)
								{ //Sembolün boþluklarýný belirtelim.
									cout << " ";
								}
								for (int y = 1; y <= 3; y++)
								{ //Sembolü çizelim.
									cout << "*";
								}
								cout << setw(disKareEn - z - ucgenUzunluk * 3 - 5) << "*" << endl; // Sembolü ekledikten sonra karenin boþluklarýnýn kaymamasý için ek düzenleme yapýldý.
								satirAtlandiMi = true; //Üçgen oluþturduðumuzda Satýrý atladýðýmýz için karenin fazla uzamasý engellendi.
							}
							else if (z == 2)
							{//Sembolün ikinci kýsmý
								for (int b = 1; b <= 2; b++)
								{ // Sembolün ikinci kýsmý için boþluk býrakalým.
									cout << " ";
								}
								cout << "*";
								cout << setw(disKareEn - z - ucgenUzunluk * 3 - 2) << "*" << endl;
								satirAtlandiMi = true; //Üçgen yüzünden kare satýrýnýn içinde arttýrdýðýmýzý söyleyelim.
							}
						}
						if (i == 11 && kacUcgen == 1)
						{ // Ýkinci Satýrýn Birinci Üçgeninin Ek Sembolünü Ekleyelim.
							if (z == 1)
							{ // Sembolün ilk kýsmý
								for (int b = 1; b <= 2; b++)
								{ // Sembolün ilk kýsmýnýn boþluklarýný ekleyelim.
									cout << " ";
								}
								for (int y = 1; y <= 3; y++)
								{// Sembolün ilk kýsmýnýn yýldýzlarýný ekleyelim.
									cout << "*";
								}
							}
							else if (z == 2)
							{// Sembolün ikinci kýsmý
								for (int b = 1; b <= 2; b++)
								{// Sembolün ilk kýsmýnýn boþluklarýný ekleyelim.
									cout << " ";
								}
								cout << "*";
							}
							// 3lüleri yap
						}
					}
					if (satirAtlandiMi != true) // Eðer satýr üçgen eklenip atlanmadýysa sonuna yýldýz ekleyelim.
						cout << setw(disKareEn - z - ucgenUzunluk * 3 + 1) << "*" << endl;
				}


			}
			else if ((i>=4 && i<=9) || (i>=12 && i<=17)) // Üçgen çizim yüzünden karenin köþelerinin bozulmamasý için oluþturduðumuz dizinin satýrýnda mýyýz kontrol edilir. {DÝZÝYE ÝZÝN VERÝLMEDÝ} Üçgenin bütün es geçtiði satýrlar yazýldý.
			{
				continue;
			}
			else
			{ // Eðer hiçbir özel iþlem yapýlmayacaksa boþ kare satýrý eklenir.
				cout << "*";
				cout << setw(disKareEn - 1) << "*" << endl;
			}
		}
	}
	cin.get(); // Programýn hemen kapanmasýný engelleyen komut.
	return 0;
}

