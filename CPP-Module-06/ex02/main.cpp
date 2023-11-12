/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 23:30:14 by iengels           #+#    #+#             */
/*   Updated: 2023/11/12 23:32:00 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base *generate(void)
{
    int random = rand() % 3;

    if (random == 0)
        return (new A);
    else if (random == 1)
        return (new B);
    else
        return (new C);
}

void identify_from_pointer(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
}

void identify_from_reference(Base &p)
{
    if (dynamic_cast<A *>(&p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(&p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(&p))
        std::cout << "C" << std::endl;
}

int main(void)
{
    srand(time(NULL));

    Base *base = generate();
    identify_from_pointer(base);
    identify_from_reference(*base);
    delete base;
    return (0);
}
