/**
*
* @author Onur Osman Gule onur.gule@ogr.sakarya.edu.tr
* @since 05.05.2021
* <p>
* Emir Source File
* </p>
*/
#include "Emir.h"

Emir::Emir(std::string id, std::string sembol, std::string islem, int adet)
{
	//nullable id ve sembol de eklenir
	this->_id = id;
	this->Sembol = sembol;
	if (islem == "ALIS") this->Islem = ALIS;
	else if (islem == "SATIS") this->Islem = SATIS;
	else throw 501;
	if (adet > 0) this->Adet = adet;
	else throw 501;
}

IslemTipi Emir::getIslem()
{
	return this->Islem;
}

std::string Emir::getId()
{
	return this->_id;
}

std::string Emir::getSembol()
{
	return this->Sembol;
}

int Emir::getAdet()
{
	return this->Adet;
}
