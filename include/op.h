/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** op.h
*/

#ifndef _OP_H_
    #define _OP_H_

    #include <inttypes.h>
    #include <sys/types.h>
    #include "corewar.h"
    #define MEM_SIZE (6 * 1024)
    #define IDX_MOD 512 // modulo of the index
    #define MAX_ARGS_NUMBER 4 // this may not be changed 2^*IND_SIZE

    #define COMMENT_CHAR '#'
    #define LABEL_CHAR ':'
    #define DIRECT_CHAR '%'
    #define SEPARATOR_CHAR ','
    #define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"

    #define NAME_CMD_STRING ".name"
    #define COMMENT_CMD_STRING ".comment"

    // regs
    #define REG_NUMBER 16 // r1 <--> rx
typedef char args_type_t;

    #define T_REG 1 // register
    #define T_DIR 2 // direct  (ld  #1,r1  put 1 into r1)
    #define T_IND 4 // indirect always relative (ld 1,r1 put what's
                    // '-> in the address (1+pc) into r1 (4 bytes ))
    #define T_LAB 8 // LABEL

    // live
    #define CYCLE_TO_DIE 1536 // number of cycle before beig declared dead
    #define CYCLE_DELTA 5
    #define NBR_LIVE 40

    #define CB_REG 1
    #define CB_DIR 2
    #define CB_IND 3
    #define CB_IDT 4

    // size (in bytes)
    #define IND_SIZE 2
    #define DIR_SIZE 4
    #define REG_SIZE 1

    #define BYTE 8
    // header
    #define PROG_NAME_LENGTH 128
    #define COMMENT_LENGTH 2048
    #define COREWAR_EXEC_MAGIC 0xea83f3

    /*
    op struct
    */

typedef struct op_s {
    char *mnemonique;
    char nbr_args;
    args_type_t type[MAX_ARGS_NUMBER];
    char code;
    int nbr_cycles;
    char *comment;
} op_t;

typedef enum op_ind {
    LIVE = 0x01,
    LD = 0x02,
    ST = 0x03,
    ADD = 0x04,
    SUB = 0x05,
    AND = 0x06,
    OR = 0x07,
    XOR = 0x08,
    ZJUMP = 0x09,
    LDI = 0x0a,
    STI = 0x0b,
    FORK = 0x0c,
    LLD = 0x0d,
    LLDI = 0x0e,
    LFORK = 0x0f,
    AFF = 0x10
} op_ind_t;

extern const op_t op_tab[];

/*
struct champion
    meme parsing que robot replis la structure pour que ensuite je puisse
    l'utiliser dans l'intruction live :)

    uint8_t c'est la meme chose que des char mais au lieux d'etre des chars
    ce sont des chiffres de 0 a 255 en gros c'est plus stylé
*/

/* WE ARE NOT SUPPOSE TO TOUCH THIS STRUCT */
typedef struct header_s {
    int magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_size;
    char comment[COMMENT_LENGTH + 1];
} header_t;

    #define HEADER_SIZE sizeof(header_t)

/*
    struct process
    program counter
    r1 to r16
    0 or 1 needed for some instructions
    next if fork (pas sur de ca encore)

*/

typedef struct proc_s {
    size_t pc;
    size_t cldwn;
    bool alive;
    struct proc_s *next;
} proc_t;

typedef struct champ_s {
    size_t carry;
    size_t reg[REG_NUMBER];
    size_t id;
    char prog_name[PROG_NAME_LENGTH + 1];
    size_t prog_size;
    char comment[COMMENT_LENGTH + 1];
    uint8_t *code;
    proc_t *process;
    bool is_alive;
} champ_t;

/*
    vm main struct
    4 champ max
    arenna
    cycle count
    limited cycles count
    last champ to be alive

*/
    #define NB_CHAMP 4
    #define NB_PATH_CHAMP 5

typedef struct info_cor_files_s info_cor_files_t;

typedef struct vm_s {
    champ_t champ[NB_CHAMP];
    info_cor_files_t info_cor_files;
    uint8_t arena[MEM_SIZE];
    size_t cycle;
    size_t cur_cycle;
    size_t dump_cycle;
    size_t nb_live;
    size_t nb_robots;
} vm_t;

#endif /* _OP_H_ */
