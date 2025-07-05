/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** charisalpha.c
*/

#include <stddef.h>
#include "mylib.h"

int charisalpha(char const c)
{
    if ((c >= 'A' && c <= 'Z')
        || (c >= 'a' && c <= 'z')
        || c == ' ')
        return LIB_EXIT_SUCCESS;
    else
        return LIB_EXIT_ERROR;
    return LIB_EXIT_SUCCESS;
}
