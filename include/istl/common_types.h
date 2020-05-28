/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#ifndef IS_COMMON_TYPES_H_INCLUDED
#define IS_COMMON_TYPES_H_INCLUDED

#include <curses.h>

#ifndef NMAX
#define NMAX(x1, x2) ((x1) > (x2) ? (x1) : (x2))
#endif

/*!
    \brief Variable attribute allowing to autofree a pointer
    \details If the pointer was allocated with **snew**, allows to
    automatically call a destructor upon it (if any stored in it's **mtype_t**
*/
#define SMART __attribute__((cleanup(sdel)))

// typedef enum {FALSE = 0, TRUE = 1} (bool_t);    //!< Boolean typedef
typedef bool (bool_t);
typedef unsigned int (uint_t);                  //!< Unsigned int typedef
typedef unsigned long long (hash_value_t);      //!< Hash number typedef
typedef long unsigned int (dsize_t);    //!< Data size typedef
typedef unsigned char (byte_t);         //!< Byte typedef
typedef char const * (cchar_t);          //!< Constant C string typedef

/*!
    \brief Copy constructor prototype
    \details Any type intended to be stored in the provided data
    container should implement a copy constructor to prevent any
    problems related to an object's shallow copy.
*/
typedef void *(*cpy_constructor_ft)(void const *poriginal);
typedef void *(*ctor_ft)(void const *poriginal);

/*!
    \brief Destructor prototype
    \details Any type intended to be stored in the provided data
    container should not only implement a copy constructor, but also
    a destructor to ensure full object's deep free and to prevent
    any memory leak due to the storage in such structure.
*/
typedef void (*destructor_ft)(void *pdata);
typedef void (*dtor_ft)(void *pdata);

typedef enum SPTR_TYPE {SP_UNIQUE, SP_SHARED, SP_WEAK} sptrt_t;

typedef void *(wptr_t);
/*!
    \brief Extended allocated memory block
    \details This structure is for internal use only:
    alloc functions use it to stock an object's destructor
    right before the memory block itself
*/
typedef struct ExMemCell {
    sptrt_t type;
    uint_t *count;
    uint_t *wcount;
    dtor_ft dtor;
    void *data;
} (mcell_t);

typedef struct Vector2 {
    int x;
    int y;
} vec2_t;

extern const vec2_t V_NULL;

/*!
    \brief Container with all custom type infos
    \details A meta bundle is passed to any provided container
    so they could be stored properly in this container. This
    structure is the actual bridge between your type and a data
    structure. Any type that you intent to store in such container
    should also implement a constant meta bundle, providing its
    copy constructor and a destructor, with the size of your
    structure. In C you can't guess generic structure's type,
    so you have to create a description structure manually.
*/
struct MetaBundle {
    cpy_constructor_ft copy; //!< Pointer to the type's copy constructor
    destructor_ft destroy; //!< Pointer to the type destructor
    dsize_t data_size;  //!< Type's size in bytes
};

//__attribute__((deprecated("Use mdata_t instead")))
typedef struct MetaBundle (meta_bundle_t);
typedef struct MetaBundle (mdata_t);

extern const meta_bundle_t MB_SPTR;
extern const meta_bundle_t MB_INT;
extern const meta_bundle_t MB_FLOAT;
extern const meta_bundle_t MB_DOUBLE;
extern const meta_bundle_t MB_CHAR;
extern const meta_bundle_t MB_PTR;
extern const meta_bundle_t MB_BOOL;

mcell_t *get_mcell(void *ptr);
void *snew(mdata_t m);
void sdel(void *data);
void sdel_weak(void *data);
void *mem_copy(void const *data, dsize_t size);

#endif
