/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** d_ptr.c
*/

#include <stddef.h>
#include "mylib.h"

int d_ptr(int fd, void *ptr)
{
    int *tmp = NULL;

    tmp = ptr;
    d_putstr(fd, "0x");
    if (tmp == NONE) {
        d_putstr(fd, "0");
        return LIB_EXIT_SUCCESS;
    }
    d_putnbr(fd, *tmp);
    return LIB_EXIT_SUCCESS;
}
