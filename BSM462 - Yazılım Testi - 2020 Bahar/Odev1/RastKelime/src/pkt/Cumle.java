/**
*
* @author Onur Osman Güle onur.gule@ogr.sakarya.edu.tr
* @since 03.04.2021
* <p>
* Cümle Oluþturma Sýnýfý
* </p>
*/

package pkt;
import pkt.Kelime;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;
public class Cumle {
	//private Kelime[] cumle;
	List<Kelime> cumle = new ArrayList<Kelime>();
	public Cumle() {
		Random rnd = new Random();
		int kelimeSayisi = rnd.nextInt(11)+2;
		for (int i = 0; i < kelimeSayisi; i++) {
			int harfSayisi = rnd.nextInt(13)+3;
			cumle.add(new Kelime(harfSayisi));
		}
		//2 ile 10 arasýnda random oluþturup kelime sayýsý bul, 
		//tekrardan 3 ile 12 arasýnda random oluþturup kelimenin karakter sayýsýný bul. 
	}
	public Cumle(Integer size) {
		if(size < 1) {
			throw new IllegalArgumentException("Girilen sayý 0'dan büyük olmalýdýr.");
		}
		try {
		Random rnd = new Random();
			for (int i = 0; i < size; i++) {
				int harfSayisi = rnd.nextInt(13)+3;
				cumle.add(new Kelime(harfSayisi));
			}
		} catch(OutOfMemoryError err) {
			System.out.println("Sistem bu parametre için yetersizdir.");
		}
		// 3 ile 12 arasýnda random oluþturup kelimenin karakter sayýsýný bul. 
	}
	public String getCumle() {
		String cumle = "";
		for (Kelime kelime : this.cumle) {
			cumle+=kelime.getKelime() + " ";
		}
		cumle = cumle.trim();
		return cumle;
	}
	
}
