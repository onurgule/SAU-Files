package Rasts;

/*
 *
 * @author Onur Osman Güle - onur.gule@ogr.sakarya.edu.tr
 * @since 26.03.2018
 * 
 */
public class Kisi extends KimlikNo{
    //private KimlikNo tcNo;
    private String isim; //ad ve soyadı birlikte tutsun.
    private int yas;
    private Telefon tel;
    public Kisi(){
        tel = new Telefon();
    }
   /* public String getTcNo() {
        return tcNo.getTcNo();
      }
    public void setTcNo( String tcNo ) {
      this.tcNo.setTcNo(tcNo);
    }*/
    public String getIsim() {
        return isim;
      }
    public void setIsim( String isim ) {
      this.isim = isim;
    }
    public int getYas() {
        return yas;
      }
    public void setYas( int yas ) {
      this.yas = yas;
    }
    public void randomYas(){
        int r = (int) (Math.random() * (100 - 1)) + 1;
        this.yas = r;
    }
     public Telefon getTelefon() {
        return tel;
      }
     
     /*public void setTelefon(String telno, IMEINo imei){
         this.tel.setFull(telno,imei);
     }*/
}
