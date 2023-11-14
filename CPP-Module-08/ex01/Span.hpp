#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <cstdlib>
#include <ctime>

#pragma once

class Span
{
    private:
        std::vector<int> s;
        unsigned int n;
        Span(void);

    public:
        Span(unsigned int n);
        Span(const Span &copy);
        ~Span();

        Span &operator=(const Span &copy);

        std::vector<int> getS(void) const;
        
        void addNumber(int n);
        void fill_range(int start, int end);
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
