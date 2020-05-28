/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <string.h>
#include "exec.h"
#include <unistd.h>
#include "istl/vector.h"
#include "input_module.h"

bool_t valid_rd_arg(string_t *str)
{
    char const *cstr = NULL;
    bool_t res = TRUE;

    if (str == NULL)
        return (FALSE);
    cstr = str_cstr(str);
    res = !strcmp(cstr, "<") ? FALSE : res;
    res = !strcmp(cstr, "<<") ? FALSE : res;
    res = !strcmp(cstr, ">") ? FALSE : res;
    res = !strcmp(cstr, ">>") ? FALSE : res;
    res = !strcmp(cstr, ">&") ? FALSE : res;
    res = !strcmp(cstr, "|") ? FALSE : res;
    res = !strcmp(cstr, "&") ? FALSE : res;
    res = !strcmp(cstr, "&&") ? FALSE : res;
    res = !strcmp(cstr, "||") ? FALSE : res;
    res = !strcmp(cstr, ";") ? FALSE : res;
    return res;
}

bool_t rd_in(const rd_t *rd)
{
    bool res = FALSE;

    if (rd == NULL)
        return (FALSE);
    res = !strcmp(rd->type, "<") ? TRUE : res;
    res = !strcmp(rd->type, "<<") ? TRUE : res;
    return res;
}

bool_t rd_out(const rd_t *rd)
{
    bool res = FALSE;

    if (rd == NULL)
        return (FALSE);
    res = !strcmp(rd->type, ">") ? TRUE : res;
    res = !strcmp(rd->type, ">>") ? TRUE : res;
    res = !strcmp(rd->type, ">&") ? TRUE : res;
    return res;
}

int parse_rds_for_errors(cmd_t const *cmd, bool_t p_input)
{
    rd_t const *rd = NULL;
    int sti = (p_input == TRUE) ? 1 : 0;
    int sto = 0;

    if (cmd == NULL || cmd->rds == NULL)
        return 0;
    vector_narrow(cmd->rds);
    sto = (!strcmp(cmd->op, "|")) ? 1 : 0;
    for (uint_t i = 0; i < vector_len(cmd->rds); i++) {
        rd = vector_cget(cmd->rds, i);
        if (rd->to == NULL)
            return MISS_NAME_REDI;
        if (sti > 0 && rd_in(rd))
            return AMBIGUOUS_IPT;
        if (sto > 0 && rd_out(rd))
            return AMBIGUOUS_OPT;
        sti += rd_in(rd) ? 1 : 0;
        sto += rd_out(rd) ? 1 : 0;
    }
    return 0;
}

int parse_for_errors(vector_t *vec)
{
    cmd_t const *cmd = NULL;
    int rval = 0;
    cmd_t const *last = NULL;

    if (vec == NULL || vector_len(vec) == 0)
        return (NULL_CMD);
    for (uint_t i = 0; i < vector_len(vec); i++) {
        cmd = vector_cget(vec, i);
        rval = parse_rds_for_errors(cmd, cmd_pipes(last));
        if (rval != 0)
            return (rval);
        last = cmd;
    }
    return (0);
}
