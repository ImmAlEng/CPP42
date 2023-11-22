/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:48:30 by rkurnava          #+#    #+#             */
/*   Updated: 2023/11/10 14:13:17 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void print(int const i)
{
    std::cout << i << " ";
}

int main(void)
{
    std::vector<int> nums;
    nums.insert(nums.begin(), 6);
    nums.push_back(7);
    nums.push_back(8);
    std::cout << "Vector contains: ";
    std::for_each(nums.begin(), nums.end(), &print);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Trying to find: 6, 8, 10" << std::endl;
    try
    {
        easyfind(nums, 6);
        std::cout << "Found 6" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        easyfind(nums, 8);
        std::cout << "Found 8" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        easyfind(nums, 10);
        std::cout << "Found 10" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
    std::vector<int> const nummer(20, 5);
    std::cout << "Const vector contains: ";
    std::for_each(nummer.begin(), nummer.end(), &print);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Trying to find: 5, 8" << std::endl;
    try
    {
        easyfind(nummer, 5);
        std::cout << "Found 5" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        easyfind(nummer, 8);
        std::cout << "Found 8" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return (0);
}
