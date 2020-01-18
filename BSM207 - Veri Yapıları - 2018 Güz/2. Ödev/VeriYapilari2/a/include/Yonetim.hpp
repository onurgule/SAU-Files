#ifndef YONETIM_HPP
#define YONETIM_HPP

#include "Okul.hpp"
#include <iostream>
using namespace std;

class Yonetim{
	private:
		Okul* okul;
	public:
		Yonetim();
		void OkulDoldur();
		void EkranListele();
		void SinifDegistir();
		void SinifDegisikligi(Sinif*, Sinif*);
		void OgrenciDegistir();
		void OgrenciDegisikligi(Ogrenci*, Ogrenci*);
		void Cikis();
		void Baslat();
};


#endif