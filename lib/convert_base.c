/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** convert_base.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "mylib.h"

static void write_result(int fd, char *num)
{
    if (stringlen(num) % 2 != 0)
        d_mini_printf(fd, "0%s", num);
    else if (strcmpare(num, "") == LIB_EXIT_SUCCESS)
        d_putstr(fd, "00");
    else
        d_mini_printf(fd, "%s", num);
    free(num);
}

void convert_base(int fd, unsigned long nb, int base)
{
    char *num = malloc(sizeof(char) * 100);
    long temp = 0;
    size_t i = 0;

    memoryset(num, 90);
    while (nb != 0) {
        temp = nb % base;
        if (temp < 10)
            temp += 48;
        else
            temp += 87;
        num[i] = temp;
        nb /= base;
        ++i;
    }
    num = revstr(num);
    write_result(fd, num);
}
