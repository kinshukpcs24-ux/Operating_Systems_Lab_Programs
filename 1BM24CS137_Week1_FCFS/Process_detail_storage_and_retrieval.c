#include <stdio.h>

#define MAX 100

struct process_details
{
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int execution_time;
};

int main()
{
    int n, i;
    struct process_details p[MAX];
    int cumulative_burst_time = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nProcess %d\n", (i+1));
        p[i].pid = i + 1;

        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival_time);

        printf("Burst Time: ");
        scanf("%d", &p[i].burst_time);

        cumulative_burst_time = cumulative_burst_time + p[i].burst_time;
        p[i].completion_time = cumulative_burst_time;
        p[i].execution_time = p[i].burst_time;
    }

    printf("\n\nProcess Details:\n");
    printf("PID\tArrival\tBurst\tCompletion\tExecution\n");
    for(i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t\t%d\n",p[i].pid,p[i].arrival_time,p[i].burst_time,p[i].completion_time,p[i].execution_time);

    return 0;
}
