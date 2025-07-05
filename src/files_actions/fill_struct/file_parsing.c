/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** file_parsing.c
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "corewar.h"
#include "op.h"
#include "mylib.h"

int file_parsing(int ac, char **av, vm_t *vm)
{
    if (get_info_path_files(ac, av, &vm->info_cor_files) == EXIT_FAIL) {
        free_info_files(&vm->info_cor_files);
        return EXIT_FAIL;
    }
    process_n_flag(vm);
    if (check_nb_param(vm->info_cor_files.nb_indexs)) {
        free_info_files(&vm->info_cor_files);
        return EXIT_FAIL;
    }
    if (read_cor_files(vm->champ, &vm->info_cor_files) == EXIT_FAIL)
        return EXIT_FAIL;
    return EXIT_SUCCESS;
}
