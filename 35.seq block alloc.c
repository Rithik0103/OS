#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 1024
#define TOTAL_BLOCKS 16
#define INODE_BLOCKS 8
#define DATA_BLOCKS (TOTAL_BLOCKS - INODE_BLOCKS)

int main() {
    int allocated_blocks[TOTAL_BLOCKS] = {0};
	int file,i;
    int num_files;
    printf("Enter the number of files: ");
    scanf("%d", &num_files);

    for (file = 1; file <= num_files; file++) {
        int file_size;
        printf("Enter the size of file %d (in KB): ", file);
        scanf("%d", &file_size);

        if (file_size < 1 || file_size > DATA_BLOCKS) {
            printf("Invalid file size. Minimum file size is 1 KB, maximum is %d KB.\n", DATA_BLOCKS);
            continue;
        }

        int start_block = -1;
        int count = 0;

        for (i = INODE_BLOCKS; i < TOTAL_BLOCKS; i++) {
            if (allocated_blocks[i] == 0) {
                if (start_block == -1) {
                    start_block = i;
                }

                count++;

                if (count == file_size) {
                    break;
                }
            } else {
                start_block = -1;
                count = 0;
            }
        }

        if (count < file_size) {
            printf("Not enough contiguous blocks available for file %d. Exiting.\n", file);
            exit(0);
        }

        // Mark the allocated blocks as used
        for (i = start_block; i < start_block + file_size; i++) {
            allocated_blocks[i] = 1;
        }

        printf("File %d allocated at blocks %d to %d.\n", file, start_block, start_block + file_size - 1);
    }

    return 0;
}

