/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 22:28:09 by iengels           #+#    #+#             */
/*   Updated: 2023/10/02 22:11:48 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

#pragma once

class Point
{
    private:
        Fixed x;
        Fixed y;
    public:
        Point();
        Point(float x, float y);
        ~Point();
        Point(Point const& copy);
        Point& operator=(const Point& copy);

        Fixed getx( void ) const;
        Fixed gety( void ) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
