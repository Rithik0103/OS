#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int shared_data; // Shared memory

sem_t semaphore; // Semaphore for synchronization

void *thread1(void *arg) {
    int data;

    sem_wait(&semaphore); // Wait for the semaphore

    data = shared_data; // Read shared memory

    sem_post(&semaphore); // Release the semaphore

    printf("Thread 1: Doubled value: %d\n", data * 2); // Print the doubled value

    pthread_exit(NULL);
}

void *thread2(void *arg) {
    int data;

    sem_wait(&semaphore); // Wait for the semaphore

    data = shared_data; // Read shared memory

    sem_post(&semaphore); // Release the semaphore

    printf("Thread 2: Five times value: %d\n", data * 5); // Print the five times value

    pthread_exit(NULL);
}

int main() {
    pthread_t tid1, tid2;
    printf("Enter shared data : ");
	scanf("%d",&shared_data);
    sem_init(&semaphore, 0, 1); // Initialize the semaphore

    pthread_create(&tid1, NULL, thread1, NULL); // Create thread 1
    pthread_create(&tid2, NULL, thread2, NULL); // Create thread 2

    pthread_join(tid1, NULL); // Wait for thread 1 to finish
    pthread_join(tid2, NULL); // Wait for thread 2 to finish

    sem_destroy(&semaphore); // Destroy the semaphore

    return 0;
}

