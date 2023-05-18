#include <stdio.h>

int main() {
    int memory[] = {40, 10, 30, 60}; // Memory partitions in KB
    int n = sizeof(memory) / sizeof(memory[0]);
    int processes[] = {100, 50, 30, 120, 35}; // Process sizes in KB
    int m = sizeof(processes) / sizeof(processes[0]);
    int allocated[m];
    int i, j, max_index;

    // Initialize allocated array with -1
    for (i = 0; i < m; i++) {
        allocated[i] = -1;
    }

    // Allocate memory blocks to processes
    for (i = 0; i < m; i++) {
        max_index = -1;

        for (j = 0; j < n; j++) {
            if (memory[j] >= processes[i]) {
                if (max_index == -1 || memory[j] > memory[max_index]) {
                    max_index = j;
                }
            }
        }

        if (max_index != -1) {
            allocated[i] = max_index;
            memory[max_index] -= processes[i];
        }
    }

    // Print the outcome
    printf("Process\t\tAllocated Block\n");

    for (i = 0; i < m; i++) {
        printf("%d\t\t", processes[i]);

        if (allocated[i] != -1) {
            printf("%d\n", allocated[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }

    return 0;
}

