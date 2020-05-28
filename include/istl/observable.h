/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#ifndef OBSERVABLE_H_INCLUDED
#define OBSERVABLE_H_INCLUDED

typedef struct Observable (observable_t);
typedef int (*obs_callback_ft)(void *observer, void *obs, int);

observable_t *obs_create(void);
void obs_free(observable_t **obsp_p);
int obs_subscribe(observable_t *obs, void *obsr, obs_callback_ft callback);
int obs_notify(observable_t *obs, void *obsr, int sig);
int obs_unsubscribe(observable_t *obs, void *obsr);

#endif
