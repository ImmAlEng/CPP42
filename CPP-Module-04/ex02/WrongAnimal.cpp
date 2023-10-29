/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:16:45 by iengels           #+#    #+#             */
/*   Updated: 2023/10/28 22:38:56 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
    std::cout << "Default WrongAnimal constructor called -" << type << " Created" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
    std::cout << "Type WrongAnimal constructor called -" << type << " Created" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy)
{
    std::cout << "Copy WrongAnimal constructor called -" << type << " Created" << std::endl;
    *this = copy;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Default WrongAnimal deconstructor called -" << type << " Destroyed" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &copy)
{
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        type = copy.type;
    }
    return *this;
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "Default Wronganimal barking sound" << std::endl;
}

const std::string WrongAnimal::getType(void) const
{
    return (type);
}