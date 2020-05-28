/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <wordexp.h>
#include "lib.h"
#include "istl/utility.h"
#include "istl/hash_table.h"
#include "istl/string.h"
#include "input_module.h"
#include "input_handling.h"
#include "exec.h"

static bool_t is_redirection(string_t *str)
{
    (void)str;
    return (FALSE);
}

void list_clean(list_t *args)
{
    itr_t it;
    string_t *str = NULL;

    if (args == NULL)
        return;
    it = list_begin(args);
    for (; !list_final(args, it); it = it_next(it)) {
        str = it_data(it);
        if (str_len(str) == 0)
            list_pull(args, it);
    }
}

int cmd_from_match(map_t *match, cmd_t *cmd)
{
    list_t *args = NULL;
    string_t *op = NULL;

    if (match == NULL || cmd == NULL)
        return (-1);
    args = extract_all_args(map_get(match, 2));
    args = (args == NULL) ? list_create(MB_STR) : args;
    list_clean(args);
    cmd->args = vector_from_list(args);
    cmd->rds = NULL;
    op = map_get(match, 3);
    if (op == NULL)
        return (0);
    for (uint_t i = 0; i < str_len(op) && i < 3; i++)
        cmd->op[i] = str_cstr(op)[i];
    return (0);
}

char **vector_to_char(vector_t *expr)
{
    char **conv = NULL;

    if (expr == NULL)
        return (NULL);
    conv = malloc(sizeof(char *) * (vector_len(expr) + 1));
    conv[vector_len(expr)] = NULL;
    for (uint_t i = 0; i < vector_len(expr); i++) {
        conv[i] = str_to_cstr(vector_cget(expr, i));
    }
    return (conv);
}

bool_t regex_error(int val, int *err)
{
    int tmp = 0;

    if (err == NULL)
        return (TRUE);
    tmp = *err;
    *err = (val == -1) ? TOO_MANY_CL_PAR : *err;
    *err = (val == 6) ? TOO_MANY_OP_PAR : *err;
    *err = (val == 7) ? UNMATCHED_DQUOTES : *err;
    *err = (val == 9) ? UNMATCHED_SQUOTES : *err;
    *err = (val == 8) ? MISS_NAME_REDI : *err;
    if (tmp != *err)
        return (TRUE);
    return (FALSE);
}
