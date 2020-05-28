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

string_t *str_cconcat(cchar_t c_lhs, cchar_t c_rhs)
{
    string_t *lhs = str_create(c_lhs);
    string_t *rhs = str_create(c_rhs);
    string_t *res = str_concat(lhs, rhs);

    str_free(&lhs);
    str_free(&rhs);
    return (res);
}

string_t *str_substr(string_t const *lhs, uint_t start, uint_t end)
{
    uint_t len = 0;
    uint_t nlen = 0;
    char *substr = 0;

    if (lhs == 0)
        return (0);
    len = str_len(lhs);
    start = expect_uint(start, 0, len);
    end = expect_uint(end, start, len);
    nlen = end - start + 1;
    substr = malloc(sizeof(char) * (nlen + 1));
    for (uint_t i = start; i <= end; i++) {
        substr[i - start] = str_cstr(lhs)[i];
    }
    substr[nlen] = '\0';
    return (str_wcreate(substr));
}

string_t *str_addch(string_t const *lhs, char rhs)
{
    char *tmp = 0;
    string_t *nstr = 0;
    string_t *ret = 0;

    if (lhs == NULL)
        return (NULL);
    tmp = malloc(sizeof(char) * 2);
    tmp[0] = rhs;
    tmp[1] = 0;
    nstr = str_wcreate(tmp);
    ret = str_concat(lhs, nstr);
    str_free(&nstr);
    return (ret);
}

uint_t str_len(string_t const *str)
{
    return (str->length);
}

bool_t str_ccmp(string_t const *lhs, cchar_t rhs)
{
    string_t *s_rhs = 0;
    bool_t res = FALSE;

    s_rhs = str_create(rhs);
    res = str_cmp(lhs, s_rhs);
    str_free(&s_rhs);
    return (res);
}
