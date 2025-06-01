#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define SIZE 5

int buffer[SIZE];
int in = 0, out = 0;

sem_t empty, full, mutex;

void* producer(void* arg) {
    int item, i;
    for(i = 0; i < 5; i++) {
        item = i+1;
        sem_wait(&empty);
        sem_wait(&mutex);

        buffer[in] = item;
        printf("Producer produced item %d at position %d\n", item, in);
        in = (in+1)%SIZE;

        sem_post(&mutex);
        sem_post(&full);

        sleep(1);
    }
    pthread_exit(NULL);
}

void* consumer(void* arg) {
    int item, i;
    for(i = 0; i < 5; i++) {
        sem_wait(&full);
        sem_wait(&mutex);

        item = buffer[out];
        printf("Consumer consumed item %d from position %d\n", item, out);
        out = (out+1)%SIZE;

        sem_post(&mutex);
        sem_post(&empty);

        sleep(2);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t p, c;

    sem_init(&empty, 0, SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    return 0;
}
