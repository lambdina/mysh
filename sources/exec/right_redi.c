/*
** EPITECH PROJECT, 2020
** righ_redi
** File description:
** function that handles right redirections.
*/

#include "exec.h"
#include "lib.h"
#include "env_handling.h"
#include "input_module.h"

int right_redirections(rd_t *rd)
{
    int fd = 0;
    int flag = my_strcmp(rd->type, ">") ? O_APPEND : O_TRUNC;

    fd = open(rd->to, O_CREAT | O_WRONLY | flag, 0664);
    if (fd == -1)
        return -1;
    if (rd->from != NULL && !my_strcmp(rd->from, "&"))
        dup2(fd, 2);
    dup2(fd, 1);
    return 0;
}
