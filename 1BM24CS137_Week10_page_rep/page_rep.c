#include <stdio.h>

void fifo(int pages[], int n, int frames)
{
  int frame[10], index = 0, faults = 0, flag;
  for(int i = 0; i < frames; i++)
    frame[i] = -1;
  for(int i = 0; i < n; i++)
  {
    flag = 0;
    for(int j = 0; j < frames; j++)
    {
      if(frame[j] == pages[i])
      {
        flag = 1;
        break;
      }
    }
    if(flag == 0)
    {
      frame[index] = pages[i];
      index = (index + 1) % frames;
      faults++;
    }
  }
  printf("\nFIFO Page Faults = %d\n", faults);
}

void lru(int pages[], int n, int frames)
{
  int frame[10], time[10];
  int faults = 0, count = 0, flag;
  for(int i = 0; i < frames; i++)
  {
    frame[i] = -1;
    time[i] = 0;
  }
  for(int i = 0; i < n; i++)
  {
    flag = 0;
    for(int j = 0; j < frames; j++)
    {
      if(frame[j] == pages[i])
      {
        count++;
        time[j] = count;
        flag = 1;
        break;
      }
    }
    if(flag == 0)
    {
      int pos = 0;
      for(int j = 1; j < frames; j++)
      {
        if(time[j] < time[pos])
        pos = j;
      }
      count++;
      frame[pos] = pages[i];
      time[pos] = count;
      faults++;
    }
  }
  printf("LRU Page Faults = %d\n", faults);
}

void optimal(int pages[], int n, int frames)
{
  int frame[10];
  int faults = 0, flag;
  for(int i = 0; i < frames; i++)
  frame[i] = -1;
  for(int i = 0; i < n; i++)
  {
    flag = 0;
    for(int j = 0; j < frames; j++)
    {
      if(frame[j] == pages[i])
      {
        flag = 1;
        break;
      }
    }
    if(flag == 0)
    {
      int pos = -1, farthest = i;
      for(int j = 0; j < frames; j++)
      {
        int k;
        for(k = i + 1; k < n; k++)
        {
          if(frame[j] == pages[k])
          {
            if(k > farthest)
            {
              farthest = k;
              pos = j;
            }
            break;
          }
        }
        if(k == n)
        {
          pos = j;
          break;
        }
      }
      if(pos == -1)
        pos = 0;
      frame[pos] = pages[i];
      faults++;
    }
  }
  printf("Optimal Page Faults = %d\n", faults);
}

int main()
{
  int n, frames;
  printf("Enter number of pages: ");
  scanf("%d", &n);
  int pages[50];
  printf("Enter page reference string:\n");
  for(int i = 0; i < n; i++)
    scanf("%d", &pages[i]);
  printf("Enter number of frames: ");
  scanf("%d", &frames);
  
  fifo(pages, n, frames);
  lru(pages, n, frames);
  optimal(pages, n, frames);
  return 0;
}
