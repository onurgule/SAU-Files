
package httpistemcisi;
import java.net.*;
import java.io.*;
import java.util.logging.Level;
import java.util.logging.Logger;

public class HTTPistemcisi 
{

  
    public static void main(String[] args) 
    {
     
        try
        {
        URL url=new URL("https:\\www.sakarya.edu.tr");
        
        
        String hostname=url.getHost();
        int port=80;
        
        Socket socket = new Socket(hostname, port); 
        
 
            OutputStream output = socket.getOutputStream();
            PrintWriter writer = new PrintWriter(output, true);
 
            writer.println("HEAD " + url.getPath() + " HTTP/1.1");
            writer.println("Host: " + hostname);
            writer.println("User-Agent: Simple Http Client");
            writer.println("Accept: text/html");
            writer.println("Accept-Language: en-US");
            writer.println("Connection: close");
            writer.println();
 
            InputStream input = socket.getInputStream();
 
            BufferedReader reader = new BufferedReader(new InputStreamReader(input));
 
            String line;
 
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }
            
        
        } catch(Exception e){System.out.println(e);}
        
       
    }
    
}
