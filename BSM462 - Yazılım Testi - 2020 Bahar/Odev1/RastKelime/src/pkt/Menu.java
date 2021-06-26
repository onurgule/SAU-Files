/**
*
* @author Onur Osman G�le onur.gule@ogr.sakarya.edu.tr
* @since 03.04.2021
* <p>
* Men� �a��rma ve ��lem S�n�f�
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
		System.out.println("1- Harf Olu�tur");
		System.out.println("2- Birka� Harf Olu�tur");
		System.out.println("3- Belli Harfler Aras�nda Olu�tur");
		System.out.println("4- Birka� Harfi Belli Harflerden Olu�tur");
		System.out.println("5- Rastgele C�mle Olu�tur");
		System.out.println("6- ��k��");
		System.out.print("Se�iminiz: ");
		try {
			try { 
				secim = Integer.parseInt(s.nextLine()); 
				Menu.selectOption(secim);
				}
			catch(InputMismatchException | java.lang.NumberFormatException e) { throw new InvalidParameterException("Sadece say� giriniz."); }
		}
		catch(InvalidParameterException e) { System.out.println(e.getMessage()); continue;	}
		catch(Exception e) { System.out.println("s"+e);}
		
		}
	}
	public static void selectOption(int secim) {
		if(secim > 6 || secim < 1) {
			throw new InvalidParameterException("1-6 aras� giri� yap�n�z.");
		}
		try {
		switch(secim) {
		case 1:
			Karakter k = new Karakter();
			System.out.println(k.getKarakter());
			break;
		case 2:
			Scanner s = new Scanner(System.in);
			System.out.print("Ka� harfli olu�tursun: ");
			int sayi = Integer.parseInt(s.nextLine()); 
			Kelime kel = new Kelime(sayi);
			System.out.println(kel.getKelime());
			break;
		case 3:
			Scanner sc = new Scanner(System.in);
			System.out.print("�lk karakteri girin: ");
			String gel = sc.nextLine();
			char ilkHarf = gel.length()!=0?gel.charAt(0):' '; 	
			System.out.print("�kinci karakteri girin: ");
			gel = sc.nextLine();
			char ikinciHarf = gel.length()!=0?gel.charAt(0):' '; 			
			System.out.print("Ka� karakterli bir kelime olsun: ");
			int karSayisi = Integer.parseInt(sc.nextLine());
			Kelime kel3 = new Kelime(karSayisi,ilkHarf,ikinciHarf);
			System.out.println(kel3.getKelime());
			break;
		case 4:
			Scanner scr = new Scanner(System.in);
			System.out.print("��erecek harfleri birle�ik olarak girin (�rn: asdfg): ");
			String harfler = scr.nextLine(); 			
			System.out.print("Ka� karakterli bir kelime olsun: ");
			int karakterSayisi = Integer.parseInt(scr.nextLine());
			Kelime kel5 = new Kelime(karakterSayisi,harfler.toCharArray());
			System.out.println(kel5.getKelime());
			break;
		case 5:
			Scanner scn = new Scanner(System.in);
			System.out.print("Ka� kelimeli c�mle olu�tursun: ");
			int kelimeSayisi = Integer.parseInt(scn.nextLine()); 
			Cumle c = new Cumle(kelimeSayisi);
			System.out.println(c.getCumle());
			break;
		case 6:
			System.exit(0);
			break;
		}

		} catch(OutOfMemoryError err) {
			System.out.println("Sistem bu parametre i�in yetersizdir.");
		}
		Scanner s = new Scanner(System.in);
	    System.out.println("Tekrar �al��t�rmak i�in Enter tu�una bas�n.....");
	    s.nextLine();   
	}
}
