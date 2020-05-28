/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include "lib.h"
#include "input_module.h"

const epair_t RPAIRS[] = {
    {"<", extract_l_rdr},
    {"<<", extract_dl_rdr},
    {">", extract_r_rdr},
    {">&", extract_rd_rdr},
    {">>", extract_dr_rdr},
};

rdr_extr_ft get_rdr_extr(char const *op)
{
    rdr_extr_ft func = NULL;
    int size = sizeof(RPAIRS) / sizeof(epair_t);

    for (int i = 0; i < size; i++)
        func = !my_strcmp(op, RPAIRS[i].op) ? RPAIRS[i].extr : func;
    return (func);
}

int extract_r_rdr(cmd_t *cmd, int idx[3])
{
    string_t *str[2] = {NULL};
    rdr_t rdr = (rdr_t) {">", NULL, NULL};

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

int extract_dr_rdr(cmd_t *cmd, int idx[3])
{
    string_t *str[2] = {NULL};
    rdr_t rdr = (rdr_t) {">>", NULL, NULL};

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

int extract_l_rdr(cmd_t *cmd, int idx[3])
{
    string_t *str[2] = {NULL};
    rdr_t rdr = (rdr_t) {"<", NULL, NULL};

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

int extract_dl_rdr(cmd_t *cmd, int idx[3])
{
    string_t *str[2] = {NULL};
    rdr_t rdr = (rdr_t) {"<<", NULL, NULL};

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
