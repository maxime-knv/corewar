/*
** EPITECH PROJECT, 2024
** coeur
** File description:
** exec_jzump.c
*/

#include "corewar.h"
#include "op.h"
#include <stdio.h>

int exec_zjump(__maybe_unused vm_t *vm,
    __maybe_unused int i, __maybe_unused size_t *pc)
{
    short new_pc = 0;

    read_map(vm, sizeof(short), &new_pc, *pc + 1);
    *pc += new_pc;
    return EXIT_SUCCESS;
}
