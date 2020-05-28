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

const meta_bundle_t MB_STR = {
    str_copy,
    str_destroy,
    sizeof(string_t)
};

void *str_copy(void const *str)
{
    string_t *nstr = 0;

    if (str == 0)
        return (0);
    nstr = (string_t *)str;
    nstr = str_dup(nstr);
    return (nstr);
}

void str_print(string_t const *str)
{
    uint_t len;
    char const *cstr = 0;

    cstr = str_cstr(str);
    len = str_len(str);
    write(1, cstr, len);
}

void str_errprint(string_t const *str)
{
    uint_t len;
    char const *cstr = 0;

    cstr = str_cstr(str);
    len = str_len(str);
    write(2, cstr, len);
}

void str_destroy(void *data)
{
    string_t *str = (string_t *)data;

    if (str == 0)
        return;
    str_free(&str);
}

string_t *str_create(const cchar_t cstr)
{
    string_t *nstr = malloc(sizeof(string_t));
    uint_t len = 0;

    nstr->cstr = 0;
    if (cstr != 0) {
        for (len = 0; cstr[len] != 0; len++);
        nstr->cstr = (char *)mem_copy(cstr, len + 1);
    }
    nstr->length = len;
    return (nstr);
}
