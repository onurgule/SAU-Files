/**        
 * @file  Yonetim.cpp  
 * @description Veri Yapıları 2. Ödev
 * @course Veri Yapıları - 2B   
 * @date  25.11.2018 
 * @author  Onur Osman Güle - onur.gule@ogr.sakarya.edu.tr - G171210021   
 */
#include "Yonetim.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>
#include <iomanip>
using namespace std;
Yonetim::Yonetim(){
	this->head = NULL;
	
	VerileriIsle();
}
void Yonetim::EkranListele(){
	system("Color 4F");
	system("cls"); 
	cout << "1- Sola Hareket" << endl << "2- Saga Hareket" << endl << "3- Bir Dugumun Durumlarini Yazdir" << endl << "4- Tum Durumlari Yazdir" << endl << "5- Cikis" <<endl<< "Seciminizi Yapiniz:";
	char secim =0;
	try{
				cin >> secim;
				switch(secim){
					case '1':
						SolaHareket(); break;
					case '2': 
						SagaHareket(); break;
					case '3': 
						DugumDurumlariSecimi(); break;
					case '4': 
						TumDugumDurumlari(); break;
					case '5': 
						Cikis(); break;
					default:
						EkranListele(); break;
				}
				}
				catch(int hat){
					EkranListele();
				}
}

void Yonetim::Cikis(){

	system("Color 0F");
	Node *temp = this->head;
	Node *sonraki = NULL;
	for(;;)
	{
		if(temp->getNext() != this->head && sonraki != this->head)
		{
			temp = temp->getNext();
			if(sonraki != NULL) delete sonraki;
			sonraki = temp->getNext();
			if(temp != NULL) delete temp;
			temp = sonraki;
		}
		else {
			delete temp; delete head; 
			break;
			}
	}
	system("cls");
	exit(0);
}
void Yonetim::SolaHareket(){
	Node *temp = this->head;
	Node *temphead = new Node(*this->head);
	for(;;)
	{
		if(temp->getNext() != this->head)
		temp->setData(temp->getNext()->getData());
		else temp->setData(temphead->getData());
		if(temp->getNext() != this->head)
		{
			temp = temp->getNext();
		}
		else break;
	}
	delete temphead;
	EkranListele();
}
void Yonetim::SagaHareket(){
	Node *temp = this->head;
	Node *temphead = new Node(*this->head);
	for(;;)
	{
		if(temp->getPrevious() != this->head)
		temp->setData(temp->getPrevious()->getData());
		else temp->setData(temphead->getData());
		if(temp->getPrevious() != this->head)
		{
			temp = temp->getPrevious();
		}
		else break;
	}
	delete temphead;
	EkranListele();
}
void Yonetim::DugumDurumlariSecimi(){
	system("cls");
	cout << "Dugum Konumu:";
	int dugumKonumu;
	try{
		cin >> dugumKonumu;
		Node *temp = this->head;
		for(int i=0;;i++)
		{
			if(i == dugumKonumu) {
				DugumDurumlari(temp);
				break;
			}
			
			if(temp->getNext() != this->head)
			{
				temp = temp->getNext();
			}
			else {EkranListele(); 	break; }
		}
	}
	catch(int hat)
	{
		EkranListele();
	}
}
void Yonetim::DugumDurumlari(Node* dugum){
	cout << setw(6) <<dugum->getData() << left;
			dugum->getAllStackStates();
			cout << endl;
			system("pause");
			EkranListele();
}
void Yonetim::TumDugumDurumlari(){
	system("cls");
	Node *temp = this->head;
	for(;;)
	{
		cout << setw(6) <<temp->getData() << left;
		temp->getAllStackStates();
		cout << endl;
		//nedense ilk satırın ilk sütunu 2. satırın ilk sütununu gösteriyor? ERROR
		if(temp->getNext() != this->head)
		{
			temp = temp->getNext();
		}
		else break;
	}
	system("pause");
	EkranListele();
}
void Yonetim::VerileriIsle(){
	ifstream file("Sayi.txt");
	string sayi;
	Node *temp;
	while (file >> sayi)
	{
		int numara = atoi(sayi.c_str());
		Node *dugum = new Node(numara,NULL,NULL);
		if(this->head == NULL) {this->head = dugum;}
		else{
			temp->setNext(dugum);
			dugum->setPrevious(temp);
			dugum->setNext(head);
			//2 satırı: Node *dugum = new Node(Numara,temp,head); diyebiliriz.
		}
		temp = dugum;
	}
	this->head->setPrevious(temp);
	
}