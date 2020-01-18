/*
 *
 * @author Onur Osman Güle - onur.gule@ogr.sakarya.edu.tr
 * @since 26.03.2018
 * 
 */
package rastgelekisiler;
import Rasts.*;
/**
 *
 * @author Onur Osman Güle
 */
public class RastgeleKisiler {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try{
            Menu menu = new Menu();
        }
        catch(Exception a) {
            System.out.println("Bir hata oluştu!" + a.getMessage() + a.getCause() + a.toString());
        }
        
        
    }
    
}
