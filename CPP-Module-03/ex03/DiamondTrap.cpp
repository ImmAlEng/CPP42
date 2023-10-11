/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:46:38 by iengels           #+#    #+#             */
/*   Updated: 2023/10/10 00:14:05 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp" // Include your class declaration

DiamondTrap::DiamondTrap(void) : ClapTrap("Diamond_ClapTrap "), name("Diamond")
{
    this->hitpoints = FragTrap::hitpoints; 
    this->energypoints = ScavTrap::energypoints;
    this->attackpoints = FragTrap::attackpoints;
    std::cout << "DiamondTrap " << DiamondTrap.name << " created" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap " << DiamondTrap::name << " destroyed" << std::endl;
}

// class Parent1
// {
//     protected:
//         std::string name;
//     public:
//         Parent1();
//         ~Parent1();

// };
// class Middle2 : public Parent1
// {
//     public:
//         Middle2();
//         ~Middle2();

// };
// class Middle1 : public Parent1
// {
//     public:
//         Middle1();
//         ~Middle1();

// };
// class Child1 : public Middle1, public Middle2
// {
//     private:
//         std::string name;
//     public:
//         Child1(void);
//         ~Child1();
// };

// Child1::~Child1(void)
// {
//     std::cout << "Child1 " << name << " destroyed" << std::endl;
// }