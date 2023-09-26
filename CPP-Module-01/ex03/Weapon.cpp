/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:39:45 by iengels           #+#    #+#             */
/*   Updated: 2023/09/26 18:39:28 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string name)
{
    this->type = name;
}

Weapon::Weapon(void)
{

}

Weapon::~Weapon(void)
{
    
}

const std::string& Weapon::getType()  const
{
    return type;
}

void Weapon::setType(const std::string type)
{
    this->type = type;
}
