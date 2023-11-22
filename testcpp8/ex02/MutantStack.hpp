/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 02:12:14 by iengels           #+#    #+#             */
/*   Updated: 2023/11/21 17:03:31 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <algorithm>
#include <iostream>
#include <iterator>
#include <stack>

#pragma once

template < typename T > class MutantStack : public std::stack< T >
{
  public:
    typedef typename std::stack< T >::container_type::iterator iterator;
    typedef typename std::stack< T >::container_type::const_iterator c_iterator;

    MutantStack(void) : std::stack< T >()
    {
        std::cout << "Type MutantStack constructor called - MutantStack Created" << std::endl;
    }
    MutantStack(const MutantStack &copy) : std::stack< T >(copy)
    {
        std::cout << "Copy MutantStack constructor called - MutantStack Created" << std::endl;
    }
    ~MutantStack() { std::cout << "Default MutantStack deconstructor called - MutantStack Destroyed" << std::endl; }

    MutantStack &operator=(const MutantStack &copy)
    {
        if (this != &copy)
            std::stack< T >::operator=(copy);
        return *this;
    }

    iterator begin(void) { return std::stack< T >::c.begin(); }
    iterator end(void) { return std::stack< T >::c.end(); }
    c_iterator cbegin() const { return std::stack< T >::c.begin(); }
    c_iterator cend() const { return std::stack< T >::c.end(); }
};

#endif
