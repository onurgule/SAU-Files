/**
*
* @author Onur Osman G�le onur.gule@ogr.sakarya.edu.tr
* @since 03.04.2021
* <p>
* C�mle S�n�f Testleri
* </p>
*/
package pkt;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

class CumleTest {

	@Test
	@DisplayName("Rastgele c�mle kelime say�s� testi")
	void testCumle() {
		Cumle c = new Cumle();
		int wordCount = c.getCumle().split(" ").length;
		assertTrue(wordCount<=12 && wordCount >= 2,"Kelime say�s� do�ru de�ildi.");
	}

	@Test
	@DisplayName("Verilen say�daki c�mledeki kelime say�s� testi")
	void testCumleInt() {
		Cumle c = new Cumle(5);
		int wordCount = c.getCumle().split(" ").length;
		assertEquals(wordCount,5);
	}	
	@Test
	@DisplayName("Verilen say�n�n negatif olma durum testi")
	void testCumleNegativeInt() {
		assertThrows(IllegalArgumentException.class,()->{
			Cumle c = new Cumle(-5);
		});
	}

	@Test
	@DisplayName("C�mle d�nd�rme testi")
	void testGetCumle() {
		Cumle c = new Cumle(2);
		assertTrue(c.getCumle() instanceof String,"String bir de�er gelmedi.");
	}


}
