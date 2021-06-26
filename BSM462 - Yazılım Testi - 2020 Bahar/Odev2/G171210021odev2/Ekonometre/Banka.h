/**
*
* @author Onur Osman Gule onur.gule@ogr.sakarya.edu.tr
* @since 05.05.2021
* <p>
* Banka Header File
* </p>
*/
#pragma once
#include <fstream>
#include "Hisse.h"
#include <vector>
#include "Portfoy.h"
#include "Emir.h"

class Banka {
private:
	std::vector<Hisse> hisseler;
	std::vector<Portfoy> portfoyler;
	std::vector<Emir> emirler;
public:
	std::vector<Hisse> getHisseler();
	std::vector<Portfoy> getPortfoy();
	std::vector<Emir> getEmirler();
	void HisseFiyatGuncelle(std::string hisseDosyasi);
	void PortfoyGuncelle(std::string portfoyDosyasi);
	void EmirGuncelle(std::string emirDosyasi);
	void HisseEkle(std::string id, std::string sembol, std::string ad, double fiyat);
	Hisse HisseBul(std::string sembol);
	void PortfoyEkle(std::string id, std::string sembol, double maliyet, int adet);
	Portfoy PortfoyBul(std::string sembol);
	int PortfoyIndexBul(std::string sembol);
	void PortfoySil(std::string id);
	void EmirEkle(std::string id, std::string sembol, std::string islem, int adet);
	Emir EmirBul(std::string sembol);
	int IslemeGoreEmirSayisi(IslemTipi islem);
	double EmirleriIsle();
	void PiyasaIslemi();
	double GuncelPortfoy();
};