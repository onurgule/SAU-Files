/**        
 * @file  Sinif.cpp  
 * @description Veri Yapıları 1. Ödev
 * @course Veri Yapıları - 2B   
 * @date  22.10.2018 
 * @author  Onur Osman Güle - onur.gule@ogr.sakarya.edu.tr - G171210021   
 */
#include "Sinif.hpp"
#include <string>
Sinif::Sinif(char ad){
    this->Sube = ad;
    this->ogrNumara = 0;
}
Sinif::~Sinif(){
    for(int i = 0; i<getOgrenciSayisi(); i++){
        delete Ogrenciler[i];
    }
}
char Sinif::getSube(){
return this->Sube;
}
void Sinif::OgrenciEkle(Ogrenci* ogr){
this->Ogrenciler[ogrNumara] = ogr;
this->ogrNumara++;
}
int Sinif::getOgrenciSayisi(){
    return this->ogrNumara;
}
Ogrenci* Sinif::getOgrenci(int og){
return this->Ogrenciler[og];
}
bool Sinif::ogrenciVarMi(int og){
    int maxIndex = ogrNumara;
    if(og < maxIndex) return true;
    else return false;

}
void Sinif::ogrenciDegistir(int og1i,Ogrenci* og1){
    Ogrenciler[og1i] = og1;
}