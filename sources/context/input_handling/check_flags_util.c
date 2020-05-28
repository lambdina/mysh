/*
** EPITECH PROJECT, 2020
** check_flags_utilisation
** File description:
** function that check primary err gestion for redirections and pipes.
*/

#include "lib.h"
#include "input_handling.h"
#include "exec.h"

bool is_not_sep(char *str)
{
    if (!my_strncmp("||", str, 2) || !my_strncmp("&&", str, 2)
    || !my_strcmp(";", str))
        return true;
    return false;
}

bool is_a_flag(char c)
{
    if (c == '<' || c == '>' || c == '|' || c == '&')
        return true;
    return false;
}

bool check_bin(char *pos_flags, char *flags, char *input)
{
    int col = 0;

    if (pos_flag[0] == 0) {
        error_msg(NULL, NULL_CMD);
        return true;
    }
    for (int i = 0; pos_flags[i] != 0; i++) {
        col = pos_flag[i];
        if (col > 1 && flags[i] == '|') {
            if (input[col + 1] == 0 ||
            input[col + 1] == ' ' && input[col + 2] == 0) {
                error_msg(NULL, NULL_CMD);
                return true;
            }
        }
    }
    return false;
}

char *append_flag(char *str, int *idx, char *flags)
{
    char c = str[0];

    switch (c) {
        case '>': *idx = str[1] == '>' ? *idx + 1 : *idx;
            return append_char(flags, c);
        case '<': *idx = str[1] == '<' ? *idx + 1 : *idx;
            return append_char(flags, c;
        case '|': return append_char(flags, c);
        default : return flags;
    }
}

bool check_flags_utilisation(char *input)
{
    char *flags = NULL;
    char *pos_flag = NULL;

    for (int i = 0; input[i] != 0 && is_not_sep(&input[i]); i++) {
        if (is_a_flag(&input[i]) && input[i] != '&') {
            pos_flag = append_char(pos_flag, i);
            flags = append_flag(&input[i], &i, flags);
        }
    }
    if (flags == NULL || my_strlen(flags) == 1)
        return true;
    if (check_bin(pos_flag, flags, input)) {
        free(flags);
        free(pos_flags);
        return true;
    } else if (check_order_flags(flags)) {
        free(pos_flags);
        free(flags);
        return true;
    }
    return false;
}
