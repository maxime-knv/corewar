/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** get_file_size.c
*/

#include <sys/stat.h>
#include <unistd.h>
#include "corewar.h"

size_t get_file_size(char const *filename)
{
    struct stat st;

    if (stat(filename, &st) != 0) {
        return 0;
    }
    return st.st_size;
}
