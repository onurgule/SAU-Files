/**
*
* @author Onur Osman Gule onur.gule@ogr.sakarya.edu.tr
* @since 05.05.2021
* <p>
* Emir Header File
* </p>
*/
#pragma once
#include <string>
enum IslemTipi{ALIS, SATIS};
class Emir {
private:
	std::string _id;
	std::string Sembol;
	IslemTipi Islem;
	int Adet;
public:
	Emir(std::string id, std::string sembol, std::string islem, int adet);
	IslemTipi getIslem();
	std::string getId();
	std::string getSembol();
	int getAdet();

};