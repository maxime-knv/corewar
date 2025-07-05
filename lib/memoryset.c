/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** memoryset.c
*/

#include <stdlib.h>
#include "mylib.h"


int memoryset(char *str, int size)
{
    if (str == NONE)
        return LIB_EXIT_ERROR;
    for (int i = 0; i < size; i++)
        str[i] = '\0';
    return LIB_EXIT_SUCCESS;
}
