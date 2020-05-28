/*
** EPITECH PROJECT, 2020
** tests_cd.c
** File description:
** tests for cd built_in
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

Test(is_directory, testisdir)
{
    struct stat dir;
    struct stat notdir;
    char *mkfl = my_strdup("Makefile");
    char *inc = my_strdup("include");

    stat(mkfl, &notdir);
    stat(inc, &dir);
    cr_assert_eq(is_directory(dir, inc), true);
    cr_assert_eq(is_directory(notdir, mkfl), false);
}

Test(cd_error_handling, errorhandling)
{
    char **input_wrong = tabgen("cd error handling", ' ');
    char **input_one_arg = tabgen("cd", ' ');
    char **input_ok = tabgen("cd includes", ' ');
    char **env = tabgen("HOME=/home/bogdan", ':');

    cr_assert_eq(cd_error_handling(input_wrong), 0);
    input_one_arg = cd_error_handling(input_one_arg);
    input_ok = cd_error_handling(input_ok);
    cr_assert_str_eq(input_ok[1], "includes");
    free_tab((void **)env);
    free_tab((void **)input_ok);
    free_tab((void **)input_one_arg);
    free_tab((void **)input_wrong);
}

Test(get_path, getpath)
{
    char *input = my_strdup("bogdan");

    cr_assert_neq(get_path(input), 0);
    free(input);
}

Test(update_cd_argument, updatecdarg)
{
    char **argument_two = tabgen("cd ~", ' ');
    char **argument_three = tabgen("cd", ' ');

    argument_two = update_cd_argument(argument_two);
    cr_assert_str_eq(argument_two[1], getline_from_env(environ, "HOME="));
    argument_three = update_cd_argument(argument_three);
    cr_assert_str_eq(argument_three[1], getline_from_env(environ, "HOME="));
    free_tab((void **)argument_two);
    free_tab((void **)argument_three);
}

Test(is_dir_accessible, dirnotaccessible, .init = redirect_all)
{
    char *input = my_strdup("includes");

    cr_assert_eq(is_dir_accessible(input), false);
    free(input);
}

Test(is_dir_accessible, notadir, .init = redirect_all)
{
    char *input = my_strdup("Makefile");

    cr_assert_eq(is_dir_accessible(input), false);
    free(input);
}

Test(built_in_cd, testbuiltin)
{
    char **input = tabgen("cd include", ' ');

    cr_assert_eq(built_in_cd(input, 0), 0);
    free_tab((void **)input);
}