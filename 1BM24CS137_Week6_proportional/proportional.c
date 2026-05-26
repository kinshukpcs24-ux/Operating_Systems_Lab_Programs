#include <stdio.h>

typedef struct {
    int id;
    int burst_time;
    int weight;
    int remaining_time;
} Process;

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process p[n];
    int total_weight = 0;

    for (int i = 0; i < n; i++) {
        printf("Enter burst time and weight for process %d: ", i+1);
        scanf("%d %d", &p[i].burst_time, &p[i].weight);
        p[i].id = i+1;
        p[i].remaining_time = p[i].burst_time;
        total_weight += p[i].weight;
    }

    printf("\n--- Proportional Scheduling Simulation ---\n");

    int time = 0;
    int finished = 0;

    while (finished < n) {
        for (int i = 0; i < n; i++) {
            if (p[i].remaining_time > 0) {
                int quantum = p[i].weight; // proportional to weight
                if (quantum > p[i].remaining_time) {
                    quantum = p[i].remaining_time;
                }

                printf("Time %d: Process %d runs for %d units\n", time, p[i].id, quantum);
                time += quantum;
                p[i].remaining_time -= quantum;

                if (p[i].remaining_time == 0) {
                    printf("Process %d finished at time %d\n", p[i].id, time);
                    finished++;
                }
            }
        }
    }

    printf("\nAll processes finished by time %d\n", time);
    return 0;
}
