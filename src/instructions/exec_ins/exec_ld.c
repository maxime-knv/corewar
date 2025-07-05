/*
** EPITECH PROJECT, 2024
** coeur
** File description:
** exec_ld.c
*/

#include "corewar.h"
#include "op.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void process_cb_ld(__maybe_unused vm_t *vm,
    __maybe_unused int i, __maybe_unused size_t *pc, uint8_t *cb_arr)
{
    uint8_t reg_nb = 0;
    size_t retrive_at = 0;
    uint8_t reg = 0;
    int ind = 0;
    uint8_t val_to_store = 0;

    if (cb_arr[0] == CB_IND) {
        read_map(vm, sizeof(uint8_t), &reg, *pc + 1);
        read_map(vm, sizeof(uint8_t), &reg_nb, *pc + IND_SIZE + REG_SIZE);
        retrive_at = *pc + reg % IDX_MOD;
        vm->champ[i].reg[reg_nb] = vm->champ[i].reg[reg];
    } else {
        read_map(vm, sizeof(int), &ind, *pc + 2);
        read_map(vm, sizeof(uint8_t), &reg_nb, *pc + IND_SIZE + DIR_SIZE);
        retrive_at = (*pc + ind % IDX_MOD);
        read_map(vm, sizeof(uint8_t), &val_to_store, retrive_at);
        vm->champ[i].reg[reg_nb] = val_to_store;
    }
}

int exec_ld(__maybe_unused vm_t *vm,
    __maybe_unused int i, __maybe_unused size_t *pc)
{
    uint8_t cb_arr[CB_LEN] = {0};

    if (check_cb(vm->arena[*pc + 1], 0xd0, cb_arr) == EXIT_FAILURE &&
        check_cb(vm->arena[*pc + 1], 0x90, cb_arr) == EXIT_FAILURE)
        return EXIT_FAILURE;
    process_cb_ld(vm, i, pc, cb_arr);
    move_pc(cb_arr, pc, 0);
    return EXIT_SUCCESS;
}
