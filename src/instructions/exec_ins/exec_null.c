/*
** EPITECH PROJECT, 2024
** coeur
** File description:
** exec_null.c
*/

#include "corewar.h"
#include "op.h"
#include <stdio.h>

int exec_null(__maybe_unused vm_t *vm,
    __maybe_unused int i, __maybe_unused size_t *pc)
{
    *pc += 1;
    return EXIT_SUCCESS;
}
