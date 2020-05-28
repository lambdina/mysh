/*
** EPITECH PROJECT, 2020
** malloc_toolbox
** File description:
** any function used to malloc a string
*/

#include "lib.h"
#include <stdlib.h>
#include <stdbool.h>

char *append_char(char *str, char to_add)
{
    char *result = NULL;
    int size = 0;

    if (str == NULL) {
        result = malloc(sizeof(char) * 2);
        result[0] = to_add;
        result[1] = 0;
    } else {
        size = my_strlen(str);
        result = malloc(sizeof(char) * (size + 2));
        result = my_strcpy(result, str);
        result[size] = to_add;
        result[size + 1] = 0;
        free(str);
    }
    return result;
}

char *my_strdup(const char *s)
{
    int len_string = my_strlen(s);
    char *result = (void *)0;
    int i = 0;

    if (len_string == 0)
        return ((void *)0);
    result = malloc(sizeof(char) * (len_string + 1));
    for (; s[i] != '\0'; i++)
        result[i] = s[i];
    result[i] = '\0';
    return (result);
}

char *my_strcat(const char *s1, const char *s2)
{
    int len_string = 0;
    char *result = (void *)0;
    int ctr = 0;
    int ctr2 = 0;

    if (s2 == (void *)0 || s2[0] == 0)
        return (my_strdup(s1));
    else if (s1 == (void *)0 || s1[0] == 0)
        return (my_strdup(s2));
    len_string = my_strlen(s1) + my_strlen(s2) + 1;
    if (len_string == 1)
        return ((void *)0);
    result = malloc(sizeof(char) * (len_string + 3));
    for (; s1[ctr] != '\0'; ctr++)
        result[ctr] = s1[ctr];
    for (; s2[ctr2] != '\0'; ctr2++)
        result[ctr + ctr2] = s2[ctr2];
    result[ctr + ctr2] = '\0';
    return (result);
}

char *my_itoa(int nb)
{
    int nb_len = my_nblen(nb);
    char *result = (void *)0;
    bool is_negative = nb < 0 ? true : false;

    if (nb == 0)
        return (my_strdup("0"));
    result = malloc(sizeof(char) * (nb_len + 1));
    nb = is_negative == true ? nb * -1 : nb;
    result[nb_len] = '\0';
    for (int i = nb_len - 1; i > -1; i--) {
        result[i] = (nb % 10) + 48;
        nb = nb / 10;
    }
    return (is_negative == true ? my_strcat("-", result) : result);
}

char **append_str(char **tab, char *str)
{
    int size = my_tablen((char const **)tab);
    char **res = size < 0 ? NULL : malloc(sizeof(char *) * (size + 2));
    int i = 0;

    if (str == NULL || str[0] == 0 || res == NULL)
        return tab;
    if (tab == NULL) {
        res = malloc(sizeof(char *) * 2);
        res[0] = my_strdup(str);
        res[1] = NULL;
        return (res);
    }
    for (; tab[i] != NULL; i++)
        res[i] = my_strdup(tab[i]);
    res[i] = my_strdup(str);
    res[i + 1] = NULL;
    free_tab((void **)tab);
    return (res);
}
