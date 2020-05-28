/*
** EPITECH PROJECT, 2019
** Cubic bezier module
** File description:
** Cubic bezier function declarations
*/

#ifndef CUBIC_BEZIER_H_INCLUDED
#define CUBIC_BEZIER_H_INCLUDED

typedef struct PointSet
{
    double x1;
    double y1;
    double x2;
    double y2;
} point_set_t;

extern const point_set_t CP_LINEAR;
extern const point_set_t CP_EASE;
extern const point_set_t CP_EASE_IN;
extern const point_set_t CP_EASE_OUT;
extern const point_set_t CP_EASE_IN_OUT;

point_set_t curve_profile(double x1, double y1, double x2, double y2);
double cubic_bezier(point_set_t, double x);

#endif
