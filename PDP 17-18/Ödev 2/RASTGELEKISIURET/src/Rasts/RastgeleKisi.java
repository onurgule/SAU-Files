package Rasts;


import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Random;

/*
 *
 * @author Onur Osman Güle - onur.gule@ogr.sakarya.edu.tr
 * @since 26.03.2018
 * 
 */
public class RastgeleKisi extends Kisi {

    
    public RastgeleKisi() {
        try{
        setIsim(isimGetir()); //isim oluşturuldu, burada getirildi.
        rastgeleKimlikOlustur(); //rastgele kimlik oluşturuldu.
        randomYas(); // rastgele yaş oluşturuldu.
        getTelefon().rastgeleTelUret(); // rastgele telefon no üretildi.
        getTelefon().rastgeleIMEIOlustur(); //ratgele imei oluşturuldu.
        //kişi tamamlandı.
        }catch(Exception a ){System.out.println("Bir hata meydana geldi!" + a.getMessage());}
    }
    String isimGetir() throws IOException{
        File file = new File("random_isimler.txt");
        FileReader fileReader = new FileReader(file);
        String line = "ok";
        String rIsim = "";
        BufferedReader br = new BufferedReader(fileReader);
        int maxLine = (int) br.lines().count();
        fileReader = new FileReader(file);
        br = new BufferedReader(fileReader);
        Random rnd = new Random();
        int r = rnd.nextInt(maxLine);
        int i = 1;
        while (line != null) {
            line = br.readLine();
            i++;
            if(i == r)
            {rIsim = line; break;}//random isim olarak satırı koyduk.
        }
        br.close();
        return rIsim;
    }
   
    
}
