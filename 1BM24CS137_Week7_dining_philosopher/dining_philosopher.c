#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int n;
int hungry[MAX];
int state[MAX];

int can_eat(int i)
{
    int left = (i+n-1)%n;
    int right = (i-1)%n;
    if(state[left]!=2&&state[right]!=2)
        return 1;
    return 0;
}

void one_at_a_time(int h)
{
    for(int i=0; i<h; i++)
    {
        printf("P%d is waiting \n",hungry[i]);
    }
    for(int i=0; i<h; i++)
    {
        int p = hungry[i] - 1;
        if(can_eat(p))
        {
            state[p] = 2;
            printf("P%d is granted to eat\n",hungry[i]);
            printf("P%d has finished eating\n",hungry[i]);
            state[p] = 0;
        }
    }
}

void two_at_a_time(int h)
{
    int count = 0;
    for(int i=0; i<h; i++)
    {
        printf("P%d is waiting \n",hungry[i]);
    }
    for(int i=0; i<h; i++)
    {
        int p = hungry[i]-1;
        if(can_eat(p))
        {
            state[p] = 2;
            printf("P%d is granted to eat\n",hungry[i]);
            count++;
        }
    }
    for(int i=0; i<h; i++)
    {
        int p = hungry[i]-1;
        if(state[p]==2)
        {
            printf("P%d has finished eating\n",hungry[i]);
            state[p] = 0;
        }
    }
}

int main()
{
    int h, choice;
    printf("Enter total number of philosophers : ");
    scanf("%d",&n);

    printf("How many are hungry : ");
    scanf("%d",&h);

    printf("Print positions : ");
    for(int i=0; i<h; i++)
    {
        scanf("%d",&hungry[i]);
    }
    while(1)
    {
        printf("\n1. One can eat at a time\n2. Two can eat at a time\n3. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("One philosopher\n");
                    one_at_a_time(h);
                    break;
            case 2: printf("Two philosophers\n");
                    two_at_a_time(h);
                    break;
            case 3: exit(0);
            default: printf("Invalid");
        }
    }
}
