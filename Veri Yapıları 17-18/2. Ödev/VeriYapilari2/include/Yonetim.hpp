#ifndef YONETIM_HPP
#define YONETIM_HPP

#include "Node.hpp"
#include <iostream>
using namespace std;

class Yonetim
{
  private:
  Node* head;

  public:
	Yonetim();
	void VerileriIsle();
	void EkranListele();
	void SolaHareket();
	void SagaHareket();
	void DugumDurumlari(Node *);
	void DugumDurumlariSecimi();
	void TumDugumDurumlari();
	void Cikis();
};

#endif