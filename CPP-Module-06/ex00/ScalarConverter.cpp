/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:11:14 by iengels           #+#    #+#             */
/*   Updated: 2023/11/09 16:07:32 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static const std::string trunctzeros(const std::string &str)
{
    // Remove leading zeros
    size_t i = 0;
    if (str.empty())
        return ("NO!");
    while (str[i] == '0' && str[i + 1])
        i++;
    std::string newstr = str.substr(i, str.length() - i);
    return (newstr);
}

ScalarConverter::ScalarConverter(const std::string &l) : literal(trunctzeros(l)), type("Unknown"), t_char(0), t_double(0.0), t_float(0.0f), t_int(0), no_literal(0), no_int(0), no_char(0), no_print(0)
{
    if (setType())
    {
        convert();
    }
    else
    {
        no_literal = true;
    }
    std::cout << "ScalarConverter constructor called - Object created" << std::endl;
}

ScalarConverter::~ScalarConverter(void)
{
    std::cout << "ScalarConverter destructor called - Object destroyed" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &copy) : literal(copy.literal)
{
    *this = copy;
    std::cout << "ScalarConverter copy constructor called - Object copied" << std::endl;
}

ScalarConverter::ScalarConverter(void) : literal("default"), type("Unknown"), t_char(0), t_double(0.0), t_float(0.0f), t_int(0), no_literal(0), no_int(0), no_char(0), no_print(0)
{
    std::cout << "ScalarConverter default constructor called - Object created" << std::endl;
}

ScalarConverter const &ScalarConverter::operator=(ScalarConverter const &copy)
{
    if (this != &copy)
    {
        type = copy.type;
        t_char = copy.t_char;
        t_double = copy.t_double;
        t_float = copy.t_float;
        t_int = copy.t_int;
        no_int = copy.no_int;
        no_char = copy.no_char;
        no_literal = copy.no_literal;
        no_print = copy.no_print;
    }
    std::cout << "ScalarConverter assignation operator called - Object assigned" << std::endl;
    return (*this);
}

bool ScalarConverter::setType(void)
{
    if (isNaN_Inf())
    {
        type = "NaN_Inf";
        return (true);
    }
    else if (isInt())
    {
        type = "int";
        return (true);
    }
    else if (isChar())
    {
        type = "char";
        return (true);
    }
    else if (isFloat())
    {
        type = "float";
        return (true);
    }
    else if (isDouble())
    {
        type = "double";
        return (true);
    }
    return (false);
}

std::string ScalarConverter::getLiteral(void) const
{
    return (literal);
}

void ScalarConverter::setFromDouble()
{
    char *end;
    t_double = std::strtod(literal.c_str(), &end);
    t_float = static_cast<float>(t_double);
    t_int = static_cast<int>(t_double);
    t_char = static_cast<char>(t_double);
    if (t_double < std::numeric_limits<int>::min() || t_double > std::numeric_limits<int>::max())
        no_int = true;
    if (t_double < 0 || t_double > 127)
        no_char = true;
    else if (!std::isprint(t_char))
        no_print = true;
}

void ScalarConverter::setFromFloat()
{
    char *end;
    t_float = std::strtof(literal.c_str(), &end);
    t_double = static_cast<double>(t_float);
    t_int = static_cast<int>(t_float);
    t_char = static_cast<char>(t_float);
    if (t_double < 0 || t_double > 127)
        no_char = true;
    else if (!std::isprint(t_char))
        no_print = true;
}

void ScalarConverter::setFromInt()
{
    char *end;
    t_int = std::strtol(literal.c_str(), &end, 10);
    t_double = static_cast<double>(t_int);
    t_float = static_cast<float>(t_int);
    t_char = static_cast<char>(t_int);
    if (t_int < 0 || t_int > 127)
        no_char = true;
    else if (!std::isprint(t_char))
        no_print = true;
}

void ScalarConverter::setFromChar()
{
    t_char = literal[0];
    t_double = static_cast<double>(t_char);
    t_float = static_cast<float>(t_char);
    t_int = static_cast<int>(t_char);
}

void ScalarConverter::setFromNaN_Inf(void)
{
    if (literal == "nan" || literal == "nanf")
    {
        t_double = std::numeric_limits<double>::quiet_NaN();
        t_float = std::numeric_limits<float>::quiet_NaN();
        no_int = true;
        no_char = true;
    }
    else if (literal == "inf" || literal == "inff")
    {
        t_double = std::numeric_limits<double>::infinity();
        t_float = std::numeric_limits<float>::infinity();
        no_int = true;
        no_char = true;
    }
    else if (literal == "-inf" || literal == "-inff")
    {
        t_double = -std::numeric_limits<double>::infinity();
        t_float = -std::numeric_limits<float>::infinity();
        no_int = true;
        no_char = true;
    }
}

bool ScalarConverter::isNaN_Inf(void) const
{
    if (literal == "nan" || literal == "nanf" || literal == "inf" || literal == "inff" || literal == "-inf" || literal == "-inff")
        return (true);
    return (false);
}

bool ScalarConverter::isChar(void) const
{
    if (literal.length() == 1)
    {
        if (std::isprint(literal[0]))
            return (true);
    }
    return (false);
}

bool ScalarConverter::isInt(void) const
{
    for (unsigned int i = 0; i < literal.length(); i++)
    {
        if (i == 0 && (literal[i] == '+' || literal[i] == '-'))
            i++;
        if (!std::isdigit(literal[i]))
            return (false);
    }
    char *end;
    int test = std::strtol(literal.c_str(), &end, 10);
    if (*end != '\0')
        return (false);
    std::stringstream ss;
    ss << test;
    std::string convertedString = ss.str();
    return (convertedString == literal);
}

bool ScalarConverter::isFloat(void) const
{
    int i = 0;
    bool dot = false;
    while (literal[i + 1])
    {
        if (i == 0 && (literal[i] == '+' || literal[i] == '-'))
            i++;
        if (!dot && literal[i] == '.')
        {
            i++;
            dot = true;
        }
        if (!std::isdigit(literal[i]))
            return (false);
        i++;
    }
    if (!dot || literal[i] != 'f')
        return (false);
    char *end;
    std::strtof(literal.c_str(), &end);
    return (*end == 'f');
}

bool ScalarConverter::isDouble(void) const
{
    bool dot = false;
    for (size_t i = 0; i < literal.length(); i++)
    {
        if (i == 0 && (literal[i] == '+' || literal[i] == '-'))
            i++;
        if (!dot && literal[i] == '.')
        {
            i++;
            dot = true;
        }
        if (!std::isdigit(literal[i]))
            return false;
    }
    if (!dot)
        return false;
    char *end;
    std::strtod(literal.c_str(), &end);
    return (*end == '\0');
}

double ScalarConverter::getDouble() const
{
    return t_double;
}

float ScalarConverter::getFloat() const
{
    return t_float;
}

std::string ScalarConverter::getType() const
{
    return type;
}

int ScalarConverter::getInt() const
{
    return t_int;
}

char ScalarConverter::getChar() const
{
    return t_char;
}

bool ScalarConverter::getIntB(void) const
{
    return no_int;
}

bool ScalarConverter::getCharB(void) const
{
    return no_char;
}

bool ScalarConverter::getPrintB(void) const
{
    return no_print;
}

bool ScalarConverter::getLiteralB(void) const
{
    return no_literal;
}

void ScalarConverter::convert(void)
{
    std::string types[5] = {"int", "char", "float", "double", "NaN_Inf"};
    for (int i = 0; i < 5; i++)
    {
        if (types[i] == type)
        {
            switch (i)
            {
            case 0:
                setFromInt();
                return;
            case 1:
                setFromChar();
                return;
            case 2:
                setFromFloat();
                return;
            case 3:
                setFromDouble();
                return;
            case 4:
                setFromNaN_Inf();
                return;
            }
        }
    }
    std::cout << "Error: Invalid type" << std::endl;
}

std::ostream &operator<<(std::ostream &os, ScalarConverter const &ScalarConverter)
{
    if (ScalarConverter.getLiteralB())
    {
        os << "Error: Invalid literal" << std::endl;
        return (os);
    }
    os << "Literal: " << ScalarConverter.getLiteral() << std::endl;
    os << "Type: " << ScalarConverter.getType() << std::endl;
    if (ScalarConverter.getIntB())
        os << "Int: impossible" << std::endl;
    else
        os << "Int: " << ScalarConverter.getInt() << std::endl;
    if (ScalarConverter.getCharB())
        os << "Char: impossible" << std::endl;
    else if (ScalarConverter.getPrintB())
        os << "Char: Non displayable" << std::endl;
    else
        os << "Char: " << ScalarConverter.getChar() << std::endl;

    if (ScalarConverter.getFloat() - static_cast<int>(ScalarConverter.getFloat()) == 0)
        os << "Float: " << ScalarConverter.getFloat() << ".0f" << std::endl;
    else
        os << "Float: " << ScalarConverter.getFloat() << "f" << std::endl;

    if (ScalarConverter.getDouble() - static_cast<int>(ScalarConverter.getDouble()) == 0)
        os << "Double: " << ScalarConverter.getDouble() << ".0" << std::endl;
    else
        os << "Double: " << ScalarConverter.getDouble() << std::endl;
    return (os);
}
