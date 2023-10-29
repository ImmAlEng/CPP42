/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:48:52 by iengels           #+#    #+#             */
/*   Updated: 2023/10/29 10:49:17 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

IMateriaSource::~IMateriaSource(void)
{
    std::cout << "IMateriaSource default constructor called" << std::endl;
}

IMateriaSource::IMateriaSource(IMateriaSource const &copy)
{
    std::cout << "IMateriaSource copy constructor called" << std::endl;
    *this = copy;
}

IMateriaSource::~IMateriaSource()
{
    std::cout << "IMateriaSource deconstructor called" << std::endl;
}

IMateriaSource& IMateriaSource::operator =(IMateriaSource const &copy)
{
    std::cout << "IMateriaSource assignment operator called" << std::endl;
    return *this;
}
