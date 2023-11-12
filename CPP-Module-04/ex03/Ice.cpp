/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:55:42 by iengels           #+#    #+#             */
/*   Updated: 2023/10/29 15:52:31 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice(void) :AMateria("ice")
{
    std::cout << "Ice default constructor called - " << type << " created" << std::endl;
}

Ice::~Ice()
{
    std::cout << "Ice deconstructor called - " << type << " destroyed" << std::endl;
}

Ice::Ice(Ice const &copy) : AMateria(copy)
{
    std::cout << "Ice copy constructor called - " << type << " created" << std::endl;
    *this = copy;
}

Ice& Ice::operator=(Ice const &copy)
{
    std::cout << "Ice assignment operator called" << std::endl;
    AMateria::operator=(copy);
    return *this;
}

AMateria* Ice::clone() const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
