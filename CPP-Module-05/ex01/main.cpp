/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 00:18:02 by iengels           #+#    #+#             */
/*   Updated: 2023/10/30 13:20:32 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("b1", 2);
        std::cout << b1 << std::endl;

        Form f1("f1", 10, 100);
        std::cout << f1 << std::endl;

        f1.beSigned(b1);
        std::cout << f1 << std::endl;
    
        Form f2("f2", 1, 5);
        std::cout << f2 << std::endl;

        f2.beSigned(b1); // Exceptions
        std::cout << f2 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    Bureaucrat b2("b2", 3);
    Form f3("f3", 5, 8);
    std::cout << f3 << std::endl;

    b2.signForm(f3);
    std::cout << f3 << std::endl;

    Form f4("f4", 2, 8);
    std::cout << f4 << std::endl;

    b2.signForm(f4);
    std::cout << f4 << std::endl;
    return (0);
}
