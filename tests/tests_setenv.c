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
#include "lib.h"
#include "env_handling.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void redirect_all(void);

Test(setenv_check_input, setenvtoenv, .init = redirect_all)
{
    char **input = tabgen("setenv", ' ');

    cr_assert_eq(setenv_check_input(input, 0), -1);
    free_tab((void **)input);
}

Test(setenv_check_input, setenvtoomanyargs)
{
    char **input = tabgen("setenv too many args", ' ');

    cr_assert_eq(setenv_check_input(input, 0), -1);
    free_tab((void **)input);
}

Test(setenv_check_input, setenvok)
{
    char **input = tabgen("setenv ok", ' ');

    cr_assert_eq(setenv_check_input(input, 0), 0);
    free_tab((void **)input);
}

Test(set_to_env, settoenvok)
{
    char **e = tabgen("OLDPWD=/home:PWD=/home/bogdan:HOME=/home/bogdan", ':');
    char *new = my_strdup("HOME=/home");

    e = set_to_env(e, new);
    cr_assert_eq(my_tablen((char const **)e), 3);
    cr_assert_str_eq(e[2], "HOME=/home");
    free(new);
    free_tab((void **)e);
}

Test(built_in_setenv, builtinsetenv)
{
    char **input = tabgen("setenv test test", ' ');

    cr_assert_eq(built_in_setenv(input, 1), 0);
    cr_assert_neq(find_in_env(environ, "test=test"), -1);
    free_tab((void **)input);
}