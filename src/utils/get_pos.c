/*
** EPITECH PROJECT, 2024
** coeur
** File description:
** get_pos.c
*/

#include "corewar.h"
#include "op.h"
#include <stdlib.h>
#include <stdio.h>

size_t get_pos(size_t pc, uint8_t *args, size_t move_in_cb)
{
    size_t ret = pc;

    for (size_t i = 0; i < move_in_cb; ++i) {
        ret += args[i];
    }
    return ret + 1;
}
