/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 01:05:33 by iengels           #+#    #+#             */
/*   Updated: 2023/10/29 11:31:54 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) :AMateria("cure")
{
    std::cout << "Cure default constructor called - " << type << " created" << std::endl;
}

Cure::~Cure()
{
    std::cout << "Cure deconstructor called - " << type << " destroyed" << std::endl;
}

Cure::Cure(Cure const &copy) :AMateria(copy)
{
    std::cout << "Cure copy constructor called - " << type << " created" << std::endl;
    *this = copy;
}

Cure& Cure::operator=(Cure const &copy)
{
    std::cout << "Cure assignment operator called" << std::endl;
    AMateria::operator=(copy);
    return *this;
}
