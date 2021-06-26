/**
*
* @author Onur Osman Güle onur.gule@ogr.sakarya.edu.tr
* @since 03.04.2021
* <p>
* Harf Oluþturma Sýnýfý
* </p>
*/
package pkt;

import java.security.InvalidAlgorithmParameterException;
import java.util.Random;
public class Harf {
	//private char harf = 'a';
	public static char getHarf() {
		Random rnd = new Random();
		int rast=rnd.nextInt(26)+97; 
		int upper = rnd.nextInt(2);
		if(upper == 1) rast-=32;
		rnd = null;
		return (char)rast;
	}
	public static char getHarf(int first, int last) {
		//burada harf olmayaný alma.
		int buyukHarf = 0;
		if(first < 97) {first+=32; buyukHarf+=50;}
		if(last < 97) {last += 32; buyukHarf+=50;}
		if(first<97 || last > 122) throw new IllegalArgumentException("Yalnýzca harf giriniz.");
		Random rnd = new Random();
		int rast=rnd.nextInt(last-first+1)+first; 
		if(rnd.nextInt(100) < buyukHarf) rast-=32;
		rnd = null;
		return (char)rast;
	}
	public static char getHarf(char... chs) {
		for (char c : chs) {
			if(!Character.isLetter(c)) throw new IllegalArgumentException("Yalnýzca harf giriniz.");
		}
		Random rnd = new Random();
		int rast = rnd.nextInt(chs.length);
		rnd = null;
		return chs[rast];
	}
	/*public char getHarf() {
		return this.harf;
	}*/
}
