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
#include "exec.h"

void manage_pipes(cmd_t *cmd, cmd_t *last, int rw[2])
{
    if (cmd_pipes(last)) {
        rw[OUT] = last->pipe[OUT];
        rw[IN] = -1;
    }
    if (cmd_pipes(cmd)) {
        pipe(cmd->pipe);
        rw[IN] = cmd->pipe[IN];
    }
}

void manage_discard(cmd_t *cmd, vector_t *expr, int res)
{
    if (res != 0 && strcmp(cmd->op, "&&") == 0)
        vector_discard(expr, TRUE);
    if (res == 0 && strcmp(cmd->op, "||") == 0)
        vector_discard(expr, FALSE);
}
