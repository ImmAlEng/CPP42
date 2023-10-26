/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 00:47:51 by iengels           #+#    #+#             */
/*   Updated: 2023/10/26 18:23:14 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

#pragma once

class ScavTrap : public ClapTrap
{
public:
    ScavTrap(void);
    ScavTrap(std::string name);
    ScavTrap(ScavTrap const &copy);
    ~ScavTrap();

    ScavTrap &operator=(ScavTrap const &copy);

    void guardGate(void);
    void attack(const std::string &target);
};

#endif