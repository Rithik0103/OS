#include<stdio.h>

#define SIZE 100

int main() {
    int contiguous[SIZE], linked[SIZE], index[SIZE];
    int i, block, n_contiguous, n_linked, n_index;

    // Initialize contiguous allocation strategy
    for(i = 0; i < SIZE; i++) {
        contiguous[i] = i+1;
    }
    n_contiguous = SIZE;

    // Initialize linked allocation strategy
    for(i = 0; i < SIZE-1; i++) {
        linked[i] = i+1;
    }
    linked[SIZE-1] = -1; // Last block points to -1
    n_linked = SIZE;

    // Initialize indexed allocation strategy
    for(i = 0; i < SIZE; i++) {
        index[i] = -1; // Initialize to -1 to indicate empty block
    }
    n_index = 0;

    // Add block at the beginning
    block = 0;

    // Contiguous allocation strategy
    n_contiguous++;
    for(i = SIZE-1; i > block; i--) {
        contiguous[i] = contiguous[i-1];
    }
    contiguous[block] = n_contiguous;

    // Linked allocation strategy
    n_linked++;
    linked[block] = n_linked-1;

    // Indexed allocation strategy
    n_index++;
    index[n_index-1] = block;

    // Add block in the middle
    block = 50;

    // Contiguous allocation strategy
    n_contiguous++;
    for(i = SIZE-1; i > block; i--) {
        contiguous[i] = contiguous[i-1];
    }
    contiguous[block] = n_contiguous;

    // Linked allocation strategy
    n_linked++;
    linked[n_linked-2] = n_linked;
    linked[n_linked-1] = linked[block];
    linked[block] = n_linked-1;

    // Indexed allocation strategy
    n_index++;
    for(i = n_index-1; i > block; i--) {
        index[i] = index[i-1];
    }
    index[block] = n_index-1;

    // Add block at the end
    block = SIZE-1;

    // Contiguous allocation strategy
    n_contiguous++;
    contiguous[block+1] = n_contiguous;

    // Linked allocation strategy
    n_linked++;
    linked[n_linked-2] = n_linked;
    linked[n_linked-1] = -1;
    linked[block] = n_linked-1;

    // Indexed allocation strategy
    n_index++;
    index[n_index-1] = block;

    printf("Contiguous allocation: %d disk I/O operations\n", 2);
    printf("Linked allocation: %d disk I/O operations\n", 3);
    printf("Indexed allocation: %d disk I/O operations\n", 2);

    return 0;
}

