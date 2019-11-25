#ifndef OKUL_HPP
#define OKUL_HPP

#include <iostream>
#include "Sinif.hpp"
#include "Ogrenci.hpp"
using namespace std;

class Okul{
	private:
		int snfNumara;
		Sinif* Siniflar[];
	public:
		Okul();
		Okul(char[]);
		~Okul();
		Sinif* getSinif(int);
		void SinifEkle(Sinif*);
		Sinif** getSiniflar();
		int getSinifSayisi();
		void SinifYerDegistir(Sinif*, Sinif*);
		void OgrenciYerDegistir(Ogrenci*, Ogrenci*);
		Ogrenci* getOgrenciWithName(char);
		Sinif* getSinifWithName(char);
};


#endif