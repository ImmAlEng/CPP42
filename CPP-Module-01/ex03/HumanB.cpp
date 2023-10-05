/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:39:30 by iengels           #+#    #+#             */
/*   Updated: 2023/10/05 16:22:12 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) :weapon(NULL), name(name)
{
    std::cout << "HumanB " << name << " created" << std::endl;
}

HumanB::HumanB(void) {}

HumanB::~HumanB(void)
{
    std::cout << "HumanB " << name << " destroyed" << std::endl;
}

void HumanB::attack()
{
    if (!weapon)
        std::cout << name << " attacks with no weapon!" << std::endl;

    else
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}
