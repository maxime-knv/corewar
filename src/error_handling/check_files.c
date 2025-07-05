/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** check_files.c
*/

#include <stddef.h>
#include "corewar.h"
#include "mylib.h"

static int check_pathname(char **av, int i, int k)
{
    if (av[i][k] == '.') {
        if (av[i][k + 1] != 'c'
            && av[i][k + 2] != 'o'
            && av[i][k + 3] != 'r') {
            d_mini_printf(STDERR, "%s\n",
                errmessage[DOT_COR_FILE]);
            return EXIT_FAIL;
        }
    }
    return EXIT_SUCCESS;
}

static int browse_files(char **av, int i)
{
    for (size_t k = 0; av[i][k] != '\0'; ++k)
        if (check_pathname(av, i, k) == EXIT_FAIL)
            return EXIT_FAIL;
    return EXIT_SUCCESS;
}

int check_files(int ac, char **av)
{
    for (size_t i = 1; i < (size_t)ac; ++i) {
        if (browse_files(av, i) == EXIT_FAIL)
            return EXIT_FAIL;
    }
    return EXIT_SUCCESS;
}
