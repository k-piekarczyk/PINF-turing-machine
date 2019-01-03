#include <stdio.h>
#include "tm_list.h"
#include "tm_load.h"

#define OWN_DEBUG

int main() {
    printf("Hello, World!\n");
    TMRuleNode *rule_list = loadRules("demo.rul");
    destroyList(&rule_list);
    return 0;
}