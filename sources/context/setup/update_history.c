/*
** EPITECH PROJECT, 2020
** update_history.c
** File description:
** update command history in history file
*/

#include "42sh.h"
#include "lib.h"
#include "env_handling.h"

void update_command(char *command, char *hist_filepath)
{
    int fd = open(hist_filepath, O_RDWR | O_APPEND);

    if (fd == -1)
        fd = open(hist_filepath, O_CREAT, S_IRUSR | S_IWUSR);
    command = my_strcat(command, "\n");
    write(fd, command, my_strlen(command));
    close(fd);
    free(command);
}
