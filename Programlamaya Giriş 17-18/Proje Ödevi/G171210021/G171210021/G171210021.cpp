/****************************************************************************
**					SAKARYA ÜNÝVERSÝTESÝ
**		   BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**			      PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI.....: P_1
**				ÖÐRENCÝ ADI...... : ONUR OSMAN GÜLE
**				ÖÐRENCÝ NUMARASI. : G171210021
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
int menu = 0; // Ana Menü Deðiþkeni
int ch = NULL; // Menü Ýþlev Deðiþkeni (ch:kanal)
bool islem = false; // islem yaptýrma deðiþkeni
void MenuGetir(char); // kanala göre menü getirme fonksiyonu
void HataGoster(string, double); // menülü hata gösterme fonksiyonu
void HataGoster(string, double, bool); //menüsüz hata gösterme fonksiyonu
void UstMenu(); // Üst menüye gitme fonksiyonu
string *Ayrac(string); // string dönüþ tipli '...;...;...;...' ifadeyi (;) karakterine göre split edip dizi döndüren fonksiyon. (Ýki isimli giriþlerde hata oluþtuðundan kullanýldý!)
void Cikis(); // Çýkýþ fonksiyonu
void GirisTemizle();
class Otel { // Ana Sýnýfýmýz
public: struct Oda {
	int No;
	double Ucret;
}; //Oteldeki Her Oda Ýçin Structýmýz
public:struct Musteri {
	int No;
	string Ad;
	string Soyad;
	string TC;
}; // Oteldeki her müþteri için Structýmýz
public:void OdaListele(bool sadeceBos) {
	ifstream myfile;
	myfile.open("odalar.txt"); //odalar.txt okunmak için açýlýr.
	string a; // Gereksiz(kullanýlmayacak) bir atama deðiþkeni oluþturulur.
	int odasayisi = 0; // oda sayýsý belirlenir.
	while (myfile.good() && myfile >> a) { //dosyanýn sonuna kadar okunur.
		string *dizi = Ayrac(a); // Ayrac fonksiyonu ile birlikte okunan satýr diziye atýlýr.
		if (sadeceBos) { // Eðer sadeceBos parametresi true ise sadece boþ odalarý listeler
			odasayisi++;
			ifstream bosfile;
			bosfile.open("iliskiler.txt"); // iliskiler.txt dosyasý okunmak için açýlýr.
			string bos; // gereksiz bir atama deðiþkeni oluþturulur.
			bool gec = false; // dolu odalarý geçmek için bir deðiþken oluþturulur.
			while (bosfile.good() && bosfile >> bos) { // dosyanýn sonuna kadar okunur.
				string *bosdizi = Ayrac(bos); // Ayrac fonksiyonu ile birlikte okunan satýr diziye atýlýr.
				if (dizi[0] == bosdizi[0]) { // Okunan satýr ile dizideki satýr eþit ise(Oda dolu ise) geçer.
					odasayisi--;
					gec = true;
				}
			}
			if (gec) continue; //Devam ettirir.
		}
		else { // Sadece Dolu odalarý listeleme
			ifstream bosfile;
			bosfile.open("iliskiler.txt"); //iliskiler.txt okuma olarak açýlýr.
			string bos; //gereksiz bir deðiþken oluþturulur.
			bool gec = false; //boþlarý geçmek için deðiþken.
			while (bosfile.good() && bosfile >> bos) { //dosyanýn sonuna kadar oku.
				string *bosdizi = Ayrac(bos);  // Ayrac fonksiyonu ile birlikte okunan satýr diziye atýlýr.
				if (dizi[0] == bosdizi[0]) { // Okunan satýr ile dizideki satýr eþit ise(Oda boþ ise) geçer.
					odasayisi++;
					gec = true;
					break;
				}
				
			}
			if (!gec) continue; //devam ettirir.
		}
		for (int i = 0; i < 2; i++)
		{ //fonksiyonda istenenleri yazdýrýr.
			if (i == 0) cout << "Oda No:";
			else cout << " - Ücret:";
			cout << setw(5) << dizi[i];
		}
		cout << endl;
	}
	if(sadeceBos) cout << "Otelimizdeki boþ oda sayýsý:" << odasayisi << endl;
	else cout << "Otelimizdeki dolu oda sayýsý:" << odasayisi << endl;
}
public:void OdaListele() { // Tüm odalarý yazdýrýr
	ifstream myfile;
	myfile.open("odalar.txt"); // odalar.txt okuma olarak açýlýr.
	string a;
	int odasayisi = 0;
	while (myfile.good() && myfile >> a) { //dosyanýn sonuna kadar.
		string *dizi = Ayrac(a); //Ayrac fonk. ile diziye atýlýr.
		odasayisi++;
		for (int i = 0; i < 2; i++)
		{ //Odalar yazdýrýlýr.
			if (i == 0) cout << "Oda No:";
			else cout << " - Ücret:";
			cout << setw(5) << dizi[i];
		}
		cout << endl;
	}
	cout << "Otelimizdeki oda sayýsý:" << odasayisi << endl;
}
public:bool OdaMevcutMu(int odaNo) {
	ifstream myfile;
	bool mevcut = false;
	myfile.open("odalar.txt"); //odalar.txt okumada açýlýr.
	string a;
	while (myfile.good() && myfile >> a) {
		string *dizi = Ayrac(a); //Ayrac fonksiyonu ile diziye aktarýlýr.
		if (dizi[0] == to_string(odaNo)) mevcut = true; // odalar.txt'den gelen veri odaNo'ya eþit mi deðil mi kontrol et. Eþitse oda vardýr.
	}

	return mevcut;
}
public:bool OdaBosMu(int odaNo) {
	bool dolu = false; //odanýn doluluðu kontrolü amaçlý deðiþken.
	if (OdaMevcutMu(odaNo)) { //ilk önce odanýn mevcut olup olmadýðýný kontrol edelim.
		ifstream bosfile;
		bosfile.open("iliskiler.txt");
		string bos;
		while (bosfile.good() && bosfile >> bos) {
			string *bosdizi = Ayrac(bos);
			if (to_string(odaNo) == bosdizi[0]) { // odaNo iliskiler.txtdeki veriye eþitse bir kayýt var ve oda doludur.
				dolu = true;
			}
		}
	} //else oda yok.
	return !dolu; //Boþ olup olmadýðýný sorduðundan dolunun tersini alýyoruz.
}
public:bool MusteriMevcutMu(int musNo) {
	ifstream myfile;
	bool mevcut = false; //Müþterinin mevcut olma durumunu alan deðiþken.
	myfile.open("musteriler.txt");
	string a;
	while (myfile.good() && myfile >> a) {
		string *dizi = Ayrac(a);
		if (dizi[0] == to_string(musNo)) mevcut = true; // musteriler.txtdeki veri bizim müþteri Nomuza eþitse müþteri mevcuttur.
	}

	return mevcut;
}
public:void OdaEkle(Oda oda) {
	if (!OdaMevcutMu(oda.No)) { //Oda Mevcut mu diye kontrol ediyoruz.
		ofstream myfile;
		myfile.open("odalar.txt", ios::app); //odalar.txt'yi ekleme modunda açýyoruz.
		myfile << oda.No << ";" << oda.Ucret << endl; //oda no ve ücretini arada ; olarak yazdýrýyoruz.
		myfile.close();
		GirisTemizle();
	}
	else {
		HataGoster("Oda Zaten Mevcut, Lütfen Tekrar Deneyiniz...", 1); // Oda mevcutsa 1 saniyelik hata verdirelim.
	}
}
public:void OdaSil(int odaNo) {
	ifstream myfile;
	myfile.open("odalar.txt"); // odalar.txt okuma modunda açýlýr.
	string a; 
	int silinecekSatir = 0; // silinecek satýrýn öðrenilmesi gerekiyor.
	int donguSayisi = 0; // döngü sayýsý okunmaya baþlanan satýrý temsil edecektir.
	while (myfile.good() && myfile >> a) {
		donguSayisi++; // okunan satýrý temsil eden deðiþkeni arttýrýrýz.
		string *dizi = Ayrac(a);
		if (dizi[0] == to_string(odaNo)) // odalar.txt'den gelen veri odano'ya eþitse silinecek satýrý bulduðumuz anlamýna gelir.
		{
			silinecekSatir = donguSayisi; // silinecek satýrý satýr deðiþkenimize eþitleriz.
			break; //Okumayla iþimiz bittiðinden while bloðundan çýkarýz.
		}
	}
	myfile.close(); // dosya kapanýr.
	if (silinecekSatir == 0) { //Herhangi bir satýr eþitlenmediyse oda yok.
		HataGoster("Otelimizde " + to_string(odaNo) + " nolu oda bulunmamaktadýr.", 2);
		return; //fonksiyonu bitir.
	}
	myfile.open("odalar.txt"); //artýk odalarý yazmaya baþlamak için ilk önce okuma moduna alýyoruz.
	string b;
	int yeniSatir = 0; // Biraz önceki gibi satýr sayýsýný bulmak için deðiþken atýyoruz.
	while (myfile.good() && myfile >> b) {
		yeniSatir++; //satýr sayýsýný arttýralým.
		if (yeniSatir != silinecekSatir) //satýr sayýsý bizim bulduðumuz silinecek satýr ile ayný deðilse satýrlarý yazdýralým. Aynýysa hiçbir þey yapmasýn.
		{
			ofstream urfile;
			urfile.open("tmp_odalar.txt", ios::app); // temp(gecici) olarak tmp_odalar.txt'yi ekleme modunda açalým.
			urfile << b << endl; // etkilenmeyen satýrlarý yazdýralým.
			urfile.close(); // yazma iþlemi içeren file'ý kapatalým
		}
	}
	myfile.close(); // okuma iþlemi için oluþturulan file'ý kapatalým.
	remove("odalar.txt"); //eski dosyayý silelim.
	rename("tmp_odalar.txt", "odalar.txt"); //yeni dosyayý eskisinin adýnda düzenleyelim.
	//
	IliskiSil(odaNo, "oda"); // oda silindiðinde odaya baðlý iliþkileri de silelim.
	//silinecekSatir olmadan tekrar yaz.
}
public:int MusteriNoOlustur() {
	ifstream myfile;
	string SonNo = ""; // Son eklenen müþteri numarasý deðiþkeni.
	myfile.open("musteriler.txt");
	string a;
	while (myfile.good() && getline(myfile,a)) {
		string *dizi = Ayrac(a); 
		SonNo = dizi[0]; // While'ýn son dönüþünde en son müþteri numarasýný tutacak SonNo deðiþkeni.
	}
	myfile.close();
	int yeniNo = (SonNo != "") ? stoi(SonNo) : 0; // yeniNo SonNo boþ deðilse SonNo'yu, boþ ise 0'ý tutacaktýr.
	yeniNo++; //yeniNo'yu arttýrýrsak oluþmayan bir müþteri numarasý elde ederiz.
	return yeniNo;
}
public:void MusteriEkle(Musteri mus) {
	/*
	TC Kimlik No özelliði bir anahtar belirtmediðinden bulunup bulunmadýðýna bakýlmadý.
	*/
	ofstream myfile;
	myfile.open("musteriler.txt", ios::app); //musteriler.txt yazma modunda açýlýr.
	myfile << to_string(MusteriNoOlustur()) << ";" << mus.TC << ";" << mus.Ad << ";" << mus.Soyad << endl; // Müþteriler için otomatik müþteriNo oluþturulur ve gelen veriler ile musteriler.txt'ye eklenir.
	myfile.close(); //dosya kapatýlýr.
}
public:void MusteriSil(int musNo) {
	ifstream myfile;
	myfile.open("musteriler.txt"); //musteriler.txt okuma modunda açýlýr.
	string a;
	int silinecekSatir = 0; // silinecek satýr deðiþkeni
	int donguSayisi = 0; // döngü deðiþkeni.
	while (myfile.good() && getline(myfile, a)) {
		donguSayisi++; //döngü deðiþkeni artar.
		string *dizi = Ayrac(a);
		if (dizi[0] == to_string(musNo)) // musteriler.txt'den gelen MusteriNo verisi parametreden gelen veriye eþitse silinecek satýr bulundu.
		{
			silinecekSatir = donguSayisi; // silinecek satýrý þimdiki satýra ata.
			break; // artýk dosyayla alakamýz kalmadýðýndan whiledan çýk.
		}
	}
	myfile.close(); // okuma dosyasýný kapat.
	if (silinecekSatir == 0) { // silinecek satýr yoksa müþteri yoktur.
		HataGoster("Otelimizde " + to_string(musNo) + " nolu müþteri kayýtlý deðildir.", 2);
		return;
	}
	myfile.open("musteriler.txt"); //musteriler.txt'yi okuma olarak aç.
	string b;
	int yeniSatir = 0; //döngü satýr deðiþkeni
	while (myfile.good() && getline(myfile, b)) {
		yeniSatir++;
		if (yeniSatir != silinecekSatir) //satýr bizim önceden hesapladýðýmýz silinecek satýrla eþit deðilse yazdýr. Eþitse bir þey yapma.
		{
			ofstream urfile;
			urfile.open("tmp_musteriler.txt", ios::app); //temp(gecici) olarak tmp_musteriler.txt'yi ekleme modunda aç.
			urfile << b << endl; // iþlem yapýlmayacak satýrý ekle.
			urfile.close(); //yazým iþlemini kapat.
		}
	}
	myfile.close(); // okuma iþlemini kapat.
	remove("musteriler.txt"); // eski dosya silinir.
	rename("tmp_musteriler.txt", "musteriler.txt"); // yeni dosya eski adýný alýr.
	//
	IliskiSil(musNo,"musteri"); // Müþteri ile iliþkili bir oda varsa oda boþaltýlýr.
	//silinecekSatir olmadan tekrar yaz.
}
public:void MusteriListele() {
	ifstream myfile;
	myfile.open("musteriler.txt"); // musteriler.txt okuma modunda açýlýr.
	string a;
	int musterisayisi = 0; //müþteri sayýsý 0 olarak belirlenir.
	while (myfile.good() && getline(myfile,a)) {
		string *dizi = Ayrac(a); 
		musterisayisi++;//her okumada müþteri sayýsý artar.
		for (int i = 0; i < 4; i++)
		{ //Her bilgi için bir döngü.
			if (i == 0) { cout << "Müþteri No:"; cout << setw(3) << dizi[i]; }
			else if (i == 1) { cout << " - TC:"; cout << setw(11) << dizi[i]; }
			else if (i == 2) { cout << " - Ad:"; cout << setw(10) << dizi[i]; }
			else if (i == 3) { cout << " - Soyad:"; cout << setw(10) << dizi[i]; }
		}
		cout << endl;
	}
	cout << "Otelimize kayýtlý müþteri sayýsý:" << musterisayisi << endl;
}
public:void IliskiEkle(int OdaNo, int MusNo) {
		ofstream myfile;
		myfile.open("iliskiler.txt", ios::app); // iliskiler.txt ekleme modunda açýlýr.
		myfile << to_string(OdaNo) << ";" << to_string(MusNo) << endl; // odaNo ve MusNo ; ile ayrýlarak eklenir.
		myfile.close();
}
public:void IliskiSil(int no, string type) {
	if (type == "oda") { //Ýliþki oda silinirken gerçekleþiyorsa:
		do {
			ifstream myfile;
			myfile.open("iliskiler.txt"); //iliskiler.txt okuma modunda açýlýr.
			string a;
			int silinecekSatir = 0; // silinecek satýr için deðiþken.
			int donguSayisi = 0; //döngü satýr deðiþkeni.
			while (myfile.good() && myfile >> a) {
				donguSayisi++; //her satýrda artar.
				string *dizi = Ayrac(a);
				if (dizi[0] == to_string(no)) // txtden gelen veri eþitse parametreye silinecek satýr bulunur.
				{
					silinecekSatir = donguSayisi; // silinecek satýr bulundu.
					break; // while ile iþimiz kalmadýðýndan çýkýldý.
				}
			}
			myfile.close(); // dosya kapanýr.
			if (silinecekSatir == 0) { // silinecek satýr yoksa do while'dan çýkýlýr.
				break;
			}
			myfile.open("iliskiler.txt"); // iliskiler.txt okuma modunda açýlýr.
			string b;
			int yeniSatir = 0; //satýr döngü deðiþkeni
			while (myfile.good() && myfile >> b) {
				yeniSatir++; //satýrda artar.
				if (yeniSatir != silinecekSatir) // döngü deðiþkeni hesaplanan satýrla aynýysa iþlem yapma, farklýysa ekle.
				{
					ofstream urfile;
					urfile.open("tmp_iliskiler.txt", ios::app); // temp(geçici) olarak bir dosya oluþturulur ve ona aktarýlýr.
					urfile << b << endl; //aktar.
					urfile.close(); //yazma kapanýr.
				}
			}
			myfile.close(); //okuma kapanýr.
			remove("iliskiler.txt"); // iliskiler.txt silinir.
			rename("tmp_iliskiler.txt", "iliskiler.txt"); // temp dosya gerçek adýný alýr.
		} while (1 == 1); //sonsuz döngü(bir kiþinin birden fazla odasý olabilir).
		
	}
	else if (type == "musteri") {
		do {
			ifstream myfile;
			myfile.open("iliskiler.txt");//iliskiler.txt okuma modunda açýlýr.
			string a;
			int silinecekSatir = 0; //silinecek satýr deðiþkeni.
			int donguSayisi = 0; // dongu satýr deðiþkeni
			while (myfile.good() && myfile >> a) {
				donguSayisi++; //arttýrýlýr.
				string *dizi = Ayrac(a);
				if (dizi[1] == to_string(no)) //alýnan veri eþitse parametreye 
				{
					silinecekSatir = donguSayisi; //silinecek satýr bulunur.
					break; //whiledan çýkýlýr.
				}
			}
			myfile.close(); //okuma dosyasý kapanýr.
			if (silinecekSatir == 0) { // satýr silinmiyorsa dowhile'dan çýkýlýr.
				break;
			}
			myfile.open("iliskiler.txt"); //iliskiler.txt okuma modunda açýlýr.
			string b;
			int yeniSatir = 0;
			while (myfile.good() && myfile >> b) {
				yeniSatir++;
				if (yeniSatir != silinecekSatir) // satýr sayýsý bulunan silinecek satýr sayýsýna eþitse bir þey yapýlmaz, deðilse eklenir satýrlar.
				{
					ofstream urfile;
					urfile.open("tmp_iliskiler.txt", ios::app); // temp(gecici) dosya oluþturulur her satýr ona aktarýlýr.
					urfile << b << endl; // aktarma
					urfile.close(); // yazma kapat
				}
			}
			myfile.close(); // okuma kapat
			remove("iliskiler.txt"); //ana dosya silinir.
			rename("tmp_iliskiler.txt", "iliskiler.txt"); // son dosya eski adýný alýr.
		} while (1 == 1); //sonsuz döngü.
		
	}
}
public:void IliskiListele() {
	ifstream myfile;
	myfile.open("iliskiler.txt"); //iliskiler.txt okuma modunda açýlýr.
	string a;
	int musterisayisi = 0; //müþteri sayýsý 0 olur.
	while (myfile.good() && getline(myfile, a)) {
		string *dizi = Ayrac(a);
		musterisayisi++; //müþteri sayýsý arttýrýlýr.
		int lenn = (dizi[0].length() < dizi[1].length()) ? dizi[1].length() : dizi[0].length(); // Tasarým için gerekli deðiþken - Müþteri No veya Oda Nonun hangisinin uzunluðu büyükse onu alýr.
		lenn = (lenn < 3) ? lenn = 3 : lenn = lenn;
		for (int i = 0; i < 4; i++)
		{ //Kutucuklar için for döngüsü.
			if (i == 0) { cout << "************";  for (int j = 0; j < lenn; j++)cout << "*"; cout << endl; }
			else if (i == 1) { cout << setw(lenn+7) << left << "* Oda "; cout << right << setw(lenn)  << dizi[0] << right  << " *" << endl; }
			else if (i == 2) { cout << setw(lenn+7) << left << "* Müþteri "; cout << right << setw(lenn)  << dizi[1] << right << " *" << endl; }
			else if (i == 3) { cout << "************";  for (int j = 0; j < lenn; j++)cout << "*"; cout << endl; }
		}
		cout << endl;
	}
}
}otel;
int main()
{
	setlocale(LC_ALL, "turkish"); //TR karakterler için.
	system("COLOR 9F"); // Arkaplan ve Yazým rengi için.
	MenuGetir(NULL); // Program ilk açýlýrken ana menü gelsin.
	return 0;
}
void MenuGetir(char secim) {
	/*
	menu deðiþkeni ana deðiþkendir. 
	Otel iþlemlerini içerir. (Oda, Müþteri, Oda Kayýt iþlemleri)
	secim deðiþkeni ise sadece bu menulerin içindeki iþlemleri içerir (kayýt, silme, listeleme).
	*/
	system("cls");
	switch (menu) {
	case 0: //ANA MENÜ
		cout << "Otel Ýþlemleri" << endl;
		cout << "---------------" << endl;
		cout << "1-Oda Ýþlemleri" << endl;
		cout << "2-Müþteri Ýþlemleri" << endl;
		cout << "3-Oda Kayýt Ýþlemleri" << endl;
		cout << "9-Çýkýþ" << endl;
		cout << "Seçiminiz:";
		menu = _getch(); //Seçimden gelen menü deðiþkenine aktarýlýr.
		islem = false; // ilk menüde iþlem olmadýðýndan iþlem false olur.
		MenuGetir(NULL); //Menu çaðýrýlýr.
		break;
	case '1': // ODA ÝÞLEMLERÝ
		if (!islem) {
			cout << "Oda Ýþlemleri" << endl;
			cout << "---------------" << endl;
			cout << "1-Oda Ekle" << endl;
			cout << "2-Oda Sil" << endl;
			cout << "3-Oda Listele" << endl;
			cout << "9-Üst Menü" << endl;
			cout << "Seçiminiz:";
			ch = _getch();
			islem = true;
			MenuGetir(ch);
		}
		switch (secim)
		{
		case '1': //Oda Ekle.
			Otel::Oda oda; //Otel sýnýfýndaki Oda structýndan oluþtur.
			cout << "Oda Ekleme Ýþlemi" << endl;
			cout << "---------------" << endl;
			cout << "Oda Numarasýný Giriniz:";
			cin >> oda.No;
			cout << endl << "Oda Ücretini Giriniz:";
			cin >> oda.Ucret;
			if (!cin) { //bir hata varsa iptal et.
				GirisTemizle();
				HataGoster("Giriþlerde Hata Oluþtu, Tekrar Deneyiniz...", 0.5); //hata göster.
			}
			else {
				otel.OdaEkle(oda); //oda ekle.
			}

			//Odalar Dosyaya yazdýr!
			break;
		case '2': // Oda Sil.
			cout << "######## ODALARIMIZ ########" << endl;
			otel.OdaListele();
			cout << "############################" << endl;
			int SilinecekOdaNo;
			cout << "Oda Silme Ýþlemi" << endl;
			cout << "---------------" << endl;
			cout << "Oda Numarasýný Giriniz:";
			cin >> SilinecekOdaNo;
			if (!cin) {
				GirisTemizle();
				HataGoster("Giriþlerde Hata Oluþtu, Tekrar Deneyiniz...", 0.5);
			}
			else if (!otel.OdaMevcutMu(SilinecekOdaNo)) {
				GirisTemizle();
				HataGoster("Girilen oda mevcut deðildir, Tekrar Deneyiniz...", 1);
			}
			else {
				otel.OdaSil(SilinecekOdaNo);
			}

			break;
		case '3': // Odalarý Listele.
			cout << "######## ODALARIMIZ ########" << endl;
			otel.OdaListele();
			cout << "Ana menüye gitmek için herhangi bir tuþa basýn...";
			_getch();
			break;
		case '9': //Üst Menü.
			UstMenu();
			break;
		default: // Hatalý!
			if (secim != '\0')
				HataGoster("Hatalý Giriþ!", 0.5, false);
			UstMenu();
			break;
		}
		break;
	case '2': //MÜÞTERÝ ÝÞLEMLERÝ
		if (!islem) {
			cout << "Müþteri Ýþlemleri" << endl;
			cout << "---------------" << endl;
			cout << "1-Müþteri Ekle" << endl;
			cout << "2-Müþteri Sil" << endl;
			cout << "3-Müþterileri Listele" << endl;
			cout << "9-Üst Menü" << endl;
			cout << "Seçiminiz:";
			ch = _getch();
			islem = true;
			MenuGetir(ch);
		}
		switch (secim)
		{
		case '1': //Müþteri Ekle.
		{
			GirisTemizle();
			if (!cin) cin.ignore();
			Otel::Musteri musteri;
			cout << "Oda Ekleme Ýþlemi" << endl;
			cout << "---------------" << endl;
			cout << "Müþteri TC No Giriniz:";
			getline(cin, musteri.TC);
			bool tcRakam = (musteri.TC.find_first_not_of("0123456789") == string::npos); //musteri.TC'nin "0123456789" karakterlerini içerip içermediðini(sayý olup olmadýðýný) kontrol eden bir bool deðiþkeni.
			if (!cin || !tcRakam || musteri.TC.length() != 11) {
				if (!cin) {
					GirisTemizle();
				}
				HataGoster("Giriþlerde Hata Oluþtu, Tekrar Deneyiniz...", 0.5);
			}
			cout << "Müþteri Adý Giriniz:";
			getline(cin,musteri.Ad);
			cout << "Müþteri Soyadý Giriniz:";
			getline(cin, musteri.Soyad);
			cout << endl;
			if (!cin || !tcRakam || musteri.TC.length() != 11) {
				if (!cin) {
					GirisTemizle();
				}
				HataGoster("Giriþlerde Hata Oluþtu, Tekrar Deneyiniz...", 0.5);
			}
			else {
				otel.MusteriEkle(musteri);
			}
		}
		break;
		case '2': // Müþteri Sil.
			cout << "######## MÜÞTERÝLERÝMÝZ ########" << endl;
			otel.MusteriListele();
			cout << "################################" << endl;
			int SilinecekMusNo;
			cout << "Müþteri Silme Ýþlemi" << endl;
			cout << "---------------" << endl;
			cout << "Müþteri Numarasýný Giriniz:";
			cin >> SilinecekMusNo;
			if (!cin) {
				GirisTemizle();
				HataGoster("Giriþlerde Hata Oluþtu, Tekrar Deneyiniz...", 0.5);
			}
			else {
				otel.MusteriSil(SilinecekMusNo);
			}

			break;
		case '3': // Müþterileri Listele.
			cout << "######## MÜÞTERÝLERÝMÝZ ########" << endl;
			otel.MusteriListele();
			cout << "Ana menüye gitmek için herhangi bir tuþa basýn...";
			_getch();
			break;
		case '9': //Üst Menü.
			UstMenu();
			break;
		default: // Hatalý!
			if (secim != '\0')
				HataGoster("Hatalý Giriþ!", 0.5, false);
			UstMenu();
			break;
		}
		break;
	case '3': // ATAMA ÝÞLEMLERÝ
		if (!islem) {
			cout << "Atama Ýþlemleri" << endl;
			cout << "---------------" << endl;
			cout << "1-Müþteriyi Odaya Ata" << endl;
			cout << "2-Odayý Boþalt" << endl;
			cout << "3-Oda ve Müþteri Ýliþkilerini Listele" << endl;
			cout << "9-Üst Menü" << endl;
			cout << "Seçiminiz:";
			ch = _getch();
			islem = true;
			MenuGetir(ch);
		}
		switch (secim)
		{
		case '1': //Müþteriyi Odaya Ata.
			cout << "######## BOÞ ODALARIMIZ ########" << endl;
			otel.OdaListele(true);
			cout << "################################" << endl;
			int atanacakOdaNo;
			cout << "Hangi Odaya Atama Ýþlemi Gerçekleþtirilecek?" << endl;
			cout << "---------------" << endl;
			cout << "Oda Numarasýný Giriniz:";
			cin >> atanacakOdaNo;
			if (!cin) {
				GirisTemizle();
				HataGoster("Giriþlerde Hata Oluþtu, Tekrar Deneyiniz...", 0.5);
			}
			else {
				if (otel.OdaMevcutMu(atanacakOdaNo)) {
					if (otel.OdaBosMu(atanacakOdaNo)) {
						system("cls");
						cout << "######## MÜÞTERÝLERÝMÝZ ########" << endl;
						otel.MusteriListele();
						cout << "################################" << endl;
						int atanacakMusNo;
						cout << "Müþteri Silme Ýþlemi" << endl;
						cout << "---------------" << endl;
						cout << "Müþteri Numarasýný Giriniz:";
						cin >> atanacakMusNo;
						if (!cin) {
							GirisTemizle();
							HataGoster("Giriþlerde Hata Oluþtu, Tekrar Deneyiniz...", 0.5);
						}
						else {
							//iþlemini yap.
							if (otel.MusteriMevcutMu(atanacakMusNo)) {

								otel.IliskiEkle(atanacakOdaNo, atanacakMusNo);
							}

							else {
								GirisTemizle();
								HataGoster("Böyle bir müþteri mevcut deðil, Tekrar Deneyiniz...", 0.5);
							}
						}
					}
					else {
						GirisTemizle();
						HataGoster(to_string(atanacakOdaNo) + " nolu odamýz doludur. Baþka bir odayý deneyiniz.", 1);
					}
				}
				else {
					GirisTemizle();
					HataGoster("Böyle bir oda mevcut deðil, Tekrar Deneyiniz...", 0.5);
				}
			}
				
			break;
		case '2': //Odayý Boþalt.
			cout << "######## DOLU ODALARIMIZ ########" << endl;
			otel.OdaListele(false);
			cout << "#################################" << endl;
			int bosalacakOdaNo;
			cout << "Hangi Oda Boþaltýlacak?" << endl;
			cout << "---------------" << endl;
			cout << "Oda Numarasýný Giriniz:";
			cin >> bosalacakOdaNo;
			if (!cin) {
				GirisTemizle();
				HataGoster("Hatalý Giriþ, Tekrar Deneyiniz...", 0.5);
			}
			else if (!otel.OdaMevcutMu(bosalacakOdaNo)) {
				GirisTemizle();
				HataGoster("Oda Mevcut Deðildir, Tekrar Deneyiniz...", 0.5);
			}
			else if (otel.OdaBosMu(bosalacakOdaNo)) {
				GirisTemizle();
				HataGoster("Oda Zaten Boþ, Tekrar Deneyiniz...", 0.5);
			}
			else {
				otel.IliskiSil(bosalacakOdaNo, "oda");
				//YAP.
			}
			break;
		case '3': //Oda ve Müþteri Ýliþkilerini Listele.
			cout << "############### ODALAR ve MÜÞTERÝLER ###################" <<endl<<endl;
			otel.IliskiListele();
			cout << "Ana menüye gitmek için herhangi bir tuþa basýn...";
			_getch();
			break;
		case '9': //Üst Menü.
			UstMenu();
			break;
		default: // Hatalý!
			if (secim != '\0')
				HataGoster("Hatalý Giriþ!", 0.5, false);
			UstMenu();
			break;
		}
		break;
	case '9':
		Cikis();
		break;
	default: // Ýlk Hatalý Giriþ
		menu = NULL;
		HataGoster("Hatalý Giriþ!", 0.5);
		break;
	}
}
void HataGoster(string hata, double saniye) {
	system("cls"); //konsol temizlenir.
	system("COLOR 9C"); //yazý rengi deðiþir.
	cout << hata; // hata yazýlýr.
	islem = false; //iþlem varsa kapanýr. 
	Sleep(saniye * 1000); // parametreden gelen veri 1000ms ile çarpýlýr bekletilir.
	system("COLOR 9F"); // yazý rengi normale döner.
	MenuGetir(NULL); // menü çaðrýlýr.
}
void HataGoster(string hata, double saniye, bool menu) {
	system("cls"); // Konsol temizlenir.
	system("COLOR 9C"); //Yazý rengi deðiþir.
	cout << hata; // Hata yazýlýr.
	islem = false; // iþlem kapanýr.
	Sleep(saniye * 1000); // parametredeki saniye 1000ms ile çarpýlýr bekletilir.
	system("COLOR 9F"); // Yazý rengi normale döner.
}
void UstMenu() {
	menu = 0; //menü sýfýrlanýr.
	islem = false; //bir iþlem yapýldýysa kapatýlýr.
	MenuGetir(NULL); // MenuGetir fonksiyonuyla menü getirilir.
}
void Cikis() { //Eðlenceli Çýkýþ.
	system("cls"); //konsol temizlenir.
	cout << "Hoþçakalýn!"; //Hoþçakalýn yazýlýr.
	system("COLOR 1A"); //Arkaplan ve yazý rengi deðiþir.
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
	exit(0); //Programdan çýkýlýr.
}
string *Ayrac(string veri) {
	//1;20 gelen veri dizi halinde [0]:1, [1]:20 olarak çýkýyor.
	int i = 1; //kaç adet veri olduðunu gösteren deðiþken.
	stringstream ss(veri); // stringi iþleyen sýnýf (filestream gibi)
	string token; // her noktalý virgül ile ayrýlan veriyi ekleyen deðiþken burada sadece saymak için konulmuþtur.
	while (getline(ss, token, ';')) { // her noktalý virgülle ayrýlan verileri teker teker iþleyen while döngüsü.
		i++; // bu while döngüsü sadece kaç adet veri olduðunu bulan bir döngüdür. Bu döngüyle pointer yardýmýyla dizi oluþturulur.
	}
	string* arr = new string[i]; // kaç adet veri varsa o büyüklükte dizi oluþturulur.
	i = 0; // i sayýsý 0 yapýlýr tekrardan.
	stringstream ss1(veri); // ayný sýnýf tekrardan oluþturulur ayný veriler iþleneceði için.
	string token1; // her noktalý virgül ile ayrýlan veriyi ekleyen deðiþken.
	while (getline(ss1, token1, ';')) { // Her noktalý virgül ile ayrýlan veriyi iþleyen while döngüsü.
		arr[i] = token1; // daha önce oluþturulan diziye burada her noktalý virgül ile ayrýlan veri eklenir.
		i++; // diziye eklemek için i arttýrýlýr.
	}
	return arr; // asd;123;345 gibi veriyi 3 elemanlý elemanlarý "asd", "123", "345" olan bir dizi haline getirip döndürür.
}
void GirisTemizle() {
	if (!cin) {
		cin.clear(); // cin fonksiyonu hatalý olduðunda 0 döndürür, clear fonksiyonu bunu düzeltir.
		cin.ignore(100, '\n'); // ignore fonksiyonu bir hata olduðunda o hataya dair (100) satýrlýk veriyi reddeder.
	}
}
/*
 TC kimlik no algoritmasýna girilmedi.
 TC Kimlik no bir anahtar içermediðinden müþteriler dosyasýnda aratýlmadý.
*/