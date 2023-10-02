/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:32:16 by iengels           #+#    #+#             */
/*   Updated: 2023/10/02 20:14:36 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie (std::string name)
{
    this->_name = name;
    std::cout << "Zombie " << this->_name << " created by default constructor" << std::endl;
}

Zombie::~Zombie (void)
{
    std::cout << "Zombie " << _name << " destroyed by destructor" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
