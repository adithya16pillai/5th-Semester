// For Grammar :
// S -> aA | bB
// A -> bS | c
// B -> aS | c

#include <stdio.h>
#include <string.h>
char stack[1000], parseString[1000];
int stackPos = 0, parsingPos = 0;
void addToStack(char ch) { 
    stack[stackPos++] = ch; 
}

void S() {
    if (parseString[parsingPos] == 'a') {
        addToStack('a');
        parsingPos++;
        A();
    } else if (parseString[parsingPos] == 'b') {
        addToStack('b');
        parsingPos++;
        B();
    }
    addToStack('S');
}

void A() {
    if (parseString[parsingPos] == 'b') {
        addToStack('b');
        parsingPos++;
        S();
    } else if (parseString[parsingPos] == 'c') {
        addToStack('c');
        parsingPos++;
    }
    addToStack('A');
}

void B() {
    if (parseString[parsingPos] == 'a') {
        addToStack('a');
        parsingPos++;
        S();
    } else if (parseString[parsingPos] == 'c') {
        addToStack('c');
        parsingPos++;
    }
    addToStack('B');
}

int main() {
    printf("Enter the string to be parsed : ");
    scanf("%s", parseString);
    S();
    if (parseString[parsingPos] == '\0') {
        printf("Accepted\nParse Tree (POSTFIX) : ");
        for (int i = 0; i < stackPos; i++)
            printf("%c ", stack[i]);
    } else
        printf("Rejected");
}
