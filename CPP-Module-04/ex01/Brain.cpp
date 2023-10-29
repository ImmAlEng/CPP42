/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 23:03:09 by iengels           #+#    #+#             */
/*   Updated: 2023/10/28 23:23:26 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Default Brain constructor called - Brain Created" << std::endl;
}

Brain::~Brain(void)
{
    std::cout << "Default Brain deconstructor called - Brain destroyed" << std::endl;
}

Brain::Brain(Brain const &copy)
{
    std::cout << "Copy Brain constructor called - Brain Created" << std::endl;
    *this = copy;
}

Brain& Brain::operator=(Brain const &copy)
{
    std::cout << "Brain copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        for (int i = 0; i < 100; i++)
            ideas[i] = copy.ideas[i];
    }
    return *this;
}