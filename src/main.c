/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** main.c
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "corewar.h"
#include "mylib.h"
#include "op.h"

int main(int ac, char **av)
{
    size_t tmp = error_handling(ac, av);

    if (tmp != EXIT_SUCCESS)
        return tmp;
    return browse_files_actions(ac, av);
}
