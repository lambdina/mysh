/*
** EPITECH PROJECT, 2020
** test_setenv.c
** File description:
** unit tests setenv built_in
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "42sh.h"
#include "builtins.h"
#include "env_handling.h"
#include "lib.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void redirect_all(void);

Test(reset_from_position, resettab)
{
    char **tab = tabgen("this is an array of string", ' ');

    tab = reset_from_position(2, tab);
    cr_assert_str_eq(tab[0], "this");
    cr_assert_str_eq(tab[1], "is");
    cr_assert_str_eq(tab[2], "array");
    cr_assert_str_eq(tab[3], "of");
    cr_assert_str_eq(tab[4], "string");
    free_tab((void **)tab);
}

Test(unsetenv_check_input, unsetenv_checkinput)
{
    char **valid = tabgen("unsetenv value asd", ' ');
    char **invalid = tabgen("unsetenv", ' ');

    cr_assert_eq(unsetenv_check_input(valid), 0);
    cr_assert_eq(unsetenv_check_input(invalid), -1);
    free_tab((void **)valid);
    free_tab((void **)invalid);
}

Test(built_in_unsetenv, testbuiltinunsetenv)
{
    char **input = tabgen("unsetenv value asd", ' ');

    cr_assert_eq(built_in_setenv(input, 0), 0);
    free_tab((void **)input);
}