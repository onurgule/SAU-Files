#include "Kisi.h"
Kisi KisiOlustur(){
Kisi this;
this = (Kisi)malloc(sizeof(struct KISI));
this->tc = TcOlustur();
this->telefon = TelefonOlustur();
return this;
}
