/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:42:56 by iengels           #+#    #+#             */
/*   Updated: 2023/10/29 11:38:15 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
    type = "defaultType";
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type)
{
    std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::AMateria(AMateria const &copy) : type(copy.type)
{
    std::cout << "AMateria copy constructor called" << std::endl;
    *this = copy;
}

AMateria::~AMateria()
{
    std::cout << "AMateria deconstructor called" << std::endl;
}

AMateria &AMateria::operator=(AMateria const &copy)
{
    std::cout << "AMateria assignment operator called" << std::endl;
    if (this != &copy)
        type = copy.type;
    return *this;
}
