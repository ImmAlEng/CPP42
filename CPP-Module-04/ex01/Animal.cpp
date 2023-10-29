/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:39:39 by iengels           #+#    #+#             */
/*   Updated: 2023/10/28 22:46:58 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("Animal")
{
    std::cout << "Default Animal constructor called -" << type << " Created" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
    std::cout << "Type Animal constructor called -" << type << " Created" << std::endl;
}

Animal::Animal(Animal const &copy)
{
    std::cout << "Copy Animal constructor called -" << type << " Created" << std::endl;
    *this = copy;
}

Animal::~Animal()
{
    std::cout << "Default Animal deconstructor called -" << type << " Destroyed" << std::endl;
}

Animal &Animal::operator=(Animal const &copy)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        type = copy.type;
    }
    return *this;
}

const std::string Animal::getType(void) const
{
    return (type);
}

void Animal::makeSound(void)const
{
    std::cout << "Default animal sound" << std::endl;
}
