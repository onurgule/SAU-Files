#ifndef SINIF_HPP
#define SINIF_HPP

#include <iostream>
#include "Ogrenci.hpp"
using namespace std;

class Sinif{
	private:
		char Sube;
		int ogrNumara;
		Ogrenci* Ogrenciler[]; //heapte yapcaz unutma
	public:
		Sinif(char);
		~Sinif();
		char getSube();
		void OgrenciEkle(Ogrenci*);
		int getOgrenciSayisi();
		Ogrenci* getOgrenci(int);
		bool ogrenciVarMi(int);
		void ogrenciDegistir(int,Ogrenci*);
		
};


#endif