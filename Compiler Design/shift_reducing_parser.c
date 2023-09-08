#include<stdio.h>
#include<string.h>

int k=0,z=0,i=0,j=0,c=0;
char a[16],ac[20],stack[15],act[10];
void check();

int main() {
    printf("By:21BCE3546\n");
    printf("GRAMMAR is \n E->E+E \n E->E*E \n E->(E) \n E->id");
    puts("\nEnter input string: ");
    scanf("%s",a);
    c=strlen(a);
    strcpy(act,"SHIFT->");
    printf("stack \t input \t action");
    for(k=0,i=0; j<c; k++,i++,j++) {
        if(a[j]=='i' && a[j+1]=='d') {
            stack[i]=a[j];
            stack[i+1]=a[j+1];
            stack[i+2]='\0';
            a[j]=' ';
            a[j+1]=' ';
            printf("\n$%s\t%s$\t%sid",stack,a,act);
            check();
        } else {
            stack[i]=a[j];
            stack[i+1]='\0';
            a[j]=' ';
            printf("\n$%s\t%s$\t%ssymbols",stack,a,act);
            check();
        }
    }
}

void check() {
    strcpy(ac,"REDUCE TO E");
    for(z=0; z<c; z++)
        if(stack[z]=='i' && stack[z+1]=='d') {
            stack[z]='E';
            stack[z+1]='\0';
            printf("\n$%s\t%s$\t%s",stack,a,ac);
            j++;
        }
        for(z=0; z<c; z++)
            if(stack[z]=='E' && stack[z+1]=='+' && stack[z+2]=='E') {
                stack[z]='E';
                stack[z+1]='\0';
                stack[z+2]='\0';
                printf("\n$%s\t%s$\t%s",stack,a,ac);
                i=i-2;
            }
        for(z=0; z<c; z++)
            if(stack[z]=='E' && stack[z+1]=='*' && stack[z+2]=='E') {
                stack[z]='E';
                stack[z+1]='\0';
                stack[z+1]='\0';
                printf("\n$%s\t%s$\t%s",stack,a,ac);
                i=i-2;
            }
        for(z=0; z<c; z++)
            if(stack[z]=='(' && stack[z+1]=='E' && stack[z+2]==')') {
                stack[z]='E';
                stack[z+1]='\0';
                stack[z+1]='\0';
                printf("\n$%s\t%s$\t%s",stack,a,ac);
                i=i-2;
            }
}
