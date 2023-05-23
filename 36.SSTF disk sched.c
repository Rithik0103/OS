#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int num_tracks = 5;
    int track_positions[] = {55, 58, 60, 70, 18};
    int head_position;
    int total_head_movement = 0;
	int i,j;
    printf("Enter the initial head position: ");
    scanf("%d", &head_position);

    int *visited = (int *)malloc(num_tracks * sizeof(int));

    for (i = 0; i < num_tracks; i++) {
        visited[i] = 0;
    }

    int min_distance, closest_track;
    int current_track = head_position;

    for (i = 0; i < num_tracks; i++) {
        min_distance = INT_MAX;
        closest_track = -1;

        for (j = 0; j < num_tracks; j++) {
            if (!visited[j] && abs(track_positions[j] - current_track) < min_distance) {
                min_distance = abs(track_positions[j] - current_track);
                closest_track = j;
            }
        }

        visited[closest_track] = 1;
        total_head_movement += min_distance;
        current_track = track_positions[closest_track];
    }

    printf("Total head movement: %d\n", total_head_movement);
    printf("Average head movement: %.2f\n", (float)total_head_movement / num_tracks);

    free(visited);
    return 0;
}

