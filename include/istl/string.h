/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#ifndef IS_STRING_H_INCLUDED
#define IS_STRING_H_INCLUDED

#include "common_types.h"
#include "list.h"

typedef struct String {
    char *cstr;
    uint_t length;
} string_t;

extern const meta_bundle_t MB_STR;
void *str_copy(void const *str);
void str_destroy(void *str);

string_t *str_create(const cchar_t cstr);
string_t *str_wcreate(char *cstr);
void str_free(string_t **str);
cchar_t str_cstr(string_t const *str);
char *str_to_cstr(string_t const *str);
string_t *str_dup(string_t const *str);
string_t *str_concat(string_t const *lhs, string_t const *rhs);
string_t *str_cconcat(cchar_t lhs, cchar_t rhs);
string_t *str_addch(string_t const *lhs, char rhs);
string_t *str_substr(string_t const *lhs, uint_t start, uint_t end);
bool_t str_cmp(string_t const *lhs, string_t const *rhs);
bool_t str_ccmp(string_t const *lhs, cchar_t rhs);
void str_print(string_t const *str);
void str_errprint(string_t const *str);
uint_t str_len(string_t const *str);
uint_t str_count(string_t const *str, char c);
void str_pick(string_t *rstr, char c);
void str_strip(string_t *str);
void str_cnstrip(string_t *str, char c, uint_t l, uint_t r);
void str_replace(string_t *str, char a, char b);
list_t *str_split(string_t const *str, char c);
list_t *str_nsplit(string_t const *str, char c, uint_t count);

#endif
