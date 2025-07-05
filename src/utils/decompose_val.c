/*
** EPITECH PROJECT, 2024
** coeur
** File description:
** decompose_val.c
*/

#include "corewar.h"
#include "op.h"
#include <stdlib.h>
#include <stdio.h>

void decompose_val(size_t val, uint8_t *tab, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        tab[i] = (val >> (BYTE * i)) & 0xff;
    }
}
