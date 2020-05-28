/*
** EPITECH PROJECT, 2020
** exec.h
** File description:
** exec module header
*/

#ifndef EXEC_H
#define EXEC_H

#include "builtins.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <stdbool.h>
#include "istl/vector.h"
#include "input_module.h"

extern char **environ;

#ifndef IN
#define IN (1)
#endif

#ifndef OUT
#define OUT (0)
#endif

typedef enum error_type_s
{
    WRG_ARCH,
    CMD_NOT_FOUND,
    PERM_DENIED,
    NOT_A_DIR,
    NO_SUCH_FILE,
    TOOMANY_ARGS,
    NOARGS_ACC,
    ALPHANUM,
    TOOFEW_ARGS,
    IS_A_DIR,
    NULL_CMD,
    AMBIGUOUS_OPT,
    AMBIGUOUS_IPT,
    MISS_NAME_REDI,
    TOO_MANY_CL_PAR,
    TOO_MANY_OP_PAR,
    UNMATCHED_DQUOTES,
    UNMATCHED_SQUOTES,
    TRIGGER_STRERROR
} exec_error_type_t;

typedef struct exec_error_s
{
    char *message;
    int return_value;
} exec_error_t;

// located in exec_error_messages.c
extern const exec_error_t ERRORS[];

// exec_error_handling.c
int check_if_directory(char *dir_path);
int check_if_segfault(int status);
int execve_error(char *input, char *input_with_path);

// exec_error_messages.c
int error_msg(char *command, exec_error_type_t type);

typedef struct Command (cmd_t);

// exec.c
int exec(cmd_t *, int return_value, int rw[2]);
int init_execve(cmd_t *, int return_value, int rw[2]);
char *get_exec_input(char *input);
char **get_all_exec_ipt(char *, char **);

builtin_t check_if_builtin_or_dir(char **input, int *rvalue);

// exec_redi.c
bool missing_file(rd_t rd);
int handle_cmd_rds(vector_t *rds);
vector_t *sort_by_prior(vector_t *redi);
int open_fd(rd_t *rd);

// left_redi.c
int left_redi(rd_t *);

// right_redi.c
int right_redirections(rd_t *);

#endif
