/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:43:45 by iengels           #+#    #+#             */
/*   Updated: 2023/11/21 14:20:03 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <limits>
#pragma once

//create functions
std::deque<std::deque<size_t> > ft_create_deque(std::vector< size_t > const &input);
std::vector<std::vector<size_t> > ft_create_vector(std::vector< size_t > const &input);

//print functions
void ft_print_deque(std::deque<std::deque<size_t> > const &deq, std::string str);
void ft_print_vector(std::vector<std::vector<size_t> > const &vec, std::string str);

//check sort functions
bool vector_sorted(std::vector<std::vector<size_t> >::iterator begin, std::vector<std::vector<size_t> >::iterator end);
bool deque_sorted(std::deque<std::deque<size_t> >::iterator begin, std::deque<std::deque<size_t> >::iterator end);

//make pairs functions
void vector_merge_pairs(std::vector<std::vector<size_t> > &vec);
void deque_merge_pairs(std::deque<std::deque<size_t> > &deq);

//compare functions
size_t vector_compare(size_t a, size_t b, bool getnb);
size_t deque_compare(size_t a, size_t b, bool getnb);

//list functions
bool create_input_from_arg(std::vector< size_t > const &vect, std::string input);
bool input_sorted(std::vector< size_t > const &vect);
bool input_check_duplicates(std::vector< size_t > const &vect);
void ft_print_input(std::vector< size_t > const &vect);


bool ft_pMergeMe(std::vector<size_t> input);

class PmergeMe_NegativInteger : public std::exception
{
public:
    virtual const char *what() const throw();
};

class PmergeMe_IntegerOverflow : public std::exception
{
public:
    virtual const char *what() const throw();
};

class PmergeMe_InvalidInput : public std::exception
{
public:
    virtual const char *what() const throw();
};

#endif