/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:22:33 by iengels           #+#    #+#             */
/*   Updated: 2023/11/13 00:26:16 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
    int int_array[5] = {1, 2, 3, 4, 5};
    std::string string_array[5] = {"Hello", "World", "!", "How", "Are You?"};

    std::cout << "Int array:" << std::endl;
    iter(int_array, 5, print);
    std::cout << std::endl;

    std::cout << "String array:" << std::endl;
    iter(string_array, 5, print);
    std::cout << std::endl;

    std::cout << "Double array:" << std::endl;
    double double_array[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    iter(double_array, 5, print);

    

    return (0);
}
