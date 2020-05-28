/*
** EPITECH PROJECT, 2020
** input_handling.h
** File description:
** input handling module header
*/

#include <signal.h>
#include "istl/hash_table.h"
#include "istl/utility.h"
#include "istl/string.h"

#ifndef INPUT_HANDLING_H
#define INPUT_HANDLING_H

// init_shell.c
void handle_main_loop(void);

// read_user_input.c
map_t *read_user_input(char *history_filepath);

// update_history.c
void update_command(char *command, char *hist_filepath);

// init_shell.c
char *setup_shell(void);

// check_flags_util.c
bool is_not_sep(char *str);
bool is_a_flag(char c);
char *check_bin(char *, char *, char);
char *append_flag(char *, int *, char *);
bool check_flags_utilisation(char *);

// check_flags_util2.c
bool check_order_flags(char *);

#endif
