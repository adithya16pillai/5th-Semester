#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct process {
    int id,AT,WT,TT,BT,PR,PT;
};

struct process a[10];

int FCFS() {
    int n;
    int burst=0,cmpl_T;
    float Avg_WT,Avg_TT,Total=0;
    printf("Enter number of process\n");
    scanf("%d",&n);
    printf("Enter Arrival time and Burst time of the process\n");
    printf("At BT\n");
    for(int i=0;i<n;i++) {
        scanf("%d%d",&a[i].AT,&a[i].BT);
    }
    for(int i=0;i<n;i++) {
        if(i==0)
            a[i].WT=a[i].AT;
        else
            a[i].WT=burst-a[i].AT;
        burst+=a[i].BT;
        Total+=a[i].WT;
    }
    Avg_WT=Total/n;
    cmpl_T=0;
    Total=0;
    for(int i=0;i<n;i++) {
        cmpl_T+=a[i].BT;
        a[i].TT=cmpl_T-a[i].AT;
        Total+=a[i].TT;
    }
    Avg_TT=Total/n;
    printf("Process ,  Waiting_time ,  TurnA_time\n");
    for(int i=0;i<n;i++) {
        printf("%d\t\t%d\t\t%d\n",i+1,a[i].WT,a[i].TT);
    }
    printf("Average waiting time is : %f\n",Avg_WT);
    printf("Average turn around time is : %f\n",Avg_TT);
    return 0;
}

void swap(int *b,int *c) {
    int tem;
    tem=*c;
    *c=*b;
    *b=tem;
}

int queue[100];
int front=-1;
int rear=-1;

void insert(int n) {
    if(front==-1)
     front=0;
    rear=rear+1;
    queue[rear]=n;
}

int delete() {
    int n;
    n=queue[front];
    front=front+1;
    return n;
}

int SRT() {
    int a[10],b[10],x[10],i,j,smallest,count=0,time,n;
    double avg=0,tt=0,end;
    printf("enter the number of Processes:\n");
    scanf("%d",&n); 
    printf("enter arrival time\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("enter burst time\n");
    for(i=0;i<n;i++)
        scanf("%d",&b[i]); 
    for(i=0;i<n;i++)
        x[i]=b[i];

    b[9]=9999;
  
    for(time=0;count!=n;time++) {
        smallest=9;
        for(i=0;i<n;i++) {
            if(a[i]<=time && b[i]<b[smallest] && b[i]>0 )
                smallest=i;
        }
        b[smallest]--;
        if(b[smallest]==0) {
            count++;
            end=time+1;
            avg=avg+end-a[smallest]-x[smallest];
            tt= tt+end-a[smallest];
        }
    }
    printf("\n\nAverage waiting time = %lf\n",avg/n);
    printf("Average Turnaround time = %lf",tt/n);
    return 0;
}

int RR() {
    int n,TQ,p,TIME=0;
    int temp[10],exist[10]={0};
    float total_wt=0,total_TT=0,Avg_WT,Avg_TT;
    printf("Enter the number of the process\n");
    scanf("%d",&n);
    printf("Enter the arrival time and burst time of the process\n");
    printf("AT BT\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].AT,&a[i].BT);
        a[i].id=i;
        temp[i]=a[i].BT;
    }
    printf("Enter the time quantum\n");
    scanf("%d",&TQ);
    insert(0);
    exist[0]=1;
    while(front<=rear) {
        p=delete();
        if(a[p].BT>=TQ) {
            a[p].BT=a[p].BT-TQ;
            TIME=TIME+TQ;
        } else {
            TIME=TIME+a[p].BT;
            a[p].BT=0;
        }
        for(int i=0;i<n;i++) {
            if(exist[i]==0 && a[i].AT<=TIME) {
                insert(i);
                exist[i]=1;
            }
        }
        if(a[p].BT==0) {
            a[p].TT=TIME-a[p].AT;
            a[p].WT=a[p].TT-temp[p];
            total_TT=total_TT+a[p].TT;
            total_wt=total_wt+a[p].WT;
        } else {
            insert(p);
        }
    }
    Avg_TT=total_TT/n;
    Avg_WT=total_wt/n;
    printf("ID WT TAT\n");
    for(int i=0;i<n;i++) {
        printf("%d  %d  %d\n",a[i].id,a[i].WT,a[i].TT);
    }
    printf("Average waiting time of the processes is : %f\n",Avg_WT);
    printf("Average turn around time of the processes is : %f\n",Avg_TT);
    return 0;
}

int SJF_PREEMPTIVE() {
    int n,temp[10];
    int count=0,t=0,short_P;
    float total_WT=0, total_TT=0,Avg_WT,Avg_TT;
    printf("Enter the number of the process\n");
    scanf("%d",&n);
    printf("Enter the arrival time and burst time of the process\n");
    printf("AT WT\n");
    for(int i=0;i<n;i++) {
        scanf("%d%d",&a[i].AT,&a[i].BT);
        temp[i]=a[i].BT;
    }
    a[9].BT=10000;
    for(t=0;count!=n;t++) {
        short_P=9;
        for(int i=0;i<n;i++) {
            if(a[i].BT<a[short_P].BT && (a[i].AT<=t && a[i].BT>0)) {
                short_P=i;
            }
        }
        a[short_P].BT=a[short_P].BT-1;
        if(a[short_P].BT==0) {
            count++;
            a[short_P].WT=t+1-a[short_P].AT-temp[short_P];
            a[short_P].TT=t+1-a[short_P].AT;
            total_WT=total_WT+a[short_P].WT;
            total_TT=total_TT+a[short_P].TT;
        }
    }
    Avg_WT=total_WT/n;
    Avg_TT=total_TT/n;
    printf("Id WT TT\n");
    for(int i=0;i<n;i++) {
        printf("%d\t%d\t%d\n",i+1,a[i].WT,a[i].TT);
    }
    printf("Avg waiting time of the process is %f\n",Avg_WT);
    printf("Avg turn around time of the process %f\n",Avg_TT);
    
}

int SJF_NONPREEMPTIVE() {
    int n,check_ar=0;
    int Cmp_time=0;
    float Total_WT=0,Total_TT=0,Avg_WT,Avg_TT;
    printf("Enter the number of process \n");
    scanf("%d",&n);
    printf("Enter the Arrival time and Burst time of the process\n");
    printf("AT BT\n");
    for(int i=0;i<n;i++) {
        scanf("%d%d",&a[i].AT,&a[i].BT);
        a[i].id=i+1;
        if(i==0)
            check_ar=a[i].AT;
        if(check_ar!=a[i].AT )
            check_ar=1; 
    }
    if(check_ar!=0) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n-i-1;j++) {
                if(a[j].AT>a[j+1].AT) {
                    swap(&a[j].id,&a[j+1].id);
                    swap(&a[j].AT,&a[j+1].AT);
                    swap(&a[j].BT,&a[j+1].BT);
                }
            }
        }
    }
    if(check_ar!=0) {
        a[0].WT=a[0].AT;
        a[0].TT=a[0].BT-a[0].AT;
        Cmp_time=a[0].TT;
        Total_WT=Total_WT+a[0].WT;
        Total_TT=Total_TT+a[0].TT;
        for(int i=1;i<n;i++) {
            int min=a[i].BT;
            for(int j=i+1;j<n;j++) {
                if(min>a[j].BT && a[j].AT<=Cmp_time) {
                    min=a[j].BT;
                    swap(&a[i].id,&a[j].id);
                    swap(&a[i].AT,&a[j].AT);
                    swap(&a[i].BT,&a[j].BT);
                }
            }
            a[i].WT=Cmp_time-a[i].AT;
            Total_WT=Total_WT+a[i].WT;
            Cmp_time=Cmp_time+a[i].BT;
            a[i].TT=Cmp_time-a[i].AT;
            Total_TT=Total_TT+a[i].TT;
        }
    } else {
        for(int i=0;i<n;i++) {
            int min=a[i].BT;
            for(int j=i+1;j<n;j++) {
                if(min>a[j].BT && a[j].AT<=Cmp_time) {
                    min=a[j].BT;
                    swap(&a[i].id,&a[j].id);
                    swap(&a[i].AT,&a[j].AT);
                    swap(&a[i].BT,&a[j].BT);
                }
            }
            a[i].WT=Cmp_time-a[i].AT;
            Cmp_time=Cmp_time+a[i].BT;
            a[i].TT=Cmp_time-a[i].AT;
            Total_WT=Total_WT+a[i].WT;
            Total_TT=Total_TT+a[i].TT;
        }
    }
    Avg_WT=Total_WT/n;
    Avg_TT=Total_TT/n;
    printf("The process are\n");
    printf("ID WT TT\n");
    for(int i=0;i<n;i++) {
        printf("%d\t%d\t%d\n",a[i].id,a[i].WT,a[i].TT);
    }
    printf("Avg waiting time is:- %f\n",Avg_WT);
    printf("Avg turn around time is:- %f",Avg_TT);
    return 0;
}

int PRIOR_SC_PREEMPTIVE() {
    int n,temp[10],t,count=0,short_p;
    float total_WT=0,total_TT=0,Avg_WT,Avg_TT;
    printf("Enter the number of the process\n");
    scanf("%d",&n);
    printf("Enter the arrival time , burst time and priority of the process\n");
    printf("AT BT PT\n");
    for(int i=0;i<n;i++) {
        scanf("%d%d%d",&a[i].AT,&a[i].BT,&a[i].PT);
        temp[i]=a[i].BT;
    }
    a[9].PT=10000;
    for(t=0;count!=n;t++) {
        short_p=9;
        for(int i=0;i<n;i++) {
            if(a[short_p].PT>a[i].PT && a[i].AT<=t && a[i].BT>0) {
                short_p=i;
            }
        }
        a[short_p].BT=a[short_p].BT-1;
        if(a[short_p].BT==0) {
            count++;
            a[short_p].WT=t+1-a[short_p].AT-temp[short_p];
            a[short_p].TT=t+1-a[short_p].AT;
            total_WT=total_WT+a[short_p].WT;
            total_TT=total_TT+a[short_p].TT;
        }
    }
    Avg_WT=total_WT/n;
    Avg_TT=total_TT/n;
    printf("ID WT TT\n");
    for(int i=0;i<n;i++) {
        printf("%d %d\t%d\n",i+1,a[i].WT,a[i].TT);
    }
    printf("Avg waiting time of the process  is %f\n",Avg_WT);
    printf("Avg turn around time of the process is %f\n",Avg_TT);

    return 0;
}

int PRIOR_SC_NONPREEMPTIVE() {
    int n,check_ar=0;
    int Cmp_time=0;
    float Total_WT=0,Total_TT=0,Avg_WT,Avg_TT;
    printf("Enter the number of process \n");
    scanf("%d",&n);
    printf("Enter the Arrival time , Burst time and priority of the process\n");
    printf("AT BT PR\n");
    for(int i=0;i<n;i++) {
        scanf("%d%d%d",&a[i].AT,&a[i].BT,&a[i].PR);
        a[i].id=i+1;
        if(i==0)
         check_ar=a[i].AT;
         
        if(check_ar!=a[i].AT )
         check_ar=1;   
    }
    if(check_ar!=0) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n-i-1;j++) {
                if(a[j].AT>a[j+1].AT) {
                    swap(&a[j].id,&a[j+1].id);
                    swap(&a[j].AT,&a[j+1].AT);
                    swap(&a[j].BT,&a[j+1].BT);
                    swap(&a[j].PR,&a[j+1].PR);
                }
            }
        }
    }
    if(check_ar!=0) {
        a[0].WT=a[0].AT;
        a[0].TT=a[0].BT-a[0].AT;
        Cmp_time=a[0].TT;
        Total_WT=Total_WT+a[0].WT;
        Total_TT=Total_TT+a[0].TT;
        for(int i=1;i<n;i++) {
            int min=a[i].PR;
            for(int j=i+1;j<n;j++) {
                if(min>a[j].PR && a[j].AT<=Cmp_time) {
                    min=a[j].PR;
                    swap(&a[i].id,&a[j].id);
                    swap(&a[i].AT,&a[j].AT);
                    swap(&a[i].BT,&a[j].BT);
                    swap(&a[i].PR,&a[j].PR); 
                }  
            }
            a[i].WT=Cmp_time-a[i].AT;
            Total_WT=Total_WT+a[i].WT;
            Cmp_time=Cmp_time+a[i].BT;
            a[i].TT=Cmp_time-a[i].AT;
            Total_TT=Total_TT+a[i].TT;
        }
    } else {
        for(int i=0;i<n;i++) {
            int min=a[i].PR;
            for(int j=i+1;j<n;j++) {
                if(min>a[j].PR && a[j].AT<=Cmp_time) {
                    min=a[j].PR;
                    swap(&a[i].id,&a[j].id);
                    swap(&a[i].AT,&a[j].AT);
                    swap(&a[i].BT,&a[j].BT);
                    swap(&a[i].PR,&a[j].PR);
                }
            }
            a[i].WT=Cmp_time-a[i].AT;
            Cmp_time=Cmp_time+a[i].BT;
            a[i].TT=Cmp_time-a[i].AT;
            Total_WT=Total_WT+a[i].WT;
            Total_TT=Total_TT+a[i].TT;
        }
    }
    Avg_WT=Total_WT/n;
    Avg_TT=Total_TT/n;
    printf("The process are\n");
    printf("ID WT TAT\n");
    for(int i=0;i<n;i++) {
        printf("%d\t%d\t%d\n",a[i].id,a[i].WT,a[i].TT);
    }
    printf("Avg waiting time is: %f\n",Avg_WT);
    printf("Avg turn around time is: %f",Avg_TT);
    return 0;
}

int main() {
    int ch,n;
    do {
        printf("\nCPU SCHEDULING\n");
        printf("\n Options: ");
        printf("\n1 - FCFS ");
        printf("\n2 - SJF (Preemptive)");
        printf("\n3 - SJF (Non Preemptive)");
        printf("\n4 - SRT ");
        printf("\n5 - Round Robin");
        printf("\n6 - Priority (Preemptive)");
        printf("\n7 - Priority (Non preemptive)");
        printf("\n8 - Quit\n");
        printf("\nYour choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                FCFS(); 
                break;
            case 2:
                SJF_PREEMPTIVE();
                break;
            case 3:
                SJF_NONPREEMPTIVE();
                break;
            case 4:
                SRT();
                break;
            case 5:
                RR();
                break;
            case 6:
                PRIOR_SC_PREEMPTIVE();
                break;
            case 7:
                PRIOR_SC_NONPREEMPTIVE();
                break;
            case 8:
                exit;
                break;
            default:
                printf("\nInvalid Choice!\n");
        }
    } while(ch!=8);
    return 0;
}
