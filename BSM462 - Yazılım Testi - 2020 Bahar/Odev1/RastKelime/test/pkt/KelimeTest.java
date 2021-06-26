/**
*
* @author Onur Osman Güle onur.gule@ogr.sakarya.edu.tr
* @since 03.04.2021
* <p>
* Kelime Sýnýf Testleri
* </p>
*/
package pkt;

import static org.junit.jupiter.api.Assertions.*;


import java.time.Duration;


import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Order;
import org.junit.jupiter.api.Test;


class KelimeTest {

	@Test
	@DisplayName("Verilen Sayýda Karakterli Kelime Oluþturma Testi")
	void testKelimeInt() {
		int sayi = 7;
		Kelime k = new Kelime(sayi);
		assertTrue(k.getKelime().length() == sayi, "Harf sayýsý doðru deðildi.");
	}

	@Test
	@DisplayName("Verilen sayýnýn int olmama durum testi")
	void testKelimeNonInt() {
		assertThrows(IllegalArgumentException.class, () -> {
			Kelime k = new Kelime('a');
		});
	}

	@Test
	@DisplayName("Verilen sayýnýn negatif olma durum testi")
	void testKelimeNegativeInt() {
		assertThrows(IllegalArgumentException.class, () -> {
			Kelime k = new Kelime(-5);
		});
	}

	@Test
	@DisplayName("Verilen iki karakter arasýnda verilen sayýnýn negatif olma durum testi")
	void testKelimeNotIntCharChar() {
		int sayi = -3;
		assertThrows(IllegalArgumentException.class, () -> {
			Kelime k = new Kelime(sayi, 'c', 'g');
		});
	}

	@Test
	@DisplayName("Verilen iki karakterden birinin boþ olma durum testi")
	void testKelimeIntEmptyCharChar() {
		int sayi = 3;
		assertThrows(IllegalArgumentException.class, () -> {
			Kelime k = new Kelime(sayi, ' ', 'g');
		});
	}

	@Test
	@DisplayName("Verilen char dizisinin yanýnda verilen sayýnýn negatif olma durum testi")
	void testKelimeNotIntCharArray() {
		int sayi = -5;
		char harfler[] = { 'o', 'n', 'u', 'r', 'g' };
		assertThrows(IllegalArgumentException.class, () -> {
			Kelime k = new Kelime(sayi, harfler);
		});
	}

	@Test
	@DisplayName("Verilen char dizisinin boþ olma durum testi")
	void testKelimeIntEmptyCharArray() {
		int sayi = 5;
		char harfler[] = {};
		assertThrows(IllegalArgumentException.class, () -> {
			Kelime k = new Kelime(sayi, harfler);
		});
	}

	@Test
	@DisplayName("Verilen iki karakter arasýnda üretim testi")
	void testKelimeIntCharChar() {
		int sayi = 3;
		Kelime k = new Kelime(sayi, 'c', 'g');
		char harfler[] = { 'c', 'd', 'e', 'f', 'g' };
		int correct = 0;
		for (char c : k.getKelime().toCharArray()) {
			for (char h : harfler) {
				if (h == c)
					correct++;
			}
		}
		assertEquals(correct, sayi);
	}

	@Test
	@DisplayName("Verilen dizi içerisinde üretim testi")
	void testKelimeIntCharArray() {
		int sayi = 3;
		char harfler[] = { 'o', 'n', 'u', 'r', 'g' };
		Kelime k = new Kelime(sayi, harfler);
		int correct = 0;
		for (char c : k.getKelime().toCharArray()) {
			for (char h : harfler) {
				if (h == c)
					correct++;
			}
		}
		assertEquals(correct, sayi);
	}

	@Test
	@DisplayName("Kelime döndürme testi")
	void testGetKelime() {
		Kelime k = new Kelime(3, 'a', 'a');
		assertEquals(k.getKelime(), "aaa");
	}

	@Order(Integer.MAX_VALUE)
	@Test
	@DisplayName("MAX_INT Sistem Yeterlilik Testi")
	void testKelimeYormaHata() {
		assertTimeoutPreemptively(Duration.ofSeconds(10), () -> {
			try {
			Kelime k = new Kelime(Integer.MAX_VALUE);
			} catch(OutOfMemoryError err) {
				fail("MAX_INT için yeterli bellek mevcut deðil.");
			}
		}, "Sistem MAX_INT'i kaldýramýyor.");
		// 10 saniyeyi aþarsa ya da OutOfMemoryError verirse sistem maksimum parametreler için yeterli olmadýðýndan test fail verecektir.
		// M. Fatih Adak hocamla bu konu üzerinde mailleþtik.

	}

}
