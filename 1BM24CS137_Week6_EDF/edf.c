#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;          // Task ID
    int exec_time;   // Execution time
    int deadline;    // Deadline
    int remaining;   // Remaining execution time
} Task;

void edf_schedule(Task tasks[], int n) {
    int time = 0;
    int completed = 0;

    while (completed < n) {
        // Find task with earliest deadline among unfinished tasks
        int earliest = -1;
        for (int i = 0; i < n; i++) {
            if (tasks[i].remaining > 0) {
                if (earliest == -1 || tasks[i].deadline < tasks[earliest].deadline) {
                    earliest = i;
                }
            }
        }

        if (earliest == -1) break; // No tasks left

        printf("Time %d: Executing Task %d\n", time, tasks[earliest].id);
        tasks[earliest].remaining--;
        time++;

        if (tasks[earliest].remaining == 0) {
            printf("Task %d completed at time %d (Deadline: %d)\n",
                   tasks[earliest].id, time, tasks[earliest].deadline);
            completed++;
        }
    }
}

int main() {
    int n;
    printf("Enter number of tasks: ");
    scanf("%d", &n);

    Task tasks[n];
    for (int i = 0; i < n; i++) {
        printf("Enter execution time and deadline for Task %d: ", i+1);
        scanf("%d %d", &tasks[i].exec_time, &tasks[i].deadline);
        tasks[i].id = i+1;
        tasks[i].remaining = tasks[i].exec_time;
    }

    printf("\n--- Earliest Deadline First Scheduling ---\n");
    edf_schedule(tasks, n);

    return 0;
}
