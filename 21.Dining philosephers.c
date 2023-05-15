#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5
#define EATING_TIME 2
#define THINKING_TIME 2
#define HUNGRY_TIME 1
#define MAX_MEALS 3

pthread_t philosophers[NUM_PHILOSOPHERS];
pthread_mutex_t forks[NUM_PHILOSOPHERS];
pthread_cond_t cond_vars[NUM_PHILOSOPHERS];
enum { THINKING, HUNGRY, EATING } state[NUM_PHILOSOPHERS];

void *philosopher(void *arg) {
    int id = *(int *)arg;
    int left = id;
    int right = (id + 1) % NUM_PHILOSOPHERS;
    int meals = 0;

    while (meals < MAX_MEALS) {
        // Think
        printf("Philosopher %d is thinking...\n", id);
        state[id] = THINKING;
        sleep(THINKING_TIME);

        // Get hungry
        printf("Philosopher %d is hungry...\n", id);
        state[id] = HUNGRY;

        // Try to pick up forks
        pthread_mutex_lock(&forks[left]);
        while (state[left] == EATING) {
            pthread_cond_wait(&cond_vars[left], &forks[left]);
        }

        pthread_mutex_lock(&forks[right]);
        while (state[right] == EATING) {
            pthread_cond_wait(&cond_vars[right], &forks[right]);
        }

        // Eat
        printf("Philosopher %d is eating...\n", id);
        state[id] = EATING;
        meals++;
        sleep(EATING_TIME);

        // Put down forks
        pthread_mutex_unlock(&forks[left]);
        pthread_cond_signal(&cond_vars[left]);

        pthread_mutex_unlock(&forks[right]);
        pthread_cond_signal(&cond_vars[right]);
    }

    return NULL;
}

int main() {
    int i, ids[NUM_PHILOSOPHERS];

    // Initialize mutexes and condition variables
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_init(&forks[i], NULL);
        pthread_cond_init(&cond_vars[i], NULL);
    }

    // Create threads for philosophers
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }

    // Wait for threads to finish
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    // Destroy mutexes and condition variables
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_destroy(&forks[i]);
        pthread_cond_destroy(&cond_vars[i]);
    }

    return 0;
}

