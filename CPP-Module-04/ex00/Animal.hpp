/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:30:39 by iengels           #+#    #+#             */
/*   Updated: 2023/10/12 18:51:58 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIME_HPP

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
        ~Animal();

        Animal& operator = (Animal const &copy);

        void    makeSound( void ) const;
};

#endif