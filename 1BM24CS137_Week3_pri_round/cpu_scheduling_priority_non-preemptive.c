#include <stdio.h>

struct Process
{
    int pid;
    int arrival;
    int burst;
    int priority;
    int completion;
    int turnaround;
    int waiting;
    int finished;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        printf("Enter arrival time, burst time, priority for process %d: ", i + 1);
        scanf("%d %d %d", &p[i].arrival, &p[i].burst, &p[i].priority);
        p[i].finished = 0;
    }

    int time = 0, completed = 0;

    while (completed < n)
    {
        int idx = -1;
        int highestPriority = 999999;

        for (int i = 0; i < n; i++)
        {
            if (p[i].arrival <= time && !p[i].finished)
            {
                if (p[i].priority < highestPriority)
                {
                    highestPriority = p[i].priority;
                    idx = i;
                }
                else if (p[i].priority == highestPriority)
                {
                    if (p[i].arrival < p[idx].arrival)
                    {
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1) {
            time += p[idx].burst;
            p[idx].completion = time;
            p[idx].turnaround = p[idx].completion - p[idx].arrival;
            p[idx].waiting = p[idx].turnaround - p[idx].burst;
            p[idx].finished = 1;
            completed++;
        }
        else
        {
            time++;
        }
    }

    printf("\nProcess\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].arrival, p[i].burst, p[i].priority,
               p[i].completion, p[i].turnaround, p[i].waiting);
    }

    return 0;
}
