#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5

sem_t mutex;
sem_t forks[N];

void* philosopher(void* num) {
    int id = *(int*)num;

    while(1) {
        printf("Philosopher %d is thinking.\n", id);
        sleep(1);

        // Pick up left and right forks
        sem_wait(&forks[id]);
        sem_wait(&forks[(id+1)%N]);

        printf("Philosopher %d is eating.\n", id);
        sleep(2);

        // Put down forks
        sem_post(&forks[id]);
        sem_post(&forks[(id+1)%N]);

        printf("Philosopher %d finished eating.\n", id);
        sleep(1);
    }
}

int main() {
    int i;
    pthread_t tid[N];
    int phil[N];

    sem_init(&mutex, 0, 1);
    for(i = 0; i < N; i++)
        sem_init(&forks[i], 0, 1);

    for(i = 0; i < N; i++) {
        phil[i] = i;
        pthread_create(&tid[i], NULL, philosopher, &phil[i]);
    }

    for(i = 0; i < N; i++)
        pthread_join(tid[i], NULL);

    for(i = 0; i < N; i++)
        sem_destroy(&forks[i]);
    sem_destroy(&mutex);

    return 0;
}
