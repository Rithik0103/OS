#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, i, j, k, page_faults = 0, page_hits = 0, curr_frame = 0;
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    int pages[n];
    printf("Enter the reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }
    printf("Enter the number of frames: ");
    scanf("%d", &m);
    int frames[m], in_frame[m];

    for (i = 0; i < m; i++) {
        frames[i] = -1;
        in_frame[i] = -1;
    }

    for (i = 0; i < n; i++) {
        int page=pages[i];
        int found = 0;

        for (j = 0; j < m; j++) {
            if (frames[j]==page) {
                found = 1;
                page_hits++;
                break;
            }
        }

        if (!found) {
            page_faults++;

            frames[curr_frame] = page;
            in_frame[page] = curr_frame;
            curr_frame = (curr_frame + 1) % m;
        }
    }

    printf("Total page faults = %d\n", page_faults);
    printf("Total page hits = %d\n", page_hits);

    return 0;
}

