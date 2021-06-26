/**
*
* @author Onur Osman Güle onur.gule@ogr.sakarya.edu.tr
* @since 03.04.2021
* <p>
* Deneme Programý Sýnýfý
* </p>
*/
package pkt;
//import pkt.Menu;
import pkt.Cumle;
public class Program {

	public static void main(String[] args) throws Exception {
		//programý baþlatsýn. 1- 2- 3- vs.
		try {
			Menu.getMenu();
		}
		catch(Exception e) {
			System.out.println("Hata:"+e);
		}
	}

}
