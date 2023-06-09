#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int i,j,n,head,temp=0;
    float avg;
    printf("Enter the number of tracks: ");
    scanf("%d",&n);
    int queue[n+1];
    printf("Enter the track positions: ");
    for(i=0;i<n;i++)
        scanf("%d",&queue[i]);
    printf("Enter the head position: ");
    scanf("%d",&head);
    queue[n]=head;
    n++;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(queue[i]>queue[j])
            {
                temp=queue[i];
                queue[i]=queue[j];
                queue[j]=temp;
            }
        }
    }
    int distance=0;
    for(i=0;i<n;i++)
    {
        if(queue[i]==head)
        {
            for(j=i;j>=0;j--)
            {
                printf("%d -> ",queue[j]);
                distance+=abs(head-queue[j]);
                head=queue[j];
            }
            for(j=i+1;j<n;j++)
            {
                printf("%d -> ",queue[j]);
                distance+=abs(head-queue[j]);
                head=queue[j];
            }
        }
    }
    avg=(float)distance/(float)n;
    printf("\nAverage head movement: %.2f\n",avg);
    return 0;
}

