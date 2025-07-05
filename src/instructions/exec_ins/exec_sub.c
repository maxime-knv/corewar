/*
** EPITECH PROJECT, 2024
** coeur
** File description:
** exec_sub.c
*/

#include <stdlib.h>
#include "corewar.h"
#include "op.h"

int exec_sub(__maybe_unused vm_t *vm,
    __maybe_unused int i, __maybe_unused size_t *pc)
{
    uint8_t cb_arr[CB_LEN] = {0};

    read_coding_byte(0x54, cb_arr);
    move_pc(cb_arr, pc, 0);
    return EXIT_SUCCESS;
}
