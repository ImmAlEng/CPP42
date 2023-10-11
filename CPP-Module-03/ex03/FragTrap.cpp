/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:23:32 by iengels           #+#    #+#             */
/*   Updated: 2023/10/11 21:15:27 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) :ClapTrap()
{
    hitpoints = 100;
    energypoints = 100;
    attackpoints = 30;
    std::cout << "FragTrap (inheritet from ClapTrap)" << name << "created by default constructer" << std::endl;
}

FragTrap::FragTrap(std::string name) :ClapTrap(name)
{
    name = name;
    hitpoints = 100;
    energypoints = 100;
    attackpoints = 30;
    std::cout << "FragTrap (inheritet from ClapTrap)" << name << "created by naming constructer" << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy) :ClapTrap(copy)
{
    std::cout << "FragTrap (inheritet from ClapTrap)" << name << "created by copy constructer" << std::endl;
    *this = copy;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap (inheritet from ClapTrap)" << name << "destroyed by deconstructor" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &copy)
{
    std::cout << "FragTrap assignment operator called" << std::endl;
    name = copy.name;
    hitpoints = copy.hitpoints;
    energypoints = copy.energypoints;
    attackpoints = copy.attackpoints;
    return *this;
}

void FragTrap::highFivesGuys(void)
{
    if (hitpoints <= 0)
        std::cout << "FragTrap " << name << " is dead" << std::endl;
    else
        std::cout << "FragTrap " << name << " requests a High Five!" << std::endl;

}
