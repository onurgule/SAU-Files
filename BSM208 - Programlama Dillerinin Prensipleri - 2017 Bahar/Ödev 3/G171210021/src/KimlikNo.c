#include "KimlikNo.h"
KimlikNo TcOlustur(){
  	srand(time(NULL));
  KimlikNo this;
  this = (KimlikNo)malloc(sizeof(struct KNO));
}
void RastgeleTcOlustur(KimlikNo kno){
          srand(time(NULL));
          int arl[11];
          arl[0] = (1+rand()%9);
          for (int i=1;i<9;i++) arl[i]= rand()%10;
          int t1 = 0;
          for (int i=0;i<9;i+=2) t1 += arl[i];
          int t2 = 0;
          for (int i=1;i<8;i+=2) t2 += arl[i];
          int x = (t1 * 7 - t2) % 10;
          arl[9] = (x);
          x=0;
          for(int i=0;i<10;i++) x+= arl[i];
          x= x % 10;
          arl[10] = (x);
          char res[11];
          for(int i=0;i<11;i++){
           int k = arl[i];
           char str[11];
           snprintf(str, 11, "%d", k);
           res[i] = str[0];
          }
          strcpy(kno->tcNo,res);
}
int KimlikKontrolK(char tcn[11]){

    char tmp[11];
    char gec[1];
    strcpy(tmp,tcn);
		if (strlen(tcn) == 11) {
			int totalOdd = 0;
			int totalEven = 0;
			for (int i = 0; i < 9; i++) {

        gec[0] = tmp[i];
				int val = gec[0] - '0';

				if (i % 2 == 0) {
					totalOdd += val;
				} else {
					totalEven += val;
				}
			}
      gec[0] = tmp[9];
			int total = totalOdd + totalEven + (gec[0]-'0');

			int lastDigit = total % 10;

			if ((tmp[10]-'0') == lastDigit) {
				int check = (totalOdd * 7 - totalEven) % 10;

				if ((tmp[9]-'0') == check) {
					return 1;
				}
			}
		}
	   return 0;
    }
