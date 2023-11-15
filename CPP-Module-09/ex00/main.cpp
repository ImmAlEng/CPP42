/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:41:34 by iengels           #+#    #+#             */
/*   Updated: 2023/11/15 15:37:28 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./btc <filename>!" << std::endl;
        return 1;
    }
    std::map<std::string, float> data;
    std::ifstream file("./data.csv");
    if (!file.is_open())
        std::cout << "Cannot open file: ./data.csv" << std::endl;
    std::string str;
    while (getline(file, str))
    {
        
    }
    BitcoinExchange btc(data);
    std::cout << btc << std::endl;
    return 0;
}