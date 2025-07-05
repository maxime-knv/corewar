/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** putstrr.c
*/

#include <unistd.h>
#include <stddef.h>
#include "mylib.h"

int d_putstr(int fd, char const *str)
{
    write(fd, str, stringlen(str));
    return LIB_EXIT_SUCCESS;
}
