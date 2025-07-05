/*
** EPITECH PROJECT, 2024
** coeur
** File description:
** exec_fork.c
*/

#include "corewar.h"
#include "op.h"
#include <stdio.h>
#include <stdlib.h>

int exec_fork(__maybe_unused vm_t *vm,
    __maybe_unused int i, __maybe_unused size_t *pc)
{
    if (add_node(vm, i, pc, (size_t)SIM_FORK) == EXIT_FAILURE)
        return EXIT_FAILURE;
    move_pc(NULL, pc, IND_SIZE);
    return EXIT_SUCCESS;
}
