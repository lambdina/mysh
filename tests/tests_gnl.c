/*
** EPITECH PROJECT, 2019
** tests_gnl.c
** File description:
** unit tests get_next_line.c
*/

#include "lib.h"
#include <criterion/criterion.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

Test(get_next_line, test_gnl_failure)
{
    int fd = open("fortnite", O_RDONLY);

    cr_assert_eq(get_next_line(fd), 0);
    close(fd);
}

Test(get_next_line, test_gnl)
{
    int fd = open("Makefile", O_RDONLY);

    cr_assert_str_eq(get_next_line(fd), "##");
    cr_assert_str_eq(get_next_line(fd), "## EPITECH PROJECT, 2019");
    cr_assert_str_eq(get_next_line(fd), "## Makefile");
    cr_assert_str_eq(get_next_line(fd), "## File description:");
    cr_assert_str_eq(get_next_line(fd), "## Makefile");
    cr_assert_str_eq(get_next_line(fd), "##");
    close(fd);
}
