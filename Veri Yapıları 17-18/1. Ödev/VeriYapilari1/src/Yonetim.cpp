/**        
 * @file  Yonetim.cpp  
 * @description Veri Yapıları 1. Ödev
 * @course Veri Yapıları - 2B   
 * @date  22.10.2018 
 * @author  Onur Osman Güle - onur.gule@ogr.sakarya.edu.tr - G171210021   
 */
#include "Yonetim.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>
#include <iomanip>
#include "Ogrenci.hpp"
using namespace std;
Yonetim::Yonetim(){
	
	Okul *ok = new Okul();
	this->okul = ok;
	this->OkulDoldur();
}
		void Yonetim::OkulDoldur(){
			Ogrenci *ogr = new Ogrenci('0'); // Ram rezervesi.
			Sinif *snf = new Sinif('0'); // Rami rezerve ediyoruz.
			ifstream input("Okul.txt");
			int i=0;
			for(string satir; getline( input, satir ); )
				{
					string kelime;
					stringstream sSatir(satir);
					int j = 0;
					while (sSatir >> kelime) 
					{
						if(j==0){
							
							char sinifSube = kelime[0];
							snf = new Sinif(sinifSube);
							this->okul->SinifEkle(snf);
						}
						else{
							char ogrenciAd = kelime[0];
							ogr = new Ogrenci(ogrenciAd);
							if(snf!=NULL)
							snf->OgrenciEkle(ogr);
						}
						j++;
					}
					i++;
				}
			//SinifDegisikligi(this->okul->getSinif(2),this->okul->getSinif(3));
		}
		void Yonetim::Baslat(){
			EkranListele();
		}
		void Yonetim::EkranListele(){
			system("cls");
			system("Color 0A");
			for(int i =0; i<this->okul->getSinifSayisi(); i++)
				cout <<"Sinif: "<< this->okul->getSinif(i)->getSube() << setw(22);
				cout <<setw(0)<<endl;
				int i = 0;
				for(int c = 0; c<this->okul->getSinifSayisi(); c++)
					i = (this->okul->getSinif(c)->getOgrenciSayisi()>this->okul->getSinif(i)->getOgrenciSayisi()) ? c : i;
				for(int j =0; j<this->okul->getSinif(i)->getOgrenciSayisi(); j++ ){ // 9 sınıflar için
				
					int doluElemanSayisi = 0, bosElemanSayisi=0;
					for(int k =0; k<this->okul->getSinifSayisi(); k++){ // 4 kere elemanlar için
						if(this->okul->getSinif(k)->ogrenciVarMi(j)){
							cout <<  this->okul->getSinif(k)->getOgrenci(j)->getAd() <<  " ("<< this->okul->getSinif(k)->getOgrenci(j) << ")"<< setw(12);
							doluElemanSayisi++;
						}
						
						//cout << this->okul->getSinif(k)->ogrenciVarMi(j);
						//if(k==3 && j==2) cout << "hehe";
						else {
							cout << setw(0);
							bosElemanSayisi++;
							cout << setw(12) <<""<< setw((bosElemanSayisi-1)*12 + (doluElemanSayisi-1)*12 - doluElemanSayisi)<<"" << setw(12) << "";
							
						}
					}
					cout <<setw(0) <<endl;
				}
				cout << endl << endl;
				cout << "1. Sinif Degistir"<<endl;
				cout << "2. Ogrenci Degistir"<<endl;
				cout << "3. Cikis"<<endl;
				cout << "=>";
				char secim = 0;
				try{

				cin >> secim;
				if(secim == '1'){
					SinifDegistir();
				}
				switch(secim){
					case '1':
						SinifDegistir(); break;
					case '2': 
						OgrenciDegistir(); break;
					case '3': 
						Cikis(); break;
					default:
						EkranListele(); break;
				}
				}
				catch(int hat){
					EkranListele();
				}
			
				
				// cout << endl;
			
		}
		void Yonetim::SinifDegistir(){
			char snf1,snf2;
			try{
			cout << "Sinif 1:";
			cin >> snf1;
			cout << "Sinif 2:";
			cin >> snf2;
			SinifDegisikligi(this->okul->getSinifWithName(snf1), this->okul->getSinifWithName(snf2));
			EkranListele();
			}catch(int hat){EkranListele();}
			


		}
		void Yonetim::SinifDegisikligi(Sinif* sn1, Sinif* sn2){
				int sn1l = 0, sn2l = 0;
				for(int i =0; i<this->okul->getSinifSayisi(); i++){
				if(this->okul->getSinif(i) == sn1) sn1l = i;
				if(this->okul->getSinif(i) == sn2) sn2l = i;
				}
				ofstream myfile;
				myfile.open ("Okul.txt");
				for(int i =0; i<this->okul->getSinifSayisi(); i++){
					int sinif = i;
					if(i == sn1l) sinif = sn2l;
					if(i == sn2l) sinif=sn1l;
						myfile << this->okul->getSinif(sinif)->getSube();
						for(int j = 0; j<this->okul->getSinif(sinif)->getOgrenciSayisi(); j++){
							myfile <<" "<< this->okul->getSinif(sinif)->getOgrenci(j)->getAd();
						}
						myfile << "\n";
				}
				myfile.close();
				int ilksinif = (sn1l<sn2l) ? sn1l : sn2l;
				//filedan sonra bir de dizilerde address değişikliği yapmadan taşı. basit.
				// Sinif* tempSiniflar[];
				this->okul->SinifYerDegistir(sn1,sn2);
		}
		void Yonetim::OgrenciDegistir(){
			char ogn1=0, ogn2=0;
			try{
			cout << "Ogrenci 1:";
			cin >> ogn1;
			cout << "Ogrenci 2:";
			cin >> ogn2;
			OgrenciDegisikligi(this->okul->getOgrenciWithName(ogn1), this->okul->getOgrenciWithName(ogn2));
			EkranListele();
			// cout << this->okul->getOgrenciWithName(ogn1)->getAd();
			}catch(int hat){EkranListele();
			}
		}
		void Yonetim::OgrenciDegisikligi(Ogrenci* og1, Ogrenci* og2){
				ofstream myfile;
				myfile.open ("Okul.txt");
				for(int i =0; i<this->okul->getSinifSayisi(); i++){
					int sinif = i;
						myfile << this->okul->getSinif(sinif)->getSube();
						for(int j = 0; j<this->okul->getSinif(sinif)->getOgrenciSayisi(); j++){
							if(this->okul->getSinif(sinif)->getOgrenci(j) == og1)
							myfile <<" "<< og2->getAd();
							else if(this->okul->getSinif(sinif)->getOgrenci(j) == og2)
							myfile <<" "<< og1->getAd();
							else
							myfile <<" "<< this->okul->getSinif(sinif)->getOgrenci(j)->getAd();
						}
						myfile << "\n";
				}
				myfile.close();
				this->okul->OgrenciYerDegistir(og1,og2);
		}
		void Yonetim::Cikis(){
			system("Color 0F");
			delete this->okul;
			system("cls");
			exit(0);
		}
