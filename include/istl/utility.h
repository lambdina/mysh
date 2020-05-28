/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#ifndef IS_UTILITY_H_INCLUDED
#define IS_UTILITY_H_INCLUDED

#include <SFML/Graphics.h>
#include "common_types.h"

#include <stdio.h>

typedef struct HashMap (map_t);

typedef union UniType {
    int i_num;
    float f_num;
    char *str;
    void *ptr;
} utype_t;

typedef struct FaNode {
    cchar_t cset;   //! Passing characters' set
    int ps;         //! Passing state index
    int ns;         //! Next state index
    bool_t fs;      //! Is final
    int gwl;        //! Group window left
    int gwr;        //! Group window right
} fnode_t;

#ifndef FNODE_NULL
#define FNODE_NULL ((fnode_t) {.cset = NULL, .ps = -1, .ns = -1, .fs = FALSE })
#endif

extern const char RC_WILD[];
extern const char CSET_ALPHA[];
extern const char CSET_ANUM[];
extern const meta_bundle_t MB_UTYPE;
extern const fnode_t REGEX_UINT[];
extern const fnode_t REGEX_OPT[];
extern const fnode_t REGEX_CMD[];
extern const fnode_t REGEX_CMD_ARG[];

void utility_set_var(char const *, utype_t);
void *utility_get_var(char const *);
bool_t utility_sready(void);
void utility_reset(void);

/*!
    \brief Unsigned int value control
    \details Allows to determine if a value is between one bound
    and another, return this value if ```true``` or return
    bound value if not.
*/
uint_t expect_uint(uint_t val, uint_t lhs, uint_t rhs);
bool_t str_contains(cchar_t set, char c);
bool_t str_uint(cchar_t str);
bool_t fnode_null(fnode_t const *);
bool_t regex_wild(fnode_t const *node);
fnode_t const *regex_forward(char, const fnode_t[], int *);
bool_t regex_extract(cchar_t, fnode_t const *const, map_t *grp, int *state);

#endif
