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

Test(builtin_where, test_where, .init = redirect_all)
{
    cr_assert_eq(built_in_where(tabgen("where where", ' '), 0), 0);
    cr_assert_stdout_eq_str("where is a shell built-in\n");
    cr_assert_eq(built_in_where(tabgen("where", ' '), 0), 1);
    cr_assert_stderr_eq_str("where: Too few arguments.\n");
}

Test(check_bltn_where, test_where_no_arg, .init = redirect_all)
{
    cr_assert_eq(check_bltn_where(tabgen("where", ' ')), 1);
    cr_assert_stderr_eq_str("where: Too few arguments.\n");
}

Test(builtin_which, test_which, .init = redirect_all)
{
    cr_assert_eq(built_in_which(tabgen("which which", ' '), 0), 0);
    cr_assert_stdout_eq_str("which: shell built-in command.\n");
    cr_assert_eq(built_in_which(tabgen("which", ' '), 0), 1);
    cr_assert_stderr_eq_str("which: Too few arguments.\n");
}

Test(check_bltn_which, test_where_no_arg, .init = redirect_all)
{
    cr_assert_eq(check_bltn_which(tabgen("which", ' ')), 1);
    cr_assert_stderr_eq_str("which: Too few arguments.\n");
}
