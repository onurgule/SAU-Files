// Pthread örneği
#include<stdio.h>
#include<pthread.h>

void task(int *a)
{
  int b = *a;
  printf("Merhaba burası thread a = %d\n", b);
  pthread_exit(0);
}

int main()
{
  pthread_t tid;
  pthread_attr_t attr;

  int a = 5;


  pthread_attr_init(&attr);
  pthread_create(&tid, &attr, (void *) &task, &a);
  pthread_join(tid, NULL);
}
