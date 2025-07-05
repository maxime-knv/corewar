/*
** EPITECH PROJECT, 2024
** coeur
** File description:
** insert_to_map.c
*/

#include "corewar.h"
#include "op.h"
#include <stdlib.h>
#include <stdio.h>

void insert_to_map(vm_t *vm, size_t size, void *val, size_t where)
{
    uint8_t dir_tab[DIR_SIZE] = {0};
    int revi = size - 1;

    if (size == REG_SIZE) {
        decompose_val(*(uint8_t *)val, dir_tab, size);
        for (size_t i = 0; i < size; i++)
            vm->arena[where + i] = dir_tab[i];
    }
    if (size == IND_SIZE)
        decompose_val(*(short *)val, dir_tab, size);
    if (size == DIR_SIZE)
        decompose_val(*(int *)val, dir_tab, size);
    for (size_t i = 0; i < size; i++) {
        vm->arena[where + i] = dir_tab[revi];
        revi--;
    }
}
