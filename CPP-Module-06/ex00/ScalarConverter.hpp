/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:36:11 by iengels           #+#    #+#             */
/*   Updated: 2023/11/09 16:07:20 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <climits>
#include <cstdlib>
#include <limits>
#include <sstream>
#pragma once

class ScalarConverter
{
    private:
        const std::string literal;
        std::string type;
        char t_char;
        double t_double;
        float t_float;
        int t_int;
        bool no_literal;
        bool no_int;
        bool no_char;
        bool no_print;
        ScalarConverter(void);

    public:
        ScalarConverter(const std::string &l);
        ScalarConverter(ScalarConverter const& copy);
        ~ScalarConverter();

        ScalarConverter const &operator=(ScalarConverter const &copy);
        void setFromDouble(void);
        void setFromFloat(void);
        bool setType(void);
        void setFromInt(void);
        void setFromChar(void);
        void setFromNaN_Inf(void);

        bool isChar(void) const;
        bool isInt(void) const;
        bool isFloat(void) const;
        bool isDouble(void) const;
        bool isNaN_Inf(void) const;
        
        double getDouble(void) const;
        std::string getLiteral(void) const;
        float getFloat(void) const;
        std::string getType(void) const;
        int getInt(void) const;
        char getChar(void) const;

        bool getIntB(void) const;
        bool getCharB(void) const;
        bool getPrintB(void) const;
        bool getLiteralB(void) const;

        void convert(void);

};

std::ostream &	operator<<(std::ostream &os, ScalarConverter const &ScalarConverter);

#endif
