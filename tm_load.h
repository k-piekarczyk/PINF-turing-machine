//
// Created by Krzysiek on 03.01.2019.
//

#ifndef TURING_MACHINE_TM_LOAD_H
#define TURING_MACHINE_TM_LOAD_H

#include "tm_list.h"

void parseLine(const char *src, TMRuleNode **head_ref);

TMRuleNode *loadRules(const char *file_name);

#endif //TURING_MACHINE_TM_LOAD_H
