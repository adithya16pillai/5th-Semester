#include <stdio.h>
#include <stdlib.h>

int main() {
    int r[1][10], available[1][10];
    int allocation[10][10], maximum[10][10], need[10][10], w[10], safe[10];
    int i=0, j=0, k=0, l=0, process=0, resource=0, count=0, cnt=0;
    printf("Enter the number of processes in the system: ");
    scanf("%d", &process);
    printf("Enter the number of resources in the system: ");
    scanf("%d",&resource);
    for(i=1; i<=resource; i++) {
        printf("Enter no. of instances of resource R%d: " ,i);
        scanf("%d", &r[0][i]);
        available[0][i] = r[0][i];
    }
    printf("Enter the allocation matrix:\n");
    for(i=1; i<=process; i++) {
        for(j=1; j<=resource; j++) {
            scanf("%d", &allocation[i][j]);
            available[0][j] = available[0][j] - allocation[i][j];
        }
    }
    printf("Enter the maximum matrix:\n");
    for(i=1; i<=process; i++) {
        for(j=1; j<=resource; j++) {
            scanf("%d",&maximum[i][j]);
        }
    }
    for(i=1; i<=process; i++) { // Calculating need matrix
        for(j=1; j<=resource; j++) {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
    for(i=1; i<=process; i++) {
        printf("Process P%d\n", i);
        for(j=1; j<=resource; j++) {
            printf("Allocated: %d\t",allocation[i][j]);
            printf("Maximum: %d\t",maximum[i][j]);
            printf("Need: %d\t",need[i][j]);
        }
        printf("\n");
    }
    printf("\nAvailability:\n");
    for(i=1; i<=resource; i++) {
        printf("R%d %d\t", i, available[0][i]);
    }
    printf("\n");
    printf("\nSafe sequence:\n");
    for(count=1; count<=process; count++) {
        for(i=1; i<=process; i++) {
            cnt = 0;
            for(j=1; j<=resource; j++) {
                if(need[i][j] <= available[0][j] && w[i]==0) {
                    cnt++;
                }
            }
            if(cnt == resource) {
                k++;
                safe[k] = i;
                for(l=1; l<=resource; l++) {
                    available[0][l] = available[0][l] + allocation[i][l];
                }
                printf("P%d ",safe[k]);
                printf("\tAvailability: ");
                for(l=1; l<=resource; l++) {
                    printf("R%d %d\t", l, available[0][l]);
                }
                w[i]=1;
            }
        }
    }
    return 0;
}
