/*
** EPITECH PROJECT, 2020
** left_redi
** File description:
** function that handles left redierctions.
*/

#include "exec.h"
#include "lib.h"
#include "env_handling.h"
#include "input_module.h"

int left_redi(rd_t *rd)
{
    int pipe_fd[2] = {0, 0};
    int fd = 0;
    char *line = NULL;

    if (!my_strcmp(rd->type, "<")) {
        fd = open(rd->to, O_RDONLY);
        if (fd == -1)
            return fd;
        dup2(fd, 0);
        return 0;
    }
    if (!isatty(0))
        return 0;
    pipe(pipe_fd);
    apply_pipes(pipe_fd);
    while ((line = get_next_line(0)) != NULL && my_strcmp(line, rd->to))
        printf(" ? ");
    free(line);
    return 0;
}
