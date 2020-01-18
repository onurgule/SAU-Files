package g171210021_4;


/**
 *
 * @author Onur Osman Güle - G171210021 - onur.gule@ogr.sakarya.edu.tr
 */
public class CarpimHesabi implements Runnable {
    static String sayi1;//bütün sayı1
    static String sayi2;//sayi2'den bir rakam.
    int sayi2RakamYeri = 0;
    public CarpimHesabi(String s1, String s2, int s2ry) {
        sayi1 = s1; //1231314 gibi sayı
        sayi2 = s2; //1231415 gibi sayı
        sayi2RakamYeri = s2ry; // 2. rakamı çarpalım.
    }
    @Override
    public void run() {
        String gecici = "0";
        String onda = "";
            for (int i = 0; i < sayi2RakamYeri ; i++) {
            onda+="0";
            }
            gecici = Hesaplamalar.Toplam(gecici, Hesaplamalar.Carpim(sayi1, Hesaplamalar.tersString(sayi2).charAt(sayi2RakamYeri)+onda));
            Hesaplamalar.sonuclarP.add(gecici);
    }           
}
