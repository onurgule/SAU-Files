package Rasts;
/*
 *
 * @author Onur Osman Güle - onur.gule@ogr.sakarya.edu.tr
 * @since 26.03.2018
 * 
 */
public class IMEINo {
    private String imeino;
    public IMEINo(){
        //rastgeleIMEIOlustur();
    }
     public String getIMEINo() {
        return imeino;
      }
    public void setIMEINo( String imeino ) {
      this.imeino = imeino;
    }
    public void rastgeleIMEIOlustur(){
        int pos;
        int[] str = new int[]{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int sum = 0;
        int final_digit;
        int t;
        int len_offset;
        int len = 15;
        String imei = "";

        String[] rbi = new String[]{"01", "10", "30", "33", "35", "44", "45", "49", "50", "51", "52", "53", "54", "86", "91", "98", "99"};
        String[] arr = rbi[(int) Math.floor(Math.random() * rbi.length)].split("");
        str[0] = Integer.parseInt(arr[0]);
        str[1] = Integer.parseInt(arr[1]);
        pos = 2;

        while (pos < len - 1) {
            str[pos++] = (int) (Math.floor(Math.random() * 10) % 10);
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

        for (int d : str) {
            imei += String.valueOf(d);
        }
        setIMEINo(imei);
    }
    public boolean imeiKontrol(){
        boolean okMu = false;
        int n = Integer.parseInt(getIMEINo());
        String s = Long.toString(n); // Converting the number into String for finding length
        int l = s.length();
         
        if(l!=15) // If length is not 15 then IMEI is Invalid
            okMu = false;
        else
        {
            int d = 0, sum = 0;
            for(int i=15; i>=1; i--)
            {
                d = (int)(n%10);
                if(i%2 == 0) d = 2*d;
                sum = sum + sumDig(d); // Finding sum of the digits
                n = n/10;
            }             
            if(sum%10==0)
                okMu = true;
            else
                okMu = false;
        }
        return okMu;
    }
     public boolean imeiKontrol(String im){
        boolean okMu = false;
	    long n = Long.parseLong(im);
	    String s = Long.toString(n); 
	    int l = s.length();
	    if(l!=15) 
	    okMu = false;
	    else
	    {
	    	int d = 0, sum = 0;
	        for(int i=15; i>=1; i--)
	        {
	        	d = (int)(n%10);
	        	if(i%2 == 0)
	            {
	        		d = 2*d; 
	            }
	        	sum = sum + sumDig(d); 
	        	n = n/10;
	        }
	        if(sum%10==0) okMu = true;
                else okMu = false;
	    }
        return okMu;
    }
    int sumDig(int n) 
	{
		// initialise here.
		int a = 0;
	    while(n>0)
	    {
	    	a = a + n%10;
	        n = n/10;
	    }
	    return a;
	}
}
