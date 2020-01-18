package g171210021;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

/**  
 *  
 * @author Onur Osman Güle - G171210021 - onur.gule@ogr.sakarya.edu.tr
 * @since 01.03.2018
 * <p>  
 *  Programlama Dillerinin Prensipleri 1. Ödev
 * </p>  
 */
public class AnaClass {
    public enum Objetip {
    CLASS, METHOD, VAR, PARAMETER, KAPATMA
}
    
    public static Objetip TipiVer(String satir){
        //Satırı okuyup string işlemleri yaparak hangi tipte olduğunu döndüren method.
        Objetip tip = null;
        if(satir.contains("class"))
            {
                tip = Objetip.CLASS;
            }
        else if(satir.contains("}"))
            {
                tip = Objetip.KAPATMA;
            }
            else if(satir.contains("()") ||satir.contains("int") || (satir.contains("String")) || satir.contains("boolean") || satir.contains("double") || satir.contains("void") || satir.contains("float"))  //Tanımlanan tipler buradan eklenip çıkartılabilir.
            {
                if( satir.contains("{") || satir.contains("(") || (!satir.contains("=") && !satir.contains(";"))) //method
                {
                    tip = Objetip.METHOD;
                }
                /*else if(satir.contains("(")){//parametre
                    tip = Objetip.PARAMETER;
                
                }*/
                else{ //değişken
                    tip = Objetip.VAR;
                }
            }
            
        return tip;
    }
    public static String SinifAdi(ArrayList<String> satirlar) {
        //Tüm satırları alıp class adı geçen satırı bulup gerekli string işlemleri yaparak ismi döndürür.
        String ad = null;
        Objetip usttip1 = null; //en üstü
        Objetip usttip2 = null; //şimdiki
        for (int i = 0; i < satirlar.size(); i++) {
            String ss = satirlar.get(i);
            Objetip simdikitip = TipiVer(ss);
            if(simdikitip == Objetip.CLASS && usttip2 == null)
            {
                ad = ss.substring(ss.indexOf("class") + 5,ss.indexOf("{")).trim();
            }
            if(simdikitip != null && simdikitip != Objetip.KAPATMA && (simdikitip == Objetip.CLASS || simdikitip == Objetip.METHOD)) {usttip1 = (usttip1 == null) ? simdikitip : usttip1; usttip2 = simdikitip;}
            else if(simdikitip == Objetip.KAPATMA) usttip2 = usttip1;
        }
        return ad;
    }
    public static ArrayList<String> SinifinAltElemanlari(ArrayList<String> satirlar){
        //Tüm satırları alıp değişken isimleri geçenleri bulup gerekli string işlemleri yaparak bir ArrayList döndürür, size’ı bize kaç adet alt eleman olduğu bilgisini verir.
        ArrayList<String> elemanlar = new ArrayList<>();
        Objetip usttip1 = null; //en üstü
        Objetip usttip2 = null; //şimdiki
        for (int i = 0; i < satirlar.size(); i++) {
            String ss = satirlar.get(i);
            Objetip simdikitip = TipiVer(ss);
            if(simdikitip == Objetip.VAR && usttip2 == Objetip.CLASS)
            {
                String tip = ss.split(" ")[(ss.split(" ").length-2)];
                String isim = ss.split(" ")[(ss.split(" ").length-1)].substring(0,ss.split(" ")[(ss.split(" ").length-1)].length()-1);
                elemanlar.add(isim + " - " + tip);
            }
            if(simdikitip != null && simdikitip != Objetip.KAPATMA && (simdikitip == Objetip.CLASS || simdikitip == Objetip.METHOD)) {usttip1 = (usttip1 == null) ? simdikitip : usttip1; usttip2 = simdikitip;}
            else if(simdikitip == Objetip.KAPATMA) usttip2 = usttip1;
        }
        return elemanlar;
    }
    public static ArrayList<String> MethodunAldigiParametreler(String satir){
        //Eğer verilen satir bir method tanımlama satırı ise methodun aldığı parametreleri ArrayList olarak döndürür.
        ArrayList<String> elemanlar = new ArrayList<>();
        if(TipiVer(satir)==Objetip.METHOD){
        String parametrebolum = satir.substring(satir.indexOf("(")+1,satir.indexOf(")"));
        if(satir.contains("()")) return elemanlar;
        String parametreler[] = parametrebolum.trim().split(",");
        if(parametreler.length > 0){
        for (String param : parametreler) {
            elemanlar.add(param); //int deger
        }
        }
        else {
            if(parametrebolum != "" && parametrebolum != " ")
            elemanlar.add(parametrebolum);
     
        }
        }
        if(elemanlar.size() > 0){
            if(elemanlar.get(0) == "" || elemanlar.get(0).trim() == ""){
                elemanlar.clear();
            }
        }
        return elemanlar;
    }
    public static ArrayList<String> SinifinUyeFonksiyonlari(ArrayList<String> satirlar){
        //MethodunAldigiParametreler adlı method ile çalışarak string işlemleri yapıp bize gerekli tüm verileri toplayıp bir ArrayList döndürür.
        ArrayList<String> elemanlar = new ArrayList<>();
        Objetip usttip1 = null; //en üstü
        Objetip usttip2 = null; //şimdiki
        for (int i = 0; i < satirlar.size(); i++) {
            String ss = satirlar.get(i);
            Objetip simdikitip = TipiVer(ss);
            String isim = "";
            if(simdikitip == Objetip.METHOD && usttip2 == Objetip.CLASS)
            {
                int boslukBeforeName = 0;
                for(int j = 0; j<ss.split(" ").length; j++){
                    if(ss.split(" ")[j].contains("(")){
                        boslukBeforeName = ss.indexOf(ss.split(" ")[j]);
                        break;
                    }
                }
                isim = ss.substring(boslukBeforeName, ss.indexOf("(")).trim();
                int paramsayisi = MethodunAldigiParametreler(ss).size();
                int tipBeforeName = 0;
                if(ss.contains("public"))
                    tipBeforeName = ss.indexOf("public") + "public".length();
                else if(ss.contains("private"))
                    tipBeforeName = ss.indexOf("private") + "private".length();
                else if(ss.contains("protected"))
                    tipBeforeName = ss.indexOf("protected") + "protected".length();
                if(ss.contains("static"))
                    tipBeforeName = ss.indexOf("static") + "static".length(); 
                String tip = ss.substring(tipBeforeName, boslukBeforeName).trim();
                if("".equals(tip)) tip = "Yok";
                String eleman = isim + "\nDönüş Türü: " + tip + "\nAldığı Parametre: " + MethodunAldigiParametreler(ss).size();
                for (String met : MethodunAldigiParametreler(ss)) {
                    if(met.split(" ").length > 1){
                    eleman+= "\n" + met.split(" ")[met.split(" ").length-1] + " - " + met.split(" ")[met.split(" ").length-2];
                    }
                }
                elemanlar.add(eleman);
            }
            if(simdikitip != null && simdikitip != Objetip.KAPATMA && (simdikitip == Objetip.CLASS || simdikitip == Objetip.METHOD)) { usttip1 = (usttip1 == null) ? simdikitip : usttip1; usttip2 = simdikitip;}
            else if(simdikitip == Objetip.KAPATMA ) { usttip2 = usttip1;}
        }
        return elemanlar;
    }
    public static void main(String[] args) throws IOException {
        
        File file = new File("Program.java"); // direk Program.java çalıştırmıyor.
        BufferedReader br;
        br = new BufferedReader(new FileReader(file));
        String satir = br.readLine();
        ArrayList<String> satirlar = new ArrayList<String>();
        while(satir != null){
            satirlar.add(satir);
            satir = br.readLine();
        }
        br.close();
        System.out.println("Sınıf Adı: "+SinifAdi(satirlar));
        System.out.println("Alt Elemanlar: "  + SinifinAltElemanlari(satirlar).size() + " adet");
        for (String sae : SinifinAltElemanlari(satirlar)) {
            System.out.println(sae);
        }
        System.out.println("Üye Fonksiyonlar: " + SinifinUyeFonksiyonlari(satirlar).size() + " adet");
        for(String suf : SinifinUyeFonksiyonlari(satirlar)){
            System.out.println(suf);
            System.out.println("------------------");
        }
        
    }  
}
