/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** d_putnbr.c
*/

#include "mylib.h"

int d_putnbr(int fd, int nb)
{
    if (nb < 0){
        d_putchar(fd, '-');
        nb *= (-1);
    }
    if (nb >= 10)
        d_putnbr(fd, nb / 10);
    d_putchar(fd, (nb % 10) + 48);
    return LIB_EXIT_SUCCESS;
}
