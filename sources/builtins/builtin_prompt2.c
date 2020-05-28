/*
** EPITECH PROJECT, 2020
** prompt_git.c
** File description:
** handles recursive opendir and returns in which branch we are
*/

#include "42sh.h"
#include "lib.h"
#include "builtins.h"

char *prompt_git(char *pwd)
{
    DIR *current_dir = opendir(pwd);
    struct dirent *dir_info = NULL;

    if (current_dir == NULL || my_strcmp(pwd, "/") == 0)
        return (close_and_free(current_dir, pwd));
    do {
        dir_info = readdir(current_dir);
        if (dir_info == NULL)
            return (close_and_free(current_dir, pwd));
        else if (my_strcmp(dir_info->d_name, ".git") == 0) {
            closedir(current_dir);
            return (prompt_git_found_dir(my_strcat(pwd, "/.git/HEAD")));
        }
    } while (dir_info != NULL);
    closedir(current_dir);
    return (prompt_git(go_to_last_dir(pwd)));
}

char *close_and_free(DIR *dir, char *pwd)
{
    if (dir != NULL)
        closedir(dir);
    if (pwd != NULL)
        free(pwd);
    return (NULL);
}

char *prompt_git_found_dir(char *path)
{
    int fd = open(path, O_RDONLY);
    char *line = get_next_line(fd);

    if (fd == -1 || line == NULL)
        return (NULL);
    close(fd);
    free(path);
    return get_last_occurence_of(line, '/');
}

char *go_to_last_dir(char *pwd)
{
    int i = 0;

    for (; is_in_string(pwd, '/') != -1; i += is_in_string(pwd, '/'));
    pwd[i] = '\0';
    return (pwd);
}
