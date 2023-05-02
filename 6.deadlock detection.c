#include <stdio.h>

int main() 
{
    int max[3][3] = {{3, 6, 8}, {4, 3, 3}, {3, 4, 4}};
    int allocation[3][3] = {{3, 3, 3}, {2, 0, 3}, {1, 2, 4}};
    int available[3] = {1, 2, 0};
    int i, j, k, num_deadlocked = 0;
    int finish[3] = {0}; 
    int work[3];

    printf("Max matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", max[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Allocation matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", allocation[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Available resources:\n");
    for (i = 0; i < 3; i++) {
        printf("%d ", available[i]);
        work[i] = available[i];
    }
    printf("\n\n");

    for (i = 0; i < 3; i++) {
        if (!finish[i]) { 
            int can_finish = 1;
            for (j = 0; j < 3; j++) {
                if (max[i][j] - allocation[i][j] > work[j]) {
                    can_finish = 0;
                    break;
                }
            }
            if (can_finish) { 
                for (j = 0; j < 3; j++) {
                    work[j] += allocation[i][j];
                }
                finish[i] = 1; 
            }
        }
    }

    for (i = 0; i < 3; i++) {
        if (!finish[i]) { 
            num_deadlocked++;
            printf("Process %d is deadlocked\n", i+1);
        }
    }

    if (num_deadlocked == 0) {
        printf("The system is not in a deadlock state\n");
    }

    return 0;
}

