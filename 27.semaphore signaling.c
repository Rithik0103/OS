#include <stdio.h>
#include <pthread.h>

#define NUM_INSTANCES 4

pthread_mutex_t mutex;
pthread_cond_t condition;
int semaphore = NUM_INSTANCES;

void* process(void* arg) {
    char* name = (char*)arg;
    
    printf("%s is waiting.\n", name);
    
    pthread_mutex_lock(&mutex);
    while (semaphore == 0) {
        pthread_cond_wait(&condition, &mutex);
    }
    
    semaphore--;
    printf("%s has acquired the semaphore.\n", name);
    
    pthread_mutex_unlock(&mutex);
    
    // Perform some work here
    
    pthread_mutex_lock(&mutex);
    semaphore++;
    printf("%s has released the semaphore.\n", name);
    
    pthread_cond_signal(&condition);
    pthread_mutex_unlock(&mutex);
    
    return NULL;
}

int main() {
    pthread_t p1, p2, p3, p4, p5;
    
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&condition, NULL);
    
    pthread_create(&p1, NULL, process, "P1");
    pthread_create(&p2, NULL, process, "P2");
    pthread_create(&p3, NULL, process, "P3");
    pthread_create(&p4, NULL, process, "P4");
    
    // P5 tries to acquire the semaphore
    printf("P5 is waiting.\n");
    
    pthread_mutex_lock(&mutex);
    while (semaphore == 0) {
        pthread_cond_wait(&condition, &mutex);
    }
    
    semaphore--;
    printf("P5 has acquired the semaphore.\n");
    
    pthread_mutex_unlock(&mutex);
    
    // Perform some work here
    
    pthread_mutex_lock(&mutex);
    semaphore++;
    printf("P5 has released the semaphore.\n");
    
    pthread_cond_signal(&condition);
    pthread_mutex_unlock(&mutex);
    
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    pthread_join(p3, NULL);
    pthread_join(p4, NULL);
    
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&condition);
    
    return 0;
}

