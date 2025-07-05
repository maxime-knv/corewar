/*
** EPITECH PROJECT, 2024
** coeur
** File description:
** exec_st.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "corewar.h"
#include "op.h"

static void process_cb_st(__maybe_unused vm_t *vm,
    __maybe_unused int i, __maybe_unused size_t *pc, uint8_t *cb_arr)
{
    uint8_t reg_nb = 0;
    size_t store_at = 0;
    uint8_t reg = 0;
    int ind = 0;

    if (cb_arr[1] == CB_IND) {
        read_map(vm, sizeof(uint8_t), &reg_nb, *pc + 1 + REG_SIZE);
        read_map(vm, sizeof(int), &ind, *pc + IND_SIZE + REG_SIZE);
        store_at = *pc + ind % IDX_MOD;
        insert_to_map(vm, sizeof(int), &vm->champ[i].reg[reg_nb], store_at);
    } else {
        read_map(vm, sizeof(uint8_t), &reg, *pc + 2);
        read_map(vm, sizeof(uint8_t), &reg_nb, *pc + IND_SIZE + REG_SIZE);
        vm->champ[i].reg[reg] = vm->champ[i].reg[reg_nb];
    }
}

int exec_st(__maybe_unused vm_t *vm,
    __maybe_unused int i, __maybe_unused size_t *pc)
{
    uint8_t cb_arr[CB_LEN] = {0};

    if (check_cb(vm->arena[*pc + 1], 0x50, cb_arr) == EXIT_FAILURE &&
        check_cb(vm->arena[*pc + 1], 0x70, cb_arr) == EXIT_FAILURE)
        return EXIT_FAILURE;
    process_cb_st(vm, i, pc, cb_arr);
    move_pc(cb_arr, pc, 0);
    return EXIT_SUCCESS;
}
