/*
** EPITECH PROJECT, 2020
** conversion_toolbox.c
** File description:
** handles conversions between int and char and such.
*/

#include "lib.h"
#include <stdlib.h>
#include <stdbool.h>

int my_getnbr(const char *s)
{
    unsigned long long temp = 0;
    int result = 0;
    bool is_negative = false;

    if (s == (void *)0 || s[0] == '\0')
        return (0);
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '-')
            is_negative = is_negative == true ? false : true;
        else if (s[i] != '-' && (s[i] > '9' || s[i] < '0'))
            break;
        else temp = temp * 10 + (s[i] - 48);
    }
    result = (int)temp;
    if (temp != result)
        return (0);
    return (is_negative == true ? -result : result);
}

static int get_length_of_new_base(int nb, int base_len)
{
    int result = 0;

    nb = nb < 0 ? nb * -1 : nb;
    if (base_len == 0)
        return (0);
    for (; nb > 0; result++)
        nb = nb / base_len;
    return (result);
}

char *my_getnbr_base(int nb, const char *base_to)
{
    char *result = (void *)0;
    bool is_negative = nb < 0 ? true : false;
    int nb_len = get_length_of_new_base(nb, my_strlen(base_to));
    int base_len = my_strlen(base_to);
    int ctr = nb_len - 1;

    if (base_to == (void *)0 || base_to[0] == '\0')
        return ((void *)0);
    else if (nb == 0)
        return (my_strdup("0"));
    nb = nb < 0 ? nb * -1 : nb;
    result = malloc(sizeof(char) * (nb_len + 1));
    for (int tmp = 0; ctr >= 0; ctr--) {
        tmp = nb % base_len;
        result[ctr] = base_to[tmp];
        nb = nb / base_len;
    }
    result[nb_len] = '\0';
    return (is_negative == true ? my_strcat("-", result) : result);
}
