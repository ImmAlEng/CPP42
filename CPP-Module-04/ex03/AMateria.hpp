/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 00:42:13 by iengels           #+#    #+#             */
/*   Updated: 2023/10/29 15:46:49 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class ICharacter;

#pragma once

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria(void);
        AMateria(std::string const &type);
        AMateria(AMateria const &copy);
        virtual ~AMateria();
        
        AMateria& operator =(AMateria const &copy);

        std::string const &getType(void) const;
        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);
};

#endif
