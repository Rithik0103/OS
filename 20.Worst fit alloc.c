#include <stdio.h>

int main() {
    int blockSize[10], processSize[10], allocation[10];
    int m, n, i, j, max;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);

    printf("Enter the size of each memory block: ");
    for (i = 0; i < m; i++) {
        scanf("%d", &blockSize[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the size of each process: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
    }

    // Initialize allocation array to -1
    for (i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    // Allocate memory for each process
    for (i = 0; i < n; i++) {
        max = -1;
        for (j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (max == -1) {
                    max = j;
                }
                else if (blockSize[j] > blockSize[max]) {
                    max = j;
                }
            }
        }

        // If memory block is available
        if (max != -1) {
            allocation[i] = max;
            blockSize[max] -= processSize[i];
        }
    }

    // Display allocation results
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (i = 0; i < n; i++) {
        printf("   %d\t\t   %d\t\t", i+1, processSize[i]);
        if (allocation[i] != -1) {
            printf("   %d\n", allocation[i]+1);
        }
        else {
            printf("   Not Allocated\n");
        }
    }

    return 0;
}

