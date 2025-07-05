/*
** EPITECH PROJECT, 2024
** coeur
** File description:
** display_arena.c
*/

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include "corewar.h"
#include "op.h"


#define RGB_TO_CURSES(x) ((int)((float)x*3.90625))  // 1000/256 conversion

void ncurse_display_cursor(vm_t *vm, size_t i, bool *passed)
{
    proc_t *tmp = NULL;

    for (int j = 0; j < NB_CHAMP; j++) {
        tmp =  vm->champ[j].process;
        if (tmp == NULL)
            return;
        while (tmp != NULL) {
            if (i == tmp->pc) {
                attron(COLOR_PAIR(43));
                printw("%.02x ", vm->arena[i]);
                attroff(COLOR_PAIR(43));
                *passed = true;
                break;
            }
            tmp = tmp->next;
        }
    }
}

void ncurse_display_arena(vm_t *vm)
{
    initscr();
    cbreak();
    curs_set(0);
    bool passed = false;
    start_color();
    short my_white = 8;
    short my_cyan = 9;
    short my_black = 10;
    init_color(my_white, RGB_TO_CURSES(255), RGB_TO_CURSES(255), RGB_TO_CURSES(255));
    init_color(my_black, RGB_TO_CURSES(133), RGB_TO_CURSES(133), RGB_TO_CURSES(133));
    init_color(my_black, RGB_TO_CURSES(100), RGB_TO_CURSES(100), RGB_TO_CURSES(100));
    init_pair(42, my_white, COLOR_BLACK);
    init_pair(43, my_cyan, COLOR_CYAN);
    init_pair(44, my_black, COLOR_BLACK);

    for (size_t i = 0; i < MEM_SIZE; ++i) {
        passed = false;
        if (i % (64 + 32) == 0)
            printw("\n");
        ncurse_display_cursor(vm, i, &passed);
        if (passed == true)
            continue;
        if (vm->arena[i] == 0) {
            attron(COLOR_PAIR(44));
            printw("%.02x ", vm->arena[i]);
            attroff(COLOR_PAIR(44));
            continue;
        }
        attron(COLOR_PAIR(42));
        printw("%.02x ", vm->arena[i]);
        attroff(COLOR_PAIR(42));
    }
    printw("\n");
}

void display_arena(vm_t *vm)
{
    // // init_ncurses();
    // initscr();
    // cbreak();
    // curs_set(0);
    nodelay(stdscr, TRUE);
    if (getch() == 'q') {
        endwin();
        exit(0);
    }
    clear();
    usleep(3000);
    printw("\n\n\n\ncycles to die %li / %li Total cycles %li nb_live %li / 40\n\n\n\n\n\n\n",
    vm->cur_cycle, vm->cycle, vm->cur_cycle, vm->nb_live);
    for (int i = 0; i < NB_CHAMP; i++) {
        printw("champ 1 nb actual pc n°%li = \"%.02x\" cycles %li\t",
            vm->champ[i].process->pc, vm->arena[vm->champ[i].process->pc], vm->champ[i].process->cldwn);    
    }
    // printw("\n\n\n\n%s", vm->arena);
    printw("\n\n\n\n");
    ncurse_display_arena(vm);
    refresh();    
}
