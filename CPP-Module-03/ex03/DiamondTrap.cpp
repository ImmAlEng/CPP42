/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:46:38 by iengels           #+#    #+#             */
/*   Updated: 2023/10/06 11:48:10 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp" // Include your class declaration

// Constructors
DiamondTrap::DiamondTrap() : _name("default_clap_name") {
    std::cout << "DiamondTrap " << _name << " created with default constructor." << std::endl;
}

DiamondTrap::DiamondTrap(std::string const &name) : _name(name) {
    std::cout << "DiamondTrap " << _name << " created." << std::endl;
}

// Destructor
DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << _name << " destroyed." << std::endl;
}

// Copy Constructor
DiamondTrap::DiamondTrap(const DiamondTrap &copy) : _name(copy._name) {
    std::cout << "DiamondTrap " << _name << " copied." << std::endl;
}

// Assignment Operator
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy) {
    std::cout << "Assignment operator for DiamondTrap called." << std::endl;
    if (this != &copy) {
        _name = copy._name;
    }
    return *this;
}

// Member function to display names
void DiamondTrap::whoAmI() {
    if (_hp <= 0)
        std::cout << "Cannot run whoAmI because: DiamondTrap " << _name << " is dead." << std::endl;
    else {
        std::cout << "DiamondTrap name: " << _name << "." << std::endl;
        std::cout << "ClapTrap name: " << _name + "_clap_name" << "." << std::endl;
    }
}

// Member function to delegate the attack
void DiamondTrap::attack(std::string const &target) {
    std::cout << "DiamondTrap " << _name << " attacks " << target << ", causing " << _damage << " points of damage!" << std::endl;
}
