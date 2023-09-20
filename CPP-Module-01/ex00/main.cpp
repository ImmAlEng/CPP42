/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:28:41 by iengels           #+#    #+#             */
/*   Updated: 2023/09/20 20:14:54 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump( std::string name );

Zombie* newZombie( std::string name );

int main(void)
{
    Zombie *z1 = newZombie("Immanuel");
    z1->announce();
    randomChump("Yen");
    delete z1;
    return 0;
}
