#include <stdio.h>
#include <stdlib.h>

int main() {
    int tracks[] = {55, 58, 60, 70, 18};
    int n = sizeof(tracks) / sizeof(tracks[0]);
    int head_position = 50;
    int i, j, temp, sum = 0;

    // Sort the track positions in ascending order using bubble sort
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (tracks[j] > tracks[j+1]) {
                temp = tracks[j];
                tracks[j] = tracks[j+1];
                tracks[j+1] = temp;
            }
        }
    }

    // Find the index where the head position should be inserted
    for (i = 0; i < n; i++) {
        if (tracks[i] > head_position) {
            break;
        }
    }

    // Calculate the total head movement
    for (j = i; j < n; j++) {
        printf("Head movement from %d to %d: %d\n", head_position, tracks[j], abs(head_position - tracks[j]));
        sum += abs(head_position - tracks[j]);
        head_position = tracks[j];
    }

    // Perform a full scan from the beginning to the track before the initial head position
    printf("Head movement from %d to %d: %d\n", head_position, 0, abs(head_position - 0));
    sum += abs(head_position - 0);
    head_position = 0;

    for (j = 0; j < i; j++) {
        printf("Head movement from %d to %d: %d\n", head_position, tracks[j], abs(head_position - tracks[j]));
        sum += abs(head_position - tracks[j]);
        head_position = tracks[j];
    }

    // Calculate the average head movement
    float average_movement = (float) sum / n;

    printf("\nAverage head movement: %.2f\n", average_movement);

    return 0;
}

