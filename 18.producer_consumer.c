#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 3

int buffer[BUFFER_SIZE];
int count = 0;
int in = 0;
int out = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t full_cond = PTHREAD_COND_INITIALIZER;
pthread_cond_t empty_cond = PTHREAD_COND_INITIALIZER;

void *producer_consumer(void *arg) {
    int i;
    
    // Consume an item at the beginning
    pthread_mutex_lock(&mutex);
    if (count == 0) {
        printf("Buffer is EMPTY\n");
    }
    while (count == 0) {
        printf("Buffer is EMPTY. Waiting for producer...\n");
        pthread_cond_wait(&empty_cond, &mutex);
    }
    int item = buffer[out];
    out = (out + 1) % BUFFER_SIZE;
    count--;
    printf("Consumed: Item %d\n", item);
    pthread_cond_signal(&full_cond);
    pthread_mutex_unlock(&mutex);
    
    // Produce 4 items
    for (i = 1; i <= 4; i++) {
        pthread_mutex_lock(&mutex);
        while (count == BUFFER_SIZE) {
            printf("Buffer is FULL. Waiting for consumer...\n");
            pthread_cond_wait(&full_cond, &mutex);
        }
        buffer[in] = i;
        in = (in + 1) % BUFFER_SIZE;
        count++;
        printf("Produced: Item %d\n", i);
        pthread_cond_signal(&empty_cond);
        pthread_mutex_unlock(&mutex);
    }
    
    pthread_exit(NULL);
}

int main() {
    pthread_t producer_consumer_thread;
    
    pthread_create(&producer_consumer_thread, NULL, producer_consumer, NULL);
    pthread_join(producer_consumer_thread, NULL);
    
    return 0;
}

