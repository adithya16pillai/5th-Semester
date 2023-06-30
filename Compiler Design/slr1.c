#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAX_INPUT_SIZE 100

typedef struct {
    char left;
    char right[10];
} ProductionRule;

typedef struct {
    int top;
    char items[MAX_STACK_SIZE];
} Stack;

typedef struct {
    char nonTerminal;
    char terminal;
    char action[10];
} ParseTableEntry;

void slrParser(char *inputString, ParseTableEntry *parseTable, ProductionRule *productionRules, int numRules) {
    Stack stack;
    stack.top = -1;
    stack.items[++stack.top] = '0';
    int inputIndex = 0;
    bool done = false;
    printf("\nParsing Steps:\n");
    printf("--------------------------------------------------------\n");
    printf("Stack\t\t\tInput\t\t\tAction\n");
    printf("--------------------------------------------------------\n");
    while (!done) {
        char currentState = stack.items[stack.top];
        char currentInputSymbol = inputString[inputIndex];
        int tableIndex = -1;
        for (int i = 0; i < numRules; i++) {
            if (parseTable[i].nonTerminal == currentState && parseTable[i].terminal == currentInputSymbol) {
                tableIndex = i;
                break;
            }
        }
        if (tableIndex == -1) {
            printf("\nError: Invalid input symbol '%c' at position %d\n", currentInputSymbol, inputIndex);
            break;
        }
        char action = parseTable[tableIndex].action[0];
        if (action == 's') {
            stack.items[++stack.top] = currentInputSymbol;
            stack.items[++stack.top] = parseTable[tableIndex].action[1];
            inputIndex++;
        } else if (action == 'r') {
            int ruleIndex = parseTable[tableIndex].action[1] - '0';
            ProductionRule rule = productionRules[ruleIndex];

            for (int i = 0; i < strlen(rule.right) * 2; i++) {
                stack.top--;
            }
            currentState = stack.items[stack.top];
            int newStateIndex = -1;
            for (int i = 0; i < numRules; i++) {
                if (parseTable[i].nonTerminal == currentState && parseTable[i].terminal == rule.left) {
                    newStateIndex = i;
                    break;
                }
            }
            stack.items[++stack.top] = rule.left;
            stack.items[++stack.top] = parseTable[newStateIndex].action[0];
        } else if (action == 'a') {
            done = true;
        }
        printf("%s\t\t\t%s\t\t\t%c -> %s\n", stack.items, &inputString[inputIndex], currentState, parseTable[tableIndex].action);
    }
    printf("--------------------------------------------------------\n");
    if (done) {
        printf("\nParsing successful!\n");
    } else {
        printf("\nParsing failed!\n");
    }
}

int main() {
    ParseTableEntry parseTable[] = {
        {'0', 'i', "s5"},
        {'0', 'E', "1"},
        {'1', '+', "s4"},
        {'1', '$', "a"},
        {'2', '+', "r2"},
        {'2', '*', "s6"},
        {'2', ')', "r2"},
        {'2', '$', "r2"},
        {'3', '+', "r4"},
        {'3', '*', "r4"},
        {'3', ')', "r4"},
        {'3', '$', "r4"},
        {'4', 'i', "s5"},
        {'4', 'E', "7"},
        {'5', '+', "r6"},
        {'5', '*', "r6"},
        {'5', ')', "r6"},
        {'5', '$', "r6"},
        {'6', 'i', "s5"},
        {'6', 'E', "8"},
        {'7', '+', "s4"},
        {'7', ')', "s9"},
        {'8', '+', "r1"},
        {'8', '*', "s6"},
        {'8', ')', "r1"},
        {'8', '$', "r1"},
        {'9', '+', "r3"},
        {'9', '*', "r3"},
        {'9', ')', "r3"},
        {'9', '$', "r3"},
    };
    ProductionRule productionRules[] = {
        {'E', "E+T"},
        {'E', "T"},
        {'T', "T*F"},
        {'T', "F"},
        {'F', "(E)"},
        {'F', "i"},
    };
    int numRules = sizeof(productionRules) / sizeof(productionRules[0]);
    char inputString[MAX_INPUT_SIZE];
    printf("21BCE3546\n");
    printf("Enter the input string: ");
    scanf("%s", inputString);
    slrParser(inputString, parseTable, productionRules, numRules);
    return 0;
}
