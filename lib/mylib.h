/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** mylib.h
*/

#ifndef MY_LIB_H
    #define MY_LIB_H
    #define LIB_EXIT_SUCCESS 0
    #define LIB_EXIT_FAIL 84
    #define LIB_EXIT_ERROR -1
    #define LIB_EXIT_PASSED 1
    #define LIB_STDOUT 1
    #define LIB_STDERR 2
    #define NONE NULL
    #define ONE NULL

int d_putchar(int fd, char const c);
int d_putstr(int fd, char const *str);
int stringlen(char const *str);
char *revstr(char *str);
void convert_base(int fd, unsigned long nb, int base);
int hexa_base(int fd, unsigned long nb);
int strcmpare(char const *str1, char const *str2);
int d_putnbr(int fd, int nb);
int d_ptr(int fd, void *ptr);
int memoryset(char *str, int size);
int d_mini_printf(int fd, char const *format, ...);
int charisalpha(char const c);
char *stringdup(char const *str);
char *stringcpy(char *dest, char const *src);
int free_array(char **array);
void print_array(char **array);
int isnegative(char *str);
int char_isnumber(char l);
int string_isnumber(char *str);
int getnumber(char *str);

#endif /* MY_LIB_H */
