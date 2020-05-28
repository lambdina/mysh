/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include "istl/private/p_utility.h"

const char RC_WILD[] = {'\0'};
const char CSET_ALPHA[] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
    'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
    'w', 'x', 'y', 'z',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
    'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
    'W', 'X', 'Y', 'Z', '\0'
};
const char CSET_ANUM[] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
    'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
    'w', 'x', 'y', 'z',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
    'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
    'W', 'X', 'Y', 'Z',
    '\0'
};
const fnode_t REGEX_UINT[] = {
    {.cset = "+-", .ps = 0, .ns = 1, .fs = FALSE, .gwl = 1, .gwr = 2},
    {.cset = "0123456789", .ps = 0, .ns = 2, .fs = TRUE, .gwl = 2, .gwr = 3},
    {.cset = "0123456789", .ps = 1, .ns = 2, .fs = TRUE, .gwl = 2, .gwr = 3},
    {.cset = "0123456789", .ps = 2, .ns = 2, .fs = TRUE, .gwl = 2, .gwr = 3},
    {.cset = ".", .ps = 2, .ns = 3, .fs = TRUE, .gwl = 3, .gwr = 3},
    {.cset = "0", .ps = 3, .ns = 3, .fs = TRUE, .gwl = 3, .gwr = 3},
    FNODE_NULL
};
const fnode_t REGEX_OPT[] = {
    {.cset = "-", .ps = 0, .ns = 1, .fs = FALSE, .gwl = 0, .gwr = 0},
    {.cset = "-", .ps = 1, .ns = 2, .fs = FALSE, .gwl = 0, .gwr = 0},
    {.cset = CSET_ALPHA, .ps = 1, .ns = -1, .fs = TRUE, .gwl = 1, .gwr = 2},
    {.cset = CSET_ALPHA, .ps = 2, .ns = 2, .fs = TRUE, .gwl = 2, .gwr = 3},
    {.cset = "=:", .ps = 2, .ns = 3, .fs = FALSE, .gwl = 3, .gwr = 3},
    {.cset = RC_WILD, .ps = 3, .ns = 3, .fs = TRUE, .gwl = 3, .gwr = 4},
    {.cset = " ", .ps = 3, .ns = 4, .fs = FALSE, .gwl = 4, .gwr = 4},
    FNODE_NULL
};
// ls -la | cat
const fnode_t REGEX_CMD[] = {
    {.cset = RC_WILD, .ps = 0, .ns = 0, .fs = TRUE, .gwl = 2, .gwr = 3},
    {.cset = "|", .ps = 0, .ns = 8, .fs = FALSE, .gwl = 3, .gwr = 4},
    {.cset = "&;", .ps = 0, .ns = 3, .fs = TRUE, .gwl = 3, .gwr = 4},
    {.cset = ">", .ps = 0, .ns = 5, .fs = TRUE, .gwl = 2, .gwr = 3},
    {.cset = "(", .ps = 0, .ns = 6, .fs = FALSE, .gwl = 2, .gwr = 3},
    {.cset = ")", .ps = 0, .ns = -1, .fs = FALSE, .gwl = 2, .gwr = 3},
    {.cset = "\"", .ps = 0, .ns = 7, .fs = FALSE, .gwl = 2, .gwr = 3},
    {.cset = "\'", .ps = 0, .ns = 9, .fs = FALSE, .gwl = 2, .gwr = 3},
    {.cset = RC_WILD, .ps = 5, .ns = 0, .fs = TRUE, .gwl = 2, .gwr = 3},
    {.cset = "&", .ps = 5, .ns = 0, .fs = FALSE, .gwl = 2, .gwr = 3},
    {.cset = RC_WILD, .ps = 6, .ns = 6, .fs = FALSE, .gwl = 2, .gwr = 3},
    {.cset = ")", .ps = 6, .ns = 0, .fs = TRUE, .gwl = 2, .gwr = 3},
    {.cset = RC_WILD, .ps = 7, .ns = 7, .fs = FALSE, .gwl = 2, .gwr = 3},
    {.cset = "\"", .ps = 7, .ns = 0, .fs = TRUE, .gwl = 2, .gwr = 3},
    {.cset = RC_WILD, .ps = 9, .ns = 9, .fs = FALSE, .gwl = 2, .gwr = 3},
    {.cset = "\'", .ps = 9, .ns = 0, .fs = TRUE, .gwl = 2, .gwr = 3},
    {.cset = RC_WILD, .ps = 3, .ns = 4, .fs = TRUE, .gwl = 4, .gwr = 5},
    {.cset = " \t", .ps = 3, .ns = 3, .fs = TRUE, .gwl = 0, .gwr = 0},
    {.cset = "&", .ps = 3, .ns = 4, .fs = FALSE, .gwl = 3, .gwr = 4},
    {.cset = RC_WILD, .ps = 4, .ns = 4, .fs = TRUE, .gwl = 4, .gwr = 5},
    {.cset = RC_WILD, .ps = 8, .ns = 3, .fs = TRUE, .gwl = 4, .gwr = 5},
    {.cset = "|", .ps = 8, .ns = 3, .fs = FALSE, .gwl = 3, .gwr = 4},
    FNODE_NULL
};
const fnode_t REGEX_CMD_ARG[] = {
    {.cset = RC_WILD, .ps = 0, .ns = 1, .fs = TRUE, .gwl = 1, .gwr = 2},
    {.cset = " \t", .ps = 0, .ns = 0, .fs = FALSE, .gwl = 0, .gwr = 0},
    {.cset = "\'", .ps = 0, .ns = 2, .fs = FALSE, .gwl = 1, .gwr = 2},
    {.cset = "\"", .ps = 0, .ns = 3, .fs = FALSE, .gwl = 1, .gwr = 2},
    {.cset = "(", .ps = 0, .ns = 6, .fs = FALSE, .gwl = 1, .gwr = 2},
    {.cset = "<", .ps = 0, .ns = 7, .fs = TRUE, .gwl = 1, .gwr = 2},
    {.cset = ">", .ps = 0, .ns = 8, .fs = TRUE, .gwl = 1, .gwr = 2},
    {.cset = RC_WILD, .ps = 1, .ns = 1, .fs = TRUE, .gwl = 1, .gwr = 2},
    {.cset = "\'", .ps = 1, .ns = 2, .fs = FALSE, .gwl = 1, .gwr = 2},
    {.cset = "\"", .ps = 1, .ns = 3, .fs = FALSE, .gwl = 1, .gwr = 2},
    {.cset = "(", .ps = 1, .ns = 6, .fs = FALSE, .gwl = 1, .gwr = 2},
    {.cset = "<", .ps = 1, .ns = 5, .fs = TRUE, .gwl = 2, .gwr = 3},
    {.cset = ">", .ps = 1, .ns = 5, .fs = TRUE, .gwl = 2, .gwr = 3},
    {.cset = " \t", .ps = 1, .ns = 5, .fs = TRUE, .gwl = 0, .gwr = 0},
    {
        .cset = "\\|;!?&~",
        .ps = 1, .ns = -1, .fs = FALSE, .gwl = 0, .gwr = 0
    },
    {.cset = RC_WILD, .ps = 2, .ns = 2, .fs = FALSE, .gwl = 1, .gwr = 2},
    {.cset = "\'", .ps = 2, .ns = 1, .fs = TRUE, .gwl = 1, .gwr = 2},
    {.cset = RC_WILD, .ps = 3, .ns = 3, .fs = FALSE, .gwl = 1, .gwr = 2},
    {.cset = "\"", .ps = 3, .ns = 1, .fs = TRUE, .gwl = 1, .gwr = 2},
    {.cset = RC_WILD, .ps = 6, .ns = 6, .fs = FALSE, .gwl = 1, .gwr = 2},
    {.cset = ")", .ps = 6, .ns = 1, .fs = TRUE, .gwl = 1, .gwr = 2},
    {.cset = RC_WILD, .ps = 5, .ns = 5, .fs = TRUE, .gwl = 2, .gwr = 3},
    {.cset = RC_WILD, .ps = 7, .ns = 5, .fs = TRUE, .gwl = 2, .gwr = 3},
    {.cset = "<", .ps = 7, .ns = 5, .fs = TRUE, .gwl = 1, .gwr = 2},
    {.cset = RC_WILD, .ps = 8, .ns = 5, .fs = TRUE, .gwl = 2, .gwr = 3},
    {.cset = ">", .ps = 8, .ns = 5, .fs = TRUE, .gwl = 1, .gwr = 2},
    {.cset = "&", .ps = 8, .ns = 5, .fs = TRUE, .gwl = 1, .gwr = 2},
    FNODE_NULL
};
