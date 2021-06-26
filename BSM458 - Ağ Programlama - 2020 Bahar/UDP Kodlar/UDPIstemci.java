/**
 *  UDP istemci
 *  Klavyeden girilen mesaj UDP Sunucuya gönderiliyor. Sunucu ise bu mesajı büyük harflere dönüştürüp geriye
 *  döndürüyor. İstemci sunucudan gelen mesajı ekrana yazdırıyor.
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.util.logging.FileHandler;
import java.util.logging.Level;
import java.util.logging.Logger;


public class UDPIstemci
{

	/**
	 * @param args
	 */
	private final static String hOST = "localhost";
	private final static int pORT = 8089;
	private final static Logger audit = Logger.getLogger("requests");
	private final static Logger errors = Logger.getLogger("errors");
	


	public static void main(String[] args) 
	{
		
		DatagramSocket socketClient=null;
	
		try
		{	//Log dosyası belirleniyor...
			
			FileHandler handler = new FileHandler("client.log", 100000, 10000);
			Logger.getLogger("").addHandler(handler);
			
			// Soket oluşturuluyr
			//socketClient = new DatagramSocket();
		
			socketClient= new DatagramSocket();

			//System.out.println("cevab�n� ald�mj:"+socketClient.getSoTimeout());
			
			// veri gönderildikten sonra yanıtın gelmesini bekleme süresi ayarlanıyor. UDP, TCP gibi 
			//bağlantı yönelimli olmadığı için bu kadar süre sonra yanıt gelmez ise verinin gitmediği düşünülebilir...
			
			socketClient.setSoTimeout(10000);
			
			 
			
			// hOST IP adresi bulunuyor
			InetAddress IPAddress = InetAddress.getByName(hOST);
			
			// klavyeden girdi: stdIn
			BufferedReader stdIn = new BufferedReader(new InputStreamReader(System.in));
			String userInput=null;
			
			// Giriş ve çıkışlar için oluşturulacak DatagramPacket içerisinde kullanılmak üzere tampon bellek oluşturuluyor. 
					// TCP deki stream yerine DatagramPacket kullanılıyor.
					
			byte[] in = new byte[1024]; 
			byte[] out  = new byte[1024];
			
			while (true) {
				try {
					
					userInput = new String(stdIn.readLine()); //Klavyeden girilen satiri al
					
					if (userInput.equals("cikis")) // Klavyeden "cikis" ifadesi girildiğinde bağlantı sonlandırılacak
						break;
					
					
					out=userInput.getBytes(); // kullanıcının girdiği string byte dizisine dönüştürülüyor.
					
					// Sunucuya veri göndermek üzere DatagramPacket oluşturuluyor, içerisine kullanıcının klavyeden girdiği 
					// mesaj yazılıyor.
					DatagramPacket gonderilecekPaket = new DatagramPacket(out, out.length, IPAddress, pORT);
					
					// DatagramPacket gönderiliyor
					socketClient.send(gonderilecekPaket);
					
					
					audit.info("Adres:"+IPAddress);			

					
					DatagramPacket gelenPaket = new DatagramPacket(in, in.length);

					socketClient.receive(gelenPaket);

					String inputLine = new String(gelenPaket.getData());
					InetAddress IPAddressServer = gelenPaket.getAddress(); 

					int port = gelenPaket.getPort(); 

					System.out.println ("Gönderen: " + IPAddressServer + ":" + port);
					System.out.println ("Mesaj: " + inputLine);

					
				} catch (IOException | RuntimeException ex) {
					errors.log(Level.SEVERE, ex.getMessage(), ex);
				}
			}
		} catch (IOException ex) 
		{
			errors.log(Level.SEVERE, ex.getMessage(), ex);
		}finally
		{
			socketClient.close();
		}
	} 
}

