#include <stdio.h>
#include <stdlib.h>
typedef struct process{
    char name[5];
    int bt;
    int at;
    int prt;
    int wt,ta;
    int flag;
} processes;

void b_sort(processes temp[], int n) {
    processes t;
    int i,j;
    for(i=1;i<n;i++) {
        for(j=0;j<n-i;j++) {
            if(temp[j].at > temp[j+1].at) {
                t=temp[j];
                temp[j] = temp[j+1];
                temp[j+1] = t;
            }
        }
    }
}

void FCFS(processes P[], int n) {
    processes temp[10];
    int sumw = 0, sumt = 0;
    int x = 0;
    float avgwt=0.0, avgta=0.0;
    int i,j;
    for(i=0;i<n;i++) {
        temp[i]=P[i];
    }
    b_sort(temp,n);
    printf("\n PROC. \tB.T.\tA.T. ");
    for(i=0;i<n;i++) {
        printf("\n %s\t%d\t%d", temp[i].name,temp[i].bt,temp[i].at);

    }
    sumw = temp[0].wt = 0;
    sumt = temp[0].ta = temp[0].bt - temp[0].at;
    for(i=1;i<n;i++) {
        temp[i].wt=(temp[i-1].bt + temp[i-1].at + temp[i-1].wt) - temp[i].at;;
        temp[i].ta=(temp[i].wt + temp[i].bt);
        sumw+=temp[i].wt;
        sumt+=temp[i].ta;
    }
    avgwt = (float)sumw/n;
    avgta = (float)sumt/n;
    printf("\n\n PROC.\tB.T.\tA.T.\tW.T\tT.A.T");
    for(i=0;i<n;i++) {
        printf("\n %s\t%d\t%d\t%d\t%d",temp[i].name, temp[i].bt,temp[i].at, temp[i].wt, temp[i].ta);
    }
    printf("\n GANTT CHART\n ");
    for(i=0;i<n;i++) {
        printf("   %s   ", temp[i].name);
        printf("\n ");
    }
    printf("0\t");
    for(i=1;i<=n;i++) {
        x=+temp[i=1].bt;
        printf("%d     ",x);
    }
}

int accept(processes P[]) {
    int i,n;
    printf("\n Enter total no. of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        printf("\n PROCESS [%d]", i+1);
        printf("Enter process name: ");
        scanf("%s", &P[i].name);
        printf("Enter burst time: ");
        scanf("%d", &P[i].bt);
        printf("Enter arrival time: ");
        scanf("%d", &P[i].at);
        printf("Enter priority: ");
        scanf("%d", &P[i].prt);
    }
    printf("\n PROC.\tB.T.\tA.T.\tPRIORITY");
    for(i=0;i<n;i++) {
        printf("\n %s\t%d\t%d\t%d", P[i].name,P[i].bt,P[i].at,P[i].prt);
    }
    return n;
}

int main() {
    processes P[10];
    int ch,n;
    do {
        printf("\nCPU SCHEDULING\n");
        printf("\n Options: ");
        printf("\n 0 - Enter process data: ");
        printf("\n 1 - FCFS ");
        printf("\n 2 - SJF (Pre-emptive)");
        printf("\n 3 - SJF (Non Pre-emptive)");
        printf("\n 4 - SRT ");
        printf("\n 5 - Round Robin");
        printf("\n 6 - Priority (Pre-emptive)");
        printf("\n 7 - Priority (Non pre-emptive)");
        printf("\n 8 - Quit");
        switch(ch) {
            case 0:
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
        }
    } while(ch!=8);
}