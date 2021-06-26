/**
*
* @author Onur Osman G�le onur.gule@ogr.sakarya.edu.tr
* @since 03.04.2021
* <p>
* Kelime S�n�f Testleri
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
	@DisplayName("Verilen Say�da Karakterli Kelime Olu�turma Testi")
	void testKelimeInt() {
		int sayi = 7;
		Kelime k = new Kelime(sayi);
		assertTrue(k.getKelime().length() == sayi, "Harf say�s� do�ru de�ildi.");
	}

	@Test
	@DisplayName("Verilen say�n�n int olmama durum testi")
	void testKelimeNonInt() {
		assertThrows(IllegalArgumentException.class, () -> {
			Kelime k = new Kelime('a');
		});
	}

	@Test
	@DisplayName("Verilen say�n�n negatif olma durum testi")
	void testKelimeNegativeInt() {
		assertThrows(IllegalArgumentException.class, () -> {
			Kelime k = new Kelime(-5);
		});
	}

	@Test
	@DisplayName("Verilen iki karakter aras�nda verilen say�n�n negatif olma durum testi")
	void testKelimeNotIntCharChar() {
		int sayi = -3;
		assertThrows(IllegalArgumentException.class, () -> {
			Kelime k = new Kelime(sayi, 'c', 'g');
		});
	}

	@Test
	@DisplayName("Verilen iki karakterden birinin bo� olma durum testi")
	void testKelimeIntEmptyCharChar() {
		int sayi = 3;
		assertThrows(IllegalArgumentException.class, () -> {
			Kelime k = new Kelime(sayi, ' ', 'g');
		});
	}

	@Test
	@DisplayName("Verilen char dizisinin yan�nda verilen say�n�n negatif olma durum testi")
	void testKelimeNotIntCharArray() {
		int sayi = -5;
		char harfler[] = { 'o', 'n', 'u', 'r', 'g' };
		assertThrows(IllegalArgumentException.class, () -> {
			Kelime k = new Kelime(sayi, harfler);
		});
	}

	@Test
	@DisplayName("Verilen char dizisinin bo� olma durum testi")
	void testKelimeIntEmptyCharArray() {
		int sayi = 5;
		char harfler[] = {};
		assertThrows(IllegalArgumentException.class, () -> {
			Kelime k = new Kelime(sayi, harfler);
		});
	}

	@Test
	@DisplayName("Verilen iki karakter aras�nda �retim testi")
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
	@DisplayName("Verilen dizi i�erisinde �retim testi")
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
	@DisplayName("Kelime d�nd�rme testi")
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
				fail("MAX_INT i�in yeterli bellek mevcut de�il.");
			}
		}, "Sistem MAX_INT'i kald�ram�yor.");
		// 10 saniyeyi a�arsa ya da OutOfMemoryError verirse sistem maksimum parametreler i�in yeterli olmad���ndan test fail verecektir.
		// M. Fatih Adak hocamla bu konu �zerinde maille�tik.

	}

}
