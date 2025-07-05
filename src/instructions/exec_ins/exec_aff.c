/*
** EPITECH PROJECT, 2024
** coeur
** File description:
** exec_aff.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "corewar.h"
#include "mylib.h"
#include "op.h"

int exec_aff(__maybe_unused vm_t *vm,
    __maybe_unused int i, __maybe_unused size_t *pc)
{
    uint8_t cb_arr[CB_LEN] = {0};
    uint8_t reg_nb = 0;

    if (check_cb(vm->arena[*pc + 1], 0x40, cb_arr) == EXIT_FAILURE)
        return EXIT_FAILURE;
    read_map(vm, sizeof(uint8_t), &reg_nb, *pc + 1 + REG_SIZE);
    d_mini_printf(1, "%c", vm->champ[i].reg[reg_nb]);
    move_pc(cb_arr, pc, 0);
    return EXIT_SUCCESS;
}
