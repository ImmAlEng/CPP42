/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 08:47:40 by iengels           #+#    #+#             */
/*   Updated: 2023/10/29 16:08:39 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
    for (int i = 0; i < 4; i++)
        materiabook[i] = NULL;
    std::cout << "Default MateriaSource constructor called -"
              << " Created" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &copy)
{
    std::cout << "Copy MateriaSource constructor called -"
              << " Created" << std::endl;
    *this = copy;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (materiabook[i])
            delete materiabook[i];
    }
    std::cout << "Default MateriaSource deconstructor called -"
              << " Destroyed" << std::endl;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &copy)
{
    std::cout << "MateriaSource copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        for (int i = 0; i < 4; i++)
        {
            if (materiabook[i])
            {
                delete materiabook[i];
                materiabook[i] = NULL;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (copy.materiabook[i])
                materiabook[i] = copy.materiabook[i]->clone();
            else
                materiabook[i] = NULL;
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (m)
    {
        for (int i = 0; i < 4; i++)
        {
            if (!materiabook[i])
            {
                materiabook[i] = m->clone();
                break;
            }
        }
        delete m;
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (materiabook[i] && materiabook[i]->getType() == type)
            return (materiabook[i]->clone());
    }
    return (0);
}
