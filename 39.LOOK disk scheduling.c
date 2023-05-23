#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_tracks = 5;
    int track_positions[] = {55, 58, 60, 70, 18};
    int head_position;
    int total_head_movement = 0;

    printf("Enter the initial head position: ");
    scanf("%d", &head_position);

    int direction;  // 0 for left, 1 for right
    if (head_position < track_positions[0]) {
        direction = 1;  // Move right
    } else {
        direction = 0;  // Move left
    }

    int current_track = head_position;
	int i;
    while (1) {
        if (direction) {
            // Move right
            for (i = 0; i < num_tracks; i++) {
                if (track_positions[i] >= current_track) {
                    total_head_movement += track_positions[i] - current_track;
                    current_track = track_positions[i];
                    break;
                }
            }

            // Check if reached the rightmost track
            if (current_track == track_positions[num_tracks - 1]) {
                break;
            }
        } else {
            // Move left
            for (i = num_tracks - 1; i >= 0; i--) {
                if (track_positions[i] <= current_track) {
                    total_head_movement += current_track - track_positions[i];
                    current_track = track_positions[i];
                    break;
                }
            }

            // Check if reached the leftmost track
            if (current_track == track_positions[0]) {
                break;
            }
        }
    }

    printf("Total head movement: %d\n", total_head_movement);
    printf("Average head movement: %.2f\n", (float)total_head_movement / num_tracks);

    return 0;
}

