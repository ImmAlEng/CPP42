/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:27:39 by iengels           #+#    #+#             */
/*   Updated: 2023/11/13 01:48:37 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#pragma once

template <typename T>
class Array
{
    private:
        T *array;
        unsigned int _size;
    public:
        Array(void) : array(NULL), _size(0) { std::cout << "Default constructor called - Array created" << std::endl;}
        Array(unsigned int n) : array(new T[n]), _size(n) { std::cout << "Parameter constructor called - Array of size " << _size << " created" << std::endl;}
        Array(Array const &copy) : array(NULL), _size(0) {*this = copy; std::cout << "Copy constructor called - Array of size " << _size << " copied" << std::endl;}
        ~Array(void) { std::cout << "Deconstructor called - Array destroyed" << std::endl; delete [] array;}

        Array &operator=(Array const &copy)
        {
            if (this != &copy)
            {
                delete [] array;
                array = new T[copy.size()];
                _size = copy.size();
                for (unsigned int i = 0; i < _size; i++)
                    array[i] = copy.array[i];
            }
            return (*this);
        }

        T &operator[](unsigned int i)
        {
            if (i >= _size || array == NULL)
                throw std::exception();
            return (array[i]);
        }

        unsigned int size(void) const {return (_size);}
};

#endif
