/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:22:48 by iengels           #+#    #+#             */
/*   Updated: 2023/10/03 19:02:50 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
    hitpoints = 100;
    energypoints = 50;
    attackpoints = 20;
    std::cout << "ScavTrap (inheritet from ClapTrap)" << name << "created by default constructer" << std::endl;
}

ScavTrap::ScavTrap(std::string name) :ClapTrap(name)
{
    hitpoints = 100;
    energypoints = 50;
    attackpoints = 20;
    std::cout << "ScavTrap (inheritet from ClapTrap)" << name << "created by naming constructer" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& copy) :ClapTrap(copy)
{
    std::cout << "ScavTrap (inheritet from ClapTrap)" << name << "created by copy constructer" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap (inheritet from ClapTrap)" << name << "destroyed by deconstructor" << std::endl;
}

ScavTrap& ScavTrap::operator = (ScavTrap const& copy)
{
    std::cout << "ScavTrap assignment operatot called" << std::endl;
    name = copy.name;
	hitpoints = copy.hitpoints;
	energypoints = copy.energypoints;
	attackpoints = copy.attackpoints;
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (energypoints <= 0)
        std::cout << "ScavTrap " << name << " can not attack " << target << "! No energypoints left." << std::endl;
    else if (hitpoints <= 0)
        std::cout << "ScavTrap " << name << " can not attack " << target << "! No hitpoints left." << std::endl;
    else
    {
        std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackpoints << " points of damage!" << std::endl;
        energypoints--;
    }
}

void ScavTrap::guardGate( void )
{
    if (hitpoints <= 0)
        std::cout << "ScavTrap is dead" << std::endl;
    else
        std::cout << " ScavTrap is now in Gatekeeper mode." << std::endl;
}
