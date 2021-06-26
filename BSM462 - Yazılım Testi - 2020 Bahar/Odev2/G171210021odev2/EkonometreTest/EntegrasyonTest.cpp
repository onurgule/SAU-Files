/**
*
* @author Onur Osman Gule onur.gule@ogr.sakarya.edu.tr
* @since 05.05.2021
* <p>
* Entegrasyon Testleri
* </p>
*/
#include "pch.h"
#include "../Ekonometre/Banka.h"
TEST(BankaEntegrasyonTest, HisseVarsayilanFiyatGuncellemeTesti) {
	//Verilen dosyaya g�re varsay�lan test yap�ld�.
	Banka* b = new Banka();
	b->HisseFiyatGuncelle("../../Ekonometre/hisseler.json");
	ASSERT_EQ(100, b->getHisseler().size());
	delete b;
}
TEST(BankaEntegrasyonTest, PortfoyVarsayilanGuncellemeTesti) {
	//Verilen dosyaya g�re varsay�lan test yap�ld�.
	Banka* b = new Banka();
	b->PortfoyGuncelle("../../Ekonometre/portfoy.json");
	ASSERT_EQ(4, b->getPortfoy().size());
	delete b;
}
TEST(BankaEntegrasyonTest, EmirVarsayilanGuncellemeTesti) {
	//Verilen dosyaya g�re varsay�lan test yap�ld�.
	Banka* b = new Banka();
	b->HisseFiyatGuncelle("../../Ekonometre/hisseler.json");
	b->PortfoyGuncelle("../../Ekonometre/portfoy.json");
	b->EmirGuncelle("../../Ekonometre/emirler.json");
	ASSERT_EQ(3, b->getEmirler().size());
	delete b;
}
TEST(BankaEntegrasyonTest, PiyasaIslemPortfoyAdetTesti) {

	//Verilen dosyaya g�re varsay�lan test yap�ld�.
	Banka* b = new Banka();
	b->HisseFiyatGuncelle("../../Ekonometre/hisseler.json");
	b->PortfoyGuncelle("../../Ekonometre/portfoy.json");
	b->EmirGuncelle("../../Ekonometre/emirler.json");
	//veriler okundu. ��lemler test edilecek.
	b->PiyasaIslemi(); // burada emirler i�leniyor.
	ASSERT_EQ(2, b->getPortfoy().size());
	delete b;
}
TEST(BankaEntegrasyonTest, EmirSatisSayisiTesti) {
	Banka* b = new Banka();
	b->HisseFiyatGuncelle("../../Ekonometre/hisseler.json");
	b->PortfoyGuncelle("../../Ekonometre/portfoy.json");
	b->EmirGuncelle("../../Ekonometre/emirler.json");
	ASSERT_EQ(2, b->IslemeGoreEmirSayisi(SATIS));
	delete b;
}
TEST(BankaEntegrasyonTest, EmirAlisSayisiTesti) {
	Banka* b = new Banka();
	b->HisseFiyatGuncelle("../../Ekonometre/hisseler.json");
	b->PortfoyGuncelle("../../Ekonometre/portfoy.json");
	b->EmirGuncelle("../../Ekonometre/emirler.json");
	ASSERT_EQ(1, b->IslemeGoreEmirSayisi(ALIS));
	delete b;
}
TEST(BankaEntegrasyonTest, PiyasaIslemAdetTesti) {
	//Verilen dosyaya g�re varsay�lan test yap�ld�.
	Banka* b = new Banka();
	b->HisseFiyatGuncelle("../../Ekonometre/hisseler.json");
	b->PortfoyGuncelle("../../Ekonometre/portfoy.json");
	b->EmirGuncelle("../../Ekonometre/emirler.json");
	//veriler okundu. ��lemler test edilecek.
	b->PiyasaIslemi(); // burada emirler i�leniyor.
	ASSERT_EQ(750, b->PortfoyBul("TATGD").getAdet());
	delete b;
}
TEST(BankaEntegrasyonTest, HisselerdeOlmayanEmirTesti) {
	//hisselerde olmayan bir emir i�leminin al�m sat�m� ger�ekle�mez.
	Banka* b = new Banka();
	b->PortfoyGuncelle("../../Ekonometre/portfoy.json");
	ASSERT_THROW(b->EmirGuncelle("../../Ekonometre/emirler.json"),int);
	delete b;
}
TEST(BankaEntegrasyonTest, PortfoyOlmayanEmirTesti) {
	//Portfoyde olmayan bir emir i�leminin SATI�I ger�ekle�mez.
	//default dosyada sat�� oldu�undan hata verecektir, sadece al�m olan dosyalarda throw ger�ekle�mez, default dosyaya g�re yap�ld�.
	Banka* b = new Banka();
	b->HisseFiyatGuncelle("../../Ekonometre/hisseler.json");
	ASSERT_THROW(b->EmirGuncelle("../../Ekonometre/emirler.json"), int);
	delete b;
}
TEST(BankaEntegrasyonTest, SadeceAlimPortfoyOlmayanEmirTesti) {
	Banka* b = new Banka();
	b->HisseFiyatGuncelle("../../Ekonometre/hisseler.json");
	ASSERT_NO_THROW(b->EmirEkle("123e","VESTL","ALIS",15), int);
	delete b;
}
TEST(BankaEntegrasyonTest, PiyasaIslemMaliyetTesti) {

	//Verilen dosyaya g�re varsay�lan test yap�ld�.
	Banka* b = new Banka();
	b->HisseFiyatGuncelle("../../Ekonometre/hisseler.json");
	b->PortfoyGuncelle("../../Ekonometre/portfoy.json");
	b->EmirGuncelle("../../Ekonometre/emirler.json");
	//veriler okundu. ��lemler test edilecek.
	b->PiyasaIslemi(); // burada emirler i�leniyor.
	double hataOrani = 0.009;
	ASSERT_TRUE(abs(8.76 - b->PortfoyBul("TATGD").getMaliyet())<hataOrani) << abs(8.76 - b->PortfoyBul("TATGD").getMaliyet());
	//double'lar kar��la�t�r�l�rken hata oran� %1 alt� kullan�ld�.
	delete b;
}
TEST(BankaEntegrasyonTest, EmirleriIsleSonDurumTesti) {
	//kar zarar� nas�l test edece�imizi bul.
	//Verilen dosyaya g�re varsay�lan test yap�ld�.
	Banka* b = new Banka();
	b->HisseFiyatGuncelle("../../Ekonometre/hisseler.json");
	b->PortfoyGuncelle("../../Ekonometre/portfoy.json");
	b->EmirGuncelle("../../Ekonometre/emirler.json");
	double hataOrani = 0.009; 
	ASSERT_TRUE(abs(117.20 - b->EmirleriIsle()) < hataOrani);
	//double'dan kaynakl� %0.9 hata oran� eklendi.					   
	delete b;
}
TEST(BankaEntegrasyonTest, HisseDosyasiTekrarOkumaTesti) {
	Banka* b = new Banka();
	b->HisseFiyatGuncelle("../../Ekonometre/hisseler.json");
	ASSERT_THROW(b->HisseFiyatGuncelle("../../Ekonometre/hisseler.json"),int);
	delete b;
}
TEST(BankaEntegrasyonTest, PortfoyDosyasiTekrarOkumaTesti) {
	Banka* b = new Banka();
	b->HisseFiyatGuncelle("../../Ekonometre/hisseler.json");
	b->PortfoyGuncelle("../../Ekonometre/portfoy.json");
	ASSERT_THROW(b->PortfoyGuncelle("../../Ekonometre/portfoy.json"), int);
	delete b;
}
TEST(BankaEntegrasyonTest, EmirDosyasiTekrarOkumaTesti) {
	Banka* b = new Banka();
	b->HisseFiyatGuncelle("../../Ekonometre/hisseler.json");
	b->PortfoyGuncelle("../../Ekonometre/portfoy.json");
	b->EmirGuncelle("../../Ekonometre/emirler.json");
	ASSERT_NO_THROW(b->EmirGuncelle("../../Ekonometre/emirler.json"));
	delete b;
}
TEST(BankaEntegrasyonTest, HisseDosyasiniYanlisVermeTesti) {
	Banka* b = new Banka();
	//hisseler.json yerine portfoy.json verildi. Hata vermesi bekleniyor.
	ASSERT_THROW(b->HisseFiyatGuncelle("../../Ekonometre/portfoy.json"), int);
	delete b;
}
TEST(BankaEntegrasyonTest, PortfoyDosyasiniYanlisVermeTesti) {
	Banka* b = new Banka();
	//portfoy.json yerine hisseler.json verildi. Hata vermesi bekleniyor.
	ASSERT_THROW(b->PortfoyGuncelle("../../Ekonometre/hisseler.json"), int);
	delete b;
}
TEST(BankaEntegrasyonTest, EmirDosyasiniYanlisVermeTesti) {
	Banka* b = new Banka();
	//emirler.json yerine portfoy.json verildi. Hata vermesi bekleniyor.
	ASSERT_THROW(b->EmirGuncelle("../../Ekonometre/portfoy.json"), int);
	delete b;
}
TEST(BankaEntegrasyonTest, PortfoyTekliToplamTesti) {
	Banka* b = new Banka();
	b->HisseFiyatGuncelle("../../Ekonometre/hisseler.json");
	b->PortfoyEkle("123p", "MAVI", 40, 100);
	ASSERT_EQ(4100,b->GuncelPortfoy());
	delete b;
}
TEST(BankaEntegrasyonTest, PortfoyCokluToplamTesti) {
	Banka* b = new Banka();
	b->HisseFiyatGuncelle("../../Ekonometre/hisseler.json");
	b->PortfoyEkle("123p", "MAVI", 40, 100);
	b->PortfoyEkle("123c", "IHLGM", 2, 50);
	ASSERT_EQ(4150, b->GuncelPortfoy());
	delete b;
}
TEST(BankaEntegrasyonTest, PortfoyDefaultToplamTesti) {
	Banka* b = new Banka();
	b->HisseFiyatGuncelle("../../Ekonometre/hisseler.json");
	b->PortfoyGuncelle("../../Ekonometre/portfoy.json");
	ASSERT_EQ(102492.2, b->GuncelPortfoy()) << b->GuncelPortfoy();
	delete b;
}
TEST(BankaEntegrasyonTest, DosyadanPortfoySilmeTesti) {
	Banka* b = new Banka();
	b->HisseFiyatGuncelle("../../Ekonometre/hisseler.json");
	b->PortfoyGuncelle("../../Ekonometre/portfoy.json");
	int portfoySayisi = b->getPortfoy().size();
	b->PortfoySil(b->getPortfoy()[0].getId());
	ASSERT_EQ((portfoySayisi-1), b->getPortfoy().size());
	delete b;
}
TEST(BankaEntegrasyonTest, DosyadanPortfoyAdetGuncellemeTesti) {
	Banka* b = new Banka();
	b->HisseFiyatGuncelle("../../Ekonometre/hisseler.json");
	b->PortfoyGuncelle("../../Ekonometre/portfoy.json");
	Portfoy ilkPortfoy = b->getPortfoy()[0];
	int ilkPortfoyAdedi = ilkPortfoy.getAdet();
	ilkPortfoy.setAdet(ilkPortfoyAdedi + 10);
	ASSERT_EQ(ilkPortfoyAdedi + 10, ilkPortfoy.getAdet());
	delete b;
}
TEST(BankaEntegrasyonTest, DosyadanPortfoyMaliyetGuncellemeTesti) {
	Banka* b = new Banka();
	b->HisseFiyatGuncelle("../../Ekonometre/hisseler.json");
	b->PortfoyGuncelle("../../Ekonometre/portfoy.json");
	Portfoy ilkPortfoy = b->getPortfoy()[0];
	int ilkPortfoyMaliyeti = ilkPortfoy.getMaliyet();
	ilkPortfoy.setMaliyet(ilkPortfoyMaliyeti + 10);
	ASSERT_EQ(ilkPortfoyMaliyeti + 10, ilkPortfoy.getMaliyet());
	delete b;
}
TEST(BankaEntegrasyonTest, DosyadanHisseBulmaTesti) {
	Banka* b = new Banka();
	b->HisseFiyatGuncelle("../../Ekonometre/hisseler.json");
	ASSERT_EQ("OTOKAR",b->HisseBul("OTKAR").getAd());
	delete b;
}
TEST(BankaEntegrasyonTest, DosyadanPortfoyBulmaTesti) {
	Banka* b = new Banka();
	b->HisseFiyatGuncelle("../../Ekonometre/hisseler.json");
	b->PortfoyGuncelle("../../Ekonometre/portfoy.json");
	ASSERT_EQ(120,b->PortfoyBul("AKSA").getAdet());
	delete b;
}
TEST(BankaEntegrasyonTest, DosyadanEmirBulmaTesti) {
	Banka* b = new Banka();
	b->HisseFiyatGuncelle("../../Ekonometre/hisseler.json");
	b->PortfoyGuncelle("../../Ekonometre/portfoy.json");
	b->EmirGuncelle("../../Ekonometre/emirler.json");
	ASSERT_EQ(250, b->EmirBul("TATGD").getAdet());
	delete b;
}
TEST(BankaEntegrasyonTest, IslemdenOnceGuncelPortfoySonucSayisiTesti) {
	std::stringstream buffer;
	std::streambuf* sbuf = std::cout.rdbuf();
	std::cout.rdbuf(buffer.rdbuf());

	Banka* b = new Banka();	
	b->HisseFiyatGuncelle("../../Ekonometre/hisseler.json");
	b->PortfoyGuncelle("../../Ekonometre/portfoy.json");
	b->EmirGuncelle("../../Ekonometre/emirler.json");
	b->GuncelPortfoy();
	std::string actual{ buffer.str() };
	std::cout.rdbuf(sbuf);
	int sonucSayisi = std::count(actual.begin(), actual.end(), ':') / 3;
	ASSERT_EQ(4, sonucSayisi)<<actual << sonucSayisi;
	//Portfoy bo� oldu�u i�in bo� d�nd�rmeli.
	delete b;
}
TEST(BankaEntegrasyonTest, IslemdenSonraGuncelPortfoySonucSayisiTesti) {
	std::stringstream buffer;
	std::streambuf* sbuf = std::cout.rdbuf();
	std::cout.rdbuf(buffer.rdbuf());

	Banka* b = new Banka();
	b->HisseFiyatGuncelle("../../Ekonometre/hisseler.json");
	b->PortfoyGuncelle("../../Ekonometre/portfoy.json");
	b->EmirGuncelle("../../Ekonometre/emirler.json");
	b->EmirleriIsle();
	b->GuncelPortfoy();
	std::string actual{ buffer.str() };
	std::cout.rdbuf(sbuf);
	int sonucSayisi = std::count(actual.begin(), actual.end(), ':') /3;
	ASSERT_EQ(2, sonucSayisi) << actual;
	delete b;
}
TEST(BankaEntegrasyonTest, TumIslemlerProgramErrorTesti) {
	Banka* b = new Banka();
	b->HisseFiyatGuncelle("../../Ekonometre/hisseler.json");
	b->PortfoyGuncelle("../../Ekonometre/portfoy.json");
	b->EmirGuncelle("../../Ekonometre/emirler.json");
	ASSERT_NO_THROW(b->PiyasaIslemi());
	//Program do�ru �al��t��� takdirde bir hata meydana getirmeyece�ini test ediyoruz.
	delete b;
}