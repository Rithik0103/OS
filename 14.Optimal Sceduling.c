#include <stdio.h>

#define MAX_FRAMES 10
#define MAX_PAGES 20

int main() {
    int num_frames, num_pages, num_faults = 0,i,j,k;
    int pages[MAX_PAGES], frames[MAX_FRAMES], next_use[MAX_FRAMES];

    printf("Enter the number of page frames: ");
    scanf("%d", &num_frames);

    printf("Enter the number of pages: ");
    scanf("%d", &num_pages);

    printf("Enter the page reference sequence: ");
    for (i = 0; i < num_pages; i++) {
        scanf("%d", &pages[i]);
    }

    // Initialize frames and next_use arrays to -1
    for (i = 0; i < num_frames; i++) {
        frames[i] = -1;
        next_use[i] = -1;
    }

    // Iterate over the page reference sequence
    for (i = 0; i < num_pages; i++) {
        int page = pages[i];

        // Check if page is already in memory
        int hit = 0;
        for (j = 0; j < num_frames; j++) {
            if (frames[j] == page) {
                hit = 1;
                break;
            }
        }

        if (!hit) {
            // Page fault
            num_faults++;

            // Check if there are any free frames
            int free_frame = -1;
            for (j = 0; j < num_frames; j++) {
                if (frames[j] == -1) {
                    free_frame = j;
                    break;
                }
            }

            if (free_frame != -1) {
                // Use a free frame
                frames[free_frame] = page;
                next_use[free_frame] = i;
            } else {
                // Find the frame with the longest time until next use
                int victim_frame = 0;
                for (j = 1; j < num_frames; j++) {
                    if (next_use[j] > next_use[victim_frame]) {
                        victim_frame = j;
                    }
                }

                // Replace the victim frame
                frames[victim_frame] = page;
                next_use[victim_frame] = i;
            }
        }

        // Update next_use array for all frames
        for (j = 0; j < num_frames; j++) {
            if (frames[j] != -1) {
                int next = -1;
                for (k = i+1; k < num_pages; k++) {
                    if (pages[k] == frames[j]) {
                        next = k;
                        break;
                    }
                }
                next_use[j] = next;
            }
        }
    }

    printf("Number of page faults: %d\n", num_faults);

    return 0;
}
