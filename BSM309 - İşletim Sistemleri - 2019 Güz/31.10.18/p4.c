// Signals
#include<stdio.h>
#include<signal.h>

void foo(int a)
{
  printf("Ben burdayım a = %d\n", a);
  alarm(2); //sinyalin iletimi için alarmı kur (2 saniye)
}


int main()
{
  signal(SIGALRM, foo);
  raise(SIGALRM); //çağırıldığı prosese veya iş parç. sinyal gönderir
  //alarm(2);

  while(1) ;
}
