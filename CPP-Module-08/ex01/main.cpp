/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:31:56 by iengels           #+#    #+#             */
/*   Updated: 2023/11/14 01:59:32 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
    Span sp = Span(5);
    sp.addNumber(5);
    sp.addNumber(1);
    sp.addNumber(17);
    sp.addNumber(-1);
    sp.addNumber(11);
    Span sp2 = Span(10000000);
    sp2.fill_range(1, 1);
    std::vector<int> s = sp2.getS();
    std::cout << "Size of vector: " << s.size() << std::endl;
    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

    std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;
    return 0;
}
