/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:32:06 by iengels           #+#    #+#             */
/*   Updated: 2023/09/20 18:20:34 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
    std::cout << "Hi there! This is Eddie, your crappy Phonebook" << std::endl;
    this->_index = 0;
}

PhoneBook::~PhoneBook(void)
{
    std::cout << "Goodbye..." << std::endl;
}

void PhoneBook::add(void)
{
    const char *prompts[] = {
        "First name",
        "Last name",
        "Nickname",
        "Phone number",
        "Darkest secret"};

    for (int i = 0; i < 5; ++i)
    {
        std::string str;
        while (!std::cin.eof())
        {
            std::cout << "Enter " << prompts[i] << ": ";
            if (std::getline(std::cin, str) && !str.empty() && !str_is_empty(str))
            {
                switch (i)
                {
                case 0:
                    this->_contacts[this->_index % 8].set_firstname(str);
                    break;
                case 1:
                    this->_contacts[this->_index % 8].set_lastname(str);
                    break;
                case 2:
                    this->_contacts[this->_index % 8].set_nickname(str);
                    break;
                case 3:
                    this->_contacts[this->_index % 8].set_phonenumber(str);
                    break;
                case 4:
                    this->_contacts[this->_index % 8].set_secret(str);
                    std::cout << "Contact successfully added to phonebook" << std::endl;
                    break;
                }
                break;
            }
        }
    }
    this->_index++;
}

bool PhoneBook::str_is_empty(const std::string &str)
{
    for (int i = 0; str.size() != i; i++)
    {
        if (str[i] != 32 && (str[i] < 9 || str[i] > 13))
            return false;
    }
    return true;
}

void PhoneBook::search(void)
{
    std::string str = "";

    if (_index == 0)
    {
        std::cout << "Oh No! The Phonebook is still empty!" << std::endl;
        return;
    }
    std::cout << std::endl;
    std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
    std::cout << "│     Index│First Name│ Last Name│ Nick Name│" << std::endl;
    std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
    this->list();
    std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;
    std::cout << std::endl;
    std::cout << "Please Enter the index of the Contact you want to display" << std::endl;
    while (!std::cin.eof())
    {
        std::cout << "Select an index: ";
        if (std::getline(std::cin, str) && !str.empty())
        {
            if (str.size() == 1 && str[0] >= '1' && str[0] <= '8' &&
                str[0] - '1' < _index)
                break;
            std::cout << "Invalid index!" << std::endl;
        }
    }
    if (!std::cin.eof())
        this->display(str[0] - 49);
}

void PhoneBook::display(int index)
{
    if (index < 0 || index > 8 || index > _index)
    {
        std::cout << "Invalid contact index." << std::endl;
        return;
    }
    std::cout << std::endl;
    std::cout << "┌────────────────┐" << std::endl;
    std::cout << "│ First Name:    │ " << this->_contacts[index].get_firstname() << std::endl;
    std::cout << "│ Last Name:     │ " << this->_contacts[index].get_lastname() << std::endl;
    std::cout << "│ Nickname:      │ " << this->_contacts[index].get_nickname() << std::endl;
    std::cout << "│ Phone Number:  │ " << this->_contacts[index].get_phonenumber() << std::endl;
    std::cout << "│ Darkest Secret:│ " << this->_contacts[index].get_secret() << std::endl;
    std::cout << "└────────────────┘" << std::endl;
}

void PhoneBook::list(void)
{
    int i = 0;
    while (i < _index && i < 8)
    {
        std::cout << "|" << allign(std::string(1, '1' + i)) << "|";
        std::cout << allign(_contacts[i].get_firstname()) << "|";
        std::cout << allign(_contacts[i].get_lastname()) << "|";
        std::cout << allign(_contacts[i].get_nickname()) << "|" << std::endl;
        i++;
    }
}

std::string PhoneBook::allign(std::string str)
{
    unsigned int n = str.size();                                                                                                                                                                                        ;
    if (n > 10)
    {
        str.resize(10);
        str[9] = '.';
    }
    else if (n < 10)
    {
        while (n++ < 10)
            str = " " + str;
    }
    return str;
}