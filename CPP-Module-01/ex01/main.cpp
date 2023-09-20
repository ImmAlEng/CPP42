/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:55:06 by iengels           #+#    #+#             */
/*   Updated: 2023/09/20 21:31:27 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main(void)
{
    int N = 5;
    Zombie *h = zombieHorde(N, "Immanuel");
    for (int i = 0; i < N; i++)
    {
        std::cout << i+1 << ": ";
        h[i].announce();
    }
    delete []h;
    return 0;
}