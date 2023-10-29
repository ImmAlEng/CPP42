/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 00:42:13 by iengels           #+#    #+#             */
/*   Updated: 2023/10/29 10:49:36 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

#pragma once

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria(void);
        AMateria(std::string const &type);
        virtual ~AMateria();
        
        AMateria& operator =(AMateria const &copy);

        std::string const &getType() const; // Returns the materia type
        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);
};

#endif
