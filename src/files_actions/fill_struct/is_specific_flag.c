/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** is_specific_flag.c
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "corewar.h"
#include "op.h"
#include "mylib.h"

static void switch_param(vm_t *vm)
{
    char *tmp = NULL;

    for (size_t i = 0; i < vm->info_cor_files.nb_indexs; ++i) {
        if (vm->info_cor_files.file_indexs[i]
            == vm->info_cor_files.index_champ_n_flag) {
            tmp = stringdup(vm->info_cor_files.cor_files_path[i]);
            free(vm->info_cor_files.cor_files_path[i]);
            vm->info_cor_files.cor_files_path[i] = NULL;
            vm->info_cor_files.file_indexs[i] = vm->info_cor_files.n_flag;
            vm->info_cor_files.cor_files_path[i] = stringdup(tmp);
            free(tmp);
        }
    }
}

static void switch_index(vm_t *vm)
{
    size_t tmp = INIT_ZERO;
    char *tmp_path = NULL;

    for (size_t i = 0; i < vm->info_cor_files.nb_indexs - 1; ++i) {
        if (vm->info_cor_files.file_indexs[i + NEXT_PLUS_ONE] == '\0')
            break;
        if (vm->info_cor_files.file_indexs[i]
            > vm->info_cor_files.file_indexs[i + NEXT_PLUS_ONE]) {
            tmp = vm->info_cor_files.file_indexs[i];
            tmp_path = stringdup(vm->info_cor_files.cor_files_path[i]);
            free(vm->info_cor_files.cor_files_path[i]);
            vm->info_cor_files.file_indexs[i] =
                vm->info_cor_files.file_indexs[i + NEXT_PLUS_ONE];
            vm->info_cor_files.cor_files_path[i] =
                vm->info_cor_files.cor_files_path[i + NEXT_PLUS_ONE];
            vm->info_cor_files.file_indexs[i + NEXT_PLUS_ONE] = tmp;
            vm->info_cor_files.cor_files_path[i + NEXT_PLUS_ONE] = tmp_path;
            tmp = 0;
        }
    }
}

void process_n_flag(vm_t *vm)
{
    switch_param(vm);
    switch_index(vm);
}

static int is_dump_flag(info_cor_files_t *info_cor_files,
    char **av, size_t index, size_t *count_dump)
{
    if (strcmpare(av[index], DUMP_FLAG) == EXIT_SUCCESS) {
        ++(*count_dump);
        if (*count_dump >= DOUBLE_DEFINITION
            || av[index + NEXT_PLUS_ONE] == NONE
            || string_isnumber(av[index + NEXT_PLUS_ONE]) == EXIT_ERROR) {
            d_mini_printf(STDERR, "%s\n", errmessage[ERR_DUMP_FLAG]);
            return EXIT_FAIL;
        } else
            info_cor_files->dump_flag = getnumber(av[index + NEXT_PLUS_ONE]);
    }
    return EXIT_SUCCESS;
}

static int get_n_flag_info(info_cor_files_t *info_cor_files,
    char **av, size_t index)
{
    info_cor_files->n_flag = getnumber(av[index + NEXT_PLUS_ONE]);
    if (av[index + NEXT_PLUS_TWO] != NONE) {
        info_cor_files->index_champ_n_flag = index + NEXT_PLUS_TWO;
        return EXIT_SUCCESS;
    } else {
        d_mini_printf(STDERR, "%s\n", errmessage[ERR_DUMP_FLAG]);
        return EXIT_FAIL;
    }
}

static int is_n_flag(info_cor_files_t *info_cor_files,
    char **av, size_t index)
{
    if (strcmpare(av[index], N_FLAG) == EXIT_SUCCESS) {
        if (av[index + NEXT_PLUS_ONE] == NONE
            || string_isnumber(av[index + NEXT_PLUS_ONE]) == EXIT_ERROR) {
            d_mini_printf(STDERR, "%s\n", errmessage[ERR_N_FLAG]);
            return EXIT_FAIL;
        }
        if (get_n_flag_info(info_cor_files, av, index) == EXIT_FAIL)
            return EXIT_FAIL;
    }
    return EXIT_SUCCESS;
}

int is_specific_flag(info_cor_files_t *info_cor_files,
    char **av, size_t index)
{
    static size_t count_dump = INIT_ZERO;

    if (is_dump_flag(info_cor_files, av, index, &count_dump) == EXIT_FAIL)
        return EXIT_FAIL;
    if (count_dump == 1) {
        info_cor_files->start_dump_flag = INIT_ONE;
    } else
        info_cor_files->start_dump_flag = INIT_ZERO;
    if (is_n_flag(info_cor_files, av, index) == EXIT_FAIL)
        return EXIT_FAIL;
    return EXIT_SUCCESS;
}
