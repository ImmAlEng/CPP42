/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:20:10 by iengels           #+#    #+#             */
/*   Updated: 2023/11/17 17:44:19 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <limits>
#include <climits>
#include <iomanip>
#include <sstream>
#pragma once

void ft_rpn(std::string input);

class RPN_DivideByZero : public std::exception
{
    public:
        virtual const char* what() const throw();
};

class RPN_IntegerOverflow : public std::exception
{
    public:
        virtual const char* what() const throw();
};

class RPN_NotEnoughOperants : public std::exception
{
    public:
        virtual const char* what() const throw();
};

class RPN_LeftoverOperants : public std::exception
{
    public:
        virtual const char* what() const throw();
};

class RPN_InvalidInput : public std::exception
{
    public:
        virtual const char* what() const throw();
};

#endif
