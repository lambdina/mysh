/*
** EPITECH PROJECT, 2019
** Cubic bezier module
** File description:
** Implementation
*/

#include "istl/cubic_bezier.h"

const point_set_t CP_LINEAR = {
    0, 0, 1, 1
};
const point_set_t CP_EASE = {
    0.25, 0.1, 0.25, 1
};
const point_set_t CP_EASE_IN = {
    0.42, 0, 1, 1
};
const point_set_t CP_EASE_OUT = {
    0, 0, 0.58, 1
};
const point_set_t CP_EASE_IN_OUT = {
    0.42, 0, 0.58, 1
};

point_set_t curve_profile(double x1, double y1, double x2, double y2)
{
    point_set_t point_set;

    point_set.x1 = x1;
    point_set.y1 = y1;
    point_set.x2 = x2;
    point_set.y2 = y2;
    return (point_set);
}

static double calc_cubic_polynome(double c1, double c2, double x)
{
    double b1 = 3 * c1 * x * (1.0f - x) * (1.0f - x);
    double b2 = 3 * c2 * x * x * (1.0f - x);
    double b3 = x * x * x;

    return (b1 + b2 + b3);
}

static double calc_cubic_derivative(double c1, double c2, double x)
{
    const double h = 0.005f;
    double f1 = calc_cubic_polynome(c1, c2, x + h);
    double f2 = calc_cubic_polynome(c1, c2, x);
    double r = (f1 - f2) / h;

    return (r);
}

static double calc_t_for_x(double x1, double x2, double x)
{
    double t = x;
    double f1;
    double f2;

    for (int i = 0; i < 4; i++) {
        f2 = calc_cubic_derivative(x1, x2, t);
        if ( (int)(f2 * 100) == 0 )
            return (t);
        f1 = calc_cubic_polynome(x1, x2, t) - x;
        t = t - f1 / f2;
    }

    return (t);
}

double cubic_bezier(point_set_t point_set, double x)
{
    double t = calc_t_for_x(point_set.x1, point_set.x2, x);
    double y = calc_cubic_polynome(point_set.y1, point_set.y2, t);

    return (y);
}
