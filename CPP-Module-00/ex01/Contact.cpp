/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:38:59 by iengels           #+#    #+#             */
/*   Updated: 2023/09/17 15:40:17 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

// Getter methods (const-correctness)
const std::string& Contact::get_firstname() const
{
    return _firstname;
}

const std::string& Contact::get_lastname() const
{
    return _lastname;
}

const std::string& Contact::get_phonenumber() const
{
    return _phonenumber;
}

const std::string& Contact::get_nickname() const
{
    return _nickname;
}

const std::string& Contact::get_secret() const
{
    return _secret;
}

void Contact::set_firstname(const std::string& firstname)
{
    _firstname = trimAndReduceWhitespace(firstname);
}

void Contact::set_lastname(const std::string& lastname)
{
    _lastname = trimAndReduceWhitespace(lastname);
}

void Contact::set_phonenumber(const std::string& phonenumber)
{
    _phonenumber = trimAndReduceWhitespace(phonenumber);
}

void Contact::set_nickname(const std::string& nickname)
{
    _nickname = trimAndReduceWhitespace(nickname);
}

void Contact::set_secret(const std::string& secret)
{
    _secret = trimAndReduceWhitespace(secret);
}

std::string Contact::trimAndReduceWhitespace(const std::string& input)
{
    std::string result;
    bool previousCharWasWhitespace = false;

    for (size_t i = 0; i < input.length(); ++i)
    {
        char c = input[i];
        if (c == ' ' || (c >= '\t' && c <= '\r'))
        {
            if (!previousCharWasWhitespace)
            {
                result += ' ';
                previousCharWasWhitespace = true;
            }
        }
        else
        {
            result += c;
            previousCharWasWhitespace = false;
        }
    }

    size_t start = result.find_first_not_of(" \t\v\f\r\n");
    size_t end = result.find_last_not_of(" \t\v\f\r\n");

    if (start != std::string::npos && end != std::string::npos)
    {
        return result.substr(start, end - start + 1);
    }
    else
    {
        return "";
    }
}
