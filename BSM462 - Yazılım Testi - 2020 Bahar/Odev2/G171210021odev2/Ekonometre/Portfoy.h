/**
*
* @author Onur Osman Gule onur.gule@ogr.sakarya.edu.tr
* @since 05.05.2021
* <p>
* Portfoy Header File
* </p>
*/
#pragma once
#include <string>
class Portfoy {
private:
	std::string _id;
	std::string Sembol;
	double Maliyet;
	int Adet;
public:
	Portfoy(std::string id, std::string sembol, double maliyet, int adet);
	double getMaliyet();
	std::string getId();
	std::string getSembol();
	int getAdet();
	void setAdet(int adet);
	void setMaliyet(double maliyet);

};