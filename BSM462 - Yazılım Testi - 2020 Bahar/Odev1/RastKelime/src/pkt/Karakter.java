/**
*
* @author Onur Osman Güle onur.gule@ogr.sakarya.edu.tr
* @since 03.04.2021
* <p>
* Karakter Oluþturma Sýnýfý
* </p>
*/
package pkt;
import java.security.InvalidAlgorithmParameterException;

import pkt.Harf;
public class Karakter {
	private char karakter;
	
	public Karakter(Character chr) {
		this.karakter = chr;
	}
	public Karakter() {
		//random 1 tane oluþtur.
		this.karakter = Harf.getHarf();
	}
	public Karakter(char firstCh, char lastCh) {
		// sonu ilk yazma ihtimalini kontrol et.
		int firstInt = ((int)firstCh<=(int)lastCh)?(int)firstCh:(int)lastCh;
		int lastInt = ((int)lastCh>(int)firstCh)?(int)lastCh:(int)firstCh;
			this.karakter = Harf.getHarf(firstInt, lastInt);
	}
	public Karakter(char... chs) {
		if(chs.length < 1) throw new IllegalArgumentException("En az 1 karakter girilmelidir.");
			this.karakter = Harf.getHarf(chs);
	}
	public char getKarakter() {
		return karakter;
	}
}
