/*
** EPITECH PROJECT, 2024
** coeur
** File description:
** read_codding_byte.c
*/

#include "corewar.h"
#include "op.h"
#include <stdlib.h>
#include <stdio.h>

uint8_t *read_coding_byte(uint8_t cb, uint8_t *args)
{
    int left_bitshift = 0;
    int right_bitshift = 6;

    for (size_t i = 0; i < CB_LEN; ++i)
        args[i] = cb;
    for (size_t i = 0; i < CB_LEN; ++i) {
        args[i] = args[i] << left_bitshift;
        args[i] = args[i] >> right_bitshift;
        left_bitshift += 2;
    }
    return args;
}
