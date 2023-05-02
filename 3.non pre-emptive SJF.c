#include <stdio.h>

int main()
{
    int n, i, j, temp, total_wait_time = 0, total_turnaround_time = 0;
    float avg_wait_time, avg_turnaround_time;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int burst_time[n], waiting_time[n], turnaround_time[n];

    printf("Enter burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    for (i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (burst_time[j] < burst_time[min_idx]) {
                min_idx = j;
            }
        }
        temp = burst_time[i];
        burst_time[i] = burst_time[min_idx];
        burst_time[min_idx] = temp;
    }

    waiting_time[0] = 0;
    for (i = 1; i < n; i++) {
        waiting_time[i] = 0;
        for (j = 0; j < i; j++) {
            waiting_time[i] += burst_time[j];
        }
        total_wait_time += waiting_time[i];
    }

    for (i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    avg_wait_time = (float)total_wait_time / n;
    avg_turnaround_time = (float)total_turnaround_time / n;
    printf("Average waiting time = %.2f\n", avg_wait_time);
    printf("Average turnaround time = %.2f\n", avg_turnaround_time);

    return 0;
}

