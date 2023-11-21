/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:55:31 by iengels           #+#    #+#             */
/*   Updated: 2023/11/20 23:24:19 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <cmath>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

int main(void)
{
    int array[21] = {0, 1, 3, 5, 7, 10, 13, 16, 19, 22, 26, 29, 33, 37, 41, 45, 49, 53, 57, 62, 66};
    std::vector< int > vec;
    std::string input;
    std::ifstream file("test.txt");
    int n = 0;

    std::getline(file, input, '\n');

    std::getline(file, input, '\n');

    input = input.substr(6, input.size() - 6);
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == ' ' || input[i] == ',')
            continue;
        else if (isdigit(input[i]))
        {
            n = 0;
            while (isdigit(input[i]))
            {
                n = n * 10;
                n += input[i] - '0';
                i++;
            }
            vec.push_back(n);
        }
        else
        {
            std::cout << "Invalid input" << std::endl;
            return (false);
        }
    }
    std::getline(file, input, '\n');
    int compare = 0;
    for (int i = 0; i < input.size(); i++)
    {
        if (isdigit(input[i]))
        {
            while (isdigit(input[i]))
            {
                compare = compare * 10;
                compare += input[i] - '0';
                i++;
            }
            vec.push_back(n);
        }
    }
    std::cout << (std::is_sorted(vec.begin(), vec.end()) ? "\033[32mSorted? Yes" : "\033[31mSorted? No") << RESET << std::endl;
    if (vec.size() > 21)
    {
        return (0);
    }
    if (compare <= array[vec.size() - 1])
        std::cout << GREEN << "Comparisons: " << compare << RESET << std::endl;
    else
        std::cout << RED << "Comparisons: " << compare << RESET << std::endl;
    return 0;
}
