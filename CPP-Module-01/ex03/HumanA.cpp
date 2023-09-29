/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:39:36 by iengels           #+#    #+#             */
/*   Updated: 2023/09/29 15:16:12 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon) :name(name), weapon(weapon) 
{
    std::cout << "HumanA " << name << " created" << std::endl;
}

HumanA::HumanA(void) {};

HumanA::~HumanA()
{
    std::cout << "HumanA " << name << " destroyed" << std::endl;
}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

void HumanA::setWeapon(Weapon weapon)
{
    this->weapon = weapon;
}
