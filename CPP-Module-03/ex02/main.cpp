/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:21:18 by iengels           #+#    #+#             */
/*   Updated: 2023/10/04 13:42:46 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    // Test the ClapTrap class with different constructors
    ClapTrap clapTrapDefault; // Default constructor
    ClapTrap clapTrapNamed("ClapTrapNamed"); // Named constructor
    ClapTrap clapTrapCopy(clapTrapNamed); // Copy constructor

    clapTrapDefault.attack("Target");
    clapTrapNamed.takeDamage(20);
    clapTrapCopy.beRepaired(10);

    // Test the FragTrap class with different constructors
    FragTrap fragTrapDefault; // Default constructor
    FragTrap fragTrapNamed("FragTrapNamed"); // Named constructor
    FragTrap fragTrapCopy(fragTrapNamed); // Copy constructor

    fragTrapDefault.attack("Target");
    fragTrapNamed.highFivesGuys();
    fragTrapCopy.takeDamage(30);

    // Test the ScavTrap class with different constructors
    ScavTrap scavTrapDefault; // Default constructor
    ScavTrap scavTrapNamed("ScavTrapNamed"); // Named constructor
    ScavTrap scavTrapCopy(scavTrapNamed); // Copy constructor

    scavTrapDefault.attack("Target");
    scavTrapNamed.guardGate();
    scavTrapCopy.beRepaired(12);

    return 0;
}
