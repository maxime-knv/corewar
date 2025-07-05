/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** free_utils.c
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "corewar.h"
#include "mylib.h"
#include "op.h"

void free_champ_struct(champ_t *champ, size_t n_bodies)
{
    if (champ == NONE)
        return;
    for (size_t i = 0; i < n_bodies; ++i) {
        if (champ[i].code != NULL)
            free(champ[i].code);
    }
    for (size_t i = 0; i < (size_t)NB_CHAMP; ++i) {
        if (champ[i].process != NULL)
            free(champ[i].process);
    }
}

void free_info_files(info_cor_files_t *info_cor_files)
{
    if (info_cor_files->file_indexs != NULL)
        free(info_cor_files->file_indexs);
    if (info_cor_files->cor_files_path != NULL)
        free_array(info_cor_files->cor_files_path);
}
