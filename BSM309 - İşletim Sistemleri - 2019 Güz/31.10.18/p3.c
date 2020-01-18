// Signals
#include<stdio.h>
#include<signal.h>

void foo()
{
  printf("CTRL-C ye basıldı\n");
  exit(1);
}


int main()
{
  signal(SIGINT, foo);//Interrupt from keyboard

  while(1) ;
}
