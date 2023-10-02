/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:47:40 by iengels           #+#    #+#             */
/*   Updated: 2023/10/02 22:30:29 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl harl;
    if (ac != 2)
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    else
        harl.complain(av[1]);
    return 0;
}
