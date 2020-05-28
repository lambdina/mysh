/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include "lib.h"
#include "istl/utility.h"
#include "istl/hash_table.h"
#include "istl/string.h"
#include "input_module.h"
#include "input_handling.h"
#include "exec.h"

static void display_prompt(void)
{
    char *prompt = NULL;

    if (!isatty(0))
        return;
    prompt = get_prompt(environ);
    my_putstr(prompt == NULL ? " > " : prompt);
    free_if_not_null(prompt);
}

int input_read(vector_t *expr, char *hfile, int *ecode)
{
    char *input = NULL;
    int res = 0;
    int state = 0;

    if (expr == NULL)
        return (-1);
    res = prompt_cmd(&input, hfile);
    if (res != 0)
        return (res);
    prompt_format(input, expr, &state);
    if (ecode != NULL) {
        if (regex_error(state, ecode))
            return res;
        else *ecode = parse_for_errors(expr);
    }
    return (res);
}

int prompt_cmd(char **prompt, char *hfile)
{
    if (prompt == NULL)
        return (-1);
    do {
        display_prompt();
        (*prompt) = get_next_line(0);
        if (*prompt == NULL)
            return (-1);
    } while (!strcmp("", *prompt));
    update_command(*prompt, hfile);
    return (0);
}

int prompt_format(char const *prompt, vector_t *expr, int *state)
{
    map_t *match = map_create(10, MB_STR);
    cmd_t cmd = (cmd_t) {NULL, NULL, "", {-1, -1}};

    if (match == NULL || state == NULL)
        return (map_free(&match), -1);
    if (regex_extract(prompt, REGEX_CMD, match, state) != TRUE)
        return (map_free(&match), -1);
    do {
        cmd = (cmd_t) {NULL, NULL, "", {-1, -1}};
        cmd_from_match(match, &cmd);
        cmd.args = expand_aliases(cmd.args);
        expand_cmd_args(&cmd);
        cmd_extract_rdrs(&cmd);
        vector_push(expr, &cmd);
    } while (
            regex_extract(str_cstr(map_get(match, 4)),
                REGEX_CMD, match, state) != FALSE);
    return (0);
}

int input_eval(vector_t *expr)
{
    cmd_t *cmd = NULL;
    int res = 0;
    cmd_t *last = NULL;
    int rw[2] = {-1, -1};

    if (expr == NULL || vector_len(expr) < 1)
        return (-1);
    for (uint_t i = 0; i < vector_len(expr); i++) {
        cmd = vector_pull(expr, i);
        if (cmd == NULL)
            continue;
        manage_pipes(cmd, last, rw);
        res = exec(cmd, 0, rw);
        manage_discard(cmd, expr, res);
        last = cmd;
    }
    vector_narrow(expr);
    return (res);
}
