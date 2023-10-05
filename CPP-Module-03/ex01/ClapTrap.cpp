/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 01:01:22 by iengels           #+#    #+#             */
/*   Updated: 2023/10/03 19:23:03 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) :name("Clap"), hitpoints(10), energypoints(10), attackpoints(0)
{
    std::cout << "Default ClapTrap " << name << " created" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) :name(name), hitpoints(10), energypoints(10), attackpoints(0)
{
    std::cout << "ClapTrap " << name << " created" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const& copy )
{
    std::cout << "ClapTrap " << name << " cloned" << std::endl;
    *this = copy;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " destroyed" << std::endl;
}

ClapTrap& ClapTrap::operator = (const ClapTrap &copy)
{
    std::cout << "copy assignment operator called" << std::endl;
    hitpoints = copy.hitpoints;
    energypoints = copy.energypoints;
    attackpoints = copy.attackpoints;
    name = copy.name;
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (energypoints <= 0)
        std::cout << name << " can not attack " << target << "! No energypoints left." << std::endl;
    else if (hitpoints <= 0)
        std::cout << name << " can not attack " << target << "! No hitpoints left." << std::endl;
    else
    {
        std::cout << name << " attacks " << target << ", causing " << attackpoints << " points of damage!" << std::endl;
        energypoints--;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitpoints <= 0)
        std::cout << name << " hitpoints are already gone!" << std::endl;
    else
    {
        hitpoints -= amount;
        std::cout << name << " recieves " << amount << " of damage! " << hitpoints << " hitpoints remain!" << std::endl;
    }    
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energypoints <= 0)
        std::cout << name << " can not be repaired! No energypoints left." << std::endl;
    else if (hitpoints <= 0)
        std::cout << name << " can not be repaired! No hitpoints left." << std::endl;
    else
    {
        hitpoints += amount;
        std::cout << name << " was repaired for " << amount << " hitpoints! " << hitpoints << " hitpoints remain!" << std::endl;
        energypoints--;
    }
}
