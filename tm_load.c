//
// Created by Krzysiek on 03.01.2019.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tm_load.h"

#define LINE_BUFFER 11

void parseLine(const char *src, TMRuleNode **head_ref) {
    char *bufor[LINE_BUFFER];
    char *line = malloc(strlen(src) + 1);
    strcpy(line, src);

    char *current_state;
    char *new_state;
    char *move;
    int stop = 0;

    char *ptr = strtok(line, ">");
    current_state = ptr;

    if (strlen(current_state) != 2) {
        printf("Rule '%s' is invalid. Current state HAS to be 2 characters long.\n", src);
        exit(EXIT_FAILURE);
    }

    ptr = strtok(NULL, ".");
    new_state = ptr;

    if (strlen(new_state) != 2) {
        printf("Rule '%s' is invalid. New state HAS to be 2 characters long.\n", src);
        exit(EXIT_FAILURE);
    }

    ptr = strtok(NULL, ".");

    if (strcmp(ptr, "STOP") == 0) {
        move = ptr;
        stop = 1;
    } else if ((strcmp(ptr, "R") == 0) || (strcmp(ptr, "L") == 0))
        move = ptr;
    else {
        printf("Rule '%s' is invalid. Move HAS to be R, L or STOP.\n", src);
        exit(EXIT_FAILURE);
    }


    appendRule(head_ref, current_state, new_state, move, stop);
}