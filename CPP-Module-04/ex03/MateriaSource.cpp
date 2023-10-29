/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 08:47:40 by iengels           #+#    #+#             */
/*   Updated: 2023/10/29 08:53:25 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
    std::cout << "Default MateriaSource constructor called -" <<  " Created" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &copy)
{
    std::cout << "Copy MateriaSource constructor called -" <<  " Created" << std::endl;
    *this = copy;
}

MateriaSource::~MateriaSource()
{
    std::cout << "Default MateriaSource deconstructor called -" << " Destroyed" << std::endl;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &copy)
{
    std::cout << "MateriaSource copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        
    }
    return *this;
}
