/**
*
* @author Onur Osman Gule onur.gule@ogr.sakarya.edu.tr
* @since 05.05.2021
* <p>
* Portfoy Source File
* </p>
*/
#include "Portfoy.h"

Portfoy::Portfoy(std::string id, std::string sembol, double maliyet, int adet)
{
	this->_id = id;
	this->Sembol = sembol;
	this->Maliyet = maliyet;
	this->Adet = adet;
}

double Portfoy::getMaliyet()
{
	return this->Maliyet;
}

std::string Portfoy::getId()
{
	return this->_id;
}

std::string Portfoy::getSembol()
{
	return this->Sembol;
}

int Portfoy::getAdet()
{
	return this->Adet;
}

void Portfoy::setAdet(int adet)
{
	this->Adet = adet;
}

void Portfoy::setMaliyet(double maliyet)
{
	this->Maliyet = maliyet;
}
