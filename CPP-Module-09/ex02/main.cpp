/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:23:02 by iengels           #+#    #+#             */
/*   Updated: 2023/11/22 19:23:02 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstddef>

bool input_check_duplicates(std::vector< size_t > const &vect)
{
    for (size_t i = 0; i < vect.size() - 1; i++)
    {
        if (vect[i] == vect[i + 1])
            return (true);
    }
    return (false);
}

bool input_sorted(std::vector< size_t > const &vect)
{
    size_t i = 0;
    if (vect.empty() || vect.size() == 1)
        return false;
    for (; i < vect.size() - 1; i++)
    {
        if (vect[i] < vect[i + 1])
            continue;
        else
            break;
    }
    if (i == vect.size() - 1)
        return false;
    std::vector< size_t > dups = vect;
    std::sort(dups.begin(), dups.end());
    if (input_check_duplicates(dups))
    {
        std::cout << "Input contains duplicates" << std::endl;
        return (false);
    }
    return (true);
}

static size_t getint(std::string input, size_t *i)
{
    size_t result = 0;
    while (isdigit(input[*i]))
    {
        if (result > (std::numeric_limits< size_t >::max() - (input[*i] - '0')) / 10)
            throw PmergeMe_IntegerOverflow();
        result = result * 10 + input[*i] - '0';
        (*i)++;
    }
    return (result);
}

bool create_input_from_arg(std::vector< size_t > &vect, std::string input)
{
    size_t i = 0;
    while (input[i])
    {
        if (input[i] == ' ')
            i++;
        else if (isdigit(input[i]))
        {
            size_t result = getint(input, &i);
            try
            {
                vect.push_back(result);
            }
            catch (std::exception &e)
            {
                std::cout << e.what() << std::endl;
                return (false);
            }
        }
        else
        {
            std::cout << "Invalid input" << std::endl;
            return (false);
        }
    }
    if (vect.size() < 2)
    {
        std::cout << "Invalid input" << std::endl;
        return (false);
    }
    return true;
}

static bool ft_check_for_multiple(std::string input)
{
    size_t i = 0;
    size_t count = 0;

    while (input[i])
    {
        if (input[i] == ' ')
            i++;
        else if (isdigit(input[i]))
        {
            while (isdigit(input[i]))
                i++;
            count++;
        }
    }
    if (count > 1)
        return (true);
    return (false);
}

int main(int ac, char **av)
{
    std::vector< size_t > vect;

    try
    {
        if (ac == 1)
        {
            std::cout << "Please enter a list of mutliple integers to sort." << std::endl;
            return (1);
        }
        else if (ac == 2)
        {
            if (!ft_check_for_multiple(av[1]) || create_input_from_arg(vect, av[1]))
            {
                std::cout << "Enter a list of mutliple integers to sort." << std::endl;
                return (1);
            }
        }
        else
        {
            std::string input;
            for (size_t i = 1; i < (size_t)ac; i++)
            {
                if (ft_check_for_multiple(av[i]))
                {
                    std::cout << "Enter a list of mutliple integers to sort." << std::endl;
                    return (1);
                }
                input += std::string(av[i]) + " ";
            }
            if (!create_input_from_arg(vect, input))
                return 1;
            if (!input_sorted(vect))
                return (0);
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return (1);
    }
    if (!ft_pMergeMe(vect))
        return (1);
    return (0);
}
