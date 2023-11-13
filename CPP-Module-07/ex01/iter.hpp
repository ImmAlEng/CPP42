/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:21:45 by iengels           #+#    #+#             */
/*   Updated: 2023/11/13 01:55:51 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#pragma once

template <typename T>
void iter(T *array, int length, void (*function)(T const &))
{
    if (!array || !function || length <= 0)
        return;
    for (int i = 0; i < length; i++)
        function(array[i]);
}

template <typename T>
void print(T const &x)
{
    std::cout << x << std::endl;
}

#endif
