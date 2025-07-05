/*
** EPITECH PROJECT, 2024
** coeur
** File description:
** corewar_loop.c
*/

#include "corewar.h"
#include "mylib.h"
#include "op.h"
#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdlib.h>

int go_into_ins(vm_t *vm, int ind, size_t *pc)
{
    instruction_list[vm->arena[*pc]].exec_ins(vm, ind, pc);
    return EXIT_SUCCESS;
}

int loop_into_process(vm_t *vm, proc_t *tmp, int i)
{
    while (tmp != NULL) {
        if (tmp->cldwn <= 0) {
            display_arena(vm);
            go_into_ins(vm, i, &tmp->pc);
            tmp->cldwn = op_tab[vm->arena[tmp->pc]].nbr_cycles;
        } else {
            tmp->cldwn--;
        }
        tmp = tmp->next;
    }
    return EXIT_SUCCESS;
}

vm_t *loop_into_heroes(vm_t *vm)
{
    size_t i = 0;
    proc_t *tmp = NULL;

    while (i < vm->info_cor_files.nb_indexs) {
        tmp = vm->champ[i].process;
        display_arena(vm);
        if (vm->champ[i].is_alive == true)
            loop_into_process(vm, tmp, i);
        i++;
    }
    return vm;
}

void process_cycles(vm_t *vm)
{
    if (vm->nb_live == NBR_LIVE) {
        vm->nb_live = 0;
        vm->cycle -= CYCLE_DELTA;
    }
    if (vm->cur_cycle >= vm->cycle)
        vm->cur_cycle = 0;
    else
        vm->cur_cycle++;
}

int corewar_loop(vm_t *vm)
{
    int end = CORE_FALSE;

    while (end != CORE_TRUE) {
        loop_into_heroes(vm);
        process_cycles(vm);
        ++vm->info_cor_files.start_dump_flag;
    }
    return EXIT_SUCCESS;
}
