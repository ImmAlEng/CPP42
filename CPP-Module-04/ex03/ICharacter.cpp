/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:09:29 by iengels           #+#    #+#             */
/*   Updated: 2023/10/29 10:34:01 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::~ICharacter(void)
{
    std::cout << "ICharacter default constructor called" << std::endl;
}

ICharacter::ICharacter(ICharacter const &copy)
{
    std::cout << "ICharacter copy constructor called" << std::endl;
    *this = copy;
}

ICharacter::~ICharacter()
{
    std::cout << "ICharacter deconstructor called" << std::endl;
}

ICharacter& ICharacter::operator =(ICharacter const &copy)
{
    std::cout << "ICharacter assignment operator called" << std::endl;
    return *this;
}
