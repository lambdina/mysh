/*
** EPITECH PROJECT, 2020
** do_op.c
** File description:
** handles basic operation between two ints
*/

#include "lib.h"

static int mod(int nb1, int nb2)
{
    return (nb1 % nb2);
}

static int div(int nb1, int nb2)
{
    return (nb1 / nb2);
}

static int mult(int nb1, int nb2)
{
    return (nb1 * nb2);
}

static int sub(int nb1, int nb2)
{
    return (nb1 - nb2);
}

int do_op(int first, int second, char flag)
{
    ptr functions[] = {&sub, &mult, &div, &mod, (void *)0};
    char signs[] = {'-', '*', '/', '%', '\0'};
    int i = 0;

    if (flag == '+')
        return (first + second);
    for (; signs[i] != '\0'; i++)
        if (flag == signs[i])
            return (functions[i](first, second));
    return (0);
}
