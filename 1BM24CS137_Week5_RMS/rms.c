#include <stdio.h>

typedef struct {
    int id;
    int period;
    int burst;
    int remaining_time;
} Task;

// Function to find the Least Common Multiple (LCM) for the hyperperiod
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int find_lcm(Task tasks[], int n) {
    int res = tasks[0].period;
    for (int i = 1; i < n; i++)
        res = (((tasks[i].period * res)) / (gcd(tasks[i].period, res)));
    return res;
}

int main() {
    int n = 3;
    Task tasks[] = {
        {1, 20, 3, 0}, // Task ID, Period, Burst Time
        {2, 5, 2, 0},
        {3, 10, 2, 0}
    };

    int hyperperiod = find_lcm(tasks, n);
    printf("Hyperperiod: %d\n\n", hyperperiod);

    for (int t = 0; t < hyperperiod; t++) {
        int highest_priority_task = -1;
        int min_period = 1e9;

        for (int i = 0; i < n; i++) {
            // Task arrives at the start of its period
            if (t % tasks[i].period == 0) {
                tasks[i].remaining_time = tasks[i].burst;
            }

            // Select ready task with the smallest period (highest priority)
            if (tasks[i].remaining_time > 0) {
                if (tasks[i].period < min_period) {
                    min_period = tasks[i].period;
                    highest_priority_task = i;
                }
            }
        }

        if (highest_priority_task != -1) {
            printf("Time %d: Task %d is running\n", t, tasks[highest_priority_task].id);
            tasks[highest_priority_task].remaining_time--;
        } else {
            printf("Time %d: CPU Idle\n", t);
        }
    }
    return 0;
}
