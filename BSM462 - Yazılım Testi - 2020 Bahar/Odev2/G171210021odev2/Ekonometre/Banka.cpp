/**
*
* @author Onur Osman Gule onur.gule@ogr.sakarya.edu.tr
* @since 05.05.2021
* <p>
* Banka Source File
* </p>
*/
#include "Banka.h"
#include <nlohmann/json.hpp>
#include <iostream>
#include <vector>
#include <iomanip>


using json = nlohmann::json;
using namespace std;

json jsonOku(string fileName)
{
    json baseJObject;
    string filePath = fileName;
    ifstream inFileJSON(filePath);
    if (inFileJSON.is_open())
    {
        inFileJSON >> baseJObject;
        inFileJSON.close();
        return baseJObject;
    }
    else
    {
        throw 404;
    }
}

std::vector<Hisse> Banka::getHisseler()
{
    return this->hisseler;
}

std::vector<Portfoy> Banka::getPortfoy()
{
    return this->portfoyler;
}

std::vector<Emir> Banka::getEmirler()
{
    return this->emirler;
}

void Banka::HisseFiyatGuncelle(string hisseDosyasi)
{
    //Hisseleri dosyadan okur ve bankanýn hisseler vektörüne daha sonra kullanýlmasý için yazar.
    json h = jsonOku(hisseDosyasi);
    int hisseSayisi = h["Hisseler"].size();
    if (hisseSayisi == 0) throw 404;
    for (int i = 0; i < hisseSayisi; i++) {
        HisseEkle(h["Hisseler"][i]["_id"], h["Hisseler"][i]["Sembol"], h["Hisseler"][i]["Ad"], (h["Hisseler"][i]["Fiyat"]));
    }
}
void Banka::PortfoyGuncelle(string portfoyDosyasi)
{
    //Portfoyleri dosyadan okur ve bankanýn portfoy vektörüne daha sonra kullanýlmasý için yazar.
    json h = jsonOku(portfoyDosyasi);
    int portfoySayisi = h["Portfoy"].size();
    if (portfoySayisi == 0) throw 404;
    for (int i = 0; i < portfoySayisi; i++) {

        PortfoyEkle(h["Portfoy"][i]["_id"], h["Portfoy"][i]["Sembol"], h["Portfoy"][i]["Maliyet"], (h["Portfoy"][i]["Adet"]));
    }
}
void Banka::EmirGuncelle(string emirDosyasi)
{
    //Emirleri dosyadan okur ve bankanýn emir vektörüne daha sonra kullanýlmasý için yazar.
    json h = jsonOku(emirDosyasi);
    int emirSayisi = h["Emirler"].size();
    if (emirSayisi == 0) throw 404;
    for (int i = 0; i < emirSayisi; i++) {
        string id = h["Emirler"][i]["_id"];
        string sembol = h["Emirler"][i]["Sembol"];
        string islem = h["Emirler"][i]["Islem"];
        int adet = h["Emirler"][i]["Adet"];
        EmirEkle(h["Emirler"][i]["_id"], h["Emirler"][i]["Sembol"], h["Emirler"][i]["Islem"], (h["Emirler"][i]["Adet"]));
    }
}
double KarZararHesapla()
{
    return 0.0;
}
void Banka::HisseEkle(std::string id, std::string sembol, std::string ad, double fiyat)
{
    bool err = false;
    bool exist = false;
    try {
        if (this->HisseBul(sembol).getSembol() == sembol) {
            //mevcut.
            exist = true;
        }
        if (id == "" || sembol == "" || ad == "" || fiyat <= 0) {
            //Mantýksal ya da dosyasal hata var.
            err = true;
        }
    }
    catch (int m) {
        exist = false;
    }
    if(!exist && !err) hisseler.push_back(Hisse(id, sembol, ad, fiyat));
    else throw 300;
}
Hisse Banka::HisseBul(std::string sembol)
{
    auto it = find_if(hisseler.begin(), hisseler.end(), [&sembol](Hisse& obj) {return obj.getSembol() == sembol; });
    if (it != hisseler.end()) {
        auto index = distance(hisseler.begin(), it);
        return this->hisseler[index];
    }
    else throw 404;
}
void Banka::PortfoyEkle(std::string id, std::string sembol, double maliyet, int adet)
{
    bool exist = false;
    try {
        if (this->PortfoyBul(sembol).getSembol() == sembol) {
            //mevcut.
            exist = true;
        }
    }
    catch (int m) {
        exist = false;
    }
    if (!exist) portfoyler.push_back(Portfoy(id, sembol, maliyet, adet));
    else throw 300;
    
}
Portfoy Banka::PortfoyBul(std::string sembol)
{
    auto it = find_if(portfoyler.begin(), portfoyler.end(), [&sembol](Portfoy& obj) {return obj.getSembol() == sembol; });
    if (it != portfoyler.end()) {
        auto index = distance(portfoyler.begin(), it);
        return this->portfoyler[index];
    }
    else throw 404;
}
int Banka::PortfoyIndexBul(std::string sembol)
{
    auto it = find_if(portfoyler.begin(), portfoyler.end(), [&sembol](Portfoy& obj) {return obj.getSembol() == sembol; });
    if (it != portfoyler.end()) {
        auto index = distance(portfoyler.begin(), it);
        return index;
    }
    else throw 404;
}
void Banka::PortfoySil(std::string id)
{
    auto it = find_if(portfoyler.begin(), portfoyler.end(), [&id](Portfoy& obj) {return obj.getId() == id; });
    portfoyler.erase(it);
}
void Banka::EmirEkle(std::string id, std::string sembol, std::string islem, int adet)
{
    bool hisseExist = false;
    bool error = false;
    int errCode = 0;
    try {
        if (this->HisseBul(sembol).getSembol() == sembol) {
            //hisse mevcut, problem yok.
            hisseExist = true;
        }
        if (islem == "SATIS" && this->PortfoyBul(sembol).getSembol() != sembol) {
            //Satýþ iþlemi emri veriyor ancak portfoyunde öyle bir sembol yok.
            error = true;
            errCode = 301;
        }
        if (islem == "SATIS" && this->PortfoyBul(sembol).getAdet() < adet) {
            //Satýþ iþlemi gerçekleþtiriyor ancak portfoyunde o kadar hisse yok.
            error = true;
            errCode = 302;
        }
    }
    catch (int m) {
        error = true;
    }
    if (hisseExist && !error) emirler.push_back(Emir(id, sembol, islem, adet));
    else throw errCode;
    
}
Emir Banka::EmirBul(std::string sembol)
{
    auto it = find_if(emirler.begin(), emirler.end(), [&sembol](Emir& obj) {return obj.getSembol() == sembol; });
    if (it != emirler.end()) {
        auto index = distance(emirler.begin(), it);
        return this->emirler[index];
    }
    else throw 404;
}
int Banka::IslemeGoreEmirSayisi(IslemTipi islem)
{
    int emirSayisi = 0;
    for (int i = 0; i < this->emirler.size(); i++)
    {
        if (this->emirler[i].getIslem() == islem) emirSayisi++;
    }
    return emirSayisi;
}
double Banka::EmirleriIsle()
{
    double sonDurum = 0;
    for (int i = 0; i < this->emirler.size(); i++) {
        Emir emir = emirler[i];
        if (emir.getIslem() == SATIS) {
            double fiyat = this->HisseBul(emir.getSembol()).getGuncelFiyat() * emir.getAdet();
            double maliyet = this->PortfoyBul(emir.getSembol()).getMaliyet() * emir.getAdet();
            double karzarar = fiyat - maliyet;
            std::cout << emir.getSembol() << " : " << abs(fiyat - maliyet) << " TL " << (((fiyat - maliyet) < 0) ? "Zarar" : "Kar") << endl;
            sonDurum += (fiyat - maliyet);
            PortfoySil(this->PortfoyBul(emir.getSembol()).getId());
        }
        else if (emir.getIslem() == ALIS) {
            Portfoy p = PortfoyBul(emir.getSembol());
            double fiyat = this->HisseBul(emir.getSembol()).getGuncelFiyat();
            int oldAdet = p.getAdet();
            double oldMaliyet = p.getMaliyet();
            int yeniAdet = (oldAdet + emir.getAdet());
            double yeniMaliyet = (oldAdet * oldMaliyet + emir.getAdet() * fiyat) / yeniAdet;

            portfoyler[PortfoyIndexBul(emir.getSembol())].setAdet(yeniAdet);
            portfoyler[PortfoyIndexBul(emir.getSembol())].setMaliyet(yeniMaliyet);
        }
    }
    return sonDurum;
}
void Banka::PiyasaIslemi()
{
    if (this->IslemeGoreEmirSayisi(SATIS) > 0) {
        std::cout << "Satýþlar Kar/Zarar:" << endl;
    }
    double sonDurum = EmirleriIsle();
    if(sonDurum != 0) std::cout << "Toplam Kar/Zarar: " << ((sonDurum < 0) ? "- " : "+ ") << sonDurum << endl << endl;
    if (this->portfoyler.size() > 0) {
        std::cout << "Güncel Portföy:" << endl;
        GuncelPortfoy();
    }
    else std::cout << "Portföyünüz boþ." << endl;
}

double Banka::GuncelPortfoy()
{
    double toplam = 0;
    for (int i = 0; i < this->portfoyler.size(); i++)
    {
        Portfoy p = this->portfoyler[i];
        std::cout << "Hisse: " << p.getSembol() << endl << "Adet: " << p.getAdet() << endl << "Maliyet: " << p.getMaliyet() << " TL" << endl << "--------------------" << endl;
        toplam += p.getAdet() * this->HisseBul(p.getSembol()).getGuncelFiyat();
    }
    return toplam;
}
