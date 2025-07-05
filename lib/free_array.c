/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** free_array.c
*/

#include <stdlib.h>
#include <stddef.h>
#include "mylib.h"

int free_array(char **array)
{
    if (array == NONE)
        return LIB_EXIT_FAIL;
    for (size_t i = 0; array[i] != NULL; ++i)
        free(array[i]);
    free(array);
    return LIB_EXIT_SUCCESS;
}
