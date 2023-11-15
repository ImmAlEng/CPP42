/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:49:12 by iengels           #+#    #+#             */
/*   Updated: 2023/11/15 15:37:30 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::map<std::string, double> const &data)
{

}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy) :BitcoinExchange(copy.data) {*this = copy;}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange const& BitcoinExchange::operator= (BitcoinExchange const &copy)
{
    if (this == &copy)
        data = copy.data;
    return *this;
}

const std::map<std::string, double> BitcoinExchange::getData(void) const
{
    return (data);
}

std::ostream&	operator<<(std::ostream &os, BitcoinExchange const &copy)
{
    std::cout << "Exchange Data" << std::endl;
    return (os);
}