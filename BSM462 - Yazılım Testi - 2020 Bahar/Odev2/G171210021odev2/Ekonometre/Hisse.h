/**
*
* @author Onur Osman Gule onur.gule@ogr.sakarya.edu.tr
* @since 05.05.2021
* <p>
* Hisse Header File
* </p>
*/
#pragma once
#include <string>
class Hisse {
	private:
		std::string _id;
		std::string Sembol;
		std::string Ad;
		double Fiyat;
	public:
		Hisse(std::string id, std::string sembol, std::string ad, double fiyat);
		double getGuncelFiyat();
		std::string getId();
		std::string getSembol();
		std::string getAd();


};

