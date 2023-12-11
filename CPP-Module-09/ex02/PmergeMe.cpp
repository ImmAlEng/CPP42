/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:44:38 by iengels           #+#    #+#             */
/*   Updated: 2023/11/22 23:18:14 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstddef>
#include <iostream>
#include <ostream>
#include <vector>

// static functions
static bool isDequeEmpty(const std::deque< size_t > &innerDeque)
{
    return innerDeque.empty();
} // No Lambda expressions in C++98 :-(

static bool isVectorEmpty(const std::vector< size_t > &innerVector)
{
    return innerVector.empty();
} // No Lambda expressions in C++98 :-(

// prepare index
static void deque_prepare_index(std::deque< std::deque< size_t > > &deq)
{
    for (size_t i = 0; i < deq.size(); i++)
        deq[i].push_front(i + 1);
}

static void vector_prepare_index(std::vector< std::vector< size_t > > &vec)
{
    for (size_t i = 0; i < vec.size(); i++)
        vec[i].insert(vec[i].begin(), i + 1);
}

//  compare functions
size_t vector_compare(size_t a, size_t b, bool getnb)
{
    static size_t count;
    if (getnb)
        return count;
    if (count < std::numeric_limits< size_t >::max())
        count++;
    return (a > b);
}

size_t deque_compare(size_t a, size_t b, bool getnb)
{
    static size_t count;
    if (getnb)
        return count;
    if (count < std::numeric_limits< size_t >::max())
        count++;
    return (a > b);
}

// jacobsthal functions
size_t ft_jacobsthal(size_t i)
{
    if (i == 0)
        return 0;
    else if (i == 1)
        return 1;
    else
        return ft_jacobsthal(i - 1) + 2 * ft_jacobsthal(i - 2);
}

size_t ft_jacobsthal_range(size_t n_jacobsthal, size_t size)
{
    if (n_jacobsthal <= 2)
        return 0;
    size_t range = ft_jacobsthal(n_jacobsthal) - ft_jacobsthal(n_jacobsthal - 1) - 1;
    if (range >= size - 1)
        return size - 1;
    return range;
}

// print functions
void ft_print_deque(std::deque< std::deque< size_t > > const &deq, std::string str)
{
    std::cout << str << ": ";
    for (std::deque< std::deque< size_t > >::const_iterator i = deq.begin(); i != deq.end(); i++)
    {
        for (std::deque< size_t >::const_iterator j = i->begin(); j != i->end(); j++)
        {
            std::cout << *j;
            if (j + 1 != i->end())
                std::cout << ", ";
        }
        if (i + 1 != deq.end())
            std::cout << ", ";
    }
    std::cout << std::endl;
}

void ft_print_vector(std::vector< std::vector< size_t > > const &vec, std::string str)
{
    std::cout << str << ": ";
    for (std::vector< std::vector< size_t > >::const_iterator i = vec.begin(); i != vec.end(); i++)
    {
        for (std::vector< size_t >::const_iterator j = i->begin(); j != i->end(); j++)
        {
            std::cout << *j;
            if (j + 1 != i->end())
                std::cout << ", ";
        }
        if (i + 1 != vec.end())
            std::cout << ", ";
    }
    std::cout << std::endl;
}

////create functions
std::deque< std::deque< size_t > > ft_create_deque(std::vector< size_t > const &input)
{
    std::deque< std::deque< size_t > > deq;
    for (std::vector< size_t >::const_iterator i = input.begin(); i != input.end(); i++)
        deq.push_back(std::deque< size_t >(1, *i));
    return deq;
}

std::vector< std::vector< size_t > > ft_create_vector(std::vector< size_t > const &input)
{
    std::vector< std::vector< size_t > > vec;
    for (std::vector< size_t >::const_iterator i = input.begin(); i != input.end(); i++)
        vec.push_back(std::vector< size_t >(1, *i));
    return vec;
}

// check sort functions
bool vector_sorted(std::vector< std::vector< size_t > > const &vec)
{
    if (vec.size() < 2)
        return true;
    for (size_t i = 0; i < vec.size() - 1; i++)
        if (vec[i][0] > vec[i + 1][0])
            return false;
    return true;
}

bool deque_sorted(std::deque< std::deque< size_t > > const &deq)
{
    if (deq.size() < 2)
        return true;
    for (size_t i = 0; i < deq.size() - 1; i++)
        if (deq[i][0] > deq[i + 1][0])
            return false;
    return true;
}

// move all elements from one deque/vector to another
void ft_move_deque(std::deque< size_t > &deq1, std::deque< size_t > &deq2)
{
    while (!deq1.empty())
    {
        deq2.push_back(deq1.front());
        deq1.pop_front();
    }
}

void ft_move_vector(std::vector< size_t > &vec1, std::vector< size_t > &vec2)
{
    while (!vec1.empty())
    {
        vec2.push_back(vec1.front());
        vec1.erase(vec1.begin());
    }
}

// merge pairs
void deque_merge_pairs(std::deque< std::deque< size_t > > &deq)
{
    for (size_t i = 0; i < deq.size() - 1; i += 2)
    {
        if (deque_compare(deq[i].front(), deq[i + 1].front(), false))
            ft_move_deque(deq[i + 1], deq[i]);
        else
            ft_move_deque(deq[i], deq[i + 1]);
    }
    deq.erase(std::remove_if(deq.begin(), deq.end(), isDequeEmpty), deq.end());
}

void vector_merge_pairs(std::vector< std::vector< size_t > > &vec)
{
    for (size_t i = 0; i < vec.size() - 1; i += 2)
    {
        if (vector_compare(vec[i].front(), vec[i + 1].front(), false))
            ft_move_vector(vec[i + 1], vec[i]);
        else
            ft_move_vector(vec[i], vec[i + 1]);
    }
    vec.erase(std::remove_if(vec.begin(), vec.end(), isVectorEmpty), vec.end());
}

// retrieve lower bound
std::deque< std::deque< size_t > > ft_deque_retrieve_lower_bound(std::deque< std::deque< size_t > > &deq)
{
    std::deque< std::deque< size_t > > deq2;
    for (size_t i = 0; i < deq.size(); i++)
    {
        size_t size = deq[i].size();
        std::deque< size_t > temp;
        for (size_t j = 0; j < size / 2; j++)
        {
            temp.push_front(deq[i].back());
            deq[i].pop_back();
        }
        deq2.push_back(temp);
    }
    return deq2;
}

std::vector< std::vector< size_t > > ft_vector_retrieve_lower_bound(std::vector< std::vector< size_t > > &vec)
{
    std::vector< std::vector< size_t > > vec2;
    for (size_t i = 0; i < vec.size(); i++)
    {
        size_t size = vec[i].size();
        std::vector< size_t > temp;
        for (size_t j = 0; j < size / 2; j++)
        {
            temp.insert(temp.begin(), vec[i].back());
            vec[i].pop_back();
        }
        vec2.push_back(temp);
    }
    return vec2;
}

// binary search
long deque_binary_insertion(std::deque< std::deque< size_t > > &deq1, std::deque< size_t > &deq2, size_t insertions)
{
    long predicted = deq2.front() + insertions;
    long low = 0;
    long high = predicted;
    long mid = ((low + high) >> 1);
    deq2.pop_front();
    while (low != high)
    {
        if (std::numeric_limits< long >::max() <= ((low + high) >> 1))
            throw PmergeMe_IntegerOverflow();
        if (deque_compare(deq1[mid].front(), deq2.front(), false))
            high = mid - 1 < low ? low : mid - 1;
        else
            low = mid + 1 > high ? high : mid + 1;
        mid = ((low + high) >> 1);
    }
    if (!deque_compare(deq1[mid].front(), deq2.front(), false))
        mid++;
    deq1.insert(deq1.begin() + mid, deq2);
    return predicted - mid;
}

long vector_binary_insertion(std::vector< std::vector< size_t > > &vec1, std::vector< size_t > &vec2, size_t insertions)
{
    long predicted = vec2.front() + insertions;
    long low = 0;
    long high = predicted;
    long mid = ((low + high) >> 1);
    vec2.erase(vec2.begin());
    while (low != high)
    {
        if (std::numeric_limits< long >::max() <= ((low + high) >> 1))
            throw PmergeMe_IntegerOverflow();
        if (vector_compare(vec1[mid].front(), vec2.front(), false))
            high = mid - 1 < low ? low : mid - 1;
        else
            low = mid + 1 > high ? high : mid + 1;
        mid = ((low + high) >> 1);
    }
    if (!vector_compare(vec1[mid].front(), vec2.front(), false))
        mid++;
    vec1.insert(vec1.begin() + mid, vec2);
    return predicted - mid;
}

// binary search and insertion
void deque_binary_search_and_insertion(std::deque< std::deque< size_t > > &deq1,
                                       std::deque< std::deque< size_t > > &deq2)
{
    size_t n_jaco = 3;
    size_t insertions = 0;
    deq1.push_front(deq2[0]);
    deq2.erase(deq2.begin());
    if (deq2.empty())
        return;
    deque_prepare_index(deq2);
    while (!deq2.empty())
    {
        size_t i = ft_jacobsthal_range(n_jaco, deq2.size()) + 1;
        while (i--)
        {
            deque_binary_insertion(deq1, deq2[i], insertions);
            deq2.erase(deq2.begin() + i);
            insertions++;
        }
        n_jaco++;
    }
}

void vector_binary_search_and_insertion(std::vector< std::vector< size_t > > &vec1,
                                        std::vector< std::vector< size_t > > &vec2)
{
    size_t n_jaco = 3;
    size_t insertions = 0;
    vec1.insert(vec1.begin(), vec2[0]);
    vec2.erase(vec2.begin());
    if (vec2.empty())
        return;
    vector_prepare_index(vec2);
    while (!vec2.empty())
    {
        size_t i = ft_jacobsthal_range(n_jaco, vec2.size()) + 1;
        while (i--)
        {
            vector_binary_insertion(vec1, vec2[i], insertions);
            vec2.erase(vec2.begin() + i);
            insertions++;
        }
        n_jaco++;
    }
}

// other functions
void ft_ford_johnson_deq(std::deque< std::deque< size_t > > &deq)
{
    if (deq.empty())
        return;
    bool odd = deq.size() % 2;
    std::deque< size_t > spare;
    if (odd)
    {
        spare = deq[deq.size() - 1];
        deq.pop_back();
    }
    deque_merge_pairs(deq);
    if (deq.size() != 1)
        ft_ford_johnson_deq(deq);
    std::deque< std::deque< size_t > > deq2 = ft_deque_retrieve_lower_bound(deq);
    if (odd)
        deq2.push_back(spare);
    deque_binary_search_and_insertion(deq, deq2);
}

void ft_ford_johnson_vec(std::vector< std::vector< size_t > > &vec)
{
    if (vec.empty())
        return;
    bool odd = vec.size() % 2;
    std::vector< size_t > spare;
    if (odd)
    {
        spare = vec[vec.size() - 1];
        vec.pop_back();
    }
    vector_merge_pairs(vec);
    if (vec.size() != 1)
        ft_ford_johnson_vec(vec);
    std::vector< std::vector< size_t > > vec2 = ft_vector_retrieve_lower_bound(vec);
    if (odd)
        vec2.push_back(spare);
    vector_binary_search_and_insertion(vec, vec2);
}

bool ft_pMergeMe(std::vector< size_t > input)
{
    try
    {
        clock_t start = clock();
        std::deque< std::deque< size_t > > deq = ft_create_deque(input);
        ft_print_deque((const std::deque< std::deque< size_t > >)deq, "Before");
        ft_ford_johnson_deq(deq);
        clock_t end = clock();
        ft_print_deque((const std::deque< std::deque< size_t > >)deq, "After");
        // std::cout << "Comparisons: " << deque_compare(0, 0, true) << std::endl << std::endl;
        std::cout << std::fixed << "Time to process a range of " << deq.size() << " elements with std::deque< std::deque<size_t>> : " << ((double)(end - start) / CLOCKS_PER_SEC) << " us" << std::endl;
        deq.clear();
        start = clock();
        std::vector< std::vector< size_t > > vec = ft_create_vector(input);
        // ft_print_vector((const std::vector< std::vector< size_t > >)vec, "Vector before");
        ft_ford_johnson_vec(vec);
        end = clock();
        // ft_print_vector((const std::vector< std::vector< size_t > >)vec, "After");
        // std::cout << "Comparisons: " << vector_compare(0, 0, true) << std::endl;
        std::cout << std::fixed << "Time to process a range " << vec.size() << " elements with std::vector< std::vector<size_t>> : " << ((double)(end - start) / CLOCKS_PER_SEC) << " us" << std::endl;
        vec.clear();
        return true;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return (false);
    }
}

// Exception functions
const char *PmergeMe_InvalidInput::what() const throw() { return ("Invalid input"); }

const char *PmergeMe_IntegerOverflow::what() const throw() { return ("Integer overflow"); }

const char *PmergeMe_NegativInteger::what() const throw() { return ("Negativ integer"); }
