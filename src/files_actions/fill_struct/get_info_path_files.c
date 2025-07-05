/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** get_info_path_files.c
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "corewar.h"
#include "op.h"
#include "mylib.h"

static void is_cor_file(char **av,
    size_t index, size_t *found_dot)
{
    for (size_t k = INIT_ZERO; av[index][k] != '\0'; ++k) {
        if (av[index][k] == FILE_TYPE[0]
            && av[index][k + NEXT_PLUS_ONE] != '\0'
            && av[index][k + NEXT_PLUS_ONE] == FILE_TYPE[1]
            && av[index][k + NEXT_PLUS_TWO] != '\0'
            && av[index][k + NEXT_PLUS_TWO] == FILE_TYPE[2]
            && av[index][k + NEXT_PLUS_THREE] != '\0'
            && av[index][k + NEXT_PLUS_THREE] == FILE_TYPE[3])
            ++(*found_dot);
    }
}

static void get_indexs(info_cor_files_t *info_cor_files,
    size_t *found_dot, size_t index, char **av)
{
    static size_t index_path_files = INIT_ZERO;

    if (*found_dot >= 1) {
        (info_cor_files->file_indexs)[info_cor_files->nb_indexs] = index;
        info_cor_files->cor_files_path[index_path_files] =
            stringdup(av[index]);
        ++info_cor_files->nb_indexs;
        ++index_path_files;
    }
    *found_dot = INIT_ZERO;
}

static int set_free_champ_place(info_cor_files_t *info_cor_files)
{
    if (info_cor_files->nb_indexs < NB_CHAMP) {
        for (size_t i = info_cor_files->nb_indexs; i < NB_PATH_CHAMP; ++i)
            info_cor_files->cor_files_path[i] = NULL;
        return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}

int check_for_flags(info_cor_files_t *info_cor_files,
    char **av, size_t index)
{
    if (is_specific_flag(info_cor_files, av, index) == EXIT_FAIL) {
        if (set_free_champ_place(info_cor_files) == EXIT_ERROR)
            return EXIT_FAIL;
        return EXIT_FAIL;
    }
    return EXIT_SUCCESS;
}

int get_info_path_files(int ac, char **av,
    info_cor_files_t *info_cor_files)
{
    size_t found_dot = INIT_ZERO;

    info_cor_files->file_indexs = malloc(sizeof(size_t *) * NB_CHAMP);
    if (info_cor_files->file_indexs == NONE)
        return EXIT_ERROR;
    info_cor_files->cor_files_path = malloc(sizeof(char *) * NB_PATH_CHAMP);
    if (info_cor_files->cor_files_path == NONE)
        return EXIT_ERROR;
    for (size_t index = SKIP_BINARY; index < (size_t)ac; ++index) {
        if (check_for_flags(info_cor_files, av, index) == EXIT_FAIL)
            return EXIT_FAIL;
        is_cor_file(av, index, &found_dot);
        get_indexs(info_cor_files, &found_dot, index, av);
    }
    if (set_free_champ_place(info_cor_files) == EXIT_ERROR)
        return EXIT_SUCCESS;
    info_cor_files->cor_files_path[NB_CHAMP] = NULL;
    return EXIT_SUCCESS;
}
