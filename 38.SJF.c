#include <stdio.h>

typedef struct {
    int process_id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

int main() {
    int num_processes = 3;
    Process processes[] = {
        {0, 2, 0, 0},
        {1, 4, 0, 0},
        {2, 8, 0, 0}
    };
	int i,j;
    // Sort processes based on burst time using Bubble Sort
    for (i = 0; i < num_processes - 1; i++) {
        for (j = 0; j < num_processes - i - 1; j++) {
            if (processes[j].burst_time > processes[j + 1].burst_time) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    // Compute waiting time for each process
    processes[0].waiting_time = 0;
    for (i= 1; i < num_processes; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
    }

    // Compute turnaround time for each process
    for ( i = 0; i < num_processes; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }

    // Print process details
    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < num_processes; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].burst_time,
               processes[i].waiting_time, processes[i].turnaround_time);
    }

    // Calculate average waiting time and average turnaround time
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    for (i = 0; i < num_processes; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }
    double average_waiting_time = (double)total_waiting_time / num_processes;
    double average_turnaround_time = (double)total_turnaround_time / num_processes;

    printf("Average Waiting Time: %.2f\n", average_waiting_time);
    printf("Average Turnaround Time: %.2f\n", average_turnaround_time);

    return 0;
}

