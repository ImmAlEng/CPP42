/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:22:59 by iengels           #+#    #+#             */
/*   Updated: 2023/11/22 18:40:20 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static bool is_operator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
        return (true);
    return (false);
}

static void check_input(std::string input)
{
    for (int i = 0; input[i]; i++)
    {
        if (input[i] != ' ' && !isdigit(input[i]) && !is_operator(input[i]))
            throw RPN_InvalidInput();
        if (i == 0 && is_operator(input[i]))
            throw RPN_NotEnoughOperants();
        if (is_operator(input[i]) && (isdigit(input[i + 1]) || isdigit(input[i - 1])))
            throw RPN_InvalidInput();
    }
}

void ft_check_over_underflow(int b, int a, char c)
{
    if (b == 0 || a == 0)
            return;
    if (c == '+' && (b > 0 && a > std::numeric_limits<int>::max() - b))
        throw RPN_IntegerOverflow();
    else if (c == '-' && (b > 0 && a < std::numeric_limits<int>::min() + b))
        throw RPN_IntegerOverflow();
    else if (c == '*' && ((a > 0 && b > 0 && a > std::numeric_limits<int>::max() / b) ||
                          (a < 0 && b > 0 && a < std::numeric_limits<int>::min() / b) ||
                          (a > 0 && b < 0 && b < std::numeric_limits<int>::min() / a) ||
                          (a < 0 && b < 0 && a < std::numeric_limits<int>::max() / b)))
        throw RPN_IntegerOverflow();
}

static int getint(std::string input, int *i)
{
    size_t result = 0;
    while (isdigit(input[*i]) && result < INT_MAX)
    {
        result = result * 10 + input[*i] - '0';
        (*i)++;
    }
    if (result > 9)
        throw RPN_InvalidInput();
    return (result);
}

void ft_rpn(std::string input)
{
    check_input(input);
    std::stack<int> stack;
    for (int i = 0; input[i]; i++)
    {
        if (input[i] == ' ')
            continue;
        if (isdigit(input[i]))
            stack.push(getint(input, &i));
        else if (is_operator(input[i]))
        {
            if (stack.size() < 2)
                throw RPN_NotEnoughOperants();
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
                ft_check_over_underflow(a, b, input[i]);
            if (input[i] == '+')
                stack.push(b + a);
            else if (input[i] == '-')
                stack.push(b - a);
            else if (input[i] == '*')
                stack.push(b * a);
            else if (input[i] == '/')
            {
                if (a == 0)
                    throw RPN_DivideByZero();
                if (b == 0)
                    stack.push(0);
                else
                    stack.push(b / a);
            }
        }
    }
    if (stack.size() > 1)
        throw RPN_LeftoverOperants();
    std::cout << stack.top() << std::endl;
}

const char *RPN_DivideByZero::what() const throw()
{
    return ("Division by zero");
}

const char *RPN_NotEnoughOperants::what() const throw()
{
    return ("Not enough operants");
}

const char *RPN_InvalidInput::what() const throw()
{
    return ("Invalid input");
}

const char *RPN_LeftoverOperants::what() const throw()
{
    return ("Leftover operants");
}

const char *RPN_IntegerOverflow::what() const throw()
{
    return ("Integer overflow");
}
