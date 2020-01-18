/****************************************************************************
**					SAKARYA �N�VERS�TES�
**		   B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**				B�LG�SAYAR M�HEND�SL��� B�L�M�
**			      PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI.....: P_1
**				��RENC� ADI...... : ONUR OSMAN G�LE
**				��RENC� NUMARASI. : G171210021
**				DERS GRUBU....... : B
****************************************************************************/

#include "stdafx.h"
#include <dos.h> 
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <time.h> 
#include <iomanip> 
#include <ctime> 
#include <fstream> 
#include <sstream>
#include <windows.h>
using namespace std;
int menu = 0; // Ana Men� De�i�keni
int ch = NULL; // Men� ��lev De�i�keni (ch:kanal)
bool islem = false; // islem yapt�rma de�i�keni
void MenuGetir(char); // kanala g�re men� getirme fonksiyonu
void HataGoster(string, double); // men�l� hata g�sterme fonksiyonu
void HataGoster(string, double, bool); //men�s�z hata g�sterme fonksiyonu
void UstMenu(); // �st men�ye gitme fonksiyonu
string *Ayrac(string); // string d�n�� tipli '...;...;...;...' ifadeyi (;) karakterine g�re split edip dizi d�nd�ren fonksiyon. (�ki isimli giri�lerde hata olu�tu�undan kullan�ld�!)
void Cikis(); // ��k�� fonksiyonu
void GirisTemizle();
class Otel { // Ana S�n�f�m�z
public: struct Oda {
	int No;
	double Ucret;
}; //Oteldeki Her Oda ��in Struct�m�z
public:struct Musteri {
	int No;
	string Ad;
	string Soyad;
	string TC;
}; // Oteldeki her m��teri i�in Struct�m�z
public:void OdaListele(bool sadeceBos) {
	ifstream myfile;
	myfile.open("odalar.txt"); //odalar.txt okunmak i�in a��l�r.
	string a; // Gereksiz(kullan�lmayacak) bir atama de�i�keni olu�turulur.
	int odasayisi = 0; // oda say�s� belirlenir.
	while (myfile.good() && myfile >> a) { //dosyan�n sonuna kadar okunur.
		string *dizi = Ayrac(a); // Ayrac fonksiyonu ile birlikte okunan sat�r diziye at�l�r.
		if (sadeceBos) { // E�er sadeceBos parametresi true ise sadece bo� odalar� listeler
			odasayisi++;
			ifstream bosfile;
			bosfile.open("iliskiler.txt"); // iliskiler.txt dosyas� okunmak i�in a��l�r.
			string bos; // gereksiz bir atama de�i�keni olu�turulur.
			bool gec = false; // dolu odalar� ge�mek i�in bir de�i�ken olu�turulur.
			while (bosfile.good() && bosfile >> bos) { // dosyan�n sonuna kadar okunur.
				string *bosdizi = Ayrac(bos); // Ayrac fonksiyonu ile birlikte okunan sat�r diziye at�l�r.
				if (dizi[0] == bosdizi[0]) { // Okunan sat�r ile dizideki sat�r e�it ise(Oda dolu ise) ge�er.
					odasayisi--;
					gec = true;
				}
			}
			if (gec) continue; //Devam ettirir.
		}
		else { // Sadece Dolu odalar� listeleme
			ifstream bosfile;
			bosfile.open("iliskiler.txt"); //iliskiler.txt okuma olarak a��l�r.
			string bos; //gereksiz bir de�i�ken olu�turulur.
			bool gec = false; //bo�lar� ge�mek i�in de�i�ken.
			while (bosfile.good() && bosfile >> bos) { //dosyan�n sonuna kadar oku.
				string *bosdizi = Ayrac(bos);  // Ayrac fonksiyonu ile birlikte okunan sat�r diziye at�l�r.
				if (dizi[0] == bosdizi[0]) { // Okunan sat�r ile dizideki sat�r e�it ise(Oda bo� ise) ge�er.
					odasayisi++;
					gec = true;
					break;
				}
				
			}
			if (!gec) continue; //devam ettirir.
		}
		for (int i = 0; i < 2; i++)
		{ //fonksiyonda istenenleri yazd�r�r.
			if (i == 0) cout << "Oda No:";
			else cout << " - �cret:";
			cout << setw(5) << dizi[i];
		}
		cout << endl;
	}
	if(sadeceBos) cout << "Otelimizdeki bo� oda say�s�:" << odasayisi << endl;
	else cout << "Otelimizdeki dolu oda say�s�:" << odasayisi << endl;
}
public:void OdaListele() { // T�m odalar� yazd�r�r
	ifstream myfile;
	myfile.open("odalar.txt"); // odalar.txt okuma olarak a��l�r.
	string a;
	int odasayisi = 0;
	while (myfile.good() && myfile >> a) { //dosyan�n sonuna kadar.
		string *dizi = Ayrac(a); //Ayrac fonk. ile diziye at�l�r.
		odasayisi++;
		for (int i = 0; i < 2; i++)
		{ //Odalar yazd�r�l�r.
			if (i == 0) cout << "Oda No:";
			else cout << " - �cret:";
			cout << setw(5) << dizi[i];
		}
		cout << endl;
	}
	cout << "Otelimizdeki oda say�s�:" << odasayisi << endl;
}
public:bool OdaMevcutMu(int odaNo) {
	ifstream myfile;
	bool mevcut = false;
	myfile.open("odalar.txt"); //odalar.txt okumada a��l�r.
	string a;
	while (myfile.good() && myfile >> a) {
		string *dizi = Ayrac(a); //Ayrac fonksiyonu ile diziye aktar�l�r.
		if (dizi[0] == to_string(odaNo)) mevcut = true; // odalar.txt'den gelen veri odaNo'ya e�it mi de�il mi kontrol et. E�itse oda vard�r.
	}

	return mevcut;
}
public:bool OdaBosMu(int odaNo) {
	bool dolu = false; //odan�n dolulu�u kontrol� ama�l� de�i�ken.
	if (OdaMevcutMu(odaNo)) { //ilk �nce odan�n mevcut olup olmad���n� kontrol edelim.
		ifstream bosfile;
		bosfile.open("iliskiler.txt");
		string bos;
		while (bosfile.good() && bosfile >> bos) {
			string *bosdizi = Ayrac(bos);
			if (to_string(odaNo) == bosdizi[0]) { // odaNo iliskiler.txtdeki veriye e�itse bir kay�t var ve oda doludur.
				dolu = true;
			}
		}
	} //else oda yok.
	return !dolu; //Bo� olup olmad���n� sordu�undan dolunun tersini al�yoruz.
}
public:bool MusteriMevcutMu(int musNo) {
	ifstream myfile;
	bool mevcut = false; //M��terinin mevcut olma durumunu alan de�i�ken.
	myfile.open("musteriler.txt");
	string a;
	while (myfile.good() && myfile >> a) {
		string *dizi = Ayrac(a);
		if (dizi[0] == to_string(musNo)) mevcut = true; // musteriler.txtdeki veri bizim m��teri Nomuza e�itse m��teri mevcuttur.
	}

	return mevcut;
}
public:void OdaEkle(Oda oda) {
	if (!OdaMevcutMu(oda.No)) { //Oda Mevcut mu diye kontrol ediyoruz.
		ofstream myfile;
		myfile.open("odalar.txt", ios::app); //odalar.txt'yi ekleme modunda a��yoruz.
		myfile << oda.No << ";" << oda.Ucret << endl; //oda no ve �cretini arada ; olarak yazd�r�yoruz.
		myfile.close();
		GirisTemizle();
	}
	else {
		HataGoster("Oda Zaten Mevcut, L�tfen Tekrar Deneyiniz...", 1); // Oda mevcutsa 1 saniyelik hata verdirelim.
	}
}
public:void OdaSil(int odaNo) {
	ifstream myfile;
	myfile.open("odalar.txt"); // odalar.txt okuma modunda a��l�r.
	string a; 
	int silinecekSatir = 0; // silinecek sat�r�n ��renilmesi gerekiyor.
	int donguSayisi = 0; // d�ng� say�s� okunmaya ba�lanan sat�r� temsil edecektir.
	while (myfile.good() && myfile >> a) {
		donguSayisi++; // okunan sat�r� temsil eden de�i�keni artt�r�r�z.
		string *dizi = Ayrac(a);
		if (dizi[0] == to_string(odaNo)) // odalar.txt'den gelen veri odano'ya e�itse silinecek sat�r� buldu�umuz anlam�na gelir.
		{
			silinecekSatir = donguSayisi; // silinecek sat�r� sat�r de�i�kenimize e�itleriz.
			break; //Okumayla i�imiz bitti�inden while blo�undan ��kar�z.
		}
	}
	myfile.close(); // dosya kapan�r.
	if (silinecekSatir == 0) { //Herhangi bir sat�r e�itlenmediyse oda yok.
		HataGoster("Otelimizde " + to_string(odaNo) + " nolu oda bulunmamaktad�r.", 2);
		return; //fonksiyonu bitir.
	}
	myfile.open("odalar.txt"); //art�k odalar� yazmaya ba�lamak i�in ilk �nce okuma moduna al�yoruz.
	string b;
	int yeniSatir = 0; // Biraz �nceki gibi sat�r say�s�n� bulmak i�in de�i�ken at�yoruz.
	while (myfile.good() && myfile >> b) {
		yeniSatir++; //sat�r say�s�n� artt�ral�m.
		if (yeniSatir != silinecekSatir) //sat�r say�s� bizim buldu�umuz silinecek sat�r ile ayn� de�ilse sat�rlar� yazd�ral�m. Ayn�ysa hi�bir �ey yapmas�n.
		{
			ofstream urfile;
			urfile.open("tmp_odalar.txt", ios::app); // temp(gecici) olarak tmp_odalar.txt'yi ekleme modunda a�al�m.
			urfile << b << endl; // etkilenmeyen sat�rlar� yazd�ral�m.
			urfile.close(); // yazma i�lemi i�eren file'� kapatal�m
		}
	}
	myfile.close(); // okuma i�lemi i�in olu�turulan file'� kapatal�m.
	remove("odalar.txt"); //eski dosyay� silelim.
	rename("tmp_odalar.txt", "odalar.txt"); //yeni dosyay� eskisinin ad�nda d�zenleyelim.
	//
	IliskiSil(odaNo, "oda"); // oda silindi�inde odaya ba�l� ili�kileri de silelim.
	//silinecekSatir olmadan tekrar yaz.
}
public:int MusteriNoOlustur() {
	ifstream myfile;
	string SonNo = ""; // Son eklenen m��teri numaras� de�i�keni.
	myfile.open("musteriler.txt");
	string a;
	while (myfile.good() && getline(myfile,a)) {
		string *dizi = Ayrac(a); 
		SonNo = dizi[0]; // While'�n son d�n���nde en son m��teri numaras�n� tutacak SonNo de�i�keni.
	}
	myfile.close();
	int yeniNo = (SonNo != "") ? stoi(SonNo) : 0; // yeniNo SonNo bo� de�ilse SonNo'yu, bo� ise 0'� tutacakt�r.
	yeniNo++; //yeniNo'yu artt�r�rsak olu�mayan bir m��teri numaras� elde ederiz.
	return yeniNo;
}
public:void MusteriEkle(Musteri mus) {
	/*
	TC Kimlik No �zelli�i bir anahtar belirtmedi�inden bulunup bulunmad���na bak�lmad�.
	*/
	ofstream myfile;
	myfile.open("musteriler.txt", ios::app); //musteriler.txt yazma modunda a��l�r.
	myfile << to_string(MusteriNoOlustur()) << ";" << mus.TC << ";" << mus.Ad << ";" << mus.Soyad << endl; // M��teriler i�in otomatik m��teriNo olu�turulur ve gelen veriler ile musteriler.txt'ye eklenir.
	myfile.close(); //dosya kapat�l�r.
}
public:void MusteriSil(int musNo) {
	ifstream myfile;
	myfile.open("musteriler.txt"); //musteriler.txt okuma modunda a��l�r.
	string a;
	int silinecekSatir = 0; // silinecek sat�r de�i�keni
	int donguSayisi = 0; // d�ng� de�i�keni.
	while (myfile.good() && getline(myfile, a)) {
		donguSayisi++; //d�ng� de�i�keni artar.
		string *dizi = Ayrac(a);
		if (dizi[0] == to_string(musNo)) // musteriler.txt'den gelen MusteriNo verisi parametreden gelen veriye e�itse silinecek sat�r bulundu.
		{
			silinecekSatir = donguSayisi; // silinecek sat�r� �imdiki sat�ra ata.
			break; // art�k dosyayla alakam�z kalmad���ndan whiledan ��k.
		}
	}
	myfile.close(); // okuma dosyas�n� kapat.
	if (silinecekSatir == 0) { // silinecek sat�r yoksa m��teri yoktur.
		HataGoster("Otelimizde " + to_string(musNo) + " nolu m��teri kay�tl� de�ildir.", 2);
		return;
	}
	myfile.open("musteriler.txt"); //musteriler.txt'yi okuma olarak a�.
	string b;
	int yeniSatir = 0; //d�ng� sat�r de�i�keni
	while (myfile.good() && getline(myfile, b)) {
		yeniSatir++;
		if (yeniSatir != silinecekSatir) //sat�r bizim �nceden hesaplad���m�z silinecek sat�rla e�it de�ilse yazd�r. E�itse bir �ey yapma.
		{
			ofstream urfile;
			urfile.open("tmp_musteriler.txt", ios::app); //temp(gecici) olarak tmp_musteriler.txt'yi ekleme modunda a�.
			urfile << b << endl; // i�lem yap�lmayacak sat�r� ekle.
			urfile.close(); //yaz�m i�lemini kapat.
		}
	}
	myfile.close(); // okuma i�lemini kapat.
	remove("musteriler.txt"); // eski dosya silinir.
	rename("tmp_musteriler.txt", "musteriler.txt"); // yeni dosya eski ad�n� al�r.
	//
	IliskiSil(musNo,"musteri"); // M��teri ile ili�kili bir oda varsa oda bo�alt�l�r.
	//silinecekSatir olmadan tekrar yaz.
}
public:void MusteriListele() {
	ifstream myfile;
	myfile.open("musteriler.txt"); // musteriler.txt okuma modunda a��l�r.
	string a;
	int musterisayisi = 0; //m��teri say�s� 0 olarak belirlenir.
	while (myfile.good() && getline(myfile,a)) {
		string *dizi = Ayrac(a); 
		musterisayisi++;//her okumada m��teri say�s� artar.
		for (int i = 0; i < 4; i++)
		{ //Her bilgi i�in bir d�ng�.
			if (i == 0) { cout << "M��teri No:"; cout << setw(3) << dizi[i]; }
			else if (i == 1) { cout << " - TC:"; cout << setw(11) << dizi[i]; }
			else if (i == 2) { cout << " - Ad:"; cout << setw(10) << dizi[i]; }
			else if (i == 3) { cout << " - Soyad:"; cout << setw(10) << dizi[i]; }
		}
		cout << endl;
	}
	cout << "Otelimize kay�tl� m��teri say�s�:" << musterisayisi << endl;
}
public:void IliskiEkle(int OdaNo, int MusNo) {
		ofstream myfile;
		myfile.open("iliskiler.txt", ios::app); // iliskiler.txt ekleme modunda a��l�r.
		myfile << to_string(OdaNo) << ";" << to_string(MusNo) << endl; // odaNo ve MusNo ; ile ayr�larak eklenir.
		myfile.close();
}
public:void IliskiSil(int no, string type) {
	if (type == "oda") { //�li�ki oda silinirken ger�ekle�iyorsa:
		do {
			ifstream myfile;
			myfile.open("iliskiler.txt"); //iliskiler.txt okuma modunda a��l�r.
			string a;
			int silinecekSatir = 0; // silinecek sat�r i�in de�i�ken.
			int donguSayisi = 0; //d�ng� sat�r de�i�keni.
			while (myfile.good() && myfile >> a) {
				donguSayisi++; //her sat�rda artar.
				string *dizi = Ayrac(a);
				if (dizi[0] == to_string(no)) // txtden gelen veri e�itse parametreye silinecek sat�r bulunur.
				{
					silinecekSatir = donguSayisi; // silinecek sat�r bulundu.
					break; // while ile i�imiz kalmad���ndan ��k�ld�.
				}
			}
			myfile.close(); // dosya kapan�r.
			if (silinecekSatir == 0) { // silinecek sat�r yoksa do while'dan ��k�l�r.
				break;
			}
			myfile.open("iliskiler.txt"); // iliskiler.txt okuma modunda a��l�r.
			string b;
			int yeniSatir = 0; //sat�r d�ng� de�i�keni
			while (myfile.good() && myfile >> b) {
				yeniSatir++; //sat�rda artar.
				if (yeniSatir != silinecekSatir) // d�ng� de�i�keni hesaplanan sat�rla ayn�ysa i�lem yapma, farkl�ysa ekle.
				{
					ofstream urfile;
					urfile.open("tmp_iliskiler.txt", ios::app); // temp(ge�ici) olarak bir dosya olu�turulur ve ona aktar�l�r.
					urfile << b << endl; //aktar.
					urfile.close(); //yazma kapan�r.
				}
			}
			myfile.close(); //okuma kapan�r.
			remove("iliskiler.txt"); // iliskiler.txt silinir.
			rename("tmp_iliskiler.txt", "iliskiler.txt"); // temp dosya ger�ek ad�n� al�r.
		} while (1 == 1); //sonsuz d�ng�(bir ki�inin birden fazla odas� olabilir).
		
	}
	else if (type == "musteri") {
		do {
			ifstream myfile;
			myfile.open("iliskiler.txt");//iliskiler.txt okuma modunda a��l�r.
			string a;
			int silinecekSatir = 0; //silinecek sat�r de�i�keni.
			int donguSayisi = 0; // dongu sat�r de�i�keni
			while (myfile.good() && myfile >> a) {
				donguSayisi++; //artt�r�l�r.
				string *dizi = Ayrac(a);
				if (dizi[1] == to_string(no)) //al�nan veri e�itse parametreye 
				{
					silinecekSatir = donguSayisi; //silinecek sat�r bulunur.
					break; //whiledan ��k�l�r.
				}
			}
			myfile.close(); //okuma dosyas� kapan�r.
			if (silinecekSatir == 0) { // sat�r silinmiyorsa dowhile'dan ��k�l�r.
				break;
			}
			myfile.open("iliskiler.txt"); //iliskiler.txt okuma modunda a��l�r.
			string b;
			int yeniSatir = 0;
			while (myfile.good() && myfile >> b) {
				yeniSatir++;
				if (yeniSatir != silinecekSatir) // sat�r say�s� bulunan silinecek sat�r say�s�na e�itse bir �ey yap�lmaz, de�ilse eklenir sat�rlar.
				{
					ofstream urfile;
					urfile.open("tmp_iliskiler.txt", ios::app); // temp(gecici) dosya olu�turulur her sat�r ona aktar�l�r.
					urfile << b << endl; // aktarma
					urfile.close(); // yazma kapat
				}
			}
			myfile.close(); // okuma kapat
			remove("iliskiler.txt"); //ana dosya silinir.
			rename("tmp_iliskiler.txt", "iliskiler.txt"); // son dosya eski ad�n� al�r.
		} while (1 == 1); //sonsuz d�ng�.
		
	}
}
public:void IliskiListele() {
	ifstream myfile;
	myfile.open("iliskiler.txt"); //iliskiler.txt okuma modunda a��l�r.
	string a;
	int musterisayisi = 0; //m��teri say�s� 0 olur.
	while (myfile.good() && getline(myfile, a)) {
		string *dizi = Ayrac(a);
		musterisayisi++; //m��teri say�s� artt�r�l�r.
		int lenn = (dizi[0].length() < dizi[1].length()) ? dizi[1].length() : dizi[0].length(); // Tasar�m i�in gerekli de�i�ken - M��teri No veya Oda Nonun hangisinin uzunlu�u b�y�kse onu al�r.
		lenn = (lenn < 3) ? lenn = 3 : lenn = lenn;
		for (int i = 0; i < 4; i++)
		{ //Kutucuklar i�in for d�ng�s�.
			if (i == 0) { cout << "************";  for (int j = 0; j < lenn; j++)cout << "*"; cout << endl; }
			else if (i == 1) { cout << setw(lenn+7) << left << "* Oda "; cout << right << setw(lenn)  << dizi[0] << right  << " *" << endl; }
			else if (i == 2) { cout << setw(lenn+7) << left << "* M��teri "; cout << right << setw(lenn)  << dizi[1] << right << " *" << endl; }
			else if (i == 3) { cout << "************";  for (int j = 0; j < lenn; j++)cout << "*"; cout << endl; }
		}
		cout << endl;
	}
}
}otel;
int main()
{
	setlocale(LC_ALL, "turkish"); //TR karakterler i�in.
	system("COLOR 9F"); // Arkaplan ve Yaz�m rengi i�in.
	MenuGetir(NULL); // Program ilk a��l�rken ana men� gelsin.
	return 0;
}
void MenuGetir(char secim) {
	/*
	menu de�i�keni ana de�i�kendir. 
	Otel i�lemlerini i�erir. (Oda, M��teri, Oda Kay�t i�lemleri)
	secim de�i�keni ise sadece bu menulerin i�indeki i�lemleri i�erir (kay�t, silme, listeleme).
	*/
	system("cls");
	switch (menu) {
	case 0: //ANA MEN�
		cout << "Otel ��lemleri" << endl;
		cout << "---------------" << endl;
		cout << "1-Oda ��lemleri" << endl;
		cout << "2-M��teri ��lemleri" << endl;
		cout << "3-Oda Kay�t ��lemleri" << endl;
		cout << "9-��k��" << endl;
		cout << "Se�iminiz:";
		menu = _getch(); //Se�imden gelen men� de�i�kenine aktar�l�r.
		islem = false; // ilk men�de i�lem olmad���ndan i�lem false olur.
		MenuGetir(NULL); //Menu �a��r�l�r.
		break;
	case '1': // ODA ��LEMLER�
		if (!islem) {
			cout << "Oda ��lemleri" << endl;
			cout << "---------------" << endl;
			cout << "1-Oda Ekle" << endl;
			cout << "2-Oda Sil" << endl;
			cout << "3-Oda Listele" << endl;
			cout << "9-�st Men�" << endl;
			cout << "Se�iminiz:";
			ch = _getch();
			islem = true;
			MenuGetir(ch);
		}
		switch (secim)
		{
		case '1': //Oda Ekle.
			Otel::Oda oda; //Otel s�n�f�ndaki Oda struct�ndan olu�tur.
			cout << "Oda Ekleme ��lemi" << endl;
			cout << "---------------" << endl;
			cout << "Oda Numaras�n� Giriniz:";
			cin >> oda.No;
			cout << endl << "Oda �cretini Giriniz:";
			cin >> oda.Ucret;
			if (!cin) { //bir hata varsa iptal et.
				GirisTemizle();
				HataGoster("Giri�lerde Hata Olu�tu, Tekrar Deneyiniz...", 0.5); //hata g�ster.
			}
			else {
				otel.OdaEkle(oda); //oda ekle.
			}

			//Odalar Dosyaya yazd�r!
			break;
		case '2': // Oda Sil.
			cout << "######## ODALARIMIZ ########" << endl;
			otel.OdaListele();
			cout << "############################" << endl;
			int SilinecekOdaNo;
			cout << "Oda Silme ��lemi" << endl;
			cout << "---------------" << endl;
			cout << "Oda Numaras�n� Giriniz:";
			cin >> SilinecekOdaNo;
			if (!cin) {
				GirisTemizle();
				HataGoster("Giri�lerde Hata Olu�tu, Tekrar Deneyiniz...", 0.5);
			}
			else if (!otel.OdaMevcutMu(SilinecekOdaNo)) {
				GirisTemizle();
				HataGoster("Girilen oda mevcut de�ildir, Tekrar Deneyiniz...", 1);
			}
			else {
				otel.OdaSil(SilinecekOdaNo);
			}

			break;
		case '3': // Odalar� Listele.
			cout << "######## ODALARIMIZ ########" << endl;
			otel.OdaListele();
			cout << "Ana men�ye gitmek i�in herhangi bir tu�a bas�n...";
			_getch();
			break;
		case '9': //�st Men�.
			UstMenu();
			break;
		default: // Hatal�!
			if (secim != '\0')
				HataGoster("Hatal� Giri�!", 0.5, false);
			UstMenu();
			break;
		}
		break;
	case '2': //M��TER� ��LEMLER�
		if (!islem) {
			cout << "M��teri ��lemleri" << endl;
			cout << "---------------" << endl;
			cout << "1-M��teri Ekle" << endl;
			cout << "2-M��teri Sil" << endl;
			cout << "3-M��terileri Listele" << endl;
			cout << "9-�st Men�" << endl;
			cout << "Se�iminiz:";
			ch = _getch();
			islem = true;
			MenuGetir(ch);
		}
		switch (secim)
		{
		case '1': //M��teri Ekle.
		{
			GirisTemizle();
			if (!cin) cin.ignore();
			Otel::Musteri musteri;
			cout << "Oda Ekleme ��lemi" << endl;
			cout << "---------------" << endl;
			cout << "M��teri TC No Giriniz:";
			getline(cin, musteri.TC);
			bool tcRakam = (musteri.TC.find_first_not_of("0123456789") == string::npos); //musteri.TC'nin "0123456789" karakterlerini i�erip i�ermedi�ini(say� olup olmad���n�) kontrol eden bir bool de�i�keni.
			if (!cin || !tcRakam || musteri.TC.length() != 11) {
				if (!cin) {
					GirisTemizle();
				}
				HataGoster("Giri�lerde Hata Olu�tu, Tekrar Deneyiniz...", 0.5);
			}
			cout << "M��teri Ad� Giriniz:";
			getline(cin,musteri.Ad);
			cout << "M��teri Soyad� Giriniz:";
			getline(cin, musteri.Soyad);
			cout << endl;
			if (!cin || !tcRakam || musteri.TC.length() != 11) {
				if (!cin) {
					GirisTemizle();
				}
				HataGoster("Giri�lerde Hata Olu�tu, Tekrar Deneyiniz...", 0.5);
			}
			else {
				otel.MusteriEkle(musteri);
			}
		}
		break;
		case '2': // M��teri Sil.
			cout << "######## M��TER�LER�M�Z ########" << endl;
			otel.MusteriListele();
			cout << "################################" << endl;
			int SilinecekMusNo;
			cout << "M��teri Silme ��lemi" << endl;
			cout << "---------------" << endl;
			cout << "M��teri Numaras�n� Giriniz:";
			cin >> SilinecekMusNo;
			if (!cin) {
				GirisTemizle();
				HataGoster("Giri�lerde Hata Olu�tu, Tekrar Deneyiniz...", 0.5);
			}
			else {
				otel.MusteriSil(SilinecekMusNo);
			}

			break;
		case '3': // M��terileri Listele.
			cout << "######## M��TER�LER�M�Z ########" << endl;
			otel.MusteriListele();
			cout << "Ana men�ye gitmek i�in herhangi bir tu�a bas�n...";
			_getch();
			break;
		case '9': //�st Men�.
			UstMenu();
			break;
		default: // Hatal�!
			if (secim != '\0')
				HataGoster("Hatal� Giri�!", 0.5, false);
			UstMenu();
			break;
		}
		break;
	case '3': // ATAMA ��LEMLER�
		if (!islem) {
			cout << "Atama ��lemleri" << endl;
			cout << "---------------" << endl;
			cout << "1-M��teriyi Odaya Ata" << endl;
			cout << "2-Oday� Bo�alt" << endl;
			cout << "3-Oda ve M��teri �li�kilerini Listele" << endl;
			cout << "9-�st Men�" << endl;
			cout << "Se�iminiz:";
			ch = _getch();
			islem = true;
			MenuGetir(ch);
		}
		switch (secim)
		{
		case '1': //M��teriyi Odaya Ata.
			cout << "######## BO� ODALARIMIZ ########" << endl;
			otel.OdaListele(true);
			cout << "################################" << endl;
			int atanacakOdaNo;
			cout << "Hangi Odaya Atama ��lemi Ger�ekle�tirilecek?" << endl;
			cout << "---------------" << endl;
			cout << "Oda Numaras�n� Giriniz:";
			cin >> atanacakOdaNo;
			if (!cin) {
				GirisTemizle();
				HataGoster("Giri�lerde Hata Olu�tu, Tekrar Deneyiniz...", 0.5);
			}
			else {
				if (otel.OdaMevcutMu(atanacakOdaNo)) {
					if (otel.OdaBosMu(atanacakOdaNo)) {
						system("cls");
						cout << "######## M��TER�LER�M�Z ########" << endl;
						otel.MusteriListele();
						cout << "################################" << endl;
						int atanacakMusNo;
						cout << "M��teri Silme ��lemi" << endl;
						cout << "---------------" << endl;
						cout << "M��teri Numaras�n� Giriniz:";
						cin >> atanacakMusNo;
						if (!cin) {
							GirisTemizle();
							HataGoster("Giri�lerde Hata Olu�tu, Tekrar Deneyiniz...", 0.5);
						}
						else {
							//i�lemini yap.
							if (otel.MusteriMevcutMu(atanacakMusNo)) {

								otel.IliskiEkle(atanacakOdaNo, atanacakMusNo);
							}

							else {
								GirisTemizle();
								HataGoster("B�yle bir m��teri mevcut de�il, Tekrar Deneyiniz...", 0.5);
							}
						}
					}
					else {
						GirisTemizle();
						HataGoster(to_string(atanacakOdaNo) + " nolu odam�z doludur. Ba�ka bir oday� deneyiniz.", 1);
					}
				}
				else {
					GirisTemizle();
					HataGoster("B�yle bir oda mevcut de�il, Tekrar Deneyiniz...", 0.5);
				}
			}
				
			break;
		case '2': //Oday� Bo�alt.
			cout << "######## DOLU ODALARIMIZ ########" << endl;
			otel.OdaListele(false);
			cout << "#################################" << endl;
			int bosalacakOdaNo;
			cout << "Hangi Oda Bo�alt�lacak?" << endl;
			cout << "---------------" << endl;
			cout << "Oda Numaras�n� Giriniz:";
			cin >> bosalacakOdaNo;
			if (!cin) {
				GirisTemizle();
				HataGoster("Hatal� Giri�, Tekrar Deneyiniz...", 0.5);
			}
			else if (!otel.OdaMevcutMu(bosalacakOdaNo)) {
				GirisTemizle();
				HataGoster("Oda Mevcut De�ildir, Tekrar Deneyiniz...", 0.5);
			}
			else if (otel.OdaBosMu(bosalacakOdaNo)) {
				GirisTemizle();
				HataGoster("Oda Zaten Bo�, Tekrar Deneyiniz...", 0.5);
			}
			else {
				otel.IliskiSil(bosalacakOdaNo, "oda");
				//YAP.
			}
			break;
		case '3': //Oda ve M��teri �li�kilerini Listele.
			cout << "############### ODALAR ve M��TER�LER ###################" <<endl<<endl;
			otel.IliskiListele();
			cout << "Ana men�ye gitmek i�in herhangi bir tu�a bas�n...";
			_getch();
			break;
		case '9': //�st Men�.
			UstMenu();
			break;
		default: // Hatal�!
			if (secim != '\0')
				HataGoster("Hatal� Giri�!", 0.5, false);
			UstMenu();
			break;
		}
		break;
	case '9':
		Cikis();
		break;
	default: // �lk Hatal� Giri�
		menu = NULL;
		HataGoster("Hatal� Giri�!", 0.5);
		break;
	}
}
void HataGoster(string hata, double saniye) {
	system("cls"); //konsol temizlenir.
	system("COLOR 9C"); //yaz� rengi de�i�ir.
	cout << hata; // hata yaz�l�r.
	islem = false; //i�lem varsa kapan�r. 
	Sleep(saniye * 1000); // parametreden gelen veri 1000ms ile �arp�l�r bekletilir.
	system("COLOR 9F"); // yaz� rengi normale d�ner.
	MenuGetir(NULL); // men� �a�r�l�r.
}
void HataGoster(string hata, double saniye, bool menu) {
	system("cls"); // Konsol temizlenir.
	system("COLOR 9C"); //Yaz� rengi de�i�ir.
	cout << hata; // Hata yaz�l�r.
	islem = false; // i�lem kapan�r.
	Sleep(saniye * 1000); // parametredeki saniye 1000ms ile �arp�l�r bekletilir.
	system("COLOR 9F"); // Yaz� rengi normale d�ner.
}
void UstMenu() {
	menu = 0; //men� s�f�rlan�r.
	islem = false; //bir i�lem yap�ld�ysa kapat�l�r.
	MenuGetir(NULL); // MenuGetir fonksiyonuyla men� getirilir.
}
void Cikis() { //E�lenceli ��k��.
	system("cls"); //konsol temizlenir.
	cout << "Ho��akal�n!"; //Ho��akal�n yaz�l�r.
	system("COLOR 1A"); //Arkaplan ve yaz� rengi de�i�ir.
	Sleep(100);// 100ms beklenir.
	system("COLOR 2B");
	Sleep(100);
	system("COLOR 3C");
	Sleep(100);
	system("COLOR 4D");
	Sleep(100);
	system("COLOR 5E");
	Sleep(100);
	system("COLOR 6F");
	Sleep(300);
	exit(0); //Programdan ��k�l�r.
}
string *Ayrac(string veri) {
	//1;20 gelen veri dizi halinde [0]:1, [1]:20 olarak ��k�yor.
	int i = 1; //ka� adet veri oldu�unu g�steren de�i�ken.
	stringstream ss(veri); // stringi i�leyen s�n�f (filestream gibi)
	string token; // her noktal� virg�l ile ayr�lan veriyi ekleyen de�i�ken burada sadece saymak i�in konulmu�tur.
	while (getline(ss, token, ';')) { // her noktal� virg�lle ayr�lan verileri teker teker i�leyen while d�ng�s�.
		i++; // bu while d�ng�s� sadece ka� adet veri oldu�unu bulan bir d�ng�d�r. Bu d�ng�yle pointer yard�m�yla dizi olu�turulur.
	}
	string* arr = new string[i]; // ka� adet veri varsa o b�y�kl�kte dizi olu�turulur.
	i = 0; // i say�s� 0 yap�l�r tekrardan.
	stringstream ss1(veri); // ayn� s�n�f tekrardan olu�turulur ayn� veriler i�lenece�i i�in.
	string token1; // her noktal� virg�l ile ayr�lan veriyi ekleyen de�i�ken.
	while (getline(ss1, token1, ';')) { // Her noktal� virg�l ile ayr�lan veriyi i�leyen while d�ng�s�.
		arr[i] = token1; // daha �nce olu�turulan diziye burada her noktal� virg�l ile ayr�lan veri eklenir.
		i++; // diziye eklemek i�in i artt�r�l�r.
	}
	return arr; // asd;123;345 gibi veriyi 3 elemanl� elemanlar� "asd", "123", "345" olan bir dizi haline getirip d�nd�r�r.
}
void GirisTemizle() {
	if (!cin) {
		cin.clear(); // cin fonksiyonu hatal� oldu�unda 0 d�nd�r�r, clear fonksiyonu bunu d�zeltir.
		cin.ignore(100, '\n'); // ignore fonksiyonu bir hata oldu�unda o hataya dair (100) sat�rl�k veriyi reddeder.
	}
}
/*
 TC kimlik no algoritmas�na girilmedi.
 TC Kimlik no bir anahtar i�ermedi�inden m��teriler dosyas�nda arat�lmad�.
*/