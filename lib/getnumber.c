/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** getnumber.c
*/

#include <stddef.h>
#include "mylib.h"

int isnegative(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i] > '9' || str[i] < '0') {
        if (str[i] == '-')
            ++count;
        ++i;
    }
    if (count % 2 != 0)
        return 1;
    else
        return 0;
}

int char_isnumber(char l)
{
    if (l == '-')
        return LIB_EXIT_SUCCESS;
    if (l >= '0' && l <= '9')
        return LIB_EXIT_PASSED;
    return LIB_EXIT_ERROR;
}

int string_isnumber(char *str)
{
    for (size_t i = 0; i < (size_t)stringlen(str); ++i) {
        if (str[i] >= '0' && str[i] <= '9')
            continue;
        else
            return LIB_EXIT_ERROR;
    }
    return LIB_EXIT_SUCCESS;
}

int getnumber(char *str)
{
    int i = 0;
    int nbr = 0;

    while (char_isnumber(str[i]) == LIB_EXIT_SUCCESS)
        ++i;
    while (char_isnumber(str[i]) == LIB_EXIT_PASSED) {
        nbr = ((nbr * 10) + (str[i] - 48));
        ++i;
    }
    if (isnegative(str) == LIB_EXIT_PASSED)
        nbr = -nbr;
    return nbr;
}
