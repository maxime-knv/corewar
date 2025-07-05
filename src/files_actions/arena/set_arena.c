/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** set_arena.c
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "corewar.h"
#include "op.h"
#include "mylib.h"

static void fill_champ_place(uint8_t **arena,
    champ_t *champ, size_t *elem, size_t *current_prog)
{
    for (size_t prog_size = 0; prog_size <
            champ[*current_prog].prog_size; ++prog_size)
        (*arena)[*elem + prog_size] =
            (uint8_t)champ[*current_prog].code[prog_size];
}

static int fill_arena(uint8_t **arena,
    champ_t *champ, size_t nb_champ, size_t gap)
{
    size_t current_prog = 0;
    int hero = 0;

    for (size_t elem = 0; elem < MEM_SIZE; ++elem) {
        if (elem % gap == 0 && current_prog < nb_champ) {
            champ[hero].process->pc = elem;
            champ[hero].process->alive = false;
            hero++;
            fill_champ_place(arena, champ, &elem, &current_prog);
            elem += champ[current_prog].prog_size - 1;
            ++current_prog;
            continue;
        }
        (*arena)[elem] = 0;
    }
    return hero;
}

void set_arena(vm_t *vm, champ_t *champ, size_t nb_champ)
{
    uint8_t *arena = vm->arena;
    size_t gap = MEM_SIZE / nb_champ;

    vm->nb_robots = fill_arena(&arena, champ, nb_champ, gap);
    vm->cycle = CYCLE_TO_DIE;
    vm->cur_cycle = 0;
    vm->dump_cycle = 1000;
    vm->nb_live = 0;
}
