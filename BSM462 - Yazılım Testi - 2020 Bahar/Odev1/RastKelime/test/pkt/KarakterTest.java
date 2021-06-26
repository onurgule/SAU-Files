/**
*
* @author Onur Osman Güle onur.gule@ogr.sakarya.edu.tr
* @since 03.04.2021
* <p>
* Karakter Sýnýf Testleri
* </p>
*/
package pkt;

import static org.junit.jupiter.api.Assertions.*;

import java.security.InvalidParameterException;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

class KarakterTest {

	@Test
	@DisplayName("Tekli Verilen Karakter Testi")
	void testKarakterChar() {
		Karakter k = new Karakter('c');
		assertEquals(k.getKarakter(), 'c');
	}

	@Test
	@DisplayName("Tekli Rastgele Karakter Testi")
	void testKarakter() {
		Karakter k = new Karakter();
		assertTrue(Character.isLetter(k.getKarakter()), "Rastgele oluþturulan karakter bir harf deðildi.");
	}

	@Test
	@DisplayName("Verilenlerin Arasýnda Karakter Testi")
	void testKarakterCharChar() {
		Karakter k = new Karakter('f','k');
		assertTrue((int)(k.getKarakter()) <= 107 && (int)(k.getKarakter()) >= 102, "Karakter verilen iki char arasýnda bir harf döndürmedi.");
	}

	@Test
	@DisplayName("Dizi Karakter Testi")
	void testKarakterCharArray() {
		char[] harfArray = {'o','n','u','r'};
		Karakter k = new Karakter(harfArray);
		boolean isInside = false;
		for (char c : harfArray) {
			if(c == k.getKarakter()) {
				isInside = true;
				break;
			}
		}
		assertTrue(isInside, "Karakter verilen array içerisindeki bir harfi döndürmedi.");
	}
	@DisplayName("Boþ Dizi Karakter Testi")
	void testKarakterEmptyCharArray() {
		char[] harfArray = {};
		assertThrows(InvalidParameterException.class,()->{
			Karakter k = new Karakter(harfArray);
		});
	}

	@Test
	@DisplayName("Karakteri Çaðýrma Testi")
	void testGetKarakter() {
		Karakter k = new Karakter('h');
		assertEquals(k.getKarakter(), 'h');
	}

}
