/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** browse_files_actions.c
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "corewar.h"
#include "op.h"
#include "mylib.h"

int browse_files_actions(int ac, char **av)
{
    vm_t vm = {0};

    if (file_parsing(ac, av, &vm) == EXIT_FAIL)
        return EXIT_FAIL;
    set_arena(&vm, vm.champ, vm.info_cor_files.nb_indexs);
    corewar_loop(&vm);
    free_champ_struct(vm.champ, vm.info_cor_files.nb_indexs);
    free_info_files(&vm.info_cor_files);
    return EXIT_SUCCESS;
}
