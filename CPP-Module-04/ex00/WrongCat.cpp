/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:19:17 by iengels           #+#    #+#             */
/*   Updated: 2023/10/28 22:42:17 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) :WrongAnimal("WrongCat")
{
    type = "WrongCat";
    std::cout << "Default WrongCat constructor called -" << type << " Created" << std::endl;
}

WrongCat::WrongCat(WrongCat const &copy) :WrongAnimal(copy)
{
    std::cout << "Copy WrongCat constructor called -" << type << " Created" << std::endl;
    *this = copy;
}

WrongCat::~WrongCat()
{
    std::cout << "Default WrongCat deconstructor called -" << type << " Destroyed" << std::endl;
}

WrongCat& WrongCat::operator = (WrongCat const &copy)
{
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    WrongAnimal::operator=(copy);
    return *this;
}

void    WrongCat::makeSound( void )
{
    std::cout << "Meow" << std::endl;
}
