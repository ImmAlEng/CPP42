/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:47:40 by iengels           #+#    #+#             */
/*   Updated: 2023/10/10 00:15:39 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#pragma once
class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string	name;
	public:
		DiamondTrap(void);
		~DiamondTrap();

		virtual ~DiamondTrap();
		
		void whoAmI();
};

#endif