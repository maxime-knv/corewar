/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** stringdup.c
*/

#include <stddef.h>
#include <stdlib.h>
#include "mylib.h"

char *stringdup(char const *str)
{
    char *dup = NULL;

    if (str == NONE)
        return NULL;
    dup = malloc(stringlen(str) + 1);
    if (dup == NONE)
        return NULL;
    stringcpy(dup, str);
    return dup;
}
