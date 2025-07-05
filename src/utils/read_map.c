/*
** EPITECH PROJECT, 2024
** coeur
** File description:
** read_map.c
*/

#include "corewar.h"
#include "op.h"
#include <stdlib.h>
#include <stdio.h>

void read_map(vm_t *vm, size_t size, void *val, size_t where)
{
    uint8_t readed[DIR_SIZE] = {0};
    size_t revi = size - 1;

    for (size_t i = 0; i < size; ++i) {
        readed[revi] = vm->arena[where + i];
        revi--;
    }
    if (size == REG_SIZE) {
        compose_val(&(*(int *)val), readed, sizeof(unsigned char));
    }
    if (size == IND_SIZE) {
        compose_val(&(*(int *)val), readed, sizeof(short));
    }
    if (size == DIR_SIZE) {
        compose_val(&(*(int *)val), readed, sizeof(int));
    }
}
