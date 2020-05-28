/*
** EPITECH PROJECT, 2020
** init_shell.c
** File description:
** minishell's interface with user, signal handling, etc...
*/

#include "lib.h"
#include "42sh.h"
#include "env_handling.h"
#include "builtins.h"
#include "input_handling.h"
#include "input_module.h"
#include "istl/vector.h"
#include "istl/hash_table.h"
#include "istl/utility.h"
#include "istl/string.h"
#include "builtins.h"
#include "exec.h"

void handle_main_loop(void)
{
    char *hist_filepath = setup_shell();
    vector_t *expr = vector_create((mdata_t) {0, 0, sizeof(cmd_t)});
    int rvalue = 0;

    while (1) {
        signal(SIGINT, SIG_IGN);
        if (input_read(expr, hist_filepath, &rvalue) != 0) {
            if (isatty(0))
                my_putstr("exit\n");
            free_tab((void **)environ);
            free(hist_filepath);
            exit(rvalue);
        }
        if (rvalue != 0) {
            rvalue = error_msg(NULL, rvalue);
            continue;
        }
        rvalue = input_eval(expr);
    }
}
