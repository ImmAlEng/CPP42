/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 21:34:39 by iengels           #+#    #+#             */
/*   Updated: 2023/09/20 21:45:18 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "memory address of the string variable:\t" << &str << std::endl;
    std::cout << "memory address held by stringPTR:\t" << stringPTR << std::endl;
    std::cout << "memory address held by stringREF:\t" << &stringREF << std::endl;
    std::cout << "The value of the string variable:\t" << str << std::endl;
    std::cout << "The value pointed to by stringPTR:\t" << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF:\t" << stringREF << std::endl;
    return 0;
}