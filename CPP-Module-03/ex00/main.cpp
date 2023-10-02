/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 01:54:32 by iengels           #+#    #+#             */
/*   Updated: 2023/10/02 01:57:21 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main (void)
{
    ClapTrap cp("crapclap");

    cp.attack("someone");
    cp.attack("someone");
    cp.attack("someone");
    cp.attack("someone");
    cp.takeDamage(5);
    cp.beRepaired(1);
    cp.attack("someone");
    cp.attack("someone");
    cp.attack("someone");
    cp.attack("someone");
    cp.attack("someone");
    cp.attack("someone");
    cp.beRepaired(10);
    cp.takeDamage(10);
    cp.takeDamage(10);

    return 0 ;
}