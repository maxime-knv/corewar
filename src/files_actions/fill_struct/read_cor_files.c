/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** read_files.c
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "mylib.h"
#include "corewar.h"
#include "op.h"

static void reset_values(char **line, size_t *n)
{
    *line = NULL;
    *n = INIT_ZERO;
}

static void set_body(champ_t *champ,
    char *line, size_t *n, size_t prog_size)
{
    static size_t id = INIT_ZERO;

    champ->id = id;
    champ->is_alive = true;
    champ->prog_size = prog_size;
    champ->code = malloc(prog_size + 1);
    if (champ->code == NONE)
        return;
    for (size_t i = HEADER_SIZE; i < *n; ++i)
        champ->code[i - HEADER_SIZE] = (uint8_t)line[i];
    id++;
}

static void read_file(champ_t *champ,
    char *line, FILE *fd, size_t n)
{
    size_t prog_size = n - HEADER_SIZE;

    set_body(champ, line, &n, prog_size);
    free(line);
    fclose(fd);
}

static void fill_name_comment(champ_t *champ,
    info_file_t *info_file, mem_index_t *mem_index, size_t *i)
{
    if (info_file->line[*i] != 0) {
        if (*i < PROG_NAME_LENGTH + NEXT_PLUS_ONE) {
            champ->prog_name[mem_index->mem_index_name] = info_file->line[*i];
            ++mem_index->mem_index_name;
        }
        if (*i >= PROG_NAME_LENGTH + NEXT_PLUS_ONE) {
            champ->comment[mem_index->mem_index_comment] = info_file->line[*i];
            ++mem_index->mem_index_comment;
        }
    }
}

static void get_name_comment(champ_t *champ,
    info_file_t *info_file)
{
    mem_index_t mem_index = {INIT_ZERO, INIT_ZERO};

    memoryset(champ->prog_name, PROG_NAME_LENGTH + NEXT_PLUS_ONE);
    memoryset(champ->comment, COMMENT_LENGTH + NEXT_PLUS_ONE);
    for (size_t i = SKIP_MAGIC; i < HEADER_SIZE; ++i) {
        if (charisalpha(info_file->line[i]) == EXIT_SUCCESS)
            fill_name_comment(champ, info_file, &mem_index, &i);
    }
}

static void handle_file(champ_t *champ,
    info_file_t *info_file, FILE *fd, size_t k)
{
    while (getline(&info_file->line, &info_file->n, fd) != EOF);
    get_name_comment(&champ[k], info_file);
    read_file(&champ[k], info_file->line, fd, info_file->n);
    reset_values(&info_file->line, &info_file->n);
}

static void init_utils_values(champ_t *champ, info_cor_files_t *info_cor_files)
{
    for (size_t i = INIT_ZERO; i < info_cor_files->nb_indexs; ++i) {
        champ[i].process = malloc(sizeof(proc_t));
        if (champ[i].process == NONE)
            return;
        champ[i].process->next = NULL;
        champ[i].process->cldwn = op_tab[champ->code[INIT_ZERO]].nbr_cycles;
    }
}

int read_cor_files(champ_t *champ, info_cor_files_t *info_cor_files)
{
    info_file_t info_file = {NULL, INIT_ZERO};
    FILE *fd = NULL;

    for (size_t k = INIT_ZERO; k < info_cor_files->nb_indexs; ++k) {
        fd = fopen(info_cor_files->cor_files_path[k], READ_BIN);
        if (fd == NONE) {
            free_champ_struct(champ, k - 1);
            return EXIT_FAIL;
        }
        champ[k].reg[1] = info_cor_files->file_indexs[k];
        handle_file(champ, &info_file, fd, k);
    }
    init_utils_values(champ, info_cor_files);
    return EXIT_SUCCESS;
}
