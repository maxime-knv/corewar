/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** stringlen.c
*/

#include <unistd.h>
#include "mylib.h"

int stringlen(char const *str)
{
    char const *tmp = str;

    while (*tmp)
        tmp++;
    return tmp - str;
}
