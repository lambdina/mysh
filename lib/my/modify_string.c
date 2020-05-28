/*
** EPITECH PROJECT, 2020
** modify_strings.c
** File description:
** tools used to modify a char * array
*/

#include "lib.h"

char *set_to_lowercase(char *s)
{
    if (s == (void *)0 || s[0] == '\0')
        return ((void *)0);
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
    return (s);
}

char *set_to_uppercase(char *s)
{
    if (s == (void *)0 || s[0] == '\0')
        return ((void *)0);
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] -= 32;
    return (s);
}

char *my_revstr(char *s)
{
    int len_s = my_strlen(s) - 1;

    if (s == (void *)0 || s[0] == '\0')
        return ((void *)0);
    for (int i = 0; i < len_s; i++, len_s--)
        swapc((void *)&s[i], (void *)&s[len_s]);
    return (s);
}