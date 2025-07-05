/*
** EPITECH PROJECT, 2024
** coeur
** File description:
** check_cb.c
*/

#include "corewar.h"
#include "op.h"
#include <stdlib.h>
#include <stdio.h>

int check_cb(uint8_t recieved_cb, uint8_t to_check, uint8_t *cb_arr)
{
    uint8_t check_cb[CB_LEN] = {0};
    uint8_t *tmp_cb = cb_arr;

    read_coding_byte(recieved_cb, cb_arr);
    read_coding_byte(to_check, check_cb);
    for (size_t i = 0; i < CB_LEN; ++i) {
        if (cb_arr[i] != check_cb[i]) {
            cb_arr = tmp_cb;
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}
