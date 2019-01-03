//
// Created by Krzysiek on 03.01.2019.
//
#ifndef TURING_MACHINE_TM_LIST_H
#define TURING_MACHINE_TM_LIST_H

#define TAPE 0
#define STATE 1

typedef struct _tm_rule_node {
    struct _tm_rule_node *next;
    char *currentState;
    char *newState;
    char *move;
    int stop;
} TMRuleNode;

void appendRule(TMRuleNode **, char *, char *, char *, int);

TMRuleNode *findByState(TMRuleNode **, char *);

void destroyList(TMRuleNode **);

#endif //TURING_MACHINE_TM_LIST_H
