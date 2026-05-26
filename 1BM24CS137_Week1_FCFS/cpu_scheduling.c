#include <stdio.h>

#define MAX 100

struct Process
{
    int pid;
    int arrival;
    int burst;
    int completion;
    int turnaround;
    int waiting;
};

void fcfs(struct Process p[], int n)
{
    int time = 0;

    for(int i = 0; i < n; i++)
    {
        if(time < p[i].arrival)
            time = p[i].arrival;

        p[i].completion = time + p[i].burst;
        p[i].turnaround = p[i].completion - p[i].arrival;
        p[i].waiting = p[i].turnaround - p[i].burst;

        time = p[i].completion;
    }
}

void display(struct Process p[], int n)
{

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].arrival, p[i].burst,
               p[i].completion, p[i].turnaround, p[i].waiting);
    }
}

int main()
{
    struct Process p[MAX];
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        p[i].pid = i+1;
        printf("\nProcess %d\n", i+1);
        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival);
        printf("Burst Time: ");
        scanf("%d", &p[i].burst);
    }
    fcfs(p, n);
    display(p, n);
    return 0;
}
