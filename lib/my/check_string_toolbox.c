/*
** EPITECH PROJECT, 2020
** check_string_toolbox
** File description:
** checking if a string matches with a specific pattern
*/

#include <stdbool.h>

bool is_num(const char *s)
{
    if (s == (void *)0 || s[0] == '\0')
        return (false);
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != '-' && (s[i] > '9' || s[i] < '0'))
            return (false);
    }
    return (true);
}

bool is_a_letter(char c, bool is_lower)
{
    int offset = is_lower == true ? 0 : 32;

    return (c >= 'a' + offset && c <= 'z' + offset ? true : false);
}

bool is_alphabetic(char *s)
{
    if (s == (void *)0 || s[0] == '\0')
        return (false);
    for (int i = 0; s[i] != '\0'; i++) {
        if (!is_a_letter(s[i], false) && !is_a_letter(s[i], true))
            return (false);
    }
    return (true);
}

int is_in_string(const char *s, char to_find)
{
    if (s == (void *)0 || s[0] == '\0')
        return (-1);
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == to_find)
            return (i);
    }
    return (-1);
}

char *get_last_occurence_of(char *s, char to_find)
{
    int position = is_in_string(s, to_find);

    if (position < 0)
        return (s);
    return (get_last_occurence_of(&s[position + 1], to_find));
}
