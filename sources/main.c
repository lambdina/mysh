/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main file
*/

#include "42sh.h"
#include "input_handling.h"
#include "env_handling.h"

#include "builtins.h"
#include "lib.h"

int main(UNUSED int ac, UNUSED char **av)
{
    handle_main_loop();
    return (0);
}
