
// Signals
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void foo1(int a)
{
  printf("Ben burdayım a = %d\n", a);
  alarm(1);
}
void foo2(int a)
{
  printf("CTRL C Basıldı  a = %d\n", a);
  exit(0);
}


int main()
{
  signal(SIGALRM, foo1);
  signal(SIGINT, foo2);
  raise(SIGALRM);
  alarm(2);

  while(1) ;
}
