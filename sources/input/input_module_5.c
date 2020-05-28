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

int extract_rd_rdr(cmd_t *cmd, int idx[3])
{
    string_t *str[2] = {NULL};
    rdr_t rdr = (rdr_t) {">&", NULL, NULL};

    if (cmd == NULL || idx == NULL)
        return (-1);
    str[0] = vector_pull(cmd->args, idx[1]);
    str[1] = vector_get(cmd->args, idx[2]);
    if (valid_rd_arg(str[1])) {
        rdr.to = str_to_cstr(str[1]);
        str[1] = vector_pull(cmd->args, idx[2]);
        str_free(&str[1]);
    }
    vector_push(cmd->rds, &rdr);
    str[0] = vector_pull(cmd->args, idx[1]);
    str_free(&str[0]);
    return (0);
}

int cmd_pipes(cmd_t const *cmd)
{
    if (cmd == NULL)
        return (0);
    if (strcmp(cmd->op, "|") == 0)
        return (1);
    return (0);
}

int apply_pipes(int fds[2])
{
    if (fds == NULL)
        return (-1);
    if (fds[IN] != -1) {
        dup2(fds[IN], STDOUT_FILENO);
        close(fds[IN]);
        fds[IN] = -1;
    }
    if (fds[OUT] != -1) {
        dup2(fds[OUT], STDIN_FILENO);
        close(fds[OUT]);
        fds[IN] = -1;
    }
    return (0);
}

void vector_discard(vector_t *expr, bool_t stop_at_or)
{
    cmd_t *cmd = NULL;

    if (expr == NULL)
        return;
    for (uint_t i = 0; i < vector_len(expr); i++) {
        cmd = vector_pull(expr, i);
        if (cmd == NULL)
            continue;
        if (!strcmp(cmd->op, ";"))
            break;
        if (!strcmp(cmd->op, "||") && stop_at_or)
            break;
    }
}
