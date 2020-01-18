/**        
 * @file  Okul.cpp  
 * @description Veri Yapıları 1. Ödev
 * @course Veri Yapıları - 2B   
 * @date  22.10.2018 
 * @author  Onur Osman Güle - onur.gule@ogr.sakarya.edu.tr - G171210021   
 */
#include "Okul.hpp"
#include <stdio.h>
using namespace std;
Okul::Okul(){
	this->snfNumara = 0;
}
Okul::~Okul(){
    cout<<endl << "Bellek temizleniyor...";
	 for(int i = 0; i<getSinifSayisi(); i++){
        delete Siniflar[i];
    }
}
Okul::Okul(char olaylar[]){
	
}
void Okul::SinifEkle(Sinif* snf){
    this->Siniflar[snfNumara] = snf;
    // usleep(100000);
    this->snfNumara++;
}
Sinif* Okul::getSinif(int snf){
return this->Siniflar[snf];
}
int Okul::getSinifSayisi(){
    return this->snfNumara;
}
void Okul::SinifYerDegistir(Sinif* snf1, Sinif* snf2){
    int snf1i = 0;
    int snf2i = 0;

    for(int i = 0; i<getSinifSayisi(); i++){
        if(this->Siniflar[i] == snf1) snf1i = i;
        if(this->Siniflar[i] == snf2) snf2i = i;
    }
    Siniflar[snf1i] = snf2;
    Siniflar[snf2i] = snf1;
}
Ogrenci* Okul::getOgrenciWithName(char ogradi){
    for(int j = 0; j< getSinifSayisi(); j++){
        for(int i = 0; i < getSinif(j)->getOgrenciSayisi(); i++){
                if(getSinif(j)->getOgrenci(i)->getAd() == ogradi){
                    return getSinif(j)->getOgrenci(i);
                }
            }
    }
}
Sinif* Okul::getSinifWithName(char sinifadi){
    for(int j = 0; j< getSinifSayisi(); j++){
        if(getSinif(j)->getSube() == sinifadi) return getSinif(j);
    }
}
void Okul::OgrenciYerDegistir(Ogrenci* og1, Ogrenci* og2){
    int og1i = 0, og2i = 0, sn1i = 0, sn2i = 0;

    for(int i = 0; i<getSinifSayisi(); i++){
        for(int j=0; j< getSinif(i)->getOgrenciSayisi(); j++){
            if(this->getSinif(i)->getOgrenci(j) == og1) {og1i = j; sn1i = i;}
            if(this->getSinif(i)->getOgrenci(j) == og2) {og2i = j; sn2i = i;}
        }
    }
    this->getSinif(sn1i)->ogrenciDegistir(og1i, og2);
    this->getSinif(sn2i)->ogrenciDegistir(og2i, og1);
}
