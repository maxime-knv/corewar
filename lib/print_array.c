/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** print_array.c
*/

#include <stddef.h>
#include <stdlib.h>
#include "mylib.h"

void print_array(char **array)
{
    if (array == NONE)
        return;
    while (*array) {
        d_mini_printf(LIB_STDERR, "%s\n", *array);
        array++;
    }
    return;
}
