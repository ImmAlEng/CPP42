/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:07:15 by iengels           #+#    #+#             */
/*   Updated: 2023/10/01 16:42:18 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp" 

const int Fixed::fractional = 8;

static float conversion(float value, int fractorial) 
{
	float	result = 1.0f;

	if (!fractorial)
		return (result);
	if (fractorial < 0)
        result /= 1 << -fractorial;
    else
        result = 1 << fractorial;
    return (value * result);
}

Fixed::Fixed(void) :value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const float value) :value(conversion(value, fractional))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const int value) :value(conversion(value, fractional))
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed& Fixed::operator=(const Fixed& copy) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->value = copy.getRawBits();
    return (*this);
}

Fixed::~Fixed(void)
{
    std::cout << "Deconstructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return value;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}

float Fixed::toFloat( void ) const
{
    return (conversion(value, -fractional));
}

int Fixed::toInt( void ) const
{
    return ((int)conversion(value, -fractional));
}

std::ostream& operator << (std::ostream &output, const Fixed &fixed)
{
    return (output << fixed.toFloat());
}
