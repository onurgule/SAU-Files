#ifndef KimlikNo_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define KimlikNo_H
struct KNO{
	char tcNo[11];
	void (*RastgeleTcOlustur)(struct KNO*);
	int (*KimlikKontrol)(struct KNO*);
	int (*KimlikKontrolK)(char tcn[11]);
};
typedef struct KNO* KimlikNo;
KimlikNo TcOlustur();
void RastgeleTcOlustur(KimlikNo);
int KimlikKontrol(const KimlikNo); //1-0
int KimlikKontrolK(char tcn[11]);
#endif
