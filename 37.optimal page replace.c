#include <stdio.h>

int main() {
    int num_page_frames = 3;
    int page_reference_sequence[] = {4, 1, 2, 4, 3, 2, 1, 5};
    int num_page_references = sizeof(page_reference_sequence) / sizeof(page_reference_sequence[0]);
	int i,j;
    int page_frames[num_page_frames];
    int page_faults = 0;

    for (i = 0; i < num_page_frames; i++) {
        page_frames[i] = -1;  // Initialize page frames as empty (-1)
    }

    for (i = 0; i < num_page_references; i++) {
        int page = page_reference_sequence[i];
        int page_found = 0;

        for (j = 0; j < num_page_frames; j++) {
            if (page_frames[j] == page) {
                page_found = 1;
                break;
            }
        }

        if (!page_found) {
            int optimal_distance = -1;
            int page_to_replace = -1;

            for (j = 0; j < num_page_frames; j++) {
                int distance = 0;
                int k;

                for (k = i + 1; k < num_page_references; k++) {
                    if (page_frames[j] == page_reference_sequence[k]) {
                        break;
                    }

                    distance++;
                }

                if (k == num_page_references) {
                    page_to_replace = j;
                    break;
                }

                if (distance > optimal_distance) {
                    optimal_distance = distance;
                    page_to_replace = j;
                }
            }

            page_frames[page_to_replace] = page;
            page_faults++;
        }

        printf("Page %d -> ", page);
        for (j = 0; j < num_page_frames; j++) {
            if (page_frames[j] == -1) {
                printf("[ ] ");
            } else {
                printf("[%d] ", page_frames[j]);
            }
        }
        printf("\n");
    }

    printf("Number of page faults: %d\n", page_faults);

    return 0;
}

