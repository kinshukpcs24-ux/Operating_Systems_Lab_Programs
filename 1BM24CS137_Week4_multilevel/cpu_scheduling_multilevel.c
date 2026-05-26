#include<stdio.h>

struct Process
{
    int PID;
    int AT;
    int BT;
    int CT;
    int TAT;
    int WT;
};

void main()
{
    int nSys, nUser;
    printf("Enter the number of System processes : ");
    scanf("%d",&nSys);
    printf("Enter the number of User processes : ");
    scanf("%d",&nUser);

    struct Process Sys[nSys];
    struct Process User[nUser];

    for(int i=0; i<nSys; i++)
    {
        printf("Enter arrival time and burst time for system process %d : ",i+1);
        scanf("%d %d",&Sys[i].AT,&Sys[i].BT);
        Sys[i].PID = i+1;
    }

    for(int i=0; i<nUser; i++)
    {
        printf("Enter arrival time and burst time for user process %d : ",i+1);
        scanf("%d %d",&User[i].AT,&User[i].BT);
        User[i].PID = i+1;
    }
    int time = 0;

    if(Sys[0].AT<=User[0].AT)
        time = Sys[0].AT;
    else
        time = User[0].AT;

    int sys_pointer = 0;
    int user_pointer = 0;

    // Now sort both arrays in increasing order of arrival time

    while(sys_pointer<nSys&&user_pointer<nUser)
    {
        if(Sys[sys_pointer].AT<=User[user_pointer].AT)
        {
            time += Sys[sys_pointer].BT;
            Sys[sys_pointer].CT = time;
            Sys[sys_pointer].TAT = Sys[sys_pointer].CT - Sys[sys_pointer].AT;
            Sys[sys_pointer].WT = Sys[sys_pointer].TAT - Sys[sys_pointer].BT;
            sys_pointer++;
        }
        else
        {
            time += User[user_pointer].BT;
            User[user_pointer].CT = time;
            User[user_pointer].TAT = User[user_pointer].CT - User[user_pointer].AT;
            User[user_pointer].WT = User[user_pointer].TAT - User[user_pointer].BT;
            user_pointer++;
        }
    }

    while(sys_pointer<nSys)
    {
        time += Sys[sys_pointer].BT;
        Sys[sys_pointer].CT = time;
        Sys[sys_pointer].TAT = Sys[sys_pointer].CT - Sys[sys_pointer].AT;
        Sys[sys_pointer].WT = Sys[sys_pointer].TAT - Sys[sys_pointer].BT;
        sys_pointer++;
    }

    while(user_pointer<nUser)
    {
        time += User[user_pointer].BT;
        User[user_pointer].CT = time;
        User[user_pointer].TAT = User[user_pointer].CT - User[user_pointer].AT;
        User[user_pointer].WT = User[user_pointer].TAT - User[user_pointer].BT;
        user_pointer++;
    }

    // Now sort both arrays in increasing order of Process ID

    printf("System Processes :\n");
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0; i<nSys; i++)
        printf("PS%d\t%d\t%d\t%d\t%d\t%d\n",i+1,Sys[i].AT,Sys[i].BT,Sys[i].CT,Sys[i].TAT,Sys[i].WT);

    printf("\nUser processes :\n");
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0; i<nUser; i++)
        printf("PU%d\t%d\t%d\t%d\t%d\t%d\n",i+1,User[i].AT,User[i].BT,User[i].CT,User[i].TAT,User[i].WT);
}
