/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** check_bin_file_errors.c
*/

#include <elf.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "corewar.h"

static void check_magic(int fd, int *ret)
{
    Elf64_Ehdr header = {0};

    if (read(fd, &header, sizeof(header)) != sizeof(header)) {
        *ret = EXIT_FAIL;
        return;
    }
    if (header.e_ident[EI_MAG0] != 0x00 ||
        header.e_ident[EI_MAG1] != 0xea ||
        header.e_ident[EI_MAG2] != 0x83 ||
        header.e_ident[EI_MAG3] != 0xf3) {
        *ret = EXIT_FAIL;
        return;
    }
    *ret = EXIT_SUCCESS;
    return;
}

int check_file_errors(const char *file)
{
    int ret = 0;
    int fd = open(file, O_RDONLY | O_SYNC);

    if (fd == EOF)
        return EXIT_FAIL;
    check_magic(fd, &ret);
    return ret;
}
