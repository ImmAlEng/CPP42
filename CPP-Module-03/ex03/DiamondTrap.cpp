/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:46:38 by iengels           #+#    #+#             */
/*   Updated: 2023/10/11 21:52:47 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp" // Include your class declaration

DiamondTrap::DiamondTrap(void) :ClapTrap("Diamond_ClapTrap "), name("Diamond")
{
    hitpoints = FragTrap::hitpoints; 
    energypoints = ScavTrap::energypoints;
    attackpoints = FragTrap::attackpoints;
    std::cout << "DiamondTrap " << name << " created" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap " << DiamondTrap::name << " destroyed via default constructor" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), name(name)
{
    hitpoints = FragTrap::hitpoints; 
    energypoints = ScavTrap::energypoints;
    attackpoints = FragTrap::attackpoints;
    std::cout << "DiamondTrap " << name << " created via naming constructor" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy) :ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
    std::cout << "DiamondTrap " << name << " created via copy constructor" << std::endl;
}

DiamondTrap& DiamondTrap::operator = (DiamondTrap const & copy)
{
    std::cout << "DiamondTrap " << name << " assignment operator called" << std::endl;
    name = copy.name;
    hitpoints = copy.hitpoints;
    energypoints = copy.energypoints;
    attackpoints = copy.attackpoints;
    return (*this);
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI()
{
    std::cout << "ClapTrapName: " << ClapTrap::name << std::endl;
    std::cout << "ClapTrapName: " << name << std::endl;
}