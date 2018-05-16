package g171210021_4;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

/**
 *
 * @author Onur Osman Güle - G171210021 - onur.gule@ogr.sakarya.edu.tr
 */
public final class Dosyalama {
    final public static String dosyaAdi = "Sonuc.txt";
    public static void DosyayaKaydet(String sonuc) throws IOException{
        File file = new File(dosyaAdi);
        if (!file.exists()) {
            file.createNewFile();
        }
        FileWriter fileWriter = new FileWriter(file,true);
        BufferedWriter bWriter = new BufferedWriter(fileWriter);
        bWriter.write(sonuc);
        bWriter.newLine();
        bWriter.write("#####");
        bWriter.newLine();
        bWriter.close();
    }
}
