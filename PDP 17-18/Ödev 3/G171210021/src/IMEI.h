#ifndef IMEI_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define IMEI_H
struct IMEI{
	char imeino[15];
	void (*RastgeleImeiOlustur)(struct IMEI*);
	int (*ImeiKontrol)(struct IMEI*);
	int (*ImeiKontrolK)(char imei[15]);
};
typedef struct IMEI* Imei;
void RastgeleImeiOlustur(Imei);
Imei ImeiOlustur();
int ImeiKontrol(const Imei); //1-0
int ImeiKontrolK(char imei[15]);
int sumDig(int n);
#endif
