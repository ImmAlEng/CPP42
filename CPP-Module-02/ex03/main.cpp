/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 23:54:53 by iengels           #+#    #+#             */
/*   Updated: 2023/10/01 23:08:00 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp" 

int main()
{
    Point a(0.0, 0.0);
    Point b(4.0, 0.0);
    Point c(2.0, 4.0);

    Point testPoint(2.0, 2.0);

    bool isInside = bsp(a, b, c, testPoint);

    if (isInside)
        std::cout << "\033[1;32mThe test point is inside the triangle.\033[0m" << std::endl;
    else
        std::cout << "\033[1;31mThe test point is outside the triangle.\033[0m" << std::endl;
    
    return 0;
}
