/*
** EPITECH PROJECT, 2024
** coeur
** File description:
** exec_live.c
*/

#include "corewar.h"
#include "mylib.h"
#include "op.h"

int exec_live(__maybe_unused vm_t *vm,
    __maybe_unused int i, __maybe_unused size_t *pc)
{
    d_mini_printf(1, "The player %i (%s) is alive.\n",
        vm->champ[i].id, vm->champ[i].prog_name);
    vm->nb_live++;
    vm->champ[i].process->alive = true;
    move_pc(NULL, pc, DIR_SIZE);
    return EXIT_SUCCESS;
}
