/*
** EPITECH PROJECT, 2020
** exec.c
** File description:
** project's core, handles execution and possible errors
*/

#include "exec.h"
#include "lib.h"
#include "env_handling.h"
#include "input_module.h"

int exec(cmd_t *cmd, int rvalue, int rw[2])
{
    char **input = vector_to_char(cmd->args);
    builtin_t builtin = check_if_builtin_or_dir(input, &rvalue);
    int bkcp[2] = {0};

    if (vector_len(cmd->args) == 0 && vector_len(cmd->rds) != 0)
        return (error_msg(NULL, NULL_CMD), rvalue);
    cmd->args = expand_aliases(cmd->args);
    if (rvalue != 0 || input == NULL || builtin != NULL) {
        if (builtin == NULL)
            return rvalue;
        backup_io(bkcp);
        if (cmd->rds != NULL && handle_cmd_rds(cmd->rds))
            return 1;
        apply_pipes(rw);
        rvalue = builtin(input, rvalue);
        reset_io(bkcp);
        return rvalue;
    }
    return init_execve(cmd, rvalue, rw);
}

int init_execve(cmd_t *cmd, int return_value, int rw[2])
{
    pid_t cpid = fork();
    int ws = 0;
    char **input = vector_to_char(cmd->args);
    char *command = get_exec_input(input[0]);

    if (cpid == 0) {
        if (cmd->rds != NULL && handle_cmd_rds(cmd->rds))
            return 1;
        apply_pipes(rw);
        if (execve(command, input, environ) != 0)
            _exit(execve_error(input[0], command));
    } else if (cpid > 0 && rw[IN] == -1) {
        waitpid(cpid, &ws, F_OK);
        return (WIFEXITED(ws) ? WEXITSTATUS(ws) : check_if_segfault(ws));
    } else return (close(rw[IN]), 1);
    return (return_value);
}

builtin_t check_if_builtin_or_dir(char **input, int *rvalue)
{
    builtin_t command = NULL;

    if (input != NULL && input[0] != NULL && input[0][0] != '\0') {
        *rvalue = check_if_directory(input[0]);
        return (*rvalue == 0) ? get_builtin(input[0]) : command;
    } else *rvalue = 1;
    return command;
}

char *get_exec_input(char *input)
{
    char *result = NULL;
    char **path = get_exec_paths(environ);

    if (input == NULL || input[0] == '\n' || path == NULL || *path == NULL) {
        if (is_in_string(input, '/') != -1)
            return my_strdup(input);
        return (NULL);
    } else if (is_in_string(input, '/') != -1)
        return my_strdup(input);
    for (int i = 0; path[i] != NULL; i++) {
        result = load_path(path[i], input);
        if (access(result, X_OK) == 0)
            return result;
    }
    return NULL;
}

char **get_all_exec_ipt(char *input, char **path)
{
    char **result = NULL;
    char *line = NULL;

    if (input == NULL || input[0] == '\n' || path == NULL || *path == NULL) {
        if (is_in_string(input, '/') != -1)
            return append_str(result, input);
        return (NULL);
    } else if (is_in_string(input, '/') != -1)
        return append_str(result, input);
    for (int i = 0; path[i] != NULL; i++) {
        line = load_path(path[i], input);
        if (access(line, X_OK) == 0)
            result = append_str(result, line);
        free(line);
    }
    return result;
}
