/**
*
* @author Onur Osman G�le onur.gule@ogr.sakarya.edu.tr
* @since 03.04.2021
* <p>
* Men� S�n�f Testleri
* </p>
*/
package pkt;

import static org.junit.jupiter.api.Assertions.*;

import java.security.InvalidParameterException;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

class MenuTest {

	@Test
	@DisplayName("Men�de gerekenden a�a��da say� girilme testi")
	void testSelectOptionBelow() {
		assertThrows(InvalidParameterException.class,()->{
			Menu.selectOption(0);
		});
	}
	@Test
	@DisplayName("Men�de gerekenden yukar�da say� girilme testi")
	void testSelectOptionAbove() {
		assertThrows(InvalidParameterException.class,()->{
			Menu.selectOption(8);
		});
	}
	@Test
	@DisplayName("Men�de harf girilme testi")
	void testSelectOptionHarf() {
		assertThrows(InvalidParameterException.class,()->{
			Menu.selectOption('a');
		});
	}

}
