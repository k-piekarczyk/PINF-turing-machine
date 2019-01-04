#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tm_list.h"
#include "tm_load.h"

#define TAPE_STATE 1
#define INTERNAL_STATE 0

#define RTL 1

int main() {
    printf("Hello, World!\n");
    TMRuleNode *rule_list = loadRules("../demo.rul");
    TMRuleNode *current_rule = NULL;

    char tape[] = "---1---";
    int max_index = (int) strlen(tape) - 1;
    int head = RTL == 1 ? max_index : 0;
    int stop = 0;

    char state[] = "00";
    state[INTERNAL_STATE] = '0';

    printf("Initial  tape: %s\n", tape);
    printf("               %*s^\n", head, "");

    while (stop == 0) {
        state[TAPE_STATE] = tape[head];
        current_rule = findByState(&rule_list, state);

        if (current_rule == NULL) {
            printf("No rule for current state. Tape: %c, Internal: %c.\n", state[TAPE_STATE], state[INTERNAL_STATE]);
            exit(EXIT_FAILURE);
        }

        tape[head] = current_rule->new_state[TAPE_STATE];
        state[INTERNAL_STATE] = current_rule->new_state[INTERNAL_STATE];

        printf("Modified tape: %s\n", tape);
        printf("               %*s^\n", head, "");

        if (strcmp(current_rule->move, "R") == 0)
            head++;
        else if (strcmp(current_rule->move, "L") == 0)
            head--;

        stop = current_rule->stop;

        if (stop == 0) {
            if (head < 0) {
                printf("Head index below 0. Stopping execution.\n");
                stop = 1;
            } else if (head > max_index) {
                printf("Head index above tape length. Stopping execution.\n");
                stop = 1;
            }
        }
    }

    printf("Final    tape: %s\n", tape);
    printf("               %*s^\n", head, "");
    destroyList(&rule_list);
    return 0;
}