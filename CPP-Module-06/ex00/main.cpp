/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:35:20 by iengels           #+#    #+#             */
/*   Updated: 2023/11/14 17:44:40 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        ScalarConverter::convert(av[1]);
    }
    else
    { 
        // Test cases Int
        std::cout << "\033[1;32mTest cases Int\n"
                  << std::endl;
        ScalarConverter::convert("0");
        ScalarConverter::convert("42");
        ScalarConverter::convert("-42");
        ScalarConverter::convert("2147483647");
        ScalarConverter::convert("-2147483648");
        std::cout << "Test Invalid:" << std::endl;
        ScalarConverter::convert("2147483648");

        // Test cases Char
        std::cout << "\033[1;94mTest cases Char" << std::endl;
        ScalarConverter::convert("a");
        std::cout << "Test Invalid:" << std::endl;
        ScalarConverter::convert("\t");
        ScalarConverter::convert(" ");
        std::cout << "Test Invalid:" << std::endl;
        ScalarConverter::convert("\0");

        // Test cases Float
        std::cout << "\033[1;33mTest cases Float" << std::endl;
        ScalarConverter::convert("0.0f");
        ScalarConverter::convert("42.0f");
        ScalarConverter::convert("-42.0f");
        ScalarConverter::convert("2147483647.0f");
        ScalarConverter::convert("-2147483648.0f");
        ScalarConverter::convert("2147483690283509221312348.0f");

        // Test cases Double
        std::cout << "\033[1;93mTest cases Double" << std::endl;
        ScalarConverter::convert("0.0");
        ScalarConverter::convert("42.0");
        ScalarConverter::convert("-42.0");
        ScalarConverter::convert("2147483647.0");
        ScalarConverter::convert("-2147483690283509221312348214748369028350922131234821474836902835092213123482147483690283509221312348.0");
        ScalarConverter::convert("2147483690283509221312348214748369028350922131234821474836902835092213123482147483690283509221312348.0");

        // Test cases NaN and Inf
        std::cout << "\033[1;34mTest cases NaN and Inf" << std::endl;
        ScalarConverter::convert("nan");
        ScalarConverter::convert("nanf");
        ScalarConverter::convert("inf");
        ScalarConverter::convert("inff");
        ScalarConverter::convert("-inf");
        ScalarConverter::convert("-inff");

        // Test cases Invalid
        std::cout << "\033[1;31mTest cases Invalid" << std::endl;
        ScalarConverter::convert("42.42.42");
        ScalarConverter::convert("42.42f.42");
        ScalarConverter::convert("42.42f42");
        ScalarConverter::convert("42.42f42.42");
        ScalarConverter::convert("42.dfsg");
        ScalarConverter::convert("Hello");
        ScalarConverter::convert("214748369028350922131234821474836902835092213123482147483690283509221312348214748369028350922131234821474836902835092213123482147483690283509221312348214748369028350922131234821474836902835092213123482147483690283509221312348214748369028350922131234821474836902835092213123482147483690283509221312348");
        std::cout << "\033[0m" << std::endl;
    }
    return 0;
}
