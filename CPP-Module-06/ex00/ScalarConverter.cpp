/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:11:14 by iengels           #+#    #+#             */
/*   Updated: 2023/11/14 18:34:08 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static const std::string trunctzeros(const std::string &str)
{
    // Remove leading zerstd::cout
    size_t i = 0;
    if (str.empty())
        return ("NO!");
    while (str[i] == '0' && str[i + 1])
        i++;
    std::string newstr = str.substr(i, str.length() - i);
    return (newstr);
}

static void setFromDouble(t_scalar *s)
{
    char *end;
    s->t_double = std::strtod(s->literal.c_str(), &end);
    s->t_float = static_cast<float>(s->t_double);
    s->t_int = static_cast<int>(s->t_double);
    s->t_char = static_cast<char>(s->t_double);
    if (s->t_double < std::numeric_limits<int>::min() || s->t_double > std::numeric_limits<int>::max())
        s->no_int = true;
    if (s->t_double < 0 || s->t_double > 127)
        s->no_char = true;
    else if (!std::isprint(s->t_char))
        s->no_print = true;
}

static void setFromFloat(t_scalar *s)
{
    char *end;
    s->t_float = std::strtof(s->literal.c_str(), &end);
    s->t_double = static_cast<double>(s->t_float);
    s->t_int = static_cast<int>(s->t_float);
    s->t_char = static_cast<char>(s->t_float);
    if (s->t_double < 0 || s->t_double > 127)
        s->no_char = true;
    else if (!std::isprint(s->t_char))
        s->no_print = true;
}

static void setFromInt(t_scalar *s)
{
    char *end;
    s->t_int = std::strtol(s->literal.c_str(), &end, 10);
    s->t_double = static_cast<double>(s->t_int);
    s->t_float = static_cast<float>(s->t_int);
    s->t_char = static_cast<char>(s->t_int);
    if (s->t_int < 0 || s->t_int > 127)
        s->no_char = true;
    else if (!std::isprint(s->t_char))
        s->no_print = true;
}

static void setFromChar(t_scalar *s)
{
    s->t_char = s->literal[0];
    s->t_double = static_cast<double>(s->t_char);
    s->t_float = static_cast<float>(s->t_char);
    s->t_int = static_cast<int>(s->t_char);
}

static void setFromNaN_Inf(t_scalar *s)
{
    if (s->literal == "nan" || s->literal == "nanf")
    {
        s->t_double = std::numeric_limits<double>::quiet_NaN();
        s->t_float = std::numeric_limits<float>::quiet_NaN();
        s->no_int = true;
        s->no_char = true;
    }
    else if (s->literal == "inf" || s->literal == "inff")
    {
        s->t_double = std::numeric_limits<double>::infinity();
        s->t_float = std::numeric_limits<float>::infinity();
        s->no_int = true;
        s->no_char = true;
    }
    else if (s->literal == "-inf" || s->literal == "-inff")
    {
        s->t_double = -std::numeric_limits<double>::infinity();
        s->t_float = -std::numeric_limits<float>::infinity();
        s->no_int = true;
        s->no_char = true;
    }
}

static bool isNaN_Inf(t_scalar *s)
{
    if (s->literal == "nan" || s->literal == "nanf" || s->literal == "inf" || s->literal == "inff" || s->literal == "-inf" || s->literal == "-inff")
        return (true);
    return (false);
}

static bool isChar(t_scalar *s)
{
    if (s->literal.length() == 1)
    {
        if (std::isprint(s->literal[0]))
            return (true);
    }
    return (false);
}

static bool isInt(t_scalar *s)
{
    for (unsigned int i = 0; i < s->literal.length(); i++)
    {
        if (i == 0 && (s->literal[i] == '+' || s->literal[i] == '-'))
            i++;
        if (!std::isdigit(s->literal[i]))
            return (false);
    }
    char *end;
    int test = std::strtol(s->literal.c_str(), &end, 10);
    if (*end != '\0')
        return (false);
    std::stringstream ss;
    ss << test;
    std::string convertedString = ss.str();
    return (convertedString == s->literal);
}

static bool isFloat(t_scalar *s)
{
    int i = 0;
    bool dot = false;
    if (s->literal.empty() || s->literal[0] == '\0')
        return false;
    while (s->literal[i] && s->literal[i + 1])
    {
        if (i == 0 && (s->literal[i] == '+' || s->literal[i] == '-'))
            i++;
        if (!dot && s->literal[i] == '.')
        {
            i++;
            dot = true;
        }
        if (!std::isdigit(s->literal[i]))
            return (false);
        i++;
    }
    if (!dot || s->literal[i] != 'f')
        return (false);
    char *end;
    std::strtof(s->literal.c_str(), &end);
    return (*end == 'f');
}

static bool isDouble(t_scalar *s)
{
    bool dot = false;
    for (size_t i = 0; i < s->literal.length(); i++)
    {
        if (i == 0 && (s->literal[i] == '+' || s->literal[i] == '-'))
            i++;
        if (!dot && s->literal[i] == '.')
        {
            i++;
            dot = true;
        }
        if (!std::isdigit(s->literal[i]))
            return false;
    }
    if (!dot)
        return false;
    char *end;
    std::strtod(s->literal.c_str(), &end);
    return (*end == '\0');
}

void print_scalar(t_scalar *s)
{
    if (s->no_literal)
    {
        std::cout << "Error: Invalid literal" << std::endl;
        return;
    }
    std::cout << "Literal: " << s->literal << std::endl;
    std::cout << "Type: " << s->type << std::endl;
    if (s->no_int)
        std::cout << "Int: impossible" << std::endl;
    else
        std::cout << "Int: " << s->t_int << std::endl;
    if (s->no_char)
        std::cout << "Char: impossible" << std::endl;
    else if (s->no_print)
        std::cout << "Char: Non displayable" << std::endl;
    else
        std::cout << "Char: " << s->t_char << std::endl;

    if (s->t_float - static_cast<int>(s->t_float) == 0)
        std::cout << "Float: " << s->t_float << ".0f" << std::endl;
    else
        std::cout << "Float: " << s->t_float << "f" << std::endl;

    if (s->t_double - static_cast<int>(s->t_double) == 0)
        std::cout << "Double: " << s->t_double << ".0" << std::endl;
    else
        std::cout << "Double: " << s->t_double << std::endl;
}

static bool setType(t_scalar *s)
{
    if (isNaN_Inf(s))
    {
        s->type = "NaN_Inf";
        return (true);
    }
    else if (isInt(s))
    {
        s->type = "int";
        return (true);
    }
    else if (isChar(s))
    {
        s->type = "char";
        return (true);
    }
    else if (isFloat(s))
    {
        s->type = "float";
        return (true);
    }
    else if (isDouble(s))
    {
        s->type = "double";
        return (true);
    }
    return (false);
}

static void init_struct(t_scalar *s)
{
    s->literal = "ok";
    s->literal = "ok";
    s->t_char = 0;
    s->t_double = 0;
    s->t_float = 0;
    s->t_int = 0;
    s->no_literal = 0;
    s->no_int = 0;
    s->no_char = 0;
    s->no_print = 0;
}

void ScalarConverter::convert(std::string literal)
{
    t_scalar s;
    init_struct(&s);
    s.literal = trunctzeros(literal);
    if (setType(&s))
    {
        std::string types[5] = {"int", "char", "float", "double", "NaN_Inf"};
        for (int i = 0; i < 5; i++)
        {
            if (types[i] == s.type)
            {
                switch (i)
                {
                case 0:
                    setFromInt(&s);
                    print_scalar(&s);
                    return;
                case 1:
                    setFromChar(&s);
                    print_scalar(&s);
                    return;
                case 2:
                    setFromFloat(&s);
                    print_scalar(&s);
                    return;
                case 3:
                    setFromDouble(&s);
                    print_scalar(&s);
                    return;
                case 4:
                    setFromNaN_Inf(&s);
                    print_scalar(&s);
                    return;
                }
            }
        }
    }
    else
        std::cout << "Error: Invalid type" << std::endl;
}
