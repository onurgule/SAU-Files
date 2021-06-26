/**
*
* @author Onur Osman Güle onur.gule@ogr.sakarya.edu.tr
* @since 03.04.2021
* <p>
* Cümle Sýnýf Testleri
* </p>
*/
package pkt;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

class CumleTest {

	@Test
	@DisplayName("Rastgele cümle kelime sayýsý testi")
	void testCumle() {
		Cumle c = new Cumle();
		int wordCount = c.getCumle().split(" ").length;
		assertTrue(wordCount<=12 && wordCount >= 2,"Kelime sayýsý doðru deðildi.");
	}

	@Test
	@DisplayName("Verilen sayýdaki cümledeki kelime sayýsý testi")
	void testCumleInt() {
		Cumle c = new Cumle(5);
		int wordCount = c.getCumle().split(" ").length;
		assertEquals(wordCount,5);
	}	
	@Test
	@DisplayName("Verilen sayýnýn negatif olma durum testi")
	void testCumleNegativeInt() {
		assertThrows(IllegalArgumentException.class,()->{
			Cumle c = new Cumle(-5);
		});
	}

	@Test
	@DisplayName("Cümle döndürme testi")
	void testGetCumle() {
		Cumle c = new Cumle(2);
		assertTrue(c.getCumle() instanceof String,"String bir deðer gelmedi.");
	}


}
