/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:55:06 by iengels           #+#    #+#             */
/*   Updated: 2023/10/02 22:14:43 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    int N = 5;
    Zombie *h = zombieHorde(N, "TestZombie");
    for (int i = 0; i < N; i++)
    {
        std::cout << i+1 << ": ";
        h[i].announce();
    }
    delete []h;
    return 0;
}
