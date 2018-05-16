package g171210021_4;

import java.io.IOException;
import java.util.ArrayList;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;


/**
 *
 * @author Onur Osman Güle G171210021 onur.gule@ogr.sakarya.edu.tr
 */

public final class Hesaplamalar {
    public static String sonucP = "0";
    public static ArrayList<String> sonuclarP = new ArrayList<>();
    public static void SeriCarp(String sayi1, String sayi2) throws IOException{
        long startTime = System.currentTimeMillis(); 
        String sonuc = "0";
        String gecici = "0";
        
        {
        String onda = "";
        for (int i = sayi2.length()-1; i >= 0 ; i--) {
            gecici = Hesaplamalar.Toplam(gecici, Hesaplamalar.Carpim(sayi1, sayi2.charAt(i)+onda));
            onda+="0";
        }
         sonuc = Hesaplamalar.Toplam(sonuc, gecici);
        }
        long finishTime = System.currentTimeMillis();
        System.out.println("Seri Hesaplama Süresi: " + (finishTime-startTime)  + " milisaniye");
    }
    
    public static void ParalelCarp(String sayi1, String sayi2) throws IOException{
        sonuclarP.add("0");
        ExecutorService havuz = Executors.newFixedThreadPool(8);
        long startTime = System.currentTimeMillis(); 
        for (int i = sayi2.length()-1; i >= 0 ; i--) {
         havuz.submit(new CarpimHesabi(sayi1,sayi2,i));
        }
        havuz.shutdown();
        while(!havuz.isTerminated()){}
        long finishTime = System.currentTimeMillis();
        sonucP = listedenTopla();
        Dosyalama.DosyayaKaydet(sonucP);
        System.out.println("Paralel Hesaplama Süresi: " + (finishTime-startTime)  + " milisaniye");
    }
    public static String listedenTopla(){
        String top = "0";
        for (String sonuclarP1 : sonuclarP) {
            if(top!=null && sonuclarP1 != null)
            top = Toplam(top, sonuclarP1);
        }
        return top;
    }
    public static String Carpim(String num1, String num2) {   
    String n1 = new StringBuilder(num1).reverse().toString();
    String n2 = new StringBuilder(num2).reverse().toString();
    int[] d = new int[num1.length()+num2.length()];
    for(int i=0; i<n1.length(); i++){
        for(int j=0; j<n2.length(); j++){
            d[i+j] += (n1.charAt(i)-'0') * (n2.charAt(j)-'0');
        }
    }
 
    StringBuilder sb = new StringBuilder();
    for(int i=0; i<d.length; i++){
        int mod = d[i]%10;
        int carry = d[i]/10;
        if(i+1<d.length){
            d[i+1] += carry;
        }
        sb.insert(0, mod);
    }
    while(sb.charAt(0) == '0' && sb.length()> 1){
        sb.deleteCharAt(0);
    }
 
    return sb.toString();
}
    public static String Toplam(String str1, String str2) {
    int max = Math.max(str1.length(), str2.length());
    int n1[] = new int[max];
    int n2[] = new int[max];
    for (int i = 0; i < str1.length(); i++) {
        n1[i] = Character.getNumericValue(str1.charAt(str1.length() - 1 - i));
    }
    for (int i = 0; i < str2.length(); i++) {
        n2[i] = Character.getNumericValue(str2.charAt(str2.length() - 1 - i));
    }
    int carry = 0;
    int sum[] = new int[max + 1];
    int k = 0;
    for (k = 0; k < max; k++) {
        sum[k] = (n1[k] + n2[k] + carry) % 10;
        if ((n1[k] + n2[k] + carry) >= 10) {
            carry = 1;
        } else {
            carry = 0;
        }
    }
    sum[max] = carry;
    StringBuilder sb = new StringBuilder();
    if (sum[max] > 0) {
        sb.append(String.valueOf(sum[max]));
    }
    for (int i = max - 1; i >= 0; i--) {
       sb.append(String.valueOf(sum[i]));
    }  
    return sb.toString();
}
    public static String tersString(String text) {
        char[] chars = text.toCharArray();
        int lenght = chars.length;
        String ters = "";
        for(int i = lenght-1; i >= 0; i--) {
            ters+=chars[i];
        }
        return ters;
    }
}
