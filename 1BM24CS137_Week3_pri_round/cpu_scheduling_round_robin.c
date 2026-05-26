#include<stdio.h>

struct Process
{
    int PID;
    int AT;
    int BT;
    int TL;
    int CT;
    int TAT;
    int WT;
    int COMPLETE;
};

void main()
{
    int N, TQ;
    printf("Enter the number of processes : ");
    scanf("%d",&N);
    printf("Enter time quantum : ");
    scanf("%d",&TQ);

    struct Process P[N];

    int i=0;
    for(i=0; i<N; i++)
    {
        printf("Enter arrival time and burst time of process %d : ",i+1);
        scanf("%d %d",&P[i].AT,&P[i].BT);
        P[i].TL = P[i].BT;
        P[i].COMPLETE = 0;
        P[i].PID = i+1;
    }

    int cumulative_time = 0;
    int completion_flag = 0;

    do
    {
        if(P[i].TL<TQ&&P[i].TL>0)
        {
            cumulative_time += P[i].TL;
            P[i].TL = 0;
            P[i].CT = cumulative_time;
            P[i].COMPLETE = 1;
            i++;
        }
        else
        {
            P[i].TL -= TQ;
            cumulative_time += TQ;
            i++;
        }
        if(i==N)
            i=0;
        for(int j=0; j<N; j++)
        {
            completion_flag += P[j].COMPLETE;
        }
        if(completion_flag<N)
            completion_flag = 0;

    }while(completion_flag!=N);

    for(i=0; i<N; i++)
    {
        P[i].TAT = P[i].CT - P[i].AT;
        P[i].WT = P[i].TAT - P[i].BT;
    }

    printf("\nProcess\tAT\tBT\CT\tTAT\tWT\n");
    for(i=0; i<N; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,P[i].AT,P[i].BT,P[i].CT,P[i].TAT,P[i].WT);
}
