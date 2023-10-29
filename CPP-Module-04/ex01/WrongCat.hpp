/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:20:49 by iengels           #+#    #+#             */
/*   Updated: 2023/10/28 22:36:04 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#pragma once

class WrongCat : public WrongAnimal
{
public:
    WrongCat(void);
    ~WrongCat();
    WrongCat(WrongCat const &copy);

    WrongCat &operator=(WrongCat const &copy);
    void makeSound(void);
};

#endif