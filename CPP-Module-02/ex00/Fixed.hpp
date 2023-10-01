/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:00:09 by iengels           #+#    #+#             */
/*   Updated: 2023/10/01 13:29:37 by iengels          ###   ########.fr       */
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
        Fixed();
        Fixed(Fixed const & copy);
        ~Fixed();

        Fixed& operator = (const Fixed & copy);

        int getRawBits() const;
        void setRawBits(int const raw);
};

#endif