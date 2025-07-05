/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** op.c
*/

#include "op.h"

const op_t op_tab[] = {
    [0x00] = {NULL, 0, {0}, 0, 0, NULL},
    [0x01] = {"live", 1, {T_DIR}, 1, 10, "alive"},
    [0x02] = {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load"},
    [0x03] = {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store"},
    [0x04] = {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition"},
    [0x05] = {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction"},
    [0x06] = {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
        6, 6, "et (and  r1, r2, r3   r1&r2 -> r3"},
    [0x07] = {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
        7, 6, "ou  (or   r1, r2, r3   r1 | r2 -> r3"},
    [0x08] = {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
        8, 6, "ou (xor  r1, r2, r3   r1^r2 -> r3"},
    [0x09] = {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero"},
    [0x0a] = {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
        "load index"},
    [0x0b] = {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
        "store index"},
    [0x0c] = {"fork", 1, {T_DIR}, 12, 100, "fork"},
    [0x0d] = {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load"},
    [0x0e] = {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
        "long load index"},
    [0x0f] = {"lfork", 1, {T_DIR}, 15, 1000, "long fork"},
    [0x10] = {"aff", 1, {T_REG}, 16, 2, "aff"},
    {0, 0, {0}, 0, 0, 0}};
