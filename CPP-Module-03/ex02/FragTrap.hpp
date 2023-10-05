/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:24:03 by iengels           #+#    #+#             */
/*   Updated: 2023/10/03 21:18:31 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

#pragma once

class FragTrap: public ClapTrap
{
    public:
        FragTrap( void );
        FragTrap(std::string name);
        FragTrap(FragTrap const& copy);
        ~FragTrap();

        FragTrap& operator = (FragTrap const& copy);

        void highFivesGuys(void);
};

#endif
