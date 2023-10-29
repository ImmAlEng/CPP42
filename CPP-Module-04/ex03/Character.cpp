/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 08:53:31 by iengels           #+#    #+#             */
/*   Updated: 2023/10/29 10:33:52 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : ICharacter(), name("defaultChar"), disposed_size(0)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = nullptr;
    std::cout << "Character default constructor called - " << name << " created" << std::endl;
}

Character::Character(std::string name) : ICharacter(), name(name), disposed_size(0)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = nullptr;
    std::cout << "Character naming constructor called - " << name << " created" << std::endl;
}

Character::~Character() 
{
    for (int i = 0; i < 4; i++)
        delete inventory[i];
    for (int i = 0; i < disposed_size; i++)
        disposed[i];
    delete[] disposed;
    std::cout << "Character deconstructor called - " << name << " destroyed" << std::endl;
}

Character::Character(Character const &copy) : ICharacter(copy)
{
    std::cout << "Character copy constructor called - " << name << " created" << std::endl;
    *this = copy;
}

Character &Character::operator=(Character const &copy)
{
    if (this != &copy)
    {
        for (int i = 0; i < 4; i++)
        {
            if (inventory[i])
                delete inventory[i];
            inventory[i] = nullptr;
        }
        name = copy.name;
        for (int i = 0; i < 4; i++)
        {
            if (copy.inventory[i])
                inventory[i] = copy.inventory[i]->clone();
        }
    }
    return *this;
}

std::string const &Character::getName() const
{
}

void Character::equip(AMateria *m)
{
}

void Character::unequip(int idx)
{
}

void Character::use(int idx, ICharacter &target)
{
}

void Character::disposing_Materia(AMateria *m)
{
    if (m)
    {
        AMateria **newDisposed = new AMateria *[disposed_size + 1];
        if (!newDisposed)
            return (delete m);
        for (int i = 0; i < disposed_size; i++)
            newDisposed[i] = disposed[i];
        delete[] disposed;
        disposed = newDisposed;
        disposed[disposed_size++] = m;
    }
}
