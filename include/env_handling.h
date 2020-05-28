/*
** EPITECH PROJECT, 2020
** input_handling.h
** File description:
** input handling module header
*/

#ifndef ENV_HANDLING_H
#define ENV_HANDLING_H

// parse_env.c
char **get_exec_paths(char **env);
int find_in_env(char **tab, char *to_find);
char *load_path(char *path, char *input);

// utils.c
char *getline_from_env(char **env, char *to_find);
char **add_to_env(char **env, char *to_add);

#endif /* ENV_HANDLING_H */