#include <stdio.h>
int main() 
{
    int page_frames[3] = {-1, -1, -1}; 
    int page_sequence[20] = {1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3, 6, 1, 2, 4, 3};
    int page_faults = 0;
    int i, j, k;

    for (i = 0; i < 20; i++) {
        int page = page_sequence[i];
        int page_found = 0;

        for (j = 0; j < 3; j++) {
            if (page_frames[j] == page) {
                page_found = 1;
                break;
            }
        }

        if (!page_found) { 
            page_faults++;
            int lru_frame_index = -1;
            int lru_frame_counter = 20; 

            for (j = 0; j < 3; j++) {
                int frame_found = 0;
                for (k = i-1; k >= 0; k--) {
                    if (page_frames[j] == page_sequence[k]) {
                        frame_found = 1;
                        if (k < lru_frame_counter) {
                            lru_frame_index = j;
                            lru_frame_counter = k;
                        }
                        break;
                    }
                }
                if (!frame_found) { 
                    lru_frame_index = j;
                    break;
                }
            }

            page_frames[lru_frame_index] = page;
        }

        printf("Page frames: ");
        for (j = 0; j < 3; j++) {
            if (page_frames[j] == -1) {
                printf("- ");
            } else {
                printf("%d ", page_frames[j]);
            }
        }
        printf("\n");
    }

    printf("Number of page faults: %d\n", page_faults);

    return 0;
}

