/*
** EPITECH PROJECT, 2024
** coeur
** File description:
** exec_lfork.c
*/

#include "corewar.h"
#include "op.h"
#include <stdio.h>
#include <stdlib.h>

static void choose_mode(size_t choose_fork,
    proc_t *new, size_t *pc, short val)
{
    if (choose_fork == (size_t)L_FORK)
        new->pc = (*pc + val);
    else if (choose_fork == (size_t)SIM_FORK)
        new->pc = (*pc + val % IDX_MOD);
}

int add_node(vm_t *vm, int i, size_t *pc, size_t choose_fork)
{
    proc_t *tmp = vm->champ[i].process;
    proc_t *new = NULL;
    short val = 0;
    size_t count = 0;

    read_map(vm, sizeof(short), &val, tmp->pc + 1);
    while (tmp->next != NULL) {
        ++count;
        tmp = tmp->next;
    }
    new = malloc(sizeof(proc_t));
    if (new == NONE)
        return EXIT_FAILURE;
    choose_mode(choose_fork, new, pc, val);
    new->cldwn = 0;
    new->next = NULL;
    tmp->next = new;
    tmp->next->next = NULL;
    return EXIT_SUCCESS;
}

int exec_lfork(__maybe_unused vm_t *vm,
    __maybe_unused int i, __maybe_unused size_t *pc)
{
    if (add_node(vm, i, pc, (size_t)L_FORK) == EXIT_FAILURE)
        return EXIT_FAILURE;
    move_pc(NULL, pc, IND_SIZE);
    return EXIT_SUCCESS;
}
