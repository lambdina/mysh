/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** exec_redi.c
*/

#include "exec.h"
#include "lib.h"
#include "env_handling.h"
#include "input_module.h"

bool missing_file(rd_t rd)
{
    if (rd.type != NULL && rd.to == NULL)
        return true;
    return false;
}

int handle_cmd_rds(vector_t *rds)
{
    rd_t *rd = NULL;

    rds = sort_by_prior(rds);
    for (uint_t i = 0; i < vector_len(rds); i++) {
        rd = vector_get(rds, i);
        if (missing_file(*rd))
            return error_msg(NULL, MISS_NAME_REDI);
        if (open_fd(rd)) {
            if (errno == EACCES)
                return error_msg(rd->to, PERM_DENIED);
            if (errno == EISDIR)
                return error_msg(rd->to, IS_A_DIR);
            if (errno == ENOENT)
                return error_msg(rd->to, NO_SUCH_FILE);
        }
    }
    return 0;
}

vector_t *sort_by_prior(vector_t *redi)
{
    rd_t *redirections = NULL;

    redirections = vector_get(redi, 1);
    if (redirections != NULL && redirections->type[0] == '>')
        vector_iswap(redi, 0, 1);
    return redi;
}

int open_fd(rd_t *rd)
{
    if (rd->type == NULL)
        return 0;
    if (rd->type[0] == '>')
        return right_redirections(rd);
    if (rd->type[0] == '<')
        return left_redi(rd);
    return -1;
}
