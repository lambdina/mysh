/*
** EPITECH PROJECT, 2020
** tests_lib2.c
** File description:
** unit tests for lib
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "lib.h"
#include <stddef.h>

void redirect_all(void);

//misc.c
Test(free_if_not_null, testfree)
{
    char *asd = my_strdup("fortnite");
    char *lol = (void *)0;

    free_if_not_null(asd);
    free_if_not_null(lol);
}

Test(free_tab, test_free_tab)
{
    char **tab = tabgen("i love being alive", ' ');
    int **inttab = malloc(sizeof(int *) * 3);
    char **lol = (void *)0;

    inttab[0] = malloc(sizeof(int) * 2);
    inttab[0][0] = 1;
    inttab[0][1] = 15;
    inttab[1] = malloc(sizeof(int) * 1);
    inttab[1][0] = 17;
    inttab[2] = (void *)0;
    free_tab((void **)tab);
    free_tab((void **)inttab);
    free_tab((void **)lol);
}

Test(swap, testswap, .init = redirect_all)
{
    int asd = 15;
    int lol = 13;

    swap(&asd, &lol);
    cr_assert_eq(lol, 15);
    cr_assert_eq(asd, 13);
}

Test(swap_array, testswaparray)
{
    char *asd = my_strdup("asd");
    char *lol = my_strdup("lol");

    swap_array((void **)&asd, (void **)&lol);
    cr_assert_str_eq(asd, "lol");
    cr_assert_str_eq(lol, "asd");
    free(asd);
    free(lol);
}

Test(swapc, swapchar, .init = redirect_all)
{
    char a = 'a';
    char b = 'b';

    swapc(&a, &b);
    my_putchar(a);
    my_putchar(b);
    cr_assert_stdout_eq_str("ba");
}

//check_string_toolbox.c
Test(is_num, testisnum)
{
    cr_assert_eq(is_num("-14"), true);
    cr_assert_eq(is_num("asd"), false);
    cr_assert_eq(is_num((void *)0), false);
    cr_assert_eq(is_num("1235"), true);
}

Test(is_in_string, testisinstring)
{
    cr_assert_eq(is_in_string("test", 's'), 2);
    cr_assert_eq(is_in_string("fortnite", 'z'), -1);
    cr_assert_eq(is_in_string((void *)0, 's'), -1);
}

Test(is_alphabetic, testisalpha)
{
    cr_assert_eq(is_alphabetic("isalphabetic"), true);
    cr_assert_eq(is_alphabetic("is not alpha"), false);
    cr_assert_eq(is_alphabetic((void *)0), false);
}

Test(is_a_letter, testisaletter)
{
    cr_assert_eq(is_a_letter('c', true), true);
    cr_assert_eq(is_a_letter('D', false), false);
    cr_assert_eq(is_a_letter('D', false), false);
    cr_assert_eq(is_a_letter('\n', false), false);
}

Test(get_last_occurence_of, testlastocc)
{
    char *test = my_strdup("/home/$USER/work/github/perso/teklib");
    char *test2 = (void *)0;
    char *test3 = my_strdup("no occurences !");

    cr_assert_str_eq(get_last_occurence_of(test, '/'), "teklib");
    cr_assert_str_eq(get_last_occurence_of(test3, '/'), "no occurences !");
    cr_assert_eq(get_last_occurence_of(test2, '3'), 0);
}

//number_toolbox.c
Test(my_putnbr, testputnbr, .init = redirect_all)
{
    my_putnbr(-12353);
    cr_assert_stdout_eq_str("-12353");
}

Test(my_putnbr_base, testputnbrbase, .init = redirect_all)
{
    my_putnbr_base(12, "01234567");
    cr_assert_stdout_eq_str("14");
}

//modify_strings.c
Test(set_to_lowercase, settolower)
{
    char *t = my_strdup("Paris Saint-Germain fucking SUCKS");
    char *d = my_strdup("LOL");
    char *f = (void *)0;

    cr_assert_str_eq(set_to_lowercase(t), "paris saint-germain fucking sucks");
    cr_assert_str_eq(set_to_lowercase(d), "lol");
    cr_assert_eq(set_to_lowercase(f), 0);
}

Test(set_to_uppercase, settoupper)
{
    char *t = my_strdup("Paris Saint-Germain fucking SUCKS");
    char *d = my_strdup("lol");
    char *f = (void *)0;

    cr_assert_str_eq(set_to_uppercase(t), "PARIS SAINT-GERMAIN FUCKING SUCKS");
    cr_assert_str_eq(set_to_uppercase(d), "LOL");
    cr_assert_eq(set_to_uppercase(f), 0);
}

Test(my_revstr, testrevstr)
{
    char *y = my_strdup("yes");
    char *f = my_strdup("fortnite");

    cr_assert_str_eq(my_revstr(y), "sey");
    cr_assert_str_eq(my_revstr(f), "etintrof");
    cr_assert_eq(my_revstr((void *)0), 0);
}

//do_op.c
Test(do_op, doop)
{
    cr_assert_eq(do_op(5, 12, '+'), 17);
    cr_assert_eq(do_op(5, 17, '-'), -12);
    cr_assert_eq(do_op(3, 5, '*'), 15);
    cr_assert_eq(do_op(15, 3, '/'), 5);
    cr_assert_eq(do_op(12, 5, '%'), 2);
}
