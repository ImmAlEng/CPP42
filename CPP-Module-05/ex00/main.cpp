/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 00:18:02 by iengels           #+#    #+#             */
/*   Updated: 2023/10/30 00:38:19 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    // Create a Bureaucrat with a valid grade
    try {
        Bureaucrat b1("Test1", 1);
        std::cout << b1 << std::endl;

        // Increase the grade
        b1.increase_Grade();
        std::cout << "After increasing the grade: " << b1 << std::endl;

        // Decrease the grade
        b1.decrease_Grade();
        std::cout << "After decreasing the grade: " << b1 << std::endl;

        b1.decrease_Grade(); // error
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

     try {
        Bureaucrat b2("Test1", 150);
        std::cout << b2 << std::endl;

        // Decrease the grade
        b2.decrease_Grade();
        std::cout << "After decreasing the grade: " << b2 << std::endl;

        // Increase the grade
        b2.increase_Grade();
        std::cout << "After increasing the grade: " << b2 << std::endl;

        b2.increase_Grade(); // error
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    Bureaucrat a1("Test2", 150);
    std::cout << a1.getName() << std::endl;
    std::cout << a1 << std::endl;
    Bureaucrat a2("Test3", 1);
    std::cout << a2 << std::endl;
    a2 = a1;
    std::cout << a2 << std::endl;

    // Create a Bureaucrat with an invalid grade (too high)
    try {
        Bureaucrat invalidBureaucrat("Invalid", 0); // This should throw an exception
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Create a Bureaucrat with an invalid grade (too low)
    try {
        Bureaucrat invalidBureaucrat("Invalid", 151); // This should throw an exception
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
