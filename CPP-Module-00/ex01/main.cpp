/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:41:29 by iengels           #+#    #+#             */
/*   Updated: 2023/09/18 13:24:03 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    PhoneBook pb;
    std::string str;

    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT)-$ ";
		std::getline(std::cin, str);
        if (std::cin.eof())
        {
            std::cout << std::endl;
            return 0;
        }
        if (str == "EXIT")
            break;
        else if (str == "ADD")
            pb.add();
        else if (str == "SEARCH")
            pb.search();
    }
    return 0;
}
