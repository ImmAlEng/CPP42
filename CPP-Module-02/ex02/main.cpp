/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 23:54:53 by iengels           #+#    #+#             */
/*   Updated: 2023/10/01 19:51:48 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp" 

int main() 
{
    // Create Fixed objects for testing
    Fixed a(3.875f);
    Fixed b(2.3765f);

    // Test arithmetic operators
    Fixed c = a + b;
    std::cout << "a + b = " << c << std::endl;

    c = a - b;
    std::cout << "a - b = " << c << std::endl;

    c = a * b;
    std::cout << "a * b = " << c << std::endl;

    c = a / b;
    std::cout << "a / b = " << c << std::endl;

    // Test comparison operators
    bool isEqual = a == b;
    std::cout << "a == b: " << isEqual << std::endl;

    bool isNotEqual = a != b;
    std::cout << "a != b: " << isNotEqual << std::endl;

    bool isLessThanOrEqual = a <= b;
    std::cout << "a <= b: " << isLessThanOrEqual << std::endl;

    bool isGreaterThanOrEqual = a >= b;
    std::cout << "a >= b: " << isGreaterThanOrEqual << std::endl;

    bool isLessThan = a < b;
    std::cout << "a < b: " << isLessThan << std::endl;

    bool isGreaterThan = a > b;
    std::cout << "a > b: " << isGreaterThan << std::endl;

    // Test increment and decrement operators
    Fixed temp = a;
    std::cout << std::endl;
    c = ++a;
    std::cout << "++a = " << c << std::endl;
    c = ++a;
    std::cout << "2x ++a = " << c << std::endl;
    c = ++a;
    std::cout << "3x ++a = " << c << std::endl;
    std::cout << std::endl;

    a = temp;
    c = a++;
    std::cout << "a++ = " << c << std::endl;
    c = a++;
    std::cout << "2x a++ = " << c << std::endl;
    c = a++;
    std::cout << "3x a++ = " << c << std::endl;
    std::cout << std::endl;

    temp = b;
    c = --b;
    std::cout << "--b = " << c << std::endl;
    c = --b;
    std::cout << "2x --b = " << c << std::endl;
    c = --b;
    std::cout << "3x --b = " << c << std::endl;
    std::cout << std::endl;

    b = temp;
    c = b--;
    std::cout << "b-- = " << c << std::endl;
    c = b--;
    std::cout << "2x b-- = " << c << std::endl;
    c = b--;
    std::cout << "3x b-- = " << c << std::endl;
    std::cout << std::endl;

    
    // Test toInt and toFloat functions
    int intVal = a.toInt();
    std::cout << "a as int: " << intVal << std::endl;

    float floatVal = b.toFloat();
    std::cout << "b as float: " << floatVal << std::endl;

    // Test min and max functions
    Fixed minValue = Fixed::min(a, b);
    Fixed maxValue = Fixed::max(a, b);
    std::cout << "Min of a and b: " << minValue << std::endl;
    std::cout << "Max of a and b: " << maxValue << std::endl;

    // Test getRawBits and setRawBits
    int rawBits = a.getRawBits();
    std::cout << "Raw bits of a: " << rawBits << std::endl;

    a.setRawBits(12345);
    std::cout << "a after setting raw bits: " << a << std::endl;

    return 0;
}
