/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 01:07:50 by iengels           #+#    #+#             */
/*   Updated: 2023/10/29 10:51:47 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#pragma once

class Ice : public AMateria
{
    public:
        Ice(void);
        Ice(Ice const &copy);
        ~Ice(void);

        Ice &operator= (Ice const &copy);
};

#endif
