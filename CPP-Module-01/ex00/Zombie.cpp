/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:32:16 by iengels           #+#    #+#             */
/*   Updated: 2023/09/20 21:22:55 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie (std::string name)
{
    this->_name = name;
    std::cout << "Zombie " << this->_name << " created" << std::endl;
}

Zombie::~Zombie (void)
{
    std::cout << "Zombie " << _name << " destroyed" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}