/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#include <stdlib.h>
#include <unistd.h>
#include "istl/string.h"
#include "istl/utility.h"

uint_t str_count(string_t const *str, char c)
{
    uint_t len = 0;
    uint_t count = 0;

    if (str == 0)
        return (0);
    len = str_len(str);
    for (uint_t i = 0; i < len; i++) {
        if (str_cstr(str)[i] == c)
            count += 1;
    }
    return (count);
}

void str_pick(string_t *str, char c)
{
    char *nstr = 0;
    uint_t nlen = 0;

    if (str == 0)
        return;
    nlen = str_len(str) - str_count(str, c);
    nstr = malloc(sizeof(char) * (nlen + 1));
    nstr[nlen] = 0;
    for (uint_t i = 0, j = 0; i < str_len(str); i++) {
        if (str_cstr(str)[i] == c)
            continue;
        nstr[j] = str_cstr(str)[i];
        j += 1;
    }
    str->cstr = nstr;
    str->length = nlen;
}

list_t *str_split(string_t const *str, char c)
{
    list_t *splitted = 0;
    uint_t last = 0;
    uint_t len = 0;
    uint_t cur = 0;
    string_t *substr = 0;

    if (str == 0)
        return (0);
    splitted = list_create(MB_STR);
    len = str_len(str);
    for (uint_t i = 0; i < len; i++) {
        if (str_cstr(str)[i] == c || (i == len - 1)) {
            cur = (i == len - 1) ? i : i - 1;
            substr = str_substr(str, last, cur);
            list_push_back(splitted, substr);
            str_free(&substr);
            last = i + 1;
        }
    }
    return (splitted);
}

list_t *str_nsplit(string_t const *str, char c, uint_t count)
{
    list_t *splitted = 0;
    uint_t last = 0;
    uint_t cur = 0;
    string_t *substr = 0;

    if (str == 0)
        return (0);
    splitted = list_create(MB_STR);
    for (uint_t i = 0, j = 0; i < str_len(str) && j <= count; i++) {
        if (str_cstr(str)[i] == c || (i == str_len(str) - 1)) {
            cur = (i == str_len(str) - 1) ? i : i - 1;
            cur = (j == count) ? str_len(str) : cur;
            substr = str_substr(str, last, cur);
            list_push_back(splitted, substr);
            str_free(&substr);
            last = i + 1;
            j += 1;
        }
    }
    return (splitted);
}

bool_t str_cmp(string_t const *lhs, string_t const *rhs)
{
    uint_t len = 0;

    if (lhs == 0) {
        if (rhs == 0)
            return (TRUE);
        return (FALSE);
    }
    if (str_len(lhs) != str_len(rhs))
        return (FALSE);
    len = str_len(lhs);
    for (uint_t i = 0; i < len; i++) {
        if (str_cstr(lhs)[i] != str_cstr(rhs)[i])
            return (FALSE);
    }
    return (TRUE);
}
