/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:33:30 by iengels           #+#    #+#             */
/*   Updated: 2023/09/18 12:16:57 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>

class PhoneBook
{
    private:
        Contact _contacts[8];
        int _index;

    public:
        PhoneBook(void);
        ~PhoneBook(void);

        void add(void);
        void search(void);
        void display(int index);
        void list(void);
        bool str_is_empty(const std::string &str);
        std::string allign(std::string str);
};

#endif