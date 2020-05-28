/*
** EPITECH PROJECT, 2020
** compare_string.c
** File description:
** tools used to compare char * arrays
*/

#include <stdbool.h>
#include <stdio.h>

int my_strcmp(const char *s1, const char *s2)
{
    int i = 0;

    if ((s1 == (void *)0 || s1[0] == '\0') ||
    (s2 == (void *)0 || s2[0] == '\0'))
        return (-1);
    for (; s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'; i++);
    return (s1[i] - s2[i]);
}

int my_strncmp(const char *s1, const char *s2, int n)
{
    int i = 0;

    if ((s1 == (void *)0 || s1[0] == '\0') ||
    (s2 == (void *)0 || s2[0] == '\0'))
        return (-1);
    for (; i < n && (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'); i++);
    return (s1[i] - s2[i]);
}
