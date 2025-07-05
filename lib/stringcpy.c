/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** stringcpy.c
*/

#include <stddef.h>
#include "mylib.h"

char *stringcpy(char *dest, char const *src)
{
    size_t i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
