#include <stdio.h>

#define MAX_PROCESSES 10

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

int main() {
	int QUANTUM;
    int i,n, time = 0, remaining_processes = 0;
    struct process processes[MAX_PROCESSES];

    // Get input
    printf("Enter the Quantum Time : ");
    scanf("%d",&QUANTUM);
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the arrival time and burst time of each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
        remaining_processes++;
    }

    // Run Round Robin algorithm
    while (remaining_processes > 0) {
        for (i = 0; i < n; i++) {
            if (processes[i].remaining_time <= 0) {
                continue;
            }

            if (processes[i].arrival_time <= time) {
                printf("Running process %d for %d seconds\n", processes[i].pid, QUANTUM);

                processes[i].remaining_time -= QUANTUM;
                time += QUANTUM;

                if (processes[i].remaining_time <= 0) {
                    processes[i].completion_time = time;
                    processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
                    processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;

                    printf("Process %d completed at time %d\n", processes[i].pid, processes[i].completion_time);
                    printf("Turnaround time: %d\n", processes[i].turnaround_time);
                    printf("Waiting time: %d\n", processes[i].waiting_time);

                    remaining_processes--;
                }
            }
        }
    }

    return 0;
}

