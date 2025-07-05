/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** d_miniprintf.c
*/

#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include "mylib.h"

static void flags_checking(int fd, va_list list, char c)
{
    if (c == 'i' || c == 'd')
        d_putnbr(fd, va_arg(list, int));
    if (c == 'c' || c == 'C')
        d_putchar(fd, va_arg(list, int));
    if (c == 's' || c == 'S')
        d_putstr(fd, va_arg(list, char *));
    if (c == 'p' || c == 'P')
        d_ptr(fd, va_arg(list, char *));
    if (c == 'x' || c == 'X')
        hexa_base(fd, va_arg(list, int));
    if (c == '%')
        d_putchar(fd, '%');
}

int d_mini_printf(int fd, char const *format, ...)
{
    va_list list = {0};

    va_start(list, format);
    for (size_t i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            flags_checking(fd, list, format[i]);
            continue;
        }
        d_putchar(fd, format[i]);
    }
    va_end(list);
    return LIB_EXIT_SUCCESS;
}
