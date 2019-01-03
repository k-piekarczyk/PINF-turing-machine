//
// Created by Krzysiek on 03.01.2019.
//
#ifndef TURING_MACHINE_TM_LIST_H
#define TURING_MACHINE_TM_LIST_H

#define TAPE 0
#define STATE 1

typedef struct _tm_rule_node {
    struct _tm_rule_node *next;
    char *current_state;
    char *new_state;
    char *move;
    int stop;
} TMRuleNode;

void appendRule(TMRuleNode **head_ref, char *current_state, char *new_state, char *move, int stop);

TMRuleNode *findByState(TMRuleNode **head_ref, char *query);

void destroyList(TMRuleNode **head_ref);

#endif //TURING_MACHINE_TM_LIST_H
