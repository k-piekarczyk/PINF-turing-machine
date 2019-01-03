//
// Created by Krzysiek on 03.01.2019.
//

#include <stdlib.h>
#include <string.h>
#include "tm_list.h"

void appendRule(TMRuleNode **head_ref, char *currentState, char *newState, char *move, int stop) {
    TMRuleNode *new_rule = (TMRuleNode *) malloc(sizeof(TMRuleNode));
    TMRuleNode *current_node = *head_ref;

    new_rule->next = NULL;
    new_rule->currentState = currentState;
    new_rule->newState = newState;
    new_rule->move = move;
    new_rule->stop = stop;

    if (*head_ref == NULL) {
        *head_ref = new_rule;
        return;
    }

    while (current_node->next != NULL)
        current_node = current_node->next;

    current_node->next = new_rule;
}

TMRuleNode *findByState(TMRuleNode **head_ref, char *query) {
    TMRuleNode *current_node = *head_ref;

    while (current_node != NULL) {
        if (strcmp())
    }
}