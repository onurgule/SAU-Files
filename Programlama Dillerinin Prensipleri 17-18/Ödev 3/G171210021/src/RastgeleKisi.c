#include "RastgeleKisi.h"
#include <time.h>
#include <stdlib.h>
#define txtSayi 3000
RastgeleKisi RastgeleKisiOlustur(){
  srand(time(NULL));
  RastgeleKisi this;
  this = (RastgeleKisi)malloc(sizeof(struct RASTGELEKISI));
  this->super = KisiOlustur();
  isimGetir(this);
  RandomYas(this->super);
  RastgeleTcOlustur(this->super->tc);
  RastgeleImeiOlustur(this->super->telefon->imei);
  RastgeleTelUret(this->super->telefon);
//TC alınacak random.
//IMEI ve TEL alınacak Random.
return this;
}

void isimGetir(RastgeleKisi k){

FILE *file = fopen("random_isimler.txt","r");
if(file){

  char risim[50];
  char line[50];
  int i = 0;
  int sayi = rand()%txtSayi;
  while (fgets(line, sizeof(line), file)) {
    if(line != NULL){
  //	liste[sayi] = line;
  if(i==sayi){
    strcpy(risim,line);
    risim[strlen(risim)-1] = '\0';
    strcpy(k->super->isim,risim);
  break;
  }
  i++;
}
}
}
fclose(file);
}


void RandomYas(Kisi k){

int yeniyas = 1+rand() % 100;
k->yas = yeniyas;
}
