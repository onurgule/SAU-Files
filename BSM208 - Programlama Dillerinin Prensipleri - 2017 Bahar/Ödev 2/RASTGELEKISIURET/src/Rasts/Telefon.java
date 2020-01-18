package Rasts;


import Rasts.IMEINo;
import java.util.Random;

/*
 *
 * @author Onur Osman Güle - onur.gule@ogr.sakarya.edu.tr
 * @since 26.03.2018
 * 
 */
public class Telefon extends IMEINo{
   private String tel;
   //private IMEINo imei;
   public Telefon(){
       //rastgeleTelUret();
   }
   public String getTel() {
        return tel;
      }
    public void setTel( String tel ) {
      this.tel = tel;
    }
   /* public IMEINo getIMEI() {
        return imei;
      }
    public void setIMEI( String imeino ) {
      this.imei.setIMEINo(imeino);
    }
    public void setFull(String tel, IMEINo imei){
        this.tel = tel;
        this.imei = imei;
    }*/
    public void rastgeleTelUret(){
        Random r = new Random();
        String newTel = "05"; // 05456454845
        int rakam = 9;
        do{
            rakam = r.nextInt(9);
        }while(!(rakam == 4 || rakam == 5 || rakam == 3 || rakam == 0));
        newTel += rakam+"";
        for (int i = 0; i < 8; i++) {
        newTel += r.nextInt(9) + "";
        }
        setTel(newTel);
    }
    
}
