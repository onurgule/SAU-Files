/**
*
* @author Onur Osman Güle onur.gule@ogr.sakarya.edu.tr
* @since 03.04.2021
* <p>
* Harf Sýnýf Testleri
* </p>
*/
package pkt;
import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

class HarfTest {

	@Test
	@DisplayName("Tekli Rastgele Harf Testi")
	void getHarfTest() {
		char randomHarf = Harf.getHarf();
		assertTrue(Character.isLetter(randomHarf), "randomHarf bir harf döndürmedi.");
		// harf olup olmadýðý ve char olup olmadýðý kontrol edildi.
	}
	@Test
	@DisplayName("Aradaki Rastgele Harf Testi")
	void getHarfBetweenTest() {
		char randomHarf = Harf.getHarf(100,105);
		assertTrue((int)randomHarf <= 105 && (int)randomHarf >= 100, "randomHarf verilen iki ascii arasýnda bir harf döndürmedi.");
		// harf olup olmadýðý ve char olup olmadýðý kontrol edildi.
	}
	@Test
	@DisplayName("Listedeki Rastgele Harf Testi")
	void getHarfListTest()  {
		char[] harfArray = {'g','j','o','r'};
		char randomHarf = Harf.getHarf(harfArray);
		boolean isInside = false;
		for (char c : harfArray) {
			if(c == randomHarf) {
				isInside = true;
				break;
			}
		}
		assertTrue(isInside, "randomHarf verilen array içerisindeki bir harfi döndürmedi.");
		// harf olup olmadýðý ve char olup olmadýðý kontrol edildi.
	}
	@Test
	@DisplayName("Listedeki Rastgele Harf Olmama Testi")
	void getHarfListNonLetterTest() {
		assertThrows(IllegalArgumentException.class,()->{
			char[] harfArray = {'g','!','o','r'};
			char randomHarf = Harf.getHarf(harfArray);
		});
	}
	@Test
	@DisplayName("Aradaki Rastgele Harf Olmama Testi")
	void getHarfBetweenNonLetterTest() {
		assertThrows(IllegalArgumentException.class,()->{
			char randomHarf = Harf.getHarf(15,25);
		});
	}
	

}
