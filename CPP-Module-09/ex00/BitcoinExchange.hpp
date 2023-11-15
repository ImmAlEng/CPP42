/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:34:35 by iengels           #+#    #+#             */
/*   Updated: 2023/11/15 15:37:31 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>

#pragma once

class BitcoinExchange
{
    private:
        std::map<std::string, double> data;
        BitcoinExchange();

    public:
        BitcoinExchange(std::map<std::string, double> const &data);
        ~BitcoinExchange();
        BitcoinExchange(BitcoinExchange const &copy);
        
        BitcoinExchange const& operator= (BitcoinExchange const &copy);

        const std::map<std::string, double> getData(void) const;

};

std::ostream &	operator<<(std::ostream &os, BitcoinExchange const &BitcoinExchange);

#endif