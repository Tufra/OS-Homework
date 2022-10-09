#include <stdio.h>
#include <stdlib.h>

typedef struct Process {
    int id;
    int arrival_time;
    int burst_time;
    
    int completion_time;
    int turnaround_time;
    int waiting_time;
} Process;

int comp(const void* a, const void* b) {
    if (((Process*)a)->arrival_time > ((Process*)b)->arrival_time) {
        return 1;
    }

    if (((Process*)a)->arrival_time < ((Process*)b)->arrival_time) {
        return -1;
    }
    
    if (((Process*)a)->burst_time > ((Process*)b)->burst_time)
    {
        return 1;
    }
    
    if (((Process*)a)->burst_time < ((Process*)b)->burst_time) {
        return -1;
    }

    return 0;
}

void schedule(Process* processes, int n, double* average_turnaround, double* average_waiting) {
    qsort(processes, n, sizeof(Process), comp);

    int time = processes[0].arrival_time;

    for (size_t i = 0; i < n; i++) {
        Process* current_process = processes + i;

        // Assume we are waiting for next process to appear
        if (time < current_process->arrival_time) {
            time = current_process->arrival_time;
        }
        

        current_process->completion_time = time + current_process->burst_time;
        current_process->turnaround_time = current_process->completion_time - current_process->arrival_time;

        time += current_process->burst_time;
        
        for (size_t j = i + 1; j < n; j++) {
            if (processes[j].arrival_time < time) {
                processes[j].waiting_time = time - processes[j].arrival_time;
            }
            
        }

        int shortest_available_job_index = -1;
        int shortest_job_burst = __INT_MAX__;
        for (size_t j = i + 1; j < n; j++) {
            if (processes[j].arrival_time > time) {
                break;
            }
            
            if (processes[j].burst_time < shortest_job_burst) {
                shortest_available_job_index = j;
                shortest_job_burst = processes[j].burst_time;
            }
        }
        if (shortest_available_job_index != -1 && shortest_available_job_index != i + 1) {
            Process buff = processes[i + 1];
            processes[i + 1] = processes[shortest_available_job_index];
            processes[shortest_available_job_index] = buff;   
        }
    }

    double turnaround_acc = 0;
    double waiting_acc = 0;
    for (size_t i = 0; i < n; i++) {
        turnaround_acc += processes[i].turnaround_time;
        waiting_acc += processes[i].waiting_time;
    }
    
    *average_turnaround = turnaround_acc / n;
    *average_waiting = waiting_acc / n;
}

void main() {
    int n;
    printf("n: ");
    scanf("%d", &n);

    Process* processes = malloc(n * sizeof(Process));

    for (size_t i = 0; i < n; i++) {
        processes[i].id = i;
        
        printf("Process %d (arrival, burst): ", i);

        int buff1, buff2;
        scanf("%d %d", &buff1, &buff2);

        processes[i].arrival_time = buff1;
        processes[i].burst_time = buff2;
        processes[i].completion_time = 0;
        processes[i].turnaround_time = 0;
        processes[i].waiting_time = 0;
    }

    double average_turnaround = 0;
    double average_waiting = 0;

    schedule(processes, n, &average_turnaround, &average_waiting);

    for (size_t i = 0; i < n; i++) {
        printf("Process %d:\n \
                completion time: %d\n \
                turnaround time: %d\n \
                waiting time: %d\n", 
                processes[i].id,
                processes[i].completion_time,
                processes[i].turnaround_time,
                processes[i].waiting_time
        );
    }
    
    printf("Average turnaround time: %lf\n", average_turnaround);
    printf("Average waiting time: %lf", average_waiting);
}