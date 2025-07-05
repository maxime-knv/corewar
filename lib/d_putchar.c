/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** putcharr.c
*/

#include <unistd.h>
#include "mylib.h"

int d_putchar(int fd, char const c)
{
    write(fd, &c, 1);
    return LIB_EXIT_SUCCESS;
}
