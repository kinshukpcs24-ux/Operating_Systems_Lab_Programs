#include <stdio.h>

int main()
{
    int n, i, completed = 0, currentTime = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int process[n], arrival[n], burst[n], waiting[n], turnaround[n], completion[n], done[n];

    for (i = 0; i < n; i++)
    {
        process[i] = i + 1;
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &arrival[i]);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst[i]);
        done[i] = 0;
    }

    while (completed < n)
    {
        int idx = -1;
        int minBurst = 9999;

        for (i = 0; i < n; i++)
        {
            if (!done[i] && arrival[i] <= currentTime && burst[i] < minBurst)
            {
                minBurst = burst[i];
                idx = i;
            }
        }

        if (idx == -1)
        {
            currentTime++;
        }
        else
        {
            currentTime += burst[idx];
            completion[idx] = currentTime;
            turnaround[idx] = completion[idx] - arrival[idx];
            waiting[idx] = turnaround[idx] - burst[idx];
            done[idx] = 1;
            completed++;
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", process[i], arrival[i], burst[i], completion[i], turnaround[i], waiting[i]);
    }
    return 0;
}
