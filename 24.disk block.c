#include <stdio.h>

#define DISK_BLOCK_SIZE 8192  // 8 KB
#define POINTER_SIZE 4        // 4 bytes
#define NUM_DIRECT_BLOCKS 12
#define NUM_POINTERS_BLOCK (DISK_BLOCK_SIZE / POINTER_SIZE)

int main()
{
    unsigned long long directSize = NUM_DIRECT_BLOCKS * DISK_BLOCK_SIZE;
    unsigned long long singleIndirectSize = DISK_BLOCK_SIZE * NUM_POINTERS_BLOCK;
    unsigned long long doubleIndirectSize = singleIndirectSize * NUM_POINTERS_BLOCK;
    unsigned long long tripleIndirectSize = doubleIndirectSize * NUM_POINTERS_BLOCK;

    unsigned long long maxFileSize = directSize + singleIndirectSize + doubleIndirectSize + tripleIndirectSize;

    printf("Maximum size of a file in the file system: %llu bytes\n", maxFileSize);

    return 0;
}

