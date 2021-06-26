/**
 *  UDP sunucu
 *  İstemciden gelen mesajı ekrana yazdırdıktan sonra büyük harflere dönüştürüp geriye
 *  döndürüyor. 
 */



import java.net.*;
import java.util.logging.*;
import java.io.*;

public class UDPSunucu {

	private final static int pORT = 8089;
	private final static Logger audit = Logger.getLogger("requests");
	private final static Logger errors = Logger.getLogger("errors");

	public static void main(String[] args) 
	{
		DatagramSocket socketServer=null;
		try
		{
			//Log dosyası belirleniyor...
			
			FileHandler handler = new FileHandler("server.log");
			Logger.getLogger("").addHandler(handler);
			
			socketServer = new DatagramSocket(pORT);
			
			
			String outputLine;

			while (true) {
				try {
					System.out.println("orhn");
					// Giriş ve çıkışlar için oluşturulacak DatagramPacket içerisinde kullanılmak üzere tampon bellek oluşturuluyor. 
					// TCP deki stream yerine DatagramPacket kullanılıyor.
					
					byte[] in = new byte[1024]; 
					byte[] out;//  = new byte[1024];
					
					DatagramPacket gelenPaket = new DatagramPacket(in, in.length);

					socketServer.receive(gelenPaket);

					String inputLine = new String(gelenPaket.getData());
					InetAddress IPAddress = gelenPaket.getAddress(); 

					int port = gelenPaket.getPort(); 

					System.out.println ("Mesa��n� ald�m Kimden: " + IPAddress + ":" + port);
					System.out.println ("Mesaj: " + inputLine);

					outputLine = inputLine.toUpperCase(); 
					out= outputLine.getBytes();
					
					DatagramPacket gonderilecekPaket = new DatagramPacket(out, out.length, gelenPaket.getAddress(), gelenPaket.getPort());
					socketServer.send(gonderilecekPaket);
					audit.info("Adres:"+IPAddress);			

					if (outputLine.equals("cikis")) // 
						break;



				} catch (IOException | RuntimeException ex) {
					errors.log(Level.SEVERE, ex.getMessage(), ex);
				}
			}
		} catch (IOException ex) 
		{
			errors.log(Level.SEVERE, ex.getMessage(), ex);
		}finally
		{
			socketServer.close();
		}
	} 
}
