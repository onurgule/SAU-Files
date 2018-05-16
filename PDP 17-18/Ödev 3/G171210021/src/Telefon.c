#include "Telefon.h"
Tel TelefonOlustur(){
  Tel this;
  this = (Tel)malloc(sizeof(struct TEL));
  this->imei = ImeiOlustur();
}
void RastgeleTelUret(Tel t){
    srand(time(NULL));
     char newTel[11] = {'0','5'}; // 05456454845
     int nowrakam = 2;
         int rakam = 9;
         do{
              rakam = rand()%10;
           }while(!(rakam == 4 || rakam == 5 || rakam == 3 || rakam == 0));
         char gecici[1];
         snprintf(gecici, 1, "%d", rakam);
         newTel[nowrakam] = gecici[0];
         for (int i = 0; i < 8; i++) {
             nowrakam++;
             rakam = rand()%10;
             snprintf(gecici, 1, "%d", rakam);
             newTel[nowrakam] = gecici[0];
           }
     strcpy(t->telno,newTel);

}
