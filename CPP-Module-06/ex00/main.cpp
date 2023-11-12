/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:35:20 by iengels           #+#    #+#             */
/*   Updated: 2023/11/09 16:07:25 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        ScalarConverter converter(av[1]);
        std::cout << converter << std::endl;
    }
    else
    { 
        // Test cases Int
        ScalarConverter converter1("0");
        ScalarConverter converter2("42");
        ScalarConverter converter3("-42");
        ScalarConverter converter4("2147483647");
        ScalarConverter converter5("-2147483648");
        ScalarConverter converter6("2147483648");

        // Test cases Char
        ScalarConverter converter7("a");
        ScalarConverter converter8("\t");
        ScalarConverter converter9(" ");
        ScalarConverter converter10("\0");

        // Test cases Float
        ScalarConverter converter11("0.0f");
        ScalarConverter converter12("42.0f");
        ScalarConverter converter13("-42.0f");
        ScalarConverter converter14("2147483647.0f");
        ScalarConverter converter15("-2147483648.0f");
        ScalarConverter converter16("2147483690283509221312348.0f");

        // Test cases Double
        ScalarConverter converter17("0.0");
        ScalarConverter converter18("42.0");
        ScalarConverter converter19("-42.0");
        ScalarConverter converter20("2147483647.0");
        ScalarConverter converter21("-2147483690283509221312348214748369028350922131234821474836902835092213123482147483690283509221312348.0");
        ScalarConverter converter22("2147483690283509221312348214748369028350922131234821474836902835092213123482147483690283509221312348.0");

        // Test cases NaN and Inf
        ScalarConverter converter23("nan");
        ScalarConverter converter24("nanf");
        ScalarConverter converter25("inf");
        ScalarConverter converter26("inff");
        ScalarConverter converter27("-inf");
        ScalarConverter converter28("-inff");

        // Test cases Invalid
        ScalarConverter converter29("42.42.42");
        ScalarConverter converter30("42.42f.42");
        ScalarConverter converter31("42.42f42");
        ScalarConverter converter32("42.42f42.42");
        ScalarConverter converter33("42.dfsg");
        ScalarConverter converter34("Hello");
        ScalarConverter converter35("214748369028350922131234821474836902835092213123482147483690283509221312348214748369028350922131234821474836902835092213123482147483690283509221312348214748369028350922131234821474836902835092213123482147483690283509221312348214748369028350922131234821474836902835092213123482147483690283509221312348");

        // Display the results
        std::cout << "\033[1;32mTest cases Int\n"
                  << std::endl;
        std::cout << converter1 << std::endl;
        std::cout << converter2 << std::endl;
        std::cout << converter3 << std::endl;
        std::cout << converter4 << std::endl;
        std::cout << converter5 << std::endl;
        std::cout << "Test Invalid:" << std::endl;
        std::cout << converter6 << std::endl;

        std::cout << "\033[1;94mTest cases Char" << std::endl;
        std::cout << converter7 << std::endl;
        std::cout << "Test Invalid:" << std::endl;
        std::cout << converter8 << std::endl;
        std::cout << converter9 << std::endl;
        std::cout << "Test Invalid:" << std::endl;
        std::cout << converter10 << std::endl;

        std::cout << "\033[1;33mTest cases Float" << std::endl;
        std::cout << converter11 << std::endl;
        std::cout << converter12 << std::endl;
        std::cout << converter13 << std::endl;
        std::cout << converter14 << std::endl;
        std::cout << converter15 << std::endl;
        std::cout << converter16 << std::endl;

        std::cout << "\033[1;93mTest cases Double" << std::endl;
        std::cout << converter17 << std::endl;
        std::cout << converter18 << std::endl;
        std::cout << converter19 << std::endl;
        std::cout << converter20 << std::endl;
        std::cout << converter21 << std::endl;
        std::cout << converter22 << std::endl;

        std::cout << "\033[1;34mTest cases NaN and Inf" << std::endl;
        std::cout << converter23 << std::endl;
        std::cout << converter24 << std::endl;
        std::cout << converter25 << std::endl;
        std::cout << converter26 << std::endl;
        std::cout << converter27 << std::endl;
        std::cout << converter28 << std::endl;

        std::cout << "\033[1;31mTest cases Invalid" << std::endl;
        std::cout << converter29 << std::endl;
        std::cout << converter30 << std::endl;
        std::cout << converter31 << std::endl;
        std::cout << converter32 << std::endl;
        std::cout << converter33 << std::endl;
        std::cout << converter34 << std::endl;
        std::cout << converter35 << "\033[0m" << std::endl;
    }

    return 0;
}
