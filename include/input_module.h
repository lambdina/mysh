/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#ifndef INPUT_MODULE_H_INCLUDED
#define INPUT_MODULE_H_INCLUDED

#include <stdlib.h>
#include <wordexp.h>
#include "istl/hash_table.h"
#include "istl/vector.h"
#include "istl/string.h"

typedef enum StandardDev {STD_IN, STD_OUT} (devt_t);

typedef struct Redirection {
    char type[2 + 1];   //!< Redirection operator (<, >>, <<<, ...)
    char *from;     //!< If input: right argument, if output: left argument
    char *to;       //!< If input: left argument, if output: right argument
} (rd_t);

typedef struct Redirection (rdr_t);

#define RT_NULL (0x00)
#define RT_FD (0x01) 
#define RT_FN (0x02)

typedef struct Command {
    vector_t *args;
    vector_t *rds;
    char op[3];
    int pipe[2];
} (cmd_t);

int input_read(vector_t *expr, char *hfile, int *ecode);
int input_eval(vector_t *expr);
int prompt_cmd(char **prompt, char *hfile);
int expand_cmd_args(cmd_t *prompt);
list_t *extract_all_args(string_t const *argline);
int prompt_format(char const *prompt, vector_t *expr, int *state);
int parse_for_errors(vector_t *vec);
char **vector_to_char(vector_t *expr);
int cmd_from_match(map_t *match, cmd_t *cmd);
int cmd_extract_rdrs(cmd_t *);
int cmd_pipes(cmd_t const *);
typedef int (*rdr_extr_ft)(cmd_t *, int[]);
typedef struct ExtrPair {
    char op[2 + 1];
    rdr_extr_ft extr;
} (epair_t);
rdr_extr_ft get_rdr_extr(char const *);
int extract_r_rdr(cmd_t *, int[3]);
int extract_rd_rdr(cmd_t *, int[3]);
int extract_dr_rdr(cmd_t *, int[3]);
int extract_l_rdr(cmd_t *, int[3]);
int extract_dl_rdr(cmd_t *, int[3]);
bool_t valid_rd_arg(string_t *str);
bool_t rd_in(const rd_t *rd);
bool_t rd_out(const rd_t *rd);
int apply_pipes(int fds[2]);
void from_wordexp(wordexp_t we, vector_t *exp);
void backup_io(int fd[2]);
void reset_io(int fd[2]);
bool_t regex_error(int val, int *err);
void vector_discard(vector_t *expr, bool_t);
vector_t *expand_aliases(vector_t *args);
void manage_pipes(cmd_t *cmd, cmd_t *last, int rw[2]);
void manage_discard(cmd_t *cmd, vector_t *expr, int res);

extern const epair_t RPAIRS[];

#endif
