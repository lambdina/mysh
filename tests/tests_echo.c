/*
** EPITECH PROJECT, 2020
** tests_echo.c
** File description:
** unit tests echo built_in
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

Test(builtin_echo, testecho, .init = redirect_all)
{
    cr_assert_eq(built_in_echo(tabgen("echo fortnite", ' '), 0), 0);
    cr_assert_stdout_eq_str("fortnite\n");
}

Test(builtin_echo, testechonoarg, .init = redirect_all)
{
    cr_assert_eq(built_in_echo(tabgen("echo", ' '), 0), 0);
    cr_assert_stdout_eq_str("\n");
}