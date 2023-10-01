/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:00:09 by iengels           #+#    #+#             */
/*   Updated: 2023/10/01 15:43:23 by iengels          ###   ########.fr       */
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

        Fixed& operator = (const Fixed & copy);

        int toInt( void ) const;
        float toFloat( void ) const;
        int getRawBits( void ) const;
        void setRawBits(int const raw);
};

//overload << ostream
std::ostream& operator <<(std::ostream &output, Fixed const &fixed);

#endif