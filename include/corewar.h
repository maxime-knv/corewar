/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** corewar.h
*/

#ifndef COREWAR_H
    #define COREWAR_H
    //       |        |
    #define EXIT_SUCCESS 0
    #define EXIT_FAIL 84
    #define EXIT_ERROR -1
    #define EXIT_PASSED 1
    #define EXIT_HELP 104
    //       |        |
    #define FILE_FALURE -1
    //       |        |
    #define CORE_TRUE 0
    #define CORE_FALSE -1
    //       |        |
    #define CB_LEN 4
    //       |        |
    #include <stddef.h>
    #include <stdbool.h>
    #include <inttypes.h>
    //       |        |
    #define __maybe_unused  __attribute__((unused))
    //       |        |
    #define STDOUT 1
    #define STDERR 2
    //       |        |
    #define NONE NULL
    //       |        |
    #define PATH_COREWAR_H "src/error_handling/core_h/.corewar_h"
    #define ARRAY_SIZE(array) (unsigned int)(sizeof(array) / sizeof(*array))
    //       |        |
    #define READ_BIN "rb"
    #define DUMP_FLAG "-dump"
    #define N_FLAG "-n"
    #define FILE_TYPE ".cor"
    //       |        |
    #define DOUBLE_DEFINITION 2
    #define NEXT_PLUS_ONE 1
    #define NEXT_PLUS_TWO 2
    #define NEXT_PLUS_THREE 3
    //       |        |
    #define ONE_ROBOT 1
    #define FOUR_ROBOT 4
    //       |        |
    #define SKIP_MAGIC 4
    #define SKIP_BINARY 1
    //       |        |
    #define INIT_ZERO 0
    #define INIT_ONE 1

typedef struct champ_s champ_t;
typedef struct vm_s vm_t;

typedef struct info_cor_files_s {
    size_t *file_indexs;
    size_t nb_indexs;
    char **cor_files_path;
    size_t dump_flag;
    size_t start_dump_flag;
    size_t n_flag;
    size_t index_champ_n_flag;
} info_cor_files_t;

typedef struct info_file_s {
    char *line;
    size_t n;
} info_file_t;

typedef struct mem_index_s {
    size_t mem_index_name;
    size_t mem_index_comment;
} mem_index_t;

/* bonus */

int init_ncurses(void);
void display_arena(vm_t *vm);


/* parsing */
int file_parsing(int ac, char **av, vm_t *vm);
int read_cor_files(champ_t *champ, info_cor_files_t *info_cor_files);
int get_info_path_files(int ac, char **av,
    info_cor_files_t *info_cor_files);
int is_specific_flag(info_cor_files_t *info_cor_files,
    char **av, size_t index);
void process_n_flag(vm_t *vm);

/* corewar loop */
int corewar_loop(vm_t *vm);

    #define SIM_FORK 0
    #define L_FORK 1
int add_node(vm_t *vm, int i, size_t *pc, size_t choose_fork);

/* exec_ins */
int exec_live(__maybe_unused vm_t *vm, __maybe_unused int i,
    __maybe_unused size_t *pc);
int exec_ld(__maybe_unused vm_t *vm, __maybe_unused int i,
    __maybe_unused size_t *pc);
int exec_st(__maybe_unused vm_t *vm, __maybe_unused int i,
    __maybe_unused size_t *pc);
int exec_add(__maybe_unused vm_t *vm, __maybe_unused int i,
    __maybe_unused size_t *pc);
int exec_sub(__maybe_unused vm_t *vm, __maybe_unused int i,
    __maybe_unused size_t *pc);
int exec_and(__maybe_unused vm_t *vm, __maybe_unused int i,
    __maybe_unused size_t *pc);
int exec_or(__maybe_unused vm_t *vm, __maybe_unused int i,
    __maybe_unused size_t *pc);
int exec_xor(__maybe_unused vm_t *vm, __maybe_unused int i,
    __maybe_unused size_t *pc);
int exec_zjump(__maybe_unused vm_t *vm, __maybe_unused int i,
    __maybe_unused size_t *pc);
int exec_ldi(__maybe_unused vm_t *vm, __maybe_unused int i,
    __maybe_unused size_t *pc);
int exec_sti(__maybe_unused vm_t *vm, __maybe_unused int i,
    __maybe_unused size_t *pc);
int exec_fork(__maybe_unused vm_t *vm, __maybe_unused int i,
    __maybe_unused size_t *pc);
int exec_lld(__maybe_unused vm_t *vm, __maybe_unused int i,
    __maybe_unused size_t *pc);
int exec_lldi(__maybe_unused vm_t *vm, __maybe_unused int i,
    __maybe_unused size_t *pc);
int exec_lfork(__maybe_unused vm_t *vm, __maybe_unused int i,
    __maybe_unused size_t *pc);
int exec_aff(__maybe_unused vm_t *vm, __maybe_unused int i,
    __maybe_unused size_t *pc);
int exec_null(__maybe_unused vm_t *vm,
    __maybe_unused int i, __maybe_unused size_t *pc);

/* error handling */
int error_handling(int ac, char **av);
int check_nb_param(int ac);
int check_files(int ac, char **av);
size_t get_file_size(char const *filename);
int check_file_errors(const char *file);

/* files actions */
int browse_files_actions(int ac, char **av);

/* free */
void free_champ_struct(champ_t *champ, size_t n_bodies);
void free_info_files(info_cor_files_t *info_cor_files);

/* arena */
void set_arena(vm_t *vm, champ_t *champ, size_t nb_champ);
void display_arena(vm_t *vm);

/* corewar -h */
int display_h(int ac, char **av);

/* utils */
int check_cb(uint8_t recieved_cb, uint8_t to_check, uint8_t *cb_arr);
void compose_val(int *val, uint8_t *tab, size_t size);
void decompose_val(size_t val, uint8_t *tab, size_t size);
size_t get_pos(size_t pc, uint8_t *args, size_t move_in_cb);
void insert_to_map(vm_t *vm, size_t size, void *val, size_t where);
void move_pc(uint8_t *cb_arr, size_t *pc, __maybe_unused int nb);
uint8_t *read_coding_byte(uint8_t cb, uint8_t *args);
void read_map(vm_t *vm, size_t size, void *val, size_t where);

typedef struct exec_instruction {
    int (*exec_ins)(vm_t *, int, size_t *);
} exec_instruction_t;

static const exec_instruction_t instruction_list[] = {
    {exec_null},
    {exec_live},
    {exec_ld},
    {exec_st},
    {exec_add},
    {exec_sub},
    {exec_and},
    {exec_or},
    {exec_xor},
    {exec_zjump},
    {exec_ldi},
    {exec_sti},
    {exec_fork},
    {exec_lld},
    {exec_lldi},
    {exec_lfork},
    {exec_aff}
};

typedef enum {
    FEW_WARRIOR,
    MANY_WARRIOR,
    DOT_COR_FILE,
    ERR_DUMP_FLAG,
    ERR_N_FLAG,
} message_t;

static const char *errmessage[] __maybe_unused = {
    [FEW_WARRIOR] = "INIT: Too few warrior",
    [MANY_WARRIOR] = "INIT: Too many warrior",
    [DOT_COR_FILE] = "INIT: Not a .cor file",
    [ERR_DUMP_FLAG] = "INIT: Wrong flag -dump definition",
    [ERR_N_FLAG] = "INIT: Wrong flag -n definition",
};

#endif /* COREWAR_H */
