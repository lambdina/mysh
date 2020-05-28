/*
** EPITECH PROJECT, 2020
** test_env.c
** File description:
** unit tests env built_in
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

Test(built_in_env, builtinenverror, .init = redirect_all)
{
    char **input = tabgen("env", ' ');

    cr_assert_eq(built_in_env(input, 0), 0);
    free_tab((void **)input);
}

Test(built_in_env, builtinenvok, .init = redirect_all)
{
    char **input = tabgen("env asd", ' ');

    cr_assert_eq(built_in_env(input, 0), 1);
    cr_assert_stderr_neq_str("env: no arguments are accepted.\n");
    free_tab((void **)input);
}