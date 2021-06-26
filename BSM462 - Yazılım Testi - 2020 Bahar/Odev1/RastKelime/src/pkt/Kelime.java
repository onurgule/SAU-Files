/**
*
* @author Onur Osman Güle onur.gule@ogr.sakarya.edu.tr
* @since 03.04.2021
* <p>
* Kelime Oluþturma Sýnýfý
* </p>
*/
package pkt;
import java.security.InvalidAlgorithmParameterException;
import java.security.InvalidParameterException;
import java.util.ArrayList;
import java.util.List;

import pkt.Karakter;
public class Kelime {
//karakter yalnýzca bir karakter oluþturur, birden çok karakteri kelime tutar.
	List<Karakter> kelime = new ArrayList<Karakter>();
	public Kelime(Integer size) {
		//size kadar oluþtur 
		if(size < 1) throw new IllegalArgumentException("Girilen sayý 0'dan büyük olmalýdýr.");
		try {
			for (int i = 0; i < size; i++) {
				kelime.add(new Karakter());
			}
		} catch(OutOfMemoryError err) {
			System.out.println("Sistem bu parametre için yetersizdir.");
		}
	}

	public Kelime(int size, char firstCh, char lastCh) {
		//size kadar oluþtur.
		if(size < 1) throw new IllegalArgumentException("Girilen sayý 0'dan büyük olmalýdýr.");
		if(!Character.isLetter(lastCh) || !Character.isLetter(lastCh)) throw new IllegalArgumentException("Harf Girilmeli.");
		try {
		for (int i = 0; i < size; i++) {
			kelime.add(new Karakter(firstCh,lastCh));
		}
		} catch(OutOfMemoryError err) {
			System.out.println("Sistem bu parametre için yetersizdir.");
		}
	}

	public Kelime(int size, char... chs)  {
		//size kadar oluþtur.
		if(size < 1) throw new IllegalArgumentException("Girilen sayý 0'dan büyük olmalýdýr.");
		if(chs.length < 1) throw new IllegalArgumentException("En az 1 karakter girilmelidir.");
		try {
			for (int i = 0; i < size; i++) {
				kelime.add(new Karakter(chs));
			}
		} catch(OutOfMemoryError err) {
			System.out.println("Sistem bu parametre için yetersizdir.");
		}
	}
	public String getKelime() {
		String kel = "";
		for (Karakter karakter : kelime) {
			kel+=karakter.getKarakter();
		}
		return kel;
	}
}
