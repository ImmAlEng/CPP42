/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:49:12 by iengels           #+#    #+#             */
/*   Updated: 2023/11/22 19:41:57 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstddef>

BitcoinExchange::BitcoinExchange(std::string const &data_f, std::string const &input_f)
{
    std::ifstream datafile;
    std::ifstream inputfile;
    inputfile.open(input_f.c_str());
    datafile.open(data_f.c_str());
    if (!inputfile.is_open() || !datafile.is_open())
        throw InvalidFileException();
    getData(datafile);
    getInput(inputfile);
    inputfile.close();
    datafile.close();
    setOutput();
}

void BitcoinExchange::getData(std::ifstream &datafile)
{
    std::string str;
    std::string date;
    std::string exchange;
    size_t i;
    float rate;
    getline(datafile, str, '\n');
    while (getline(datafile, str, '\n'))
    {
        if (str.length() == 0)
            break;
        i = str.find(',');
        if (i == std::string::npos)
        {
            std::cout << "Error in data.csv detected - closing program" << std::endl;
            throw InvalidDateException();
        }
        date = str.substr(0, i);
        if (ft_validate_date(date, 1))
        {
            std::cout << "Error in data.csv detected (date) - closing program" << std::endl;
            throw InvalidDateException();
        }
        exchange = str.substr(i + 1, str.length() - i - 1);
        if (ft_validate_rate(exchange))
        {
            std::cout << "Error in data.csv detected (rate) - closing program" << std::endl;
            throw InvalidRateException();
        }
        char *end;
        rate = std::strtof(exchange.c_str(), &end);
        data.insert(std::make_pair(date, rate));
    }
}

void BitcoinExchange::getInput(std::ifstream &inputfile)
{
    std::string str;
    while (getline(inputfile, str, '\n'))
    {
        if (str.empty())
            continue;
        input.push_back(str);
    }
    for (bool b = true; b;)
    {
        b = false;
        for (std::list< std::string >::iterator it = input.begin(); it != input.end(); ++it)
        {
            if (it->empty() || *it == "date | value")
            {
                input.erase(it);
                b = true;
                break;
            }
        }
    }
}

bool ft_NaN(std::string str)
{
    bool dot = false;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!dot && str[i] == '.')
        {
            dot = true;
            continue;
        }
        if (!std::isdigit(str[i]))
            return true;
    }
    return false;
}

static double get_bitcoin(std::string const &input)
{
    std::string str = input;
    size_t end = str.find('|');
    if (end == std::string::npos)
        return -1;
    str = str.substr(end + 1, str.length() - end - 1);
    size_t begin = str.find_first_not_of(" \t");
    end = str.find_last_not_of(" \t");
    if (begin != std::string::npos || end != std::string::npos || end != begin)
        str = str.substr(begin, end - begin + 1);
    if (str.empty() || ft_NaN(str))
        return (10000);
    char *endptr;
    double i = std::strtod(str.c_str(), &endptr);
    if (*endptr != '\0')
        return -1;
    if (i == std::numeric_limits< double >::infinity() || i == -std::numeric_limits< double >::infinity() ||
        i == std::numeric_limits< double >::quiet_NaN())
        return -1;
    if (i > 1000)
        return 3000000000;
    return i;
}

static std::string get_date_string(std::string const &input)
{
    std::string str = input;
    size_t end = str.find('|');
    if (end == std::string::npos)
    {
        size_t begin = str.find_first_not_of(" \t");
        end = str.find_last_not_of(" \t");
        if (begin == std::string::npos || end == std::string::npos || end <= begin)
            return "";
        str = str.substr(begin, end - begin + 1);
        return str;
    }
    else
    {
        str = str.substr(0, end);
        size_t begin = str.find_first_not_of(" \t");
        end = str.find_last_not_of(" \t");
        if (begin == std::string::npos || end == std::string::npos || end <= begin)
            return "";
        str = str.substr(begin, end - begin + 1);
        return str;
    }
}

static std::string get_nearest_date(std::map< std::string, float > data, std::string date)
{
    std::map< std::string, float >::iterator it = data.begin();
    std::string nearest_date;
    while (it != data.end())
    {
        if (it->first < date)
        {
            nearest_date = it->first;
        }
        it++;
    }
    return (nearest_date);
}

void BitcoinExchange::setOutput(void)
{
    std::stringstream ss;
    for (std::list< std::string >::iterator it = input.begin(); it != input.end(); ++it)
    {
        std::string date = get_date_string(*it);
        if (ft_validate_date(date, 0))
        {
            ss << std::fixed << "Error: Invalid Date " << date << std::endl;
            continue;
        }
        if (data.find(date) == data.end())
        {
            ss << std::fixed << date << " => ";
            date = get_nearest_date(data, date);
        }
        else
            ss << std::fixed << date << " => ";
        double i = get_bitcoin(*it);
        if (i < 0 || i > INT_MAX || i == 10000)
        {
            if (i < 0)
                ss << "Error: Negativ" << std::endl;
            else if (i == 10000)
                ss << "Number not valid" << std::endl;
            else
                ss << "Error: Number too big" << std::endl;
            continue;
        }
        double rate = data.find(date)->second;
        ss << std::setprecision(2) << i << " | " << std::setprecision(2) << (i * rate) << std::endl;
    }
    output = ss.str();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy) { *this = copy; }

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange const &BitcoinExchange::operator=(BitcoinExchange const &copy)
{
    if (this == &copy)
        data = copy.data;
    return *this;
}

const std::map< std::string, float > BitcoinExchange::getDataMap(void) const { return (data); }

const char *BitcoinExchange::InvalidDateException::what() const throw() { return ("Error: Invalid date."); }

const char *BitcoinExchange::InvalidRateException::what() const throw() { return ("Error: Number."); }

const char *BitcoinExchange::InvalidFileException::what() const throw() { return ("Error: File could not be opened."); }

bool BitcoinExchange::ft_validate_date(std::string date, bool limit)
{
    if (date.length() != 10 || date == "2009-01-01")
        return true;
    for (unsigned int i = 0; i < date.length(); i++)
    {
        if (i == 4 || i == 7)
        {
            if (date[i] != '-')
                return true;
        }
        else if (!std::isdigit(date[i]))
            return true;
    }
    char *end;
    unsigned int year = std::strtol(date.substr(0, 4).c_str(), &end, 10);
    if (*end)
        return true;
    if (limit && (year < 2009 || year > 2022))
        return true;
    if (!limit && (year < 2009))
        return true;
    bool leap_year = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    unsigned int month = std::strtol(date.substr(5, 2).c_str(), &end, 10);
    if (*end)
        return true;
    if (month < 1 || month > 12)
        return true;
    unsigned int day = std::strtol(date.substr(8, 2).c_str(), &end, 10);
    if (*end)
        return true;
    if (day < 1 || day > 31)
        return true;
    if (month == 2)
    {
        if (leap_year && day > 29)
            return true;
        else if (!leap_year && day > 28)
            return true;
    }
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return true;
    return false;
}

bool BitcoinExchange::ft_validate_rate(std::string exchange)
{
    bool dot = false;
    for (unsigned int i = 0; i < exchange.length(); i++)
    {
        if (i == 0 && exchange[i] == '+')
            continue;
        else if (exchange[i] == '.')
        {
            if (dot)
                return true;
            dot = true;
        }
        else if (!std::isdigit(exchange[i]))
            return true;
    }
    char *end;
    float rate = std::strtof(exchange.c_str(), &end);
    if (*end)
        return true;
    if (rate == std::numeric_limits< float >::infinity() || rate == -std::numeric_limits< float >::infinity() ||
        rate == std::numeric_limits< float >::quiet_NaN())
        return true;
    return false;
}

const std::string BitcoinExchange::getOutput(void) const { return (output); }

std::ostream &operator<<(std::ostream &os, BitcoinExchange const &btc)
{
    os << btc.getOutput();
    return (os);
}
