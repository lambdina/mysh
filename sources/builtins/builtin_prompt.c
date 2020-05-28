/*
** EPITECH PROJECT, 2020
** get_prompt.c
** File description:
** handles get_prompt() call in init_shell.c
*/

#include "42sh.h"
#include "lib.h"
#include "builtins.h"
#include "env_handling.h"

int built_in_prompt(char **ipt, int rvalue)
{
    char **result = tabgen("setenv PROMPT", ' ');

    if (my_tablen((char const **)ipt) == 2)
        result = append_str(result, ipt[1]);
    free_tab((void **)ipt);
    return (built_in_setenv(result, rvalue));
}

char *get_prompt(char **env)
{
    char *prompt = getline_from_env(env, "PROMPT=");
    char *result = NULL;

    if (prompt == NULL)
        return (my_strdup(" > "));
    for (int i = 0; prompt[i] != '\0'; i++) {
        if (prompt[i] == '%') {
            result = my_strcat(result, prompt_switch_case(prompt[i + 1], env));
            i++;
        } else result = append_char(result, prompt[i]);
    }
    free(prompt);
    return (result);
}

char *prompt_switch_case(char flag, char **env)
{
    switch (flag) {
        case 'g' :
            return (prompt_git(getline_from_env(env, "PWD=")));
        case 'd' :
            return (prompt_cwd(env));
        case 'p' :
            return (getline_from_env(env, "PWD="));
        case 'n' :
            return (getline_from_env(env, "USER="));
        default :
            return (append_char(NULL, flag));
    }
    return (NULL);
}

char *prompt_cwd(char **env)
{
    char *pwd = getline_from_env(env, "PWD=");

    if (pwd == NULL) {
        pwd = malloc(sizeof(char) * 75);
        pwd = getcwd(pwd, 75);
    }
    if (my_strcmp("/", pwd) == 0)
        return (pwd);
    return get_last_occurence_of(pwd, '/');
}
