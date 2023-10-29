/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 01:07:50 by iengels           #+#    #+#             */
/*   Updated: 2023/10/29 15:52:57 by iengels          ###   ########.fr       */
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
        ~Ice();

        Ice &operator= (Ice const &copy);
        
        AMateria *clone() const;
        void use(ICharacter &target);
};

#endif
