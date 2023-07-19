#include<stdio.h>
#include<math.h>
 
int sender(int arr[10],int n) {
    int checksum,sum=0,i;
    printf("\nSender Side\n");
    for(i=0;i<n;i++)
    sum+=arr[i];
    printf("Sum is: %d",sum);
    checksum=~sum;   
    printf("\Checksum is:%d",checksum);
    return checksum;
}
 
void receiver(int arr[10],int n,int sch) {
    int checksum,sum=0,i;
    printf("\n\nReciever Side\n");
    for(i=0;i<n;i++)
        sum+=arr[i];
    printf("Sum is:%d",sum);
    sum=sum+sch;
    checksum=~sum; 
    printf("\Checksum is:%d",checksum);
}
 
void main() {
    int n,sch,rch;
    printf("\nEnter size of the string:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array to calculate the checksum:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    sch=sender(arr,n);
    receiver(arr,n,sch);
    printf("21BCE3546");
}
