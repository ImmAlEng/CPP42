#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <vector>

#pragma once

class Span
{
  private:
    std::vector< int > s;
    unsigned int n;
    Span(void);

  public:
    Span(unsigned int n);
    Span(const Span &copy);
    ~Span();

    Span &operator=(const Span &copy);

    std::vector< int > getS(void) const;

    void addNumber(int n);
    void fill_range(int start, int end);

    template < typename Iterator >
    void fill_range_iterators(const Iterator begin,const Iterator end)
    {
        if (begin == end)
            throw std::exception();
        for (Iterator it = begin; it != end; ++it)
        {
            int value = *it;
            addNumber(value);
        }
        std::cout << std::endl;
    }

    void fill_random(int n);

    int shortestSpan(void) const;
    int longestSpan(void) const;

    class NotEnoughMemory : public std::exception
    {
        virtual const char *what() const throw();
    };

    unsigned int getN(void) const;
};

#endif
