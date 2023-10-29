/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:51:52 by iengels           #+#    #+#             */
/*   Updated: 2023/10/28 22:46:24 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#pragma once
class Dog: public Animal
{
    public:
        Dog(void);
        ~Dog();
        Dog(Dog const &copy);

        Dog& operator = (Dog const &copy);
        void makeSound(void) const;
};

#endif