#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_tracks = 5;
    int track_positions[] = {55, 58, 60, 70, 18};
    int head_position;
    int total_head_movement = 0;
	int i,j;
    printf("Enter the initial head position: ");
    scanf("%d", &head_position);

    int current_track = head_position;

    // Find the index of the current track position
    int current_track_index = -1;
    for (i = 0; i < num_tracks; i++) {
        if (track_positions[i] == current_track) {
            current_track_index = i;
            break;
        }
    }

    if (current_track_index == -1) {
        printf("Invalid initial head position!\n");
        return 1;
    }

    // Sort the track positions in ascending order
    for (i = 0; i < num_tracks - 1; i++) {
        for (j = 0; j < num_tracks - i - 1; j++) {
            if (track_positions[j] > track_positions[j + 1]) {
                int temp = track_positions[j];
                track_positions[j] = track_positions[j + 1];
                track_positions[j + 1] = temp;
            }
        }
    }

    // Calculate total head movement
    for (i = current_track_index; i < num_tracks - 1; i++) {
        total_head_movement += track_positions[i + 1] - track_positions[i];
    }

    total_head_movement += track_positions[num_tracks - 1] - track_positions[0];

    printf("Total head movement: %d\n", total_head_movement);
    printf("Average head movement: %.2f\n", (float)total_head_movement / num_tracks);

    return 0;
}

