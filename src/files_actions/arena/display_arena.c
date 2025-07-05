/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** display_arena.c
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "corewar.h"
#include "op.h"
#include "mylib.h"

void display_arena(vm_t *vm)
{
    bool passed = false;

    for (size_t i = 0; i < MEM_SIZE; ++i) {
        passed = false;
        if (i % 32 == 0)
            d_mini_printf(STDOUT, "\n");
        if (passed == true)
            continue;
        if (vm->arena[i] == 0) {
            d_mini_printf(1, "\033[31;2m%X \033[0m", vm->arena[i]);
            continue;
        }
        d_mini_printf(STDOUT, "\033[36;1m%X \033[0m", vm->arena[i]);
    }
    d_mini_printf(STDOUT, "\n");
    return;
}
