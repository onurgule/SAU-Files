/**
*
* @author Onur Osman Güle onur.gule@ogr.sakarya.edu.tr
* @since 03.04.2021
* <p>
* Mockito Testleri
* </p>
*/
package pkt;


import static org.junit.jupiter.api.Assertions.*;
import static org.mockito.Mockito.*;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
class MockTests {

	@Test
	@DisplayName("Mock Cümle Çaðýrma Testi")
	void testCumleMock() {
		Cumle c = mock(Cumle.class);
		when(c.getCumle()).thenReturn("dsdfg sdsfsag sdd sdsfagg");
		assertEquals(c.getCumle(), "dsdfg sdsfsag sdd sdsfagg");
	}
	@Test
	@DisplayName("Mock Kelime Çaðýrma Testi")
	void testKelimeMock() {
		Kelime k = mock(Kelime.class);
		when(k.getKelime()).thenReturn("dsdfg");
		assertEquals(k.getKelime(), "dsdfg");
	}
	@Test
	@DisplayName("Mock Karakter Çaðýrma Testi")
	void testKarakterMock() {
		Karakter k = mock(Karakter.class);
		when(k.getKarakter()).thenReturn('d');
		assertEquals(k.getKarakter(), 'd');
	}
	@Test
	@DisplayName("Mock Spy Kelime Oluþturma Testi")
	void testKelimeIntMock() {
		Kelime k = spy(new Kelime(3));
		k.kelime = new java.util.ArrayList<Karakter>();
		Karakter k1 = mock(Karakter.class);
		when(k1.getKarakter()).thenReturn('m');
		Karakter k2 = mock(Karakter.class);
		when(k2.getKarakter()).thenReturn('A');
		Karakter k3 = mock(Karakter.class);
		when(k3.getKarakter()).thenReturn('d');
		k.kelime.add(k1);
		k.kelime.add(k2);
		k.kelime.add(k3);
		assertEquals(k.getKelime(), "mAd");
	}
	@Test
	@DisplayName("Mock Spy Cümle Oluþturma Testi")
	void testCumleIntMock() {
		Cumle c = spy(new Cumle(2));
		c.cumle = new java.util.ArrayList<Kelime>();
		Kelime k1 = mock(Kelime.class);
		when(k1.getKelime()).thenReturn("aGdWcc");
		Kelime k2 = mock(Kelime.class);
		when(k2.getKelime()).thenReturn("JhhKlmw");
		c.cumle.add(k1);
		c.cumle.add(k2);
		assertEquals(c.getCumle(), "aGdWcc JhhKlmw");
	}

}
