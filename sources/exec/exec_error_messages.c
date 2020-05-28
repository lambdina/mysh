/*
** EPITECH PROJECT, 2020
** exec_error_messages.c
** File description:
** displays specific errors
*/

#include "lib.h"
#include "exec.h"
#include <errno.h>
#include <string.h>

const exec_error_t ERRORS[] = {
    {": Exec format error. Wrong Architecture.\n", 1},
    {": Command not found.\n", 1},
    {": Permission denied.\n", 1},
    {": Not a directory.\n", 1},
    {": No such file or directory.\n", 1},
    {": Too many arguments.\n", 1},
    {": No arguments are accepted.\n", 1},
    {": Variable name must contain alphanumeric characters.\n", 1},
    {": Too few arguments.\n", 1},
    {": Is a directory.\n", 1},
    {"Invalid null command.\n", 1},
    {"Ambiguous output redirect.\n", 1},
    {"Ambiguous input redirect.\n", 1},
    {"Missing name for redirect.\n", 1},
    {"Too many )'s.\n", 1},
    {"Too many ('s.\n", 1},
    {"Unmatched '\"'.\n", 1},
    {"Unmatched '''.\n", 1},
    {NULL, 0}
};

int error_msg(char *command, exec_error_type_t type)
{
    my_puterror(command);
    if (type == TRIGGER_STRERROR) {
        my_puterror(": ");
        my_puterror(strerror(errno));
        my_puterror("\n");
        return (int)errno;
    }
    my_puterror(ERRORS[type].message);
    return (ERRORS[type].return_value);
}
