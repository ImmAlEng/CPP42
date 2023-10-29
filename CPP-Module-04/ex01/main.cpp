/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:22:04 by iengels           #+#    #+#             */
/*   Updated: 2023/10/28 23:35:46 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal *Cats_Dogs[100];
    for (int i = 0; i < 100; i++)
    {
        if (i < 50)
            Cats_Dogs[i] = new Cat();
        else
            Cats_Dogs[i] = new Dog();
    }
    for (int i = 0; i < 100; i++)
        delete Cats_Dogs[i];
}
