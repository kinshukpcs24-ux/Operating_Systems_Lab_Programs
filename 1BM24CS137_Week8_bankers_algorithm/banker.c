#include<stdio.h>

int main()
{
    int n, m, i, j, k;

    printf("Enter number of processes -- ");
    scanf("%d", &n);

    printf("Enter number of resources -- ");
    scanf("%d", &m);

    int allocation[n][m], max[n][m], need[n][m];
    int available[m], work[m];
    int finish[n], safe[n];

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details for P%d\n", i);

        printf("Enter allocation -- ");
        for(j = 0; j < m; j++)
        {
            scanf("%d", &allocation[i][j]);
        }

        printf("Enter Max -- ");
        for(j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter Available Resources -- ");
    for(i = 0; i < m; i++)
    {
        scanf("%d", &available[i]);
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    printf("\nNeed Matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    int pid;

    printf("\nEnter pid (-1 for no request) -- ");
    scanf("%d", &pid);

    if(pid != -1)
    {
        int request[m];

        printf("Enter Request for Resources -- ");

        for(i = 0; i < m; i++)
        {
            scanf("%d", &request[i]);
        }

        for(i = 0; i < m; i++)
        {
            if(request[i] > need[pid][i])
            {
                printf("\nERROR : Process exceeded maximum claim.\n");
                return 0;
            }
        }

        for(i = 0; i < m; i++)
        {
            if(request[i] > available[i])
            {
                printf("\nResources not available. Process must wait.\n");
                return 0;
            }
        }

        for(i = 0; i < m; i++)
        {
            available[i] = available[i] - request[i];
            allocation[pid][i] = allocation[pid][i] + request[i];
            need[pid][i] = need[pid][i] - request[i];
        }
    }


    for(i = 0; i < m; i++)
    {
        work[i] = available[i];
    }

    for(i = 0; i < n; i++)
    {
        finish[i] = 0;
    }

    int count = 0;

    while(count < n)
    {
        int found = 0;

        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                int flag = 1;

                for(j = 0; j < m; j++)
                {
                    if(need[i][j] > work[j])
                    {
                        flag = 0;
                        break;
                    }
                }

                if(flag)
                {
                    for(k = 0; k < m; k++)
                    {
                        work[k] = work[k] + allocation[i][k];
                    }

                    printf("\nP%d is visited ( ", i);

                    for(k = 0; k < m; k++)
                    {
                        printf("%d ", work[k]);
                    }

                    printf(")");

                    finish[i] = 1;

                    safe[count] = i;
                    count++;
                    found = 1;
                }
            }
        }

        if(found == 0)
        {
            break;
        }
    }

    int safeState = 1;

    for(i = 0; i < n; i++)
    {
        if(finish[i] == 0)
        {
            safeState = 0;
            break;
        }
    }

    if(safeState)
    {
        printf("\n\nSYSTEM IS IN SAFE STATE\n");

        printf("The Safe Sequence is -- ( ");

        for(i = 0; i < n; i++)
        {
            printf("P%d ", safe[i]);
        }

        printf(")\n");
    }
    else
    {
        printf("\n\nSYSTEM IS IN UNSAFE STATE\n");
    }

    printf("\nProcess\tAllocation\tMax\t\tNeed\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t", i);

        for(j = 0; j < m; j++)
        {
            printf("%d ", allocation[i][j]);
        }

        printf("\t\t");

        for(j = 0; j < m; j++)
        {
            printf("%d ", max[i][j]);
        }

        printf("\t\t");

        for(j = 0; j < m; j++)
        {
            printf("%d ", need[i][j]);
        }

        printf("\n");
    }

    return 0;
}
