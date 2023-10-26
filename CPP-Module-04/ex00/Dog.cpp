/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:42:43 by iengels           #+#    #+#             */
/*   Updated: 2023/10/26 18:04:45 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) :Animal("Dog") {}

Dog& Dog::operator=(Dog const &copy)
{
    Animal::operator=(copy);    
    return *this;
}