#ifndef KISI_H
#include "Telefon.h"
#include "KimlikNo.h"
#define KISI_H
struct KISI{
	KimlikNo tc;
	char isim[50];
	int yas;
	Tel telefon;
	void (*RandomYas)(struct KISI*);
};
typedef struct KISI* Kisi;
void RandomYas(Kisi);
Kisi KisiOlustur();
#endif
