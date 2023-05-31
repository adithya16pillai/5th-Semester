#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STATES 100
#define MAX_CHARACTERS 128

typedef struct {
    bool isAccepting; 
    int transitions[MAX_CHARACTERS];  
} State;

typedef struct {
    State states[MAX_STATES];
    int initialState;
    int totalStates;
} DFA;

void initState(State *state) {
    state->isAccepting = false;
    for (int i = 0; i < MAX_CHARACTERS; i++) {
        state->transitions[i] = -1;
    }
}

DFA createDFA() {
    DFA dfa;
    dfa.initialState = 0;
    dfa.totalStates = 1;
    for (int i = 0; i < MAX_STATES; i++) {
        initState(&(dfa.states[i]));
    }
    return dfa;
}

void addTransition(State *state, char input, int nextState) {
    state->transitions[(int)input] = nextState;
}

DFA regexToDFA(const char *regex) {
    DFA dfa;
    return dfa;
}

bool testDFA(const DFA *dfa, const char *input) {
    int currentState = dfa->initialState;
    int i = 0;
    while (input[i] != '\0') {
        int nextState = dfa->states[currentState].transitions[(int)input[i]];
        if (nextState == -1) {
            return false;  // Invalid transition
        }
        currentState = nextState;
        i++;
    }
    return dfa->states[currentState].isAccepting;
}

int main() {
    const char *regex = "(a/b)*abb)";  // Example regular expression
    const char *testString = "aaaab";  // Example input string
    DFA dfa = regexToDFA(regex);
    printf("\nRegular expression: (a/b)*abb)");
    printf("\nInput string: aaaab");
    if (testDFA(&dfa, testString)) {
        printf("\nString accepted by the DFA.\n");
    } else {
        printf("\nString rejected by the DFA.\n");
    }
    return 0;
}