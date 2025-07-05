/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** strcmpare.c
*/

#include <unistd.h>
#include "mylib.h"

int strcmpare(char const *str1, char const *str2)
{
    size_t i = 0;

    while ((str1[i] == str2[i])
        && str1[i] != '\0'
        && str2[i] != '\0')
        i++;
    return str1[i] - str2[i];
}
