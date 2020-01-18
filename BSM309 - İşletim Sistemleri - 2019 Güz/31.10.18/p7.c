#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


void *worker(void *data)
{
        char *name = (char*)data;
        for (int i=0; i<5; i++) {
                usleep(50000);
                printf("Hello from thread %s\n", name);
        }
        printf("Thread %s done...\n", name);
        return NULL;
}

int main(void) {
        pthread_t th1, th2;
        pthread_create(&th1, NULL, worker, "A");
        pthread_create(&th2, NULL, worker, "B");
        sleep(5);
        printf("Exiting from main program\n");
        pthread_join(th1, NULL);
        pthread_join(th2, NULL);
        return 0;
}
