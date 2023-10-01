/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:00:09 by iengels           #+#    #+#             */
/*   Updated: 2023/10/01 19:53:35 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int value;
        const static int fractional;
    
    public:
        //Constructors
        Fixed();
        Fixed(const float value);
        Fixed(const int value);
        Fixed(Fixed const & copy);

        //Deconstructor
        ~Fixed();

        // Assign Operator
        Fixed& operator = (const Fixed & copy);

        // Comparison Operators
        bool operator == (const Fixed & copy);
        bool operator != (const Fixed & copy);
        bool operator <= (const Fixed & copy);
        bool operator >= (const Fixed & copy);
        bool operator > (const Fixed & copy);
        bool operator < (const Fixed & copy);

        // Arithmetic operators:
        Fixed operator * (const Fixed & copy) const;
        Fixed operator / (const Fixed & copy) const;
        Fixed operator + (const Fixed & copy) const;
        Fixed operator - (const Fixed & copy) const;

        // Post and Pre increment
        Fixed& operator ++ (void);
        Fixed& operator -- (void);
        Fixed operator ++ (int value);
        Fixed operator -- (int value);

        // static min and max members
        static const Fixed& min(Fixed const& fix1, Fixed const& fix2);
        static const Fixed& max(Fixed const& fix1, Fixed const& fix2);
        static Fixed& min(Fixed& fix1, Fixed& fix2);
        static Fixed& max(Fixed& fix1, Fixed& fix2);

        // Other Member Functions
        int toInt( void ) const;
        float toFloat( void ) const;
        int getRawBits( void ) const;
        void setRawBits(int const raw);
};

//overload << ostream
std::ostream& operator <<(std::ostream &output, Fixed const &fixed);

#endif