/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 21:02:03 by iengels           #+#    #+#             */
/*   Updated: 2023/10/11 21:55:03 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap diamond;

    diamond.attack("Someone");
    diamond.whoAmI();
    diamond.guardGate();
    diamond.highFivesGuys();
    diamond.beRepaired(10);

    return 0;
}