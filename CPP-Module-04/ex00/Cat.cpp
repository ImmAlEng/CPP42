/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:00:20 by iengels           #+#    #+#             */
/*   Updated: 2023/10/28 22:46:47 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) :Animal("Cat")
{
    type = "Cat";
    std::cout << "Default Cat constructor called -" << type << " Created" << std::endl;
}

Cat::Cat(Cat const &copy) :Animal(copy)
{
    std::cout << "Copy Cat constructor called -" << type << " Created" << std::endl;
    *this = copy;
}

Cat::~Cat()
{
    std::cout << "Default Cat deconstructor called -" << type << " Destroyed" << std::endl;
}

Cat& Cat::operator = (Cat const &copy)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    Animal::operator=(copy);
    return *this;
}

void    Cat::makeSound( void )const
{
    std::cout << "Meow" << std::endl;
}
