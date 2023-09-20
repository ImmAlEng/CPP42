/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:59:53 by iengels           #+#    #+#             */
/*   Updated: 2023/09/20 21:23:24 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->_name = name;
    std::cout << "Zombie " << this->_name << " destroyed!" << std::endl;
}

Zombie::Zombie (void)
{
    std::cout << "Zombie " << " created" << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << "Zombie " << this->_name << " destroyed!" << std::endl;
}

void    Zombie::give_name(std::string name)
{
    this->_name = name;
}

void    Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
