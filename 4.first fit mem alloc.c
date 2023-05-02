#include <stdio.h>

int main() 
{
    int partitions[6] = {300, 600, 350, 200, 750, 125};
    int processes[5] = {115, 500, 358, 200, 375};
    int num_processes = sizeof(processes) / sizeof(int);
    int i, j, k;
    int allocated[num_processes];
    int free_space;

    printf("Memory partitions:\n");
    for (i = 0; i < 6; i++) {
        printf("%d KB ", partitions[i]);
    }
    printf("\n\n");

    for (i = 0; i < num_processes; i++) {
        allocated[i] = 0; 

        for (j = 0; j < 6; j++) {
            if (partitions[j] >= processes[i]) {
                allocated[i] = partitions[j];
                partitions[j] -= processes[i];
                break; 
            }
        }
    }

    printf("Allocation results:\n");
    for (i = 0; i < num_processes; i++) {
        if (allocated[i]) {
            printf("Process %d (size %d KB) allocated to partition %d KB\n", i+1, processes[i], allocated[i]);
        }
        else {
            printf("Process %d (size %d KB) could not be allocated\n", i+1, processes[i]);
        }
    }

    printf("\nMemory partitions after allocation:\n");
    for (i = 0; i < 6; i++) {
        printf("%d KB ", partitions[i]);
        free_space += partitions[i];
    }
    printf("\n\nTotal free space: %d KB\n", free_space);

    return 0;
}
