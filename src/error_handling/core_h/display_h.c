/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** display_h.c
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "corewar.h"
#include "mylib.h"

int display_h(int ac, char **av)
{
    char *line = NULL;
    size_t n = 0;
    FILE *fd = 0;
    size_t return_value = EXIT_SUCCESS;

    if (ac == 2
        && strcmpare(av[1], "-h") == CORE_TRUE) {
        fd = fopen(PATH_COREWAR_H, "r");
        if (fd == NONE)
            return EXIT_FAIL;
        return_value = (size_t)EXIT_HELP;
        while (getline(&line, &n, fd) != EOF)
            d_mini_printf(STDOUT, "%s", line);
        d_putchar(STDOUT, '\n');
        free(line);
        fclose(fd);
    }
    return return_value;
}
