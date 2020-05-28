/*
** EPITECH PROJECT, 2020
** lib.h
** File description:
** bogdzn's C lib
*/

#ifndef LIB_H
#define LIB_H

// dont touch, necessary for get_next_line.c
#ifndef READ_SIZE
#define READ_SIZE (60)
#endif /* READ_SIZE */

// dont touch, necessary for do_op.c
typedef int(*ptr)(int, int);

#include <stdbool.h>

// write_toolbox.c
void my_putchar(char character);
void my_putstr(char const *string);
void my_puterror(char const *string);
void display_tab(char const **tab);

// get_len_toolbox.c
int my_nblen(int number);
int my_strlen(char const *string);
int my_tablen(char const **tab);

// malloc_toolbox.c
char *append_char(char *string, char to_append);
char *my_strdup(char const *string);
char *my_strcat(char const *s1, char const *s2);
char *my_itoa(int number);
char **append_str(char **, char *);

// conversions_toolbox.c
char *my_getnbr_base(int number, char const *base_to);
int my_getnbr(const char *number);

// get_next_line.c
char *copy_until(char *string, char delimiter, int start_point);
char *get_next_line(int fd);

// tabgen.c
char **tabgen(char const *string, char separator);

// copy_toolbox.c
char *my_strcpy(char *string, char const *to_copy);
char *my_strncpy(char *string, char const *to_copy, int n);

// misc.c
void free_if_not_null(void *array);
void free_tab(void **tab);
void swap(int *n1, int *n2);
void swap_array(void **array_one, void **array_two);
void swapc(char *char_one, char *char_two);

// check_string_toolbox.c
bool is_num(const char *string);
int is_in_string(char const *string, char to_find);
char *get_last_occurence_of(char *string, char to_find);
bool is_a_letter(char letter, bool is_uppercase);
bool is_alphabetic(char *string);

// number_toolbox.c
void my_putnbr(int number);
void my_putnbr_base(int number, char const *base);

// modify_strings.c
char *set_to_lowercase(char *string);
char *set_to_uppercase(char *string);
char *my_revstr(char *string);

// compare_string.c
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);

// do_op.c
int do_op(int nb1, int nb2, char sign);


#endif /* LIB_H */
