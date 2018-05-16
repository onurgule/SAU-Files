#include "IMEI.h"
Imei ImeiOlustur(){
  Imei this;
  this = (Imei)malloc(sizeof(struct IMEI));
}
void RastgeleImeiOlustur(Imei gelenImei){
    srand(time(NULL));
          int pos;
          int str[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
          int sum = 0;
          int final_digit;
          int t;
          int len_offset;
          int len = 15;
          char imei[15];
          char *rbi[17] = {"01", "10", "30", "33", "35", "44", "45", "49", "50", "51", "52", "53", "54", "86", "91", "98", "99"};
          char arr[2];
          int rast = rand() % 17;
          arr[0] = rbi[rast][0];
          arr[1] = rbi[rast][1];
          str[0] = (arr[0]) - '0';
          str[1] = (arr[1]) - '0';
          pos = 2;

          while (pos < len - 1) {
              str[pos++] = (int) ((rand()%110) % 10);
          }

          len_offset = (len + 1) % 2;
          for (pos = 0; pos < len - 1; pos++) {
              if ((pos + len_offset) % 2 != 0) {
                  t = str[pos] * 2;
                  if (t > 9) {
                      t -= 9;
                  }
                  sum += t;
              } else {
                  sum += str[pos];
              }
          }

          final_digit = (10 - (sum % 10)) % 10;
          str[len - 1] = final_digit;

          for (int sy = 0; sy<15;sy++) {
            int k = str[sy];
            char gecici[1];
            snprintf(gecici, 1, "%d", k);
            imei[sy] = gecici[0];
          }
      strcpy(gelenImei->imeino,imei);
      //  printf("imei: %s \n",imei);
}

int sumDig(int n)
	{
		int a = 0;
	    while(n>0)
	    {
	    	a = a + n%10;
	        n = n/10;
	    }
	    return a;
	}


int ImeiKontrolK(char imei[15]){
    int ok = 0;
     int n[15];
     int gecici = 15;
     for(int i =0; i<15; i++) n[i] = imei[i]-'0';
     	    char s[15];
          strcpy(s,imei);
     	    int l = strlen(s);
     	    if(l!=15)
     	      ok = 0;
     	    else
     	    {
     	    	int d = 0, sum = 0;
     	        for(int i=15; i>=1; i--)
     	        {
     	        	d = (n[gecici-1]%10);
     	        	if(i%2 == 0)
     	            {
     	        		d = 2*d;
     	            }
     	        	sum = sum + sumDig(d);
     	        	n[gecici-1] = '\0';
                gecici--;
     	        }
     	        if(sum%10==0) ok = 1;
                     else ok = 0;
     	    }

  return ok;


}
