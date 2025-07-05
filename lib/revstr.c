/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** revstr.c
*/

#include "mylib.h"

char *revstr(char *str)
{
    int i = 0;
    int j = stringlen(str) - 1;
    char c = 0;

    while (i <= j) {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
        ++i;
        --j;
    }
    return str;
}
