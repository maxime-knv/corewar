/*
** EPITECH PROJECT, 2024
** coeur
** File description:
** exec_add.c
*/

#include "corewar.h"
#include "op.h"

int exec_add(__maybe_unused vm_t *vm,
    __maybe_unused int i, __maybe_unused size_t *pc)
{
    uint8_t cb_arr[CB_LEN] = {0};

    read_coding_byte(vm->arena[*pc + 1], cb_arr);
    move_pc(cb_arr, pc, 0);
    return EXIT_SUCCESS;
}
