/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:31:53 by iengels           #+#    #+#             */
/*   Updated: 2023/11/13 12:45:35 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
    std::vector<int>    vec;
    std::list<int>      lst;
    std::deque<int>     deq;

    for (int i = 0; i < 10; i++)
    {
        vec.push_back(i);
        lst.push_back(i);
        deq.push_back(i);
    }
    const std::vector<int> cvec(vec);
    std::cout << "Vector: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "List: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl; 

    std::cout << "Deque: ";
    for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "Trying to find 5 in Vector: ";
    try
    {
        std::cout << *easyfind(vec, 5) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "5 not found in Vector" << std::endl;
    }
    std::cout << "Trying to find 10 in Vector: ";
    try
    {
        std::cout << *easyfind(vec, 10) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "10 not found in Vector" << std::endl;
    }
    std::cout << "Trying to find -1 in Vector: ";
    try
    {
        std::cout << *easyfind(vec, -1) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "-1 not found in Vector" << std::endl;
    }
    std::cout << "Trying to find 5 in List: ";
    try
    {
        std::cout << *easyfind(lst, 5) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "5 not found in List" << std::endl;
    }
    std::cout << "Trying to find 10 in List: ";
    try
    {
        std::cout << *easyfind(lst, 10) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "10 not found in List" << std::endl;
    }
    std::cout << "Trying to find -1 in List: ";
    try
    {
        std::cout << *easyfind(lst, -1) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "-1 not found in List" << std::endl;
    }
    std::cout << "Trying to find 5 in Deque: ";
    try
    {
        std::cout << *easyfind(deq, 5) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "5 not found in Deque" << std::endl;
    }
    std::cout << "Trying to find 10 in Deque: ";
    try
    {
        std::cout << *easyfind(deq, 10) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "10 not found in Deque" << std::endl;
    }
    std::cout << "Trying to find -1 in Deque: ";
    try
    {
        std::cout << *easyfind(deq, -1) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "-1 not found in Deque" << std::endl;
    }
    std::cout << "Trying to find 5 in Const Vector: ";
    try
    {
        std::cout << *easyfind(cvec, 5) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "5 not found in Const Vector" << std::endl;
    }
    std::cout << "Trying to find 10 in Const Vector: ";
    try
    {
        std::cout << *easyfind(cvec, 10) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "10 not found in Const Vector" << std::endl;
    }
    std::cout << "Trying to find -1 in Const Vector: ";
    try
    {
        std::cout << *easyfind(cvec, -1) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "-1 not found in Const Vector" << std::endl;
    }
    return (0);
}
