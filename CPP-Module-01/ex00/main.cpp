/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:28:41 by iengels           #+#    #+#             */
/*   Updated: 2023/10/02 13:55:10 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump( std::string name );

Zombie* newZombie( std::string name );

int main(void)
{
    Zombie *z1 = newZombie("Test1");
    z1->announce();
    randomChump("Randomchump");
    delete z1;
    return 0;
}
