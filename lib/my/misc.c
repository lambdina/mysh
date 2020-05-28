/*
** EPITECH PROJECT, 2020
** misc.c
** File description:
** misceallenous functions
*/

#include "lib.h"
#include <stdlib.h>

void swap_array(void **one, void **two)
{
    void *temp = *one;

    *one = *two;
    *two = temp;
}

void swapc(char *one, char *two)
{
    char tmp = *two;

    *two = *one;
    *one = tmp;
}

void swap(int *one, int *two)
{
    int temp = *two;

    *two = *one;
    *one = temp;
}

void free_if_not_null(void *s)
{
    if (s != (void *)0)
        free(s);
}

void free_tab(void **tab)
{
    if (tab == (void *)0)
        return;
    for (int i = 0; tab[i] != (void *)0; i++)
        free(tab[i]);
    free(tab);
}
