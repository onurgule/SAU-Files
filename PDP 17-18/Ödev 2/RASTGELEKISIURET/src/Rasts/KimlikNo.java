package Rasts;


import java.util.ArrayList;
import java.util.Random;

/*
 *
 * @author Onur Osman Güle - onur.gule@ogr.sakarya.edu.tr
 * @since 26.03.2018
 * 
 */
public class KimlikNo {
    private String tcNo;
    public KimlikNo(){
        //rastgeleKimlikOlustur();
    }
     public String getTcNo() {
        return tcNo;
      }
    public void setTcNo( String tcNo ) {
      this.tcNo = tcNo;
    }
    public void rastgeleKimlikOlustur(){
        ArrayList<Integer> arl = new ArrayList<Integer>();
        Random r = new Random();
        arl.add(new Integer(1 + r.nextInt(9)));
        for (int i=1;i<9;i++) arl.add(r.nextInt(10));
        int t1 = 0;
        for (int i=0;i<9;i+=2) t1 += arl.get(i);
        int t2 = 0;
        for (int i=1;i<8;i+=2) t2 += arl.get(i);
        int x = (t1 * 7 - t2) % 10;
        arl.add(new Integer(x));
        x=0;
        for(int i=0;i<10;i++) x+= arl.get(i);
        x= x % 10;
        arl.add(new Integer(x));
        String res = "";
        for(int i=0;i<11;i++) res = res + Integer.toString(arl.get(i));
        setTcNo(res);        
    }
    public boolean kimlikKontrol(){
        try {
		String tmp = getTcNo();
 
		if (tmp.length() == 11) {
			int totalOdd = 0;
 
			int totalEven = 0;
 
			for (int i = 0; i < 9; i++) {
				int val = Integer.valueOf(tmp.substring(i, i + 1));
 
				if (i % 2 == 0) {
					totalOdd += val;
				} else {
					totalEven += val;
				}
			}
 
			int total = totalOdd + totalEven + Integer.valueOf(tmp.substring(9, 10));
 
			int lastDigit = total % 10;
 
			if (tmp.substring(10).equals(String.valueOf(lastDigit))) {
				int check = (totalOdd * 7 - totalEven) % 10;
 
				if (tmp.substring(9, 10).equals(String.valueOf(check))) {
					return true;
				}
			}
		}
	} catch (Exception e) {
		System.out.println("Bir hata oluştu!");
        }
	return false;
    }
    public boolean kimlikKontrol(String tcn){
        try {
		String tmp = tcn;
 
		if (tmp.length() == 11) {
			int totalOdd = 0;
 
			int totalEven = 0;
 
			for (int i = 0; i < 9; i++) {
				int val = Integer.valueOf(tmp.substring(i, i + 1));
 
				if (i % 2 == 0) {
					totalOdd += val;
				} else {
					totalEven += val;
				}
			}
 
			int total = totalOdd + totalEven + Integer.valueOf(tmp.substring(9, 10));
 
			int lastDigit = total % 10;
 
			if (tmp.substring(10).equals(String.valueOf(lastDigit))) {
				int check = (totalOdd * 7 - totalEven) % 10;
 
				if (tmp.substring(9, 10).equals(String.valueOf(check))) {
					return true;
				}
			}
		}
	} catch (Exception e) {
		System.out.println("Bir hata oluştu!");
        }
	return false;
    }
}
