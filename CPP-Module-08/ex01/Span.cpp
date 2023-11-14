#include "Span.hpp"

Span::Span(unsigned int n) : n(n)
{
    s.reserve(n);
    std::cout << "Type Span constructor called - Span Created" << std::endl;
}

Span::Span(const Span &copy) : n(copy.n)
{
    std::cout << "Copy Span constructor called - Span Created" << std::endl;
    *this = copy;
}

Span::~Span()
{
    std::cout << "Default Span deconstructor called - Span Destroyed" << std::endl;
}

Span &Span::operator=(const Span &copy)
{
    std::cout << "Span copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        s = copy.s;
        n = copy.n;
    }
    return *this;
}
std::vector<int> Span::getS() const
{
    return s;
}

void Span::addNumber(int n)
{
    if (s.size() < this->n)
        s.push_back(n);
    else
        throw std::exception();
}

void Span::fill_range(int start, int end)
{
    if (start == end)
        throw std::exception();
    unsigned int size = start > end ? start - end : end - start;
    if (size + s.size() + 1 > n)
        throw std::exception();
    if (start > end)
        for (int i = start; i >= end; i--)
            s.push_back(i);
    else
        for (int i = start; i <= end; i++)
            s.push_back(i);
}

void Span::fill_random(int n)
{
    srand(time(NULL));
    if (n + s.size() > this->n)
        throw std::exception();
    for (int i = 0; i < n; i++)
        s.push_back(rand());
}

unsigned int Span::getN() const
{
    return n;
}

int Span::shortestSpan() const
{
    if (s.size() < 2)
        throw std::exception();
    std::vector<int> copy(s);
    std::sort(copy.begin(), copy.end());
    int shortest = copy[1] - copy[0];
    for (unsigned int i = 2; i < copy.size(); i++)
        if (copy[i] - copy[i - 1] < shortest)
            shortest = copy[i] - copy[i - 1];
    return shortest;
}

int Span::longestSpan() const
{
    if (s.size() < 2)
        throw std::exception();
    std::vector<int> copy(s);
    std::sort(copy.begin(), copy.end());
    return copy[copy.size() - 1] - copy[0];
}

const char *Span::NotEnoughMemory::what() const throw()
{
    return "Not enough memory to instantiate Span of this size";
}
