/*
** EPITECH PROJECT, 2019
** test_lib.c
** File description:
** functions testing librairy
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "lib.h"
#include <stddef.h>

void redirect_all(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

//write_toolbox.c
Test(my_putchar, test_putchar, .init = redirect_all)
{
    my_putchar('a');
    cr_assert_stdout_eq_str("a");
}

Test(my_putstr, tests_putstr, .init = redirect_all)
{
    my_putstr("this is a string.\n");
    cr_assert_stdout_eq_str("this is a string.\n");
}

Test(my_puterror, test_puterror, .init = redirect_all)
{
    my_puterror("This is a string on the error canal.\n");
    cr_assert_stderr_eq_str("This is a string on the error canal.\n");
}

//get_len_toolbox.c
Test(my_nblen, test_nb_len)
{
    cr_assert_eq(my_nblen(15), 2);
    cr_assert_eq(my_nblen(155), 3);
    cr_assert_eq(my_nblen(-12), 2);
    cr_assert_eq(my_nblen(0), 0);
}

Test(my_strlen, test_my_strlen)
{
    cr_assert_eq(my_strlen("test"), 4);
    cr_assert_eq(my_strlen((void *)0), 0);
    cr_assert_eq(my_strlen(""), 0);
    cr_assert_eq(my_strlen("fortnite\n"), 9);
}

Test(my_tablen, test_my_tablen)
{
    char **tab1 = tabgen("this is a test.", ' ');

    cr_assert_eq(my_tablen((char const **)tab1), 4);
    free_tab((void **)tab1);
    cr_assert_eq(my_tablen((void *)0), 0);
}

//malloc_toolbox.c
Test(my_strdup, test_strdup)
{
    char *asd = my_strdup("asdfortnite");
    char *lol = my_strdup((void *)0);

    cr_assert_str_eq("asdfortnite", asd);
    cr_assert_eq(0, lol);
    free(asd);
}

Test(my_strcat, test_strcat)
{
    char *asd = my_strcat("this is", " a test");
    char *a = my_strcat("this is", (void *)0);
    char *s = my_strcat((void *)0, " a test");

    cr_assert_str_eq("this is a test", asd);
    cr_assert_str_eq(a, "this is");
    cr_assert_str_eq(s, " a test");
    free(asd);
    free(a);
    free(s);
}

Test(my_itoa, test_itoa)
{
    cr_assert_str_eq(my_itoa(15), "15");
    cr_assert_str_eq(my_itoa(0), "0");
    cr_assert_str_eq(my_itoa(-666), "-666");
    cr_assert_str_eq(my_itoa(-7), "-7");
}

//conversion_toolbox.c
Test(my_getnbr_base, gnbase)
{
    cr_assert_str_eq(my_getnbr_base(12, "01234567"), "14");
    cr_assert_str_eq(my_getnbr_base(10, "01"), "1010");
    cr_assert_str_eq(my_getnbr_base(236, "0123456789abcdef"), "ec");
    cr_assert_str_eq(my_getnbr_base(12, "0123456789ABCDEF"), "C");
    cr_assert_eq(my_getnbr_base(12, (void *)0), 0);
}

Test(my_getnbr, gnbr)
{
    cr_assert_eq(my_getnbr((void *)0), 0);
    cr_assert_eq(my_getnbr("17"), 17);
    cr_assert_eq(my_getnbr("0"), 0);
    cr_assert_eq(my_getnbr(""), 0);
    cr_assert_eq(my_getnbr("asd123"), 0);
    cr_assert_eq(my_getnbr("123asc"), 123);
    cr_assert_eq(my_getnbr("---12"), -12);
    cr_assert_eq(my_getnbr("432823748324"), 0);
}

//tabgen.c
Test(tabgen, tbgn)
{
    char **tab = tabgen((void *)0, '\n');
    char **tab2 = tabgen("lol i love this game", ' ');

    cr_assert_eq(tab, 0);
    cr_assert_str_eq(tab2[0], "lol");
    free_tab((void **)tab2);
}

//copy_toolbox.c
Test(my_strcpy, strcp)
{
    char *result = malloc(sizeof(char) * 6);

    cr_assert_str_eq(my_strcpy(result, "hello"), "hello");
    cr_assert_eq(my_strcpy(result, (void *)0), 0);
    free(result);
}

Test(my_strncpy, strncp)
{
    char *result = malloc(sizeof(char) * 8);

    cr_assert_str_eq(my_strncpy(result, "hello world !", 5), "hello");
    cr_assert_eq(my_strncpy(result, (void *)0, 12), 0);
    cr_assert_eq(my_strncpy(result, "hello world !", -1), 0);
    free(result);
}
