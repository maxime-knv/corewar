/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** hexa_base.c
*/

#include "mylib.h"

int hexa_base(int fd, unsigned long nb)
{
    convert_base(fd, nb, 16);
    return LIB_EXIT_SUCCESS;
}
