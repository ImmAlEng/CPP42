/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:34:35 by iengels           #+#    #+#             */
/*   Updated: 2023/11/22 17:26:23 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <climits>
#include <list>

#pragma once

class BitcoinExchange
{
    private:
        std::map<std::string, float> data;
        std::list<std::string> input;
        std::string output;
        BitcoinExchange();

    public:
        BitcoinExchange(std::string const &data_f, std::string const &input_f);
        ~BitcoinExchange();
        BitcoinExchange(BitcoinExchange const &copy);
        
        BitcoinExchange const& operator= (BitcoinExchange const &copy);

        void getData(std::ifstream &datafile);
        void getInput(std::ifstream &inputfile);

        const std::map<std::string, float> getDataMap(void) const;
        const std::list<std::string> getInputMap(void) const;
        const std::string getOutput(void) const;

        bool ft_validate_rate(std::string exchange);
        bool ft_validate_date(std::string date, bool limit);

        void setOutput(void);

        class InvalidDateException : public std::exception
        {
            virtual const char* what() const throw();
        };
        class InvalidRateException : public std::exception
        {
            virtual const char* what() const throw();
        };
        class InvalidFileException : public std::exception
        {
            virtual const char* what() const throw();
        };
};

std::ostream &	operator<<(std::ostream &os, BitcoinExchange const &BitcoinExchange);

#endif
