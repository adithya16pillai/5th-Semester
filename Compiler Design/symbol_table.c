#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

void main() {
    int x=0, n, i=0,j=0;
    void *mypointer,*arr[5];
    char ch,arr_search,arr2[15],arr3[15],c;
    printf("Input the expression (Place '$' in the end): ");
    while((c=getchar())!='$') {
        arr2[i]=c;
        i++;
    }
    n=i-1;
    printf("Given Expression:");
    i=0;
    while(i<=n) {
        printf("%c",arr2[i]);
    i++;
    }
    printf("\n");
    printf("\n          Symbol Table          \n");
    printf("\nSymbol \t Address \t Type");
    while(j<=n) {
        c=arr2[j];
        if(isalpha(toascii(c))) {
            mypointer=malloc(c);
            arr[x]=mypointer;
            arr3[x]=c;
            printf("\n%c \t %d \t Identifier\n",c,mypointer);
            x++;
            j++;
        } else {
            ch=c;
            if(ch=='+'||ch=='-'||ch=='*'||ch=='=') {
                mypointer=malloc(ch);
                arr[x]=mypointer;
                arr3[x]=ch;
                printf("\n %c \t %d \t Operator\n",ch,mypointer);
                x++;
                j++;
            }
        }
   }
}
