#include <stdio.h>
#include "tm_list.h"
#include "tm_load.h"



int main() {
    printf("Hello, World!\n");
    TMRuleNode *rule_list = NULL;
    appendRule(&rule_list, "0a", "0b", "R", 0);

    printf("stuff: %p \n", rule_list);
    parseLine("a1>b0.R", NULL);

    return 0;
}