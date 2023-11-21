/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:31:57 by iengels           #+#    #+#             */
/*   Updated: 2023/11/21 14:28:57 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

template <typename T>
const typename T::const_iterator easyfind(const T &container, int n)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), n);
    if (it == container.end())
        throw std::exception();
    return it;
}

#endif
