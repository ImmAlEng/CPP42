/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:47:40 by iengels           #+#    #+#             */
/*   Updated: 2023/10/06 11:47:45 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string	_name;
};
