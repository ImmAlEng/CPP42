/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:37:34 by iengels           #+#    #+#             */
/*   Updated: 2023/09/21 15:53:35 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
private:
    std::string _firstname;
    std::string _lastname;
    std::string _phonenumber;
    std::string _nickname;
    std::string _secret;

public:
    // Constructor and Deconstructor
    Contact(void);
    ~Contact(void);

    // Getter methods
    const std::string& get_firstname() const;
    const std::string& get_lastname() const;
    const std::string& get_phonenumber() const;
    const std::string& get_nickname() const;
    const std::string& get_secret() const;

    // Setter methods
    void set_firstname(const std::string& firstname);
    void set_lastname(const std::string& lastname);
    void set_phonenumber(const std::string& phonenumber);
    void set_nickname(const std::string& nickname);
    void set_secret(const std::string& secret);

    // Process Input
    std::string trimAndReduceWhitespace(const std::string& input);
};

#endif