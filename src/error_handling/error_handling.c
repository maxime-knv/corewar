/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** error_handling.c
*/

#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "corewar.h"
#include "mylib.h"

int check_nb_param(int ac)
{
    if (ac == ONE_ROBOT) {
        d_mini_printf(STDERR, "%s\n",
            errmessage[FEW_WARRIOR]);
        return EXIT_FAIL;
    }
    if (ac > FOUR_ROBOT) {
        d_mini_printf(STDERR, "%s\n",
            errmessage[MANY_WARRIOR]);
        return EXIT_FAIL;
    }
    return EXIT_SUCCESS;
}

int error_handling(int ac, char **av)
{
    size_t tmp = INIT_ONE;

    tmp = display_h(ac, av);
    if (tmp == EXIT_FAIL)
        return EXIT_FAIL;
    if (tmp == EXIT_HELP)
        return EXIT_HELP;
    return EXIT_SUCCESS;
}
