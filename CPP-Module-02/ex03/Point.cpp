/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 22:28:05 by iengels           #+#    #+#             */
/*   Updated: 2023/10/01 22:59:59 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) :x(0), y(0)
{
    std::cout << "default constructor called" << std::endl;
}

Point::Point(float x, float y) :x(x), y(y)
{
    std::cout << "Init constructor called" << std::endl;
}

Point::Point(Point const& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Point::~Point(void) {}

Point& Point::operator=(const Point& copy) 
{
    std::cout << "copy assignment operator called" << std::endl;
    this->x = copy.x.getRawBits();
    this->y = copy.y.getRawBits();
    return (*this);
}

Fixed Point::getx( void ) const
{
    return this->x;
}

Fixed Point::gety( void ) const
{
    return this->y;
}
