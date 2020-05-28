/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <wordexp.h>
#include "istl/utility.h"
#include "istl/vector.h"
#include "istl/string.h"
#include "input_module.h"

int expand_cmd_args(cmd_t *cmd)
{
    vector_t *exp = NULL;
    wordexp_t we;
    string_t *str = NULL;

    if (cmd == NULL || vector_len(cmd->args) < 1)
        return (-1);
    exp = vector_create(MB_STR);
    for (uint_t i = 0; i < vector_len(cmd->args); i++) {
        str = vector_get(cmd->args, i);
        if (wordexp(str_cstr(str), &we, WRDE_NOCMD)) {
            vector_push(exp, str);
            continue;
        }
        from_wordexp(we, exp);
        wordfree(&we);
    }
    vector_free(&cmd->args);
    cmd->args = exp;
    return (0);
}

list_t *extract_all_args(string_t const *argline)
{
    list_t *list = list_create(MB_STR);
    map_t *match = map_create(5, MB_STR);
    string_t *str = NULL;
    int state = 0;

    if (argline == NULL)
        return (list_free(&list), map_free(&match), NULL);
    while (regex_extract(str_cstr(argline),
                REGEX_CMD_ARG, match, &state) != FALSE) {
        str = map_get(match, 1);
        list_push_back(list, str);
        argline = map_get(match, 2);
    }
    map_free(&match);
    return (list);
}

int cmd_extract_rdrs(cmd_t *cmd)
{
    string_t *str = NULL;
    rdr_extr_ft extr = NULL;

    if (cmd == NULL || vector_len(cmd->args) < 2)
        return (-1);
    cmd->rds = (cmd->rds == NULL) ?
        vector_create((mdata_t){0, 0, sizeof(rdr_t)}) : cmd->rds;
    for (uint_t i = 0; i < vector_len(cmd->args); i++) {
        str = vector_get(cmd->args, i);
        if (str == NULL)
            continue;
        extr = get_rdr_extr(str_cstr(str));
        if (extr == NULL)
            continue;
        extr(cmd, (int[]){i - 1, i, i + 1});
    }
    vector_narrow(cmd->args);
    return (0);
}
