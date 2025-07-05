/*
** EPITECH PROJECT, 2024
** coeur
** File description:
** compose_val.c
*/

#include "corewar.h"
#include "op.h"
#include <stdlib.h>
#include <stdio.h>

void compose_val(int *val, uint8_t *tab, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        *val += (tab[i] << (BYTE * i));
    }
}
