/*
** EPITECH PROJECT, 2019
** copy_toolbox.c
** File description:
** functions needed to copy a string
*/

#include "lib.h"
#include <unistd.h>

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if ((src == NULL || src[0] == '\0'))
        return (NULL);
    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    if (src == NULL || src[0] == 0 || n < 1)
        return (NULL);
    for (; src[i] && i < n; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
