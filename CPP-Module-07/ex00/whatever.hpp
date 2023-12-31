/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:17:09 by iengels           #+#    #+#             */
/*   Updated: 2023/11/13 00:51:00 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#pragma once

template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
const T min(const T &a, const T &b)
{
    return (a < b ? a : b);
}

template <typename T>
const T max(const T &a, const T &b)
{
    return (a > b ? a : b);
}

#endif