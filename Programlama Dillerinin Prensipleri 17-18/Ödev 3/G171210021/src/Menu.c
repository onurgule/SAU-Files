#include "Menu.h"

void DosyayaYaz(Kisi k){
	 FILE *fp = fopen("Kisiler.txt","a");
	 fprintf(fp,"%s %s %d %s (%s)\n",k->tc->tcNo,k->isim,k->yas,k->telefon->telno,k->telefon->imei->imeino);
	 fclose(fp);
}
void SayiKisiOlustur(int kisisayisi){
	int yas = 0;
	for(int i=0; i<kisisayisi; i++){
		RastgeleKisi rk = RastgeleKisiOlustur();
		if(yas == rk->super->yas) {i--; continue;}
		//printf("%s\n", rk->super->tc->tcNo);
		//dosyaya at.
    if(strlen(rk->super->isim)<3) {printf("\nDosya Bulunamadi"); break;}
		DosyayaYaz(rk->super);
		yas = rk->super->yas;
	}
  printf("\n%d Kisi olusturuldu!\n",kisisayisi);
}

void DosyaKisileriListele(){
FILE *f = fopen("Kisiler.txt","r");
if (f){
size_t pos = ftell(f);
fseek(f, 0, SEEK_END);
size_t length = ftell(f);
fseek(f, pos, SEEK_SET); 
int dosyauzunlugu = length/57+1;
	char *tcler[dosyauzunlugu];
	char *imeiler[dosyauzunlugu];
int gecerliIMEI = 0;
int gecersizIMEI = 0;
int gecerliKimlik = 0;
int gecersizKimlik = 0;
	    char line[500];




  int sayi = 0;
        char *liste[dosyauzunlugu];
				while (fgets(line, sizeof(line), f)) {
					if(line != NULL){
				//	liste[sayi] = line;

				char *pch;

				//char str[] = liste[sayi];
				char str[500];
				strcpy(str,line);
				pch = strtok(str," ");
				int bilgi = 0;
				while (pch != NULL)
				{
					bilgi++;
					if(bilgi == 1){ //tc
					//printf ("%s\n",pch);
					if(KimlikKontrolK(pch) == 1)
							 gecerliKimlik++;
					else gecersizKimlik++;
					}
					else if(bilgi ==7) { //imei
						//printf("onur %d",ImeiKontrolK(pch));
   					for(int i = 0; i < 18 - 1; i++) pch[i] = pch[i + 1];
						pch[15] = '\0';
						if(ImeiKontrolK(pch) == 1)
								 gecerliIMEI++;
						else gecersizIMEI++;
				}
				else{
					pch = strtok (NULL, " ");
				}
				}
				sayi++;
				}
			 }

			 sayi = 0;


        printf("T.C. Kimlik Kontrol\n");
        printf("%5d Gecerli\n", gecerliKimlik);
        printf("%5d Gecersiz\n", gecersizKimlik);
        printf("\nIMEI Kontrol\n");
        printf("%5d Gecerli\n", gecerliIMEI);
        printf("%5d Gecersiz\n", gecersizIMEI);
      }
      else{
        printf("\nDosya bulunamadi!\n");
      }
      fclose(f);
}


void MenuGoster(){
  int secim;
  	do{

  	            printf("1- Rastgele Kisi Uret\n");
  	            printf("2- Uretilmis Dosya Kontrol Et\n");
  	            printf("3- Cikis\n");

  	            int kacKisi;
  	            scanf("%d",&secim);
  	            if(secim == 1){
  	                //clearScreen();
  	                printf("Kac kisi olusturulsun:");
  	                scanf("%d",&kacKisi);
  									printf("Olusturuluyor...");
  	                SayiKisiOlustur(kacKisi);
  	            }
  	            else if (secim == 2){
  	                DosyaKisileriListele();
  	                printf("Devam etmek icin Enter'a basiniz...\n");
  	                getchar();
  	            }
  	        }while(secim != 3);
}
