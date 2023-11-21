/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:31:56 by iengels           #+#    #+#             */
/*   Updated: 2023/11/21 16:56:34 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <deque>
#include <list>

int main(void)
{
    try
    {
        Span sp = Span(5);
        sp.addNumber(5);
        sp.addNumber(1);
        sp.addNumber(17);
        sp.addNumber(-1);
        sp.addNumber(11);
        Span sp2 = Span(5000000);

        std::vector< int > vec;
        std::deque< int > deq;
        std::list< int > lst;
        for (int i = 1; i < 31; i++)
        {
            if (i < 11)
                deq.push_back(i);
            else if (i < 21)
                lst.push_back(i);
            else
                vec.push_back(i);
        }
        // std::vector< std::string > v;
        // v.push_back("a");
        // v.push_back("b");
        // v.push_back("c");
       // sp2.fill_range_iterators(v.begin(), v.end());

        Span sp3 = Span(30);
        sp3.fill_range_iterators(deq.begin(), deq.end());
        sp3.fill_range_iterators(lst.begin(), lst.end());
        sp3.fill_range_iterators(vec.begin(), vec.end());

        for (size_t i = 1; i <= sp3.getS().size(); i++)
            std::cout << sp3.getS()[i - 1] << " ";

        std::cout << std::endl;

        sp2.fill_range(1, 10);

        std::vector< int > s = sp2.getS();
        std::cout << "Size of vector: " << s.size() << std::endl;
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

        std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;
        return 0;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return -1;
    }
}
