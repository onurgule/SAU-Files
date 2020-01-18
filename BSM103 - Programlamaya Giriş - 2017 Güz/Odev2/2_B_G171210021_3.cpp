/****************************************************************************
**					SAKARYA �N�VERS�TES�
**		   B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**				B�LG�SAYAR M�HEND�SL��� B�L�M�
**			      PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI....:2_3
**				��RENC� ADI...... : ONUR OSMAN G�LE
**				��RENC� NUMARASI. : G171210021
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
		cout << "x� de�erini giriniz:";
		cin >> xkare;
		cout << "x de�erini giriniz:";
		cin >> x;
		cout << "c de�erini giriniz:";
		cin >> sabit;
		system("cls"); // Konsol temizlendi.
		denklem = to_string(xkare) + "x�"; //xkare yaz�ld�.
		denklem += (to_string(x).find("-")) ? "+" : ""; // E�er x'in i�inde - varsa bir �ey yazma, yoksa + yaz.
		denklem += to_string(x) + "x"; //x yaz.
		denklem += (sabit > 0) ? "+" : ""; // sabit 0'dan b�y�kse + yaz de�ilse bir �ey yazma.  Farkl� iki yoldan yap�ld�.
		denklem += to_string(sabit); //sabit yaz.
		cout << "��z�lmek istenen denklem: " << denklem << endl; //Denklemi yazd�r.
		diskriminant = pow(x, 2) - 4 * xkare*sabit; //b^2-4ac form�l�nden bul.
		if (diskriminant < 0) // 0'dan k���kse karma��k.
			cout << "K�kler karma��kt�r!"<<endl;
		else { //de�ilse form�lden bul.
			kok1 = (-x + sqrt(diskriminant)) / 2 * xkare;
			kok2 = (-x - sqrt(diskriminant)) / 2 * xkare;
			if (kok1 == kok2) //e�itse �ak���k.
				cout << "K�kler �ak���kt�r ve " <<setprecision(2)<<fixed<< kok1 << "'dir.";
			else cout << "1. K�k:" << setprecision(2) << fixed << kok1 << endl <<"2. K�k:" << setprecision(2) << fixed << kok2 <<endl; //de�ilse ikisini de yazd�r.
			}
		system("pause");
    return 0;
}

