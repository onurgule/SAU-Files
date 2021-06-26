/**
*
* @author Onur Osman Güle onur.gule@ogr.sakarya.edu.tr
* @since 03.04.2021
* <p>
* Menü Sýnýf Testleri
* </p>
*/
package pkt;

import static org.junit.jupiter.api.Assertions.*;

import java.security.InvalidParameterException;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

class MenuTest {

	@Test
	@DisplayName("Menüde gerekenden aþaðýda sayý girilme testi")
	void testSelectOptionBelow() {
		assertThrows(InvalidParameterException.class,()->{
			Menu.selectOption(0);
		});
	}
	@Test
	@DisplayName("Menüde gerekenden yukarýda sayý girilme testi")
	void testSelectOptionAbove() {
		assertThrows(InvalidParameterException.class,()->{
			Menu.selectOption(8);
		});
	}
	@Test
	@DisplayName("Menüde harf girilme testi")
	void testSelectOptionHarf() {
		assertThrows(InvalidParameterException.class,()->{
			Menu.selectOption('a');
		});
	}

}
