#include <stdio.h>
#include <pthread.h>

// Global variables
int count = 1;
pthread_mutex_t mutex;
pthread_cond_t cond;

int main() {
    pthread_t evenThread, oddThread;

    // Initialize mutex and condition variables
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    // Create the thread for printing even numbers
    pthread_create(&evenThread, NULL, NULL, NULL);

    // Create the thread for printing odd numbers
    pthread_create(&oddThread, NULL, NULL, NULL);

    while (count <= 10) {
        pthread_mutex_lock(&mutex);

        // Print even number if count is even
        if (count % 2 == 0) {
            printf("Even: %d\n", count);
        }
        // Print odd number if count is odd
        else {
            printf("Odd : %d\n", count);
        }

        count++;
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);
    }

    // Wait for threads to finish
    pthread_join(evenThread, NULL);
    pthread_join(oddThread, NULL);

    // Destroy mutex and condition variables
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}

