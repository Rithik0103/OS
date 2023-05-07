#include <stdio.h>

#define NUM_PROCESSES 5
#define NUM_RESOURCES 3

int main() {
	int i,j;
    int allocation[NUM_PROCESSES][NUM_RESOURCES] = {{1, 1, 2},
                                                     {2, 1, 2},
                                                     {3, 0, 1},
                                                     {0, 2, 0},
                                                     {1, 1, 2}};
    int max[NUM_PROCESSES][NUM_RESOURCES] = {{5, 4, 4},
                                             {4, 3, 3},
                                             {9, 1, 3},
                                             {8, 6, 4},
                                             {2, 2, 3}};
    int available[NUM_RESOURCES] = {3, 2, 1};
    int need[NUM_PROCESSES][NUM_RESOURCES];

    // Calculate the entries of the need matrix
    for (i = 0; i < NUM_PROCESSES; i++) {
        for (j = 0; j < NUM_RESOURCES; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Print the need matrix
    printf("Need Matrix:\n");
    for (i = 0; i < NUM_PROCESSES; i++) {
        printf("P%d: ", i);
        for (j = 0; j < NUM_RESOURCES; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    return 0;
}

