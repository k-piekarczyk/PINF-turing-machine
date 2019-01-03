//
// Created by Krzysiek on 03.01.2019.
//

#include <stdlib.h>
#include <string.h>
#include "tm_list.h"

void appendRule(TMRuleNode **head_ref, char *current_state, char *new_state, char *move, int stop) {
    TMRuleNode *new_rule = (TMRuleNode *) malloc(sizeof(TMRuleNode));
    TMRuleNode *current_node = *head_ref;

    new_rule->next = NULL;
    new_rule->current_state = current_state;
    new_rule->new_state = new_state;
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
        if (strcmp(current_node->current_state, query) == 0) return current_node;
        current_node = current_node->next;
    }

    return NULL;
}

void destroyList(TMRuleNode **head_ref) {
    TMRuleNode *current_node = *head_ref;
    TMRuleNode *next;

    while (current_node != NULL) {
        next = current_node->next;
        free(current_node);
        current_node = next;
    }

    *head_ref = NULL;
}