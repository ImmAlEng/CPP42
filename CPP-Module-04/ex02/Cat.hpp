/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:01:48 by iengels           #+#    #+#             */
/*   Updated: 2023/10/28 23:30:42 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#pragma once

class Cat: public Animal
{
    private:
        Brain *CatBrain;
    public:
        Cat(void);
        ~Cat();
        Cat(Cat const &copy);

        Cat& operator = (Cat const &copy);
        void makeSound(void)const;
};

#endif