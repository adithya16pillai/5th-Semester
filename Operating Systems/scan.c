#include<stdio.h>
int absoluteValue(int);

void main() {
    int queue[25],n,head,i,j,k,seek=0,max,diff,temp,queue1[20],queue2[20],temp1=0,temp2=0;
    float averageSeekTime;
    printf("Enter the maximum range of Disk: ");
    scanf("%d",&max);
    printf("\nEnter the number of queue requests: ");
    scanf("%d",&n);
    printf("\nEnter the initial head position: ");
    scanf("%d",&head);
    printf("\nEnter the disk positions to be read(queue): ");
    for(i=1;i<=n;i++)  {
        scanf("%d",&temp);  
        if(temp>head) {
            queue1[temp1]=temp; 
            temp1++;
        } else {   
            queue2[temp2]=temp;
            temp2++;
        }
    }
    for(i=0;i<temp1-1;i++) {
        for(j=i+1;j<temp1;j++) {
            if(queue1[i]>queue1[j]) {
                temp=queue1[i];
                queue1[i]=queue1[j];
                queue1[j]=temp;
            }
        }
    }
    for(i=0;i<temp2-1;i++) {
        for(j=i+1;j<temp2;j++) {
            if(queue2[i]<queue2[j]) {
                temp=queue2[i];
                queue2[i]=queue2[j];
                queue2[j]=temp;
            }
        }
    }    
    for(i=1,j=0;j<temp1;i++,j++) {
        queue[i]=queue1[j]; 
    }
    queue[i]=max;
    for(i=temp1+2,j=0;j<temp2;i++,j++) {
        queue[i]=queue2[j];
    }
    queue[i]=0;
    queue[0]=head;
    for(j=0; j<=n; j++)  {   
        diff = absoluteValue(queue[j+1]-queue[j]);
        seek = seek + diff;
        printf("\nDisk head moves from position %d to %d with Seek %d \n", queue[j], queue[j+1], diff);
    }
    averageSeekTime = seek/(float)n;
    printf("\nTotal Seek Time= %d\n", seek);
    printf("\nAverage Seek Time= %f\n", averageSeekTime);
}

int absoluteValue(int x) {
    if(x>0) {
        return x;
    } else {
        return x*-1;
    }
}
