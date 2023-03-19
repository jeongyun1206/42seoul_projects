#include <stdio.h>
#include <pthread.h>

int main(void)
{
    pthread_mutex_t mutex;

    pthread_mutex_init(&mutex, 0);
    printf("%d\n", pthread_mutex_destroy(&mutex));
}