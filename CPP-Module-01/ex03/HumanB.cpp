/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:39:30 by iengels           #+#    #+#             */
/*   Updated: 2023/09/29 15:16:17 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) :name(name)
{
    std::cout << "HumanB " << name << " created" << std::endl;
}

HumanB::HumanB(void) {};

HumanB::~HumanB()
{
    std::cout << "HumanB " << name << " destroyed" << std::endl;
}

void HumanB::attack()
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

void HumanB::setWeapon(Weapon weapon)
{
    this->weapon = weapon;
}
