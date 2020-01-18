package javaapplication34;
import java.util.concurrent.Semaphore;
public class JavaApplication34 {
    public static void main(String[] args) {
        Semaphore sem = new Semaphore(2);
        MyThread t1 = new MyThread(sem, "A");
        MyThread t2 = new MyThread(sem, "B");
        MyThread t3 = new MyThread(sem, "C");
        t1.start();
        t2.start();
        t3.start();
    }
}
class MyThread extends Thread{
    Semaphore sem;
    String threadName;
    public MyThread(Semaphore s, String n){
        this.sem = s;
        this.threadName = n;
    }
    public void run(){
        System.err.println("Başlıyor "+ threadName);
        try{
            System.err.println(threadName + " izin için bekliyor.");
            sem.acquire();
            System.err.println(threadName + " izin aldı.");
            
            for (int i = 0; i < 5; i++) {
                System.err.println(threadName + ": "+ i);
                Thread.sleep(1000);
            }
        }catch(Exception e){}
        System.err.println(threadName + " izini bıraktı.");
        sem.release();
    }
}