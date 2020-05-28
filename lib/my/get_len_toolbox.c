/*
** EPITECH PROJECT, 2020
** get_len_toolbox.c
** File description:
** any function that gets the length of an array or a variable
*/

int my_nblen(int nb)
{
    int result = 0;

    nb = nb < 0 ? nb * -1 : nb;
    if (nb == 0)
        return (0);
    for (; nb > 0; nb = nb / 10)
        result++;
    return (result);
}

int my_strlen(char const *s)
{
    int result = 0;

    if (s == (void *)0 || s[0] == '\0')
        return (result);
    for (; s[result] != '\0'; result++);
    return (result);
}

int my_tablen(char const **tab)
{
    int result = 0;

    if (tab == (void *)0 || tab[0] == (void *)0)
        return (0);
    for (; tab[result] && tab[result] != (void *)0; result++);
    return (result);
}
