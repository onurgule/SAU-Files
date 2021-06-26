/**
*
* @author Onur Osman G�le onur.gule@ogr.sakarya.edu.tr
* @since 03.04.2021
* <p>
* Faker Testleri
* </p>
*/
package pkt;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import com.github.javafaker.Faker;

class FakerTests {

	@Test
	@DisplayName("Faker rastgele say� ile c�mle olu�turma testi")
	void fakerRandomDigitCumleTest() {
		Faker f = new Faker();
		int kelimeSayisi = f.number().randomDigitNotZero();
		Cumle c = new Cumle(kelimeSayisi);
		assertEquals(c.getCumle().split(" ").length, kelimeSayisi);
	}
	@Test
	@DisplayName("Faker rastgele say� ile kelime olu�turma testi")
	void fakerRandomDigitKelimeTest() {
		Faker f = new Faker();
		int karakterSayisi = f.number().randomDigitNotZero();
		Kelime c = new Kelime(karakterSayisi);
		assertEquals(c.getKelime().length(), karakterSayisi);
	}
	@Test
	@DisplayName("Faker rastgele ismin char dizisi ile kelime olu�turma testi")
	void fakerNameKelimeCharsTest() {
		Faker f = new Faker();
		char isimChars[] = f.name().firstName().toCharArray();
		Kelime k = new Kelime(15,isimChars);
		int correctChar = 0;
		for (char c : k.getKelime().toCharArray()) {
			for (char h : isimChars) {
				if(h==c) {correctChar++; break;}
			}
		}
		assertEquals(k.getKelime().length(),correctChar);
	}
	@Test
	@DisplayName("Faker rastgele ismin char dizisi ile karakter olu�turma testi")
	void fakerNameKarakterCharsTest()  {
		Faker f = new Faker();
		char isimChars[] = f.name().firstName().toCharArray();
		Karakter k = new Karakter(isimChars);
		boolean correctHarf = false;
		for (char h : isimChars) {
			if(h==k.getKarakter()) {correctHarf = true; break;}
		}
		assertTrue(correctHarf);
	}

	@Test
	@DisplayName("Faker Rastgele 3 haneli say� ile kelime olu�turma testi")
	void fakerNameCharsTest() {
		Faker f = new Faker();
		int number = Integer.parseInt(f.numerify("###"));
		Kelime k = new Kelime(number);
		assertEquals(k.getKelime().length(),number);
	}

}
