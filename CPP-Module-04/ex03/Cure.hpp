/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 01:05:58 by iengels           #+#    #+#             */
/*   Updated: 2023/10/29 15:53:01 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#pragma once

class Cure : public AMateria
{
    public:
        Cure(void);
        Cure(Cure const &copy);
        ~Cure();

        Cure &operator= (Cure const &copy);
        
        AMateria *clone() const;
        void use(ICharacter &target);
};

#endif
