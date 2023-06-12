#include<stdio.h>  
#include<string.h>  
#define SIZE 20 //Defining Global variable   

int main () {  
    char non_terminal;  
    char beta,alpha;  
    int n;  
    char pro[10][SIZE];  //Production
    int index=3; //The starting of the string after '->' which is the the third character
    printf("BY: 21BCE3546\n");
    printf("Enter Number of Production: ");  
    scanf("%d",&n);  
    printf("Enter the grammar:\n");  //Format: E->E|A
    for(int i=0;i<n;i++){  
        scanf("%s",pro[i]);  
    }  
    for(int i=0;i<n;i++){  
        printf("\nGrammar : %s",pro[i]);  
        non_terminal=pro[i][0];  //The first character in the grammar
        if(non_terminal==pro[i][index]) {  //Condition to check if production is left recursive
            alpha=pro[i][index+1];  
            printf(" is left recursive.\n");  
            while(pro[i][index]!=0 && pro[i][index]!='|')  //Checks for vertical bar
                index++;  
                if(pro[i][index]!=0) {  
                    beta=pro[i][index+1];  
                    //Shows the output without left recursion (after elimnation)
                    printf("Grammar after elimnation of left recursion:\n");  
                    printf("%c->%c%c\'",non_terminal,beta,non_terminal);  
                    printf("\n%c\'->%c%c\'|E\n",non_terminal,alpha,non_terminal);  
                }  
                else  
                    printf(" Can not be reduced\n");  
        }  
        else  
            printf(" is not left recursive.\n");  
            index=3;  
    }  
}