package javaapplication33;
import java.util.concurrent.Semaphore;
public class JavaApplication33 extends Thread {
   static Semaphore sem = new Semaphore(1);
    public void run(){
        try{
        sem.acquire(); // kritik bölge başlangıc izni
        }catch(Exception e){}
        System.err.println("kritik bölgedeyim. " + getName());
        try{
            Thread.sleep(2000);
            
        } catch(Exception e){}
        sem.release();
        System.out.println("kritik bölgeden çıkıldı." + getName());
        try{
            Thread.sleep(2000);
            
        } catch(Exception e){}
    }
    public static void main(String[] args) {
        JavaApplication33 t1 = new JavaApplication33();
        JavaApplication33 t2 = new JavaApplication33();
        JavaApplication33 t3 = new JavaApplication33();
        JavaApplication33 t4 = new JavaApplication33();
        JavaApplication33 t5 = new JavaApplication33();
        t1.start();
        t2.start();
        t3.start();
        t4.start();
        t5.start();
        
    }
}