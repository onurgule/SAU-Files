/**
*
* @author Onur Osman Güle onur.gule@ogr.sakarya.edu.tr
* @since 03.04.2021
* <p>
* Menü Çaðýrma ve Ýþlem Sýnýfý
* </p>
*/
package pkt;

import java.security.InvalidParameterException;
import java.util.InputMismatchException;
import java.util.Scanner;

import pkt.Harf;
public class Menu {
	public static void getMenu() {
		int secim = 0;
		Scanner s = new Scanner(System.in);
		while(secim != 6) {
		System.out.println("1- Harf Oluþtur");
		System.out.println("2- Birkaç Harf Oluþtur");
		System.out.println("3- Belli Harfler Arasýnda Oluþtur");
		System.out.println("4- Birkaç Harfi Belli Harflerden Oluþtur");
		System.out.println("5- Rastgele Cümle Oluþtur");
		System.out.println("6- Çýkýþ");
		System.out.print("Seçiminiz: ");
		try {
			try { 
				secim = Integer.parseInt(s.nextLine()); 
				Menu.selectOption(secim);
				}
			catch(InputMismatchException | java.lang.NumberFormatException e) { throw new InvalidParameterException("Sadece sayý giriniz."); }
		}
		catch(InvalidParameterException e) { System.out.println(e.getMessage()); continue;	}
		catch(Exception e) { System.out.println("s"+e);}
		
		}
	}
	public static void selectOption(int secim) {
		if(secim > 6 || secim < 1) {
			throw new InvalidParameterException("1-6 arasý giriþ yapýnýz.");
		}
		try {
		switch(secim) {
		case 1:
			Karakter k = new Karakter();
			System.out.println(k.getKarakter());
			break;
		case 2:
			Scanner s = new Scanner(System.in);
			System.out.print("Kaç harfli oluþtursun: ");
			int sayi = Integer.parseInt(s.nextLine()); 
			Kelime kel = new Kelime(sayi);
			System.out.println(kel.getKelime());
			break;
		case 3:
			Scanner sc = new Scanner(System.in);
			System.out.print("Ýlk karakteri girin: ");
			String gel = sc.nextLine();
			char ilkHarf = gel.length()!=0?gel.charAt(0):' '; 	
			System.out.print("Ýkinci karakteri girin: ");
			gel = sc.nextLine();
			char ikinciHarf = gel.length()!=0?gel.charAt(0):' '; 			
			System.out.print("Kaç karakterli bir kelime olsun: ");
			int karSayisi = Integer.parseInt(sc.nextLine());
			Kelime kel3 = new Kelime(karSayisi,ilkHarf,ikinciHarf);
			System.out.println(kel3.getKelime());
			break;
		case 4:
			Scanner scr = new Scanner(System.in);
			System.out.print("Ýçerecek harfleri birleþik olarak girin (Örn: asdfg): ");
			String harfler = scr.nextLine(); 			
			System.out.print("Kaç karakterli bir kelime olsun: ");
			int karakterSayisi = Integer.parseInt(scr.nextLine());
			Kelime kel5 = new Kelime(karakterSayisi,harfler.toCharArray());
			System.out.println(kel5.getKelime());
			break;
		case 5:
			Scanner scn = new Scanner(System.in);
			System.out.print("Kaç kelimeli cümle oluþtursun: ");
			int kelimeSayisi = Integer.parseInt(scn.nextLine()); 
			Cumle c = new Cumle(kelimeSayisi);
			System.out.println(c.getCumle());
			break;
		case 6:
			System.exit(0);
			break;
		}

		} catch(OutOfMemoryError err) {
			System.out.println("Sistem bu parametre için yetersizdir.");
		}
		Scanner s = new Scanner(System.in);
	    System.out.println("Tekrar çalýþtýrmak için Enter tuþuna basýn.....");
	    s.nextLine();   
	}
}
