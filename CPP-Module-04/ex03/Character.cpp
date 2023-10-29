/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 08:53:31 by iengels           #+#    #+#             */
/*   Updated: 2023/10/29 16:01:43 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : name("defaultChar"), disposed(NULL), disposed_size(0)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
    std::cout << "Character default constructor called - " << name << " created" << std::endl;
}

Character::Character(std::string name) : name(name), disposed(NULL), disposed_size(0)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
    std::cout << "Character naming constructor called - " << name << " created" << std::endl;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i])
            delete inventory[i];
    }
    if (disposed)
    {
        for (int i = 0; i < disposed_size; i++)
        {
            if (disposed[i])
                delete disposed[i];
        }
        delete[] disposed;
    }
    std::cout << "Character deconstructor called - " << name << " destroyed" << std::endl;
}

Character::Character(Character const &copy)
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
            inventory[i] = NULL;
        }
        name = copy.name;
        for (int i = 0; i < 4; i++)
        {
            if (copy.inventory[i])
                inventory[i] = copy.inventory[i]->clone();
        }
        if (disposed)
        {
            for (int i = 0; i < disposed_size; i++)
            {
                if (disposed[i])
                    delete disposed[i];
            }
            delete[] disposed;
        }
        AMateria **newDisposed = new AMateria *[copy.disposed_size];
        if (!newDisposed)
            disposed = NULL;
        else
        {
            if (copy.disposed)
            {
                for (int i = 0; i < copy.disposed_size; i++)
                    newDisposed[i] = copy.disposed[i]->clone();
            }
        }
        disposed = newDisposed;
        disposed_size = copy.disposed_size;
    }
    return *this;
}

std::string const &Character::getName() const
{
    return (name);
}

void Character::equip(AMateria *m)
{
    if (m)
    {
        for (int i = 0; i < 4; i++)
        {
            if (!inventory[i])
            {
                inventory[i] = m->clone();
                break;
            }
        }
        delete m;
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx <= 3)
    {
        if (inventory[idx])
        {
            disposing_Materia(inventory[idx]);
            inventory[idx] = NULL;
        }
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx <= 3)
    {
        if (inventory[idx])
            inventory[idx]->use(target);
    }
}

void Character::disposing_Materia(AMateria *m)
{
    if (m)
    {
        AMateria **newDisposed = new AMateria *[disposed_size + 1];
        if (!newDisposed)
            return (delete m);
        if (disposed)
        {
            for (int i = 0; i < disposed_size; i++)
                newDisposed[i] = disposed[i]->clone();
            for (int i = 0; i < disposed_size; i++)
            {
                if (disposed[i])
                    delete disposed[i];
            }
            delete[] disposed;
        }
        disposed = newDisposed;
        disposed[disposed_size++] = m;
    }
}
