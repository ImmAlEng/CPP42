/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 01:01:51 by iengels           #+#    #+#             */
/*   Updated: 2023/10/03 17:33:37 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

#pragma once

class ClapTrap
{
    protected:
        std::string name;
        int hitpoints;
        int energypoints;
        int attackpoints;
        
    public:
        ClapTrap(void);
        ClapTrap(std::string name);
        ClapTrap( ClapTrap const& copy );
        ~ClapTrap();

        ClapTrap &operator = (const ClapTrap &copy);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif
