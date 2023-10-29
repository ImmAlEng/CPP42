/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 01:08:57 by iengels           #+#    #+#             */
/*   Updated: 2023/10/29 10:11:03 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

#pragma once

class Character: public ICharacter
{
    private:
        std::string name;
        AMateria *inventory[4];
        AMateria **disposed;
        int disposed_size;
        
    public:
        Character(void);
        Character(std::string name);
        ~Character();
        Character(Character const &copy);

        Character& operator= (Character const &copy);

        std::string const &getName() const;
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter &target);
        void disposing_Materia(AMateria *m);
};

#endif
