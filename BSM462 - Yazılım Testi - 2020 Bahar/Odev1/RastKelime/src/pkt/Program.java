/**
*
* @author Onur Osman G�le onur.gule@ogr.sakarya.edu.tr
* @since 03.04.2021
* <p>
* Deneme Program� S�n�f�
* </p>
*/
package pkt;
//import pkt.Menu;
import pkt.Cumle;
public class Program {

	public static void main(String[] args) throws Exception {
		//program� ba�lats�n. 1- 2- 3- vs.
		try {
			Menu.getMenu();
		}
		catch(Exception e) {
			System.out.println("Hata:"+e);
		}
	}

}
