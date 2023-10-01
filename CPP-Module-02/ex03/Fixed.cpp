/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:07:15 by iengels           #+#    #+#             */
/*   Updated: 2023/10/01 19:49:41 by iengels          ###   ########.fr       */
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

Fixed::Fixed(Fixed const & fix)
{
    std::cout << "fix constructor called" << std::endl;
    *this = fix;
}

Fixed& Fixed::operator=(const Fixed& fix) 
{
    std::cout << "fix assignment operator called" << std::endl;
    this->value = fix.getRawBits();
    return (*this);
}

Fixed Fixed::operator * (const Fixed & fix) const
{
    float x = this->toFloat() * fix.toFloat();
    Fixed f(x);
    return f;
}

Fixed Fixed::operator / (const Fixed & fix) const
{
    float x = this->toFloat() / fix.toFloat();
    Fixed f(x);
    return f;
}

Fixed Fixed::operator + (const Fixed & fix) const
{
    float x = this->toFloat() + fix.toFloat();
    Fixed f(x);
    return f;
}

Fixed Fixed::operator - (const Fixed & fix) const
{
    float x = this->toFloat() - fix.toFloat();
    Fixed f(x);
    return f;
}

bool Fixed::operator == (const Fixed & fix)
{
    return (this->toFloat() == fix.toFloat());
}

bool Fixed::operator != (const Fixed & fix)
{
    return (this->toFloat() != fix.toFloat());
}

bool Fixed::operator <= (const Fixed & fix)
{
    return (this->toFloat() <= fix.toFloat());
}

bool Fixed::operator >= (const Fixed & fix)
{
    return (this->toFloat() >= fix.toFloat());
}

bool Fixed::operator > (const Fixed & fix)
{
    return (this->toFloat() > fix.toFloat());
}

bool Fixed::operator < (const Fixed & fix)
{
    return (this->toFloat() < fix.toFloat());
}

Fixed& Fixed::operator ++ (void)
{
    ++value;
    return *this;
}

Fixed& Fixed::operator -- (void)
{
    --value;
    return *this;
}

Fixed Fixed::operator ++ (int)
{
    Fixed temp = *this;
    this->value++;
    return temp;
}

Fixed Fixed::operator -- (int)
{
    Fixed temp = *this;
    this->value--;
    return temp;
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

const Fixed& Fixed::min(Fixed const& fix1, Fixed const& fix2)
{
    if (fix1.toFloat() <= fix2.toFloat())
        return fix1;
    return fix2;
}

const Fixed& Fixed::max(Fixed const& fix1, Fixed const& fix2)
{
    if (fix1.toFloat() >= fix2.toFloat())
        return fix1;
    return fix2;
}

Fixed& Fixed::min(Fixed& fix1, Fixed& fix2)
{
    if (fix1.toFloat() <= fix2.toFloat())
        return fix1;
    return fix2;
}

Fixed& Fixed::max(Fixed& fix1, Fixed& fix2)
{
        if (fix1.toFloat() >= fix2.toFloat())
        return fix1;
    return fix2;
}

std::ostream& operator << (std::ostream &output, const Fixed &fix)
{
    return (output << fix.toFloat());
}
