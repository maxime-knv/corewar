/*
** EPITECH PROJECT, 2024
** coeur
** File description:
** exec_sti.c
*/

#include "corewar.h"
#include "op.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int exec_sti(vm_t *vm, int i, __maybe_unused size_t *pc)
{
    uint8_t cb_arr[CB_LEN] = {0};
    size_t pos_reg = 0;
    size_t store_at = 0;

    if (check_cb(vm->arena[*pc + 1], 0x68, cb_arr) == EXIT_FAILURE &&
    check_cb(vm->arena[*pc + 1], 0x54, cb_arr) == EXIT_FAILURE)
        return EXIT_FAILURE;
    store_at = *pc +
        (vm->arena[get_pos(*pc, cb_arr, 2)] +
        vm->arena[get_pos(*pc, cb_arr, 3)]) % IDX_MOD;
    pos_reg = get_pos(*pc, cb_arr, 1);
    insert_to_map(vm, sizeof(int),
        &vm->champ[i].reg[vm->arena[pos_reg]], store_at);
    for (size_t i = 0; i < CB_LEN; ++i)
        if (cb_arr[i] == CB_DIR)
            cb_arr[i] = CB_IDT;
    move_pc(cb_arr, pc, 0);
    return EXIT_SUCCESS;
}
