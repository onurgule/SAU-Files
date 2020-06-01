package rastgelekisiler;

import java.io.IOException;
import java.util.Scanner;

/*
 *
 * @author Onur Osman Güle - onur.gule@ogr.sakarya.edu.tr
 * @since 26.03.2018
 * 
 */
public class Menu extends Islem {
    private int secim = 0;
    public static void clearScreen() throws IOException {  
        for (int i = 0; i < 30; i++) {
            System.out.println(""); //Javada console.clear yok, böyle çözüm ürettim.
        }

}  
    public Menu() throws IOException, InterruptedException{
        do{
            clearScreen();
            System.out.println("1- Rastgele Kişi Üret");
            System.out.println("2- Üretilmiş Dosya Kontrol Et");
            System.out.println("3- Çıkış");
            Scanner scan = new Scanner(System.in);
            String oku = scan.next();
            secim = Integer.parseInt(oku);
            if(secim == 1){
                clearScreen();
                System.out.print("Kaç kişi oluşturulsun:");
                Scanner scan2 = new Scanner(System.in);
                String oku2 = scan2.next();
                KisiOlustur(Integer.parseInt(oku2));
                System.out.println("Kişi oluşturuldu!");
                Thread.sleep(1000);
            }
            else if (secim == 2){
                clearScreen();
                DosyaKisileriListele();
                System.out.print("Devam etmek için Enter'a basınız...");
                System.in.read();
            }
        }while(secim != 3);
    }
}
