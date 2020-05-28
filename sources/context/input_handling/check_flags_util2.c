/*
** EPITECH PROJECT, 2020
** check_flags_utils2
** File description:
** function that check flags order.
*/

#include "lib.h"
#include "input_handling.h"
#include "exec.h"

bool check_order_flags(char *flags)
{
    for (int i = 0; flags[i] != 0; i++) {
        if (flags[i] == '>' && flags[i + 1] == '>') {
            error_msg(NULL, AMBIGUOUS_OPT);
            return true;
        }
        if (flags[i] == '>' && flags[i + 1] == '|') {
            error_msg(NULL, AMBIGUOUS_OPT);
            return true;
        }
        if (flags[i] == '<' && flags[i + 1] == '<') {
            error_msg(NULL, AMBIGUOUS_IPT);
            return true;
        }
    }
    return false;
}
