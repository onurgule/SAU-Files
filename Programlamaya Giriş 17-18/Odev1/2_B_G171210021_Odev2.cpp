/****************************************************************************
**				SAKARYA �N�VERS�TES�
**		B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**		    B�LG�SAYAR M�HEND�SL��� B�L�M�
**	          PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI....:2
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
	int a, b, sifir=0, eksibir=0, bir=0;
	cout << "A say�s�n� giriniz: ";
	cin >> a; // a say�s� al�nd�.
	if (cin) {
		cout << "\nB say�s�n� giriniz: ";
		cin >> b; // b say�s� al�nd�.
	}
	if (!cin) {
		cout << "\na ve b tam say� olmal�d�r!\n";
		system("pause");
	}
	else if (!(a > b)) { // a'n�n b'den b�y�k olma kontrol�
		cout << "a her zaman b'den b�y�k olmal�.";
	}
	else {
		for (int x = 1; x <= 20; x++)
		{ // grafik 20 y�ld�zdan olu�acakt�r.
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
		{// ne kadar bo�luk b�rakacak?
			cout << " ";
		}
		for (int i = 1; i <= bir; i++)
		{ //1'leri yazd�r.
			cout << "*";
		}
		cout << endl;
		cout << " 0";
		for (int bos = 1; bos <= (eksibir); bos++)
		{// ne kadar bo�luk b�rakacak?
			cout << " ";
		}
		for (int i = 1; i <= sifir; i++)
		{//0'lari yazd�r.
			cout << "*";
		}
		//Bo�luk b�rak�lmad�
		cout << endl;
		cout << "-1";
		for (int i = 1; i <= eksibir; i++)
		{//-1'leri yazd�r.
			cout << "*";
		}
	}
	cin>>a;
	
}

