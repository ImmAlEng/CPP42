/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 23:02:34 by iengels           #+#    #+#             */
/*   Updated: 2023/10/01 23:02:57 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed absolute(Fixed Area)
{
    Fixed sign(-1);
    if (Area < 0)
        return (sign * Area);
    return (Area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed AreaABC = absolute((a.getx() * (b.gety() - c.gety()) + b.getx() * (c.gety() - a.gety()) + c.getx() * (a.gety() - b.gety())) / Fixed(2));
    Fixed AreaABp = absolute((a.getx() * (b.gety() - point.gety()) + b.getx() * (point.gety() - a.gety()) + point.getx() * (a.gety() - b.gety())) / Fixed(2));
    Fixed AreaBCp = absolute((b.getx() * (c.gety() - point.gety()) + c.getx() * (point.gety() - b.gety()) + point.getx() * (b.gety() - c.gety())) / Fixed(2));
    Fixed AreaACp = absolute((a.getx() * (c.gety() - point.gety()) + c.getx() * (point.gety() - a.gety()) + point.getx() * (a.gety() - c.gety())) / Fixed(2));

    if (AreaABC == Fixed(0))
        return false;

    if (AreaABp == Fixed(0) || AreaBCp == Fixed(0) || AreaACp == Fixed(0))
        return false;

    return (AreaABC == (AreaABp + AreaACp + AreaBCp));
}
