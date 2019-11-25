#ifndef OGRENCI_HPP
#define OGRENCI_HPP

#include <iostream>
using namespace std;

class Ogrenci{
	private:
		char Ad;
	public:
		Ogrenci(char ad);
		~Ogrenci();
		char getAd();
};
#endif