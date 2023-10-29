/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:55:42 by iengels           #+#    #+#             */
/*   Updated: 2023/10/29 11:32:41 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

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
