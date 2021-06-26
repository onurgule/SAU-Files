/**
*
* @author Onur Osman Gule onur.gule@ogr.sakarya.edu.tr
* @since 05.05.2021
* <p>
* Birim Testleri
* </p>
*/
#include "pch.h"
#include "../Ekonometre/Hisse.h"
#include "../Ekonometre/Portfoy.h"
#include "../Ekonometre/Emir.h"
#include "../Ekonometre/Banka.h"
#include <typeinfo> 
#include <stdexcept>

TEST(HisseTest, HisseOlusturmaTesti) {
	Hisse* h = new Hisse("123f", "OOG", "Onur", 55);
	ASSERT_EQ(typeid(Hisse*), typeid(h)) << "Class Oluþmadý!";
	delete h;
}
TEST(HisseTest, HisseFiyatTesti) {
	Hisse* h = new Hisse("123f", "OOG", "Onur", 55);
	ASSERT_EQ(55, h->getGuncelFiyat());
	delete h;
}
TEST(HisseTest, HisseIdTesti) {
	Hisse* h = new Hisse("123f", "OOG", "Onur", 55);
	ASSERT_EQ("123f", h->getId());
	delete h;
}
TEST(HisseTest, HisseSembolTesti) {
	Hisse* h = new Hisse("123f", "OOG", "Onur", 55);
	ASSERT_EQ("OOG", h->getSembol());
	delete h;
}
TEST(HisseTest, HisseAdTesti) {
	Hisse* h = new Hisse("123f", "OOG", "Onur", 55);
	ASSERT_EQ("Onur", h->getAd());
	delete h;
}
TEST(PortfoyTest, PortfoyOlusturmaTesti) {
	Portfoy* p = new Portfoy("123f", "OOG", 314, 55);
	ASSERT_EQ(typeid(Portfoy*), typeid(p)) << "Class Oluþmadý!";
	delete p;
}
TEST(PortfoyTest, PortfoyMaliyetTesti) {
	Portfoy* p = new Portfoy("123f", "OOG", 314, 55);
	ASSERT_EQ(314, p->getMaliyet());
	delete p;
}
TEST(PortfoyTest, PortfoyIdTesti) {
	Portfoy* p = new Portfoy("123f", "OOG", 314, 55);
	ASSERT_EQ("123f", p->getId());
	delete p;
}
TEST(PortfoyTest, PortfoySembolTesti) {
	Portfoy* p = new Portfoy("123f", "OOG", 314, 55);
	ASSERT_EQ("OOG", p->getSembol());
	delete p;
}
TEST(PortfoyTest, PortfoyAdetTesti) {
	Portfoy* p = new Portfoy("123f", "OOG", 314, 55);
	ASSERT_EQ(55, p->getAdet());
	delete p;
}
TEST(PortfoyTest, PortfoyFarkliAdetTesti) {
	Portfoy* p = new Portfoy("123f", "OOG", 314, 55);
	p->setAdet(15);
	ASSERT_EQ(15, p->getAdet());
	delete p;
}
TEST(PortfoyTest, PortfoyFarkliMaliyetTesti) {
	Portfoy* p = new Portfoy("123f", "OOG", 314, 55);
	p->setMaliyet(600);
	ASSERT_EQ(600, p->getMaliyet());
	delete p;
}
TEST(EmirTest, EmirOlusturmaTesti) {
	Emir* e = new Emir("123f", "OOG", "ALIS", 55);
	ASSERT_EQ(typeid(Emir*), typeid(e)) << "Class Oluþmadý!";
	delete e;
}
TEST(EmirTest, EmirIslemTesti) {
	Emir* e = new Emir("123f", "OOG", "ALIS", 55);
	ASSERT_EQ(ALIS, e->getIslem());
	delete e;
}
TEST(EmirTest, EmirSatisIslemTesti) {
	Emir* e = new Emir("123f", "OOG", "SATIS", 10);
	ASSERT_EQ(SATIS, e->getIslem());
	delete e;
}
TEST(EmirTest, EmirAlisIslemTesti) {
	Emir* e = new Emir("123f", "OOG", "ALIS", 10);
	ASSERT_EQ(ALIS, e->getIslem());
	delete e;
}
TEST(EmirTest, EmirYanlisIslemTesti) {
	Emir* e = NULL;
	ASSERT_THROW({ e = new Emir("123f", "OOG", "ALISS", 55); }, int);
	delete e;
}
TEST(EmirTest, EmirIdTesti) {
	Emir* e = new Emir("123f", "OOG", "ALIS", 55);
	ASSERT_EQ("123f", e->getId());
	delete e;
}
TEST(EmirTest, EmirSembolTesti) {
	Emir* e = new Emir("123f", "OOG", "ALIS", 55);
	ASSERT_EQ("OOG", e->getSembol());
	delete e;
}
TEST(EmirTest, EmirAdetTesti) {
	Emir* e = new Emir("123f", "OOG", "ALIS", 55);
	ASSERT_EQ(55, e->getAdet());
	delete e;
}
TEST(BankaTest, HisseFiyatGuncellemeTesti) {
	//Dosyadaki verilerle hiçbir iþlem yapýlmýyor, burada yalnýzca verileri çekebiliyor muyuz diye test ediliyor.
	Banka *b = new Banka();
	b->HisseFiyatGuncelle("../../Ekonometre/hisseler.json");
	ASSERT_TRUE(b->getHisseler().size() > 0);
	delete b;
}
TEST(BankaTest, HisseVarsayilanFiyatGuncellemeHisseTesti) {
	//Hisse Fiyat Güncelle fonksiyonu gerçekten hisse mi dolduruyor test ediliyor.
	Banka* b = new Banka();
	b->HisseFiyatGuncelle("../../Ekonometre/hisseler.json");
	ASSERT_EQ(typeid(Hisse), typeid(b->getHisseler()[0]));
	delete b;
}
TEST(BankaTest, HisseOlmayanDosyaFiyatGuncellemeHisseTesti) {
	//Dosyanýn olup olmadýðý test ediliyor.
	Banka* b = new Banka();
	ASSERT_THROW(b->HisseFiyatGuncelle("../../Ekonometre/hisseler_yok.json"), int);
	delete b;
}
TEST(BankaTest, HisseleriGetirmeTesti) {
	//getHisseler bir hisse vektörü mü döndürüyor?
	Banka* b = new Banka();
	ASSERT_EQ(typeid(std::vector<Hisse>), typeid(b->getHisseler()));
	delete b;
}
TEST(BankaTest, PortfoyGuncellemeTesti) {
	Banka* b = new Banka();
	b->PortfoyGuncelle("../../Ekonometre/portfoy.json");
	ASSERT_TRUE(b->getPortfoy().size() > 0);
	delete b;
}
TEST(BankaTest, PortfoyVarsayilanPortfoyGuncellemeTesti) {
	Banka* b = new Banka();
	b->PortfoyGuncelle("../../Ekonometre/portfoy.json");
	ASSERT_EQ(typeid(Portfoy), typeid(b->getPortfoy()[0]));
	delete b;
}
TEST(BankaTest, PortfoyOlmayanDosyaGuncellemeTesti) {
	Banka* b = new Banka();
	ASSERT_THROW(b->PortfoyGuncelle("../../Ekonometre/portfoy_yok.json"), int);
	delete b;
}
TEST(BankaTest, PortfoyGetirmeTesti) {
	//getPortfoy bir portfoy vektörü mü döndürüyor?
	Banka* b = new Banka();
	ASSERT_EQ(typeid(std::vector<Portfoy>), typeid(b->getPortfoy()));
	delete b;
}
TEST(BankaTest, EmirGuncellemeTesti) {
	//Dosyadan Emirler okundu mu, boþ mu diye kontrol ediyoruz. Veriler önemli deðil. 
	Banka* b = new Banka();
	b->HisseFiyatGuncelle("../../Ekonometre/hisseler.json");
	b->PortfoyGuncelle("../../Ekonometre/portfoy.json");
	b->EmirGuncelle("../../Ekonometre/emirler.json");
	ASSERT_TRUE(b->getEmirler().size() > 0);
	delete b;
}
TEST(BankaTest, EmirVarsayilanEmirGuncellemeTesti) {
	//Dosyadan gerçekten emir geliyor mu diye kontrol ediliyor. Veriler önemli deðil.
	Banka* b = new Banka();
	b->HisseFiyatGuncelle("../../Ekonometre/hisseler.json");
	b->PortfoyGuncelle("../../Ekonometre/portfoy.json");
	b->EmirGuncelle("../../Ekonometre/emirler.json");
	ASSERT_EQ(typeid(Emir), typeid(b->getEmirler()[0]));
	delete b;
}
TEST(BankaTest, EmirOlmayanDosyaGuncellemeTesti) {
	Banka* b = new Banka();
	ASSERT_THROW(b->EmirGuncelle("../../Ekonometre/emirler_yok.json"), int);
	delete b;
}
TEST(BankaTest, EmirleriGetirmeTesti) {
	//getEmirler bir emir vektörü mü döndürüyor?
	Banka* b = new Banka();
	ASSERT_EQ(typeid(std::vector<Emir>), typeid(b->getEmirler()));
	delete b;
}
TEST(BankaTest, HisseEklemeSayisiTesti) {
	Banka* b = new Banka();
	b->HisseEkle("123f","OOG","Onur",123);
	ASSERT_EQ(1,b->getHisseler().size());
	delete b;
}
TEST(BankaTest, HisseEklemeObjeTesti) {
	Banka* b = new Banka();
	b->HisseEkle("123f", "OOG", "Onur", 123);
	ASSERT_EQ(typeid(Hisse), typeid(b->getHisseler()[0]));
	delete b;
}
TEST(BankaTest, VarolanHisseyiTekrarEklemeTesti) {
	//tekrar ayný hisseyi ekleyemez. verilerde tutarsýzlýk oluþur.
	Banka* b = new Banka();
	b->HisseEkle("123f", "OOG", "Onur", 123);
	ASSERT_THROW(b->HisseEkle("123f", "OOG", "Onur", 123),int);
	delete b;
}
TEST(BankaTest, PortfoyEklemeSayisiTesti) {
	Banka* b = new Banka();
	b->PortfoyEkle("123f", "OOG", 314, 123);
	ASSERT_EQ(1, b->getPortfoy().size());
	delete b;
}
TEST(BankaTest, PortfoyEklemeObjeTesti) {
	Banka* b = new Banka();
	b->PortfoyEkle("123f", "OOG", 314, 123);
	ASSERT_EQ(typeid(Portfoy), typeid(b->getPortfoy()[0]));
	delete b;
}
TEST(BankaTest, VarolanPortfoyuTekrarEklemeTesti) {
	//tekrar ayný portfoyu ekleyemez. verilerde tutarsýzlýk oluþur.
	Banka* b = new Banka();
	b->PortfoyEkle("123f", "OOG", 314, 123);
	ASSERT_THROW(b->PortfoyEkle("123f", "OOG", 314, 123), int);
	delete b;
}
TEST(BankaTest, EmirEklemeSayisiTesti) {
	Banka* b = new Banka();
	b->HisseEkle("123h", "OOG", "Onur", 50);
	b->EmirEkle("123f", "OOG", "ALIS", 123);
	ASSERT_EQ(1, b->getEmirler().size());
	delete b;
}
TEST(BankaTest, EmirEklemeObjeTesti) {
	Banka* b = new Banka();
	b->HisseEkle("123h", "OOG", "Onur", 50);
	b->EmirEkle("123f", "OOG", "ALIS", 123);
	ASSERT_EQ(typeid(Emir), typeid(b->getEmirler()[0]));
	delete b;
}
TEST(BankaTest, VarolanEmriTekrarEklemeTesti) {
	//tekrar ayný sembolden emir ekleyebilir.
	Banka* b = new Banka();
	b->HisseEkle("123h", "OOG", "Onur", 50);
	b->EmirEkle("123f", "OOG", "ALIS", 123);
	ASSERT_NO_THROW(b->EmirEkle("123e", "OOG", "ALIS", 123), int);
	delete b;
}
TEST(BankaTest, HisseBulmaTesti) {
	Banka* b = new Banka();
	b->HisseEkle("123f", "OOG", "Onur", 123);
	ASSERT_EQ(b->HisseBul("OOG").getId(), "123f");
	delete b;
}
TEST(BankaTest, OlmayanHisseBulmaTesti) {
	Banka* b = new Banka();
	ASSERT_THROW(b->HisseBul("OOG"), int);
	delete b;
}
TEST(BankaTest, PortfoyBulmaTesti) {
	Banka* b = new Banka();
	b->PortfoyEkle("123f", "OOG", 314, 123);
	ASSERT_EQ("123f",b->PortfoyBul("OOG").getId(),);
	delete b;
}
TEST(BankaTest, PortfoyIndexBulmaTesti) {
	Banka* b = new Banka();
	b->PortfoyEkle("123f", "OOG", 314, 123);
	ASSERT_EQ(b->PortfoyIndexBul("OOG"), 0);
	delete b;
}
TEST(BankaTest, OlmayanPortfoyBulmaTesti) {
	Banka* b = new Banka();
	ASSERT_THROW(b->PortfoyBul("OOG"), int);
	delete b;
}
TEST(BankaTest, OlmayanPortfoyIndexBulmaTesti) {
	Banka* b = new Banka();
	ASSERT_THROW(b->PortfoyIndexBul("OOG"), int);
	delete b;
}
TEST(BankaTest, EmirBulmaTesti) {
	Banka* b = new Banka();
	b->HisseEkle("123h", "OOG", "Onur", 50);
	b->EmirEkle("123f", "OOG", "ALIS", 123);
	ASSERT_EQ("123f",b->EmirBul("OOG").getId());
	delete b;
}
TEST(BankaTest, OlmayanEmirBulmaTesti) {
	Banka* b = new Banka();
	ASSERT_THROW(b->EmirBul("OOG"), int);
	delete b;
}
TEST(BankaTest, PortfoySilmeTesti) {
	Banka* b = new Banka();
	b->PortfoyEkle("123f", "OOG", 314, 123);
	b->PortfoySil("123f");
	ASSERT_EQ(0,b->getPortfoy().size());
	delete b;
}
TEST(BankaTest, GuncelPortfoyBosTesti) {
	std::stringstream buffer;
	std::streambuf* sbuf = std::cout.rdbuf();
	std::cout.rdbuf(buffer.rdbuf());

	Banka* b = new Banka();
	b->GuncelPortfoy();
	std::string actual{ buffer.str() };
	std::cout.rdbuf(sbuf);
	ASSERT_EQ("",actual);
	//Portfoy boþ olduðu için boþ döndürmeli.
	delete b;
}
TEST(BankaTest, GuncelPortfoyTekliTesti) {
	std::stringstream buffer;
	std::streambuf* sbuf = std::cout.rdbuf();
	std::cout.rdbuf(buffer.rdbuf());

	Banka* b = new Banka();
	b->HisseEkle("123h", "OOG", "Onur", 20);
	b->PortfoyEkle("123f", "OOG", 314, 55);
	b->GuncelPortfoy();
	std::string actual{ buffer.str() };
	std::cout.rdbuf(sbuf);
	ASSERT_EQ("Hisse: OOG\nAdet: 55\nMaliyet: 314 TL\n--------------------\n", actual);
	//Portfoy dolu olduðu için istenen döndürmeli.
	delete b;
}
TEST(BankaTest, GuncelPortfoyMaliyetTesti) {
	Banka* b = new Banka();
	b->HisseEkle("123h","OOG","Onur",20);
	b->PortfoyEkle("123f", "OOG", 10, 10);
	double toplam = b->GuncelPortfoy();
	ASSERT_EQ(200,toplam) << toplam;
	delete b;
}
TEST(BankaTest, EmirSatisPortfoydeYokTesti) {
	Banka* b = new Banka();
	b->HisseEkle("123h", "OOG", "Onur", 100);
	ASSERT_THROW(b->EmirEkle("123e", "OOG", "SATIS", 50), int);
	delete b;
}
TEST(BankaTest, EmirSatisPortfoydeYeterliHisseYokTesti) {
	Banka* b = new Banka();
	b->HisseEkle("123h", "OOG", "Onur", 100);
	b->PortfoyEkle("123f", "OOG", 5, 50);
	ASSERT_THROW(b->EmirEkle("123e", "OOG", "SATIS", 100), int);
	delete b;
}
TEST(BankaTest, EmirHisselerdeYokTesti) {
	Banka* b = new Banka();
	b->HisseEkle("123h", "OOG", "Onur", 100);
	ASSERT_THROW(b->EmirEkle("123e", "TEST", "ALIS", 50), int);
	delete b;
}
