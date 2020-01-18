package javaapplication32;
public class JavaApplication32 {
    public static Object lock = new Object();
    public final static int NUMTHREAD = 5;
    public static void main(String[] args) {
        theThread thread[] = new theThread[NUMTHREAD];
        for (int i = 0; i < NUMTHREAD; i++) {
            thread[i] = new theThread(lock);
            thread[i].start();
        }
        synchronized(lock){
            try{
                Thread.sleep(3000);
            }catch(Exception a){}
        }
        System.err.println("threadlerin işinin bitmesini bekle...");
        for (int i = 0; i < NUMTHREAD; i++) {
            try {
                thread[i].join(); //bitmeseini bekle.
            } catch (Exception e) {
            }
        }
    }
}
class theThread extends Thread{
    Object lock1;
    public theThread(Object a){
        this.lock1 = a;
    }
    public void run(){
        System.err.println("Thread:"+ getName() + " kritik bölgeye girdi.");
        synchronized(lock1){
             System.err.println("Thread:"+ getName() + " kritik bölge başladı, senkron bloğu tutuldu.");
              System.err.println("Thread:"+ getName() + " kritik bölge bitti, senkron blok bırakıldı.");
              //KRİTİK BÖLGE
        }
    }
}
