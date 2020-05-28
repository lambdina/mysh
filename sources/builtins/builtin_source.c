/*
** EPITECH PROJECT, 2020
** builtin_source.c
** File description:
** builtin similar to source in bash
*/

#include "42sh.h"
#include "lib.h"
#include "builtins.h"
#include "exec.h"
#include "istl/utility.h"
#include "istl/hash_table.h"
#include "istl/string.h"
#include "input_module.h"
#include "env_handling.h"

int built_in_source(char **input, UNUSED int rvalue)
{
    char *path = my_strdup(input[1]);
    struct stat st;

    if (path == NULL)
        return 0;
    if (stat(path, &st) == -1 || !S_ISREG(st.st_mode))
        return 0;
    free_tab((void **)input);
    return read_source_file(path);
}

int read_source_file(char *filepath)
{
    int rvalue = 0;
    int fd = open(filepath, O_RDONLY);
    char *buffer = NULL;
    vector_t *expr = vector_create((mdata_t) {0, 0, sizeof(cmd_t)});
    int state = 0;

    if (fd == -1)
        return error_msg("source", TRIGGER_STRERROR);
    do {
        buffer = get_next_line(fd);
        rvalue = prompt_format(buffer, expr, &state);
        if (rvalue != 0) {
            free(buffer);
            break;
        } else rvalue = input_eval(expr);
    } while (rvalue != 0 && buffer != NULL);
    close(fd);
    free(buffer);
    free(filepath);
    return rvalue;
}
