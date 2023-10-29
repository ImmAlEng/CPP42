/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:30:39 by iengels           #+#    #+#             */
/*   Updated: 2023/10/29 00:32:36 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

#pragma once

class Animal
{
protected:
    std::string type;

public:
    Animal(void);
    Animal(std::string type);
    Animal(Animal const &copy);
    virtual ~Animal();

    Animal &operator=(Animal const &copy);
    const std::string getType(void) const;
    virtual void makeSound(void)const;
};

#endif