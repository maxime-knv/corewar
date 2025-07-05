/*
** EPITECH PROJECT, 2024
** coeur
** File description:
** move_pc.c
*/

#include "corewar.h"
#include "op.h"
#include <stdlib.h>
#include <stdio.h>

void move_pc(uint8_t *cb_arr, size_t *pc, __maybe_unused int nb)
{
    if (nb != 0) {
        *pc += nb + 1;
        return;
    }
    for (size_t i = 0; i < CB_LEN; ++i) {
        if (cb_arr[i] == CB_REG)
            *pc += REG_SIZE;
        if (cb_arr[i] == CB_DIR)
            *pc += DIR_SIZE;
        if (cb_arr[i] == CB_IND)
            *pc += IND_SIZE;
        if (cb_arr[i] == CB_IDT)
            *pc += IND_SIZE;
    }
    *pc += 2;
}
