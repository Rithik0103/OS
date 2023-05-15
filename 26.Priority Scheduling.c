#include <stdio.h>

#define NUM_PROCESSES 3

struct Process {
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
};

int main() {
    // initialize processes with given data
    struct Process processes[NUM_PROCESSES] = {
        {30, 2},
        {5, 1},
        {12, 3}
    };
    int i,j;

    // sort processes by priority in descending order
    for (i = 0; i < NUM_PROCESSES-1; i++) {
        for (j = 0; j < NUM_PROCESSES-i-1; j++) {
            if (processes[j].priority < processes[j+1].priority) {
                struct Process temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }

    // calculate waiting time and turnaround time for each process
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int current_time = 0;
    for (i = 0; i < NUM_PROCESSES; i++) {
        processes[i].waiting_time = current_time;
        processes[i].turnaround_time = current_time + processes[i].burst_time;
        current_time += processes[i].burst_time;

        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    // calculate average waiting time and average turnaround time
    float avg_waiting_time = (float)total_waiting_time / NUM_PROCESSES;
    float avg_turnaround_time = (float)total_turnaround_time / NUM_PROCESSES;

    // print results
    printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < NUM_PROCESSES; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", i+1, processes[i].burst_time, processes[i].priority,
               processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}

