#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_TRACKS 5
#define INIT_POS 50
#define MAX_POS 100
#define MIN_POS 0

int main() {
    int tracks[NUM_TRACKS] = {55, 58, 60, 70, 18};
    int head_pos = INIT_POS;
    int total_head_movement = 0;
    int i,j;
    bool direction = true; // true = right, false = left

    // sort tracks in ascending order
    for (i = 0; i < NUM_TRACKS-1; i++) {
        for (j = 0; j < NUM_TRACKS-i-1; j++) {
            if (tracks[j] > tracks[j+1]) {
                int temp = tracks[j];
                tracks[j] = tracks[j+1];
                tracks[j+1] = temp;
            }
        }
    }

    // scan in right direction
    i = 0;
    while (i < NUM_TRACKS && tracks[i] < head_pos) {
        i++;
    }
    while (i < NUM_TRACKS) {
        printf("Head is at track %d\n", head_pos);
        total_head_movement += abs(head_pos - tracks[i]);
        head_pos = tracks[i];
        i++;
    }

    // scan in left direction
    i = NUM_TRACKS - 1;
    while (i >= 0 && tracks[i] > head_pos) {
        i--;
    }
    i++;
    while (i >= 0) {
        printf("Head is at track %d\n", head_pos);
        total_head_movement += abs(head_pos - tracks[i]);
        head_pos = tracks[i];
        i--;
    }

    printf("Total head movement: %d\n", total_head_movement);
    printf("Average head movement: %.2f\n", (float)total_head_movement / NUM_TRACKS);

    return 0;
}

