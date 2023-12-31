/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:03:33 by iengels           #+#    #+#             */
/*   Updated: 2023/10/28 22:46:34 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) :Animal("Dog")
{
    type = "Dog";
    std::cout << "Default Dog constructor called -" << type << " Created" << std::endl;
}

Dog::Dog(Dog const &copy) :Animal(copy)
{
    std::cout << "Copy Dog constructor called -" << type << " Created" << std::endl;
    *this = copy;
}

Dog::~Dog()
{
    std::cout << "Default Dog deconstructor called -" << type << " Destroyed" << std::endl;
}

Dog& Dog::operator = (Dog const &copy)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    Animal::operator=(copy);
    return *this;
}

void    Dog::makeSound( void )const
{
    std::cout << "Bark" << std::endl;
}
