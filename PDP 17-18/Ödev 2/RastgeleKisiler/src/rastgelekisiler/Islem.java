/*
 *
 * @author Onur Osman Güle - onur.gule@ogr.sakarya.edu.tr
 * @since 26.03.2018
 * 
 */
package rastgelekisiler;

import Rasts.*;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Random;

/**
 *
 * @author m2hes
 */
public  class Islem {
    public Islem(){
    }
    public void KisiOlustur(int adet) throws IOException{
        for(int i = 0; i<adet; i++){
        RastgeleKisi rk = new RastgeleKisi();
        KisiyiDosyayaYaz(rk);
        }
    }
    public void KisiyiDosyayaYaz(Kisi k) throws IOException{
         File file = new File("Kisiler.txt");
        if (!file.exists()) {
            file.createNewFile();
        }

        FileWriter fileWriter = new FileWriter(file,true);
        BufferedWriter bWriter = new BufferedWriter(fileWriter);
        bWriter.write(k.getTcNo() + " " + k.getIsim() + " " + k.getYas() + " " + k.getTelefon().getTel() + " (" + k.getTelefon().getIMEINo() + ")");
        bWriter.newLine();
        bWriter.close();

    }
    public void setwL(String str, int width)
	{		
		for (int x = str.length(); x < width; ++x) 
		{
			System.out.print(' ');	
		}
		System.out.print(str);
	}
    public void DosyaKisileriListele() throws IOException{
        ArrayList<String> tcler = new ArrayList<String>();
        ArrayList<String> imeiler = new ArrayList<String>();
        
        File file = new File("Kisiler.txt");
        FileReader fileReader = new FileReader(file);
        BufferedReader br = new BufferedReader(fileReader);
        String line = "ok";
        ArrayList<String> liste = new ArrayList<>();
        while (line != null) {
            line = br.readLine();
            if(line != null)
            liste.add(line);
        }
        for(String it : liste){
            tcler.add(it.split(" ")[0].trim());
            imeiler.add(it.split(" ")[it.split(" ").length -1].substring(1,it.split(" ")[it.split(" ").length-1].length()-1).trim());
        }
        br.close();
        int gecerliKimlik = 0, gecersizKimlik = 0, gecerliIMEI = 0, gecersizIMEI =0;
        for(String tcn : tcler){
            KimlikNo k = new KimlikNo();
            if(k.kimlikKontrol(tcn)) gecerliKimlik++;
            else gecersizKimlik++;
        }
        for(String im : imeiler){
            IMEINo i = new IMEINo();
            if(i.imeiKontrol(im)) gecerliIMEI++;
            else gecersizIMEI++;
        }
        System.out.println("T.C. Kimlik Kontrol");
        System.out.println(String.format("%1$-" + 5 + "s", gecerliKimlik) + "Geçerli");
        System.out.println(String.format("%1$-" + 5 + "s", gecersizKimlik) + "Geçersiz");
        System.out.println("\nIMEI Kontrol");
        System.out.println(String.format("%1$-" + 5 + "s", gecerliIMEI) + "Geçerli");
        System.out.println(String.format("%1$-" + 5 + "s", gecersizIMEI) + "Geçersiz");
        /*System.out.print(gecerliKimlik);
        setwL("Geçerli\n", 5);
        System.out.print(gecersizKimlik);
        setwL("Geçersiz", 5);
        System.out.println("IMEI Sayısı : " + imeiler.size());*/
        
    }
    
}
