#ifndef RastgeleKisi_H

#include "Kisi.h"
#define RastgeleKisi_H
struct RASTGELEKISI{
  Kisi super;
  void (*isimGetir)(struct RASTGELEKISI*);
};
typedef struct RASTGELEKISI* RastgeleKisi;
void isimGetir(RastgeleKisi);
void tcOlustur(KimlikNo);
RastgeleKisi RastgeleKisiOlustur();
/*void SayiKisiOlustur(int kisisayisi);
int getRandomValue();
void DosyayaYaz(Kisi);
void DosyaKisileriListele();*/
#endif
