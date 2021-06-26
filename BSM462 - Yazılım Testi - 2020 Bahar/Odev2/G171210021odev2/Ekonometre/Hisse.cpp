/**
*
* @author Onur Osman Gule onur.gule@ogr.sakarya.edu.tr
* @since 05.05.2021
* <p>
* Hisse Source File
* </p>
*/
#include "Hisse.h";

Hisse::Hisse(std::string id, std::string sembol, std::string ad, double fiyat)
{
	this->_id = id;
	this->Sembol = sembol;
	this->Ad = ad;
	this->Fiyat = fiyat;
}

double Hisse::getGuncelFiyat()
{
	return this->Fiyat;
}

std::string Hisse::getId()
{
	return this->_id;
}

std::string Hisse::getSembol()
{
	return this->Sembol;
}

std::string Hisse::getAd()
{
	return this->Ad;
}
