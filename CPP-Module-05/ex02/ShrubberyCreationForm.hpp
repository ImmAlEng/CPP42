/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 23:18:09 by iengels           #+#    #+#             */
/*   Updated: 2023/10/31 19:17:12 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP 

#include "AForm.hpp"
#include <fstream>
#pragma once

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
        
    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(ShrubberyCreationForm const &copy);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm const &operator=(ShrubberyCreationForm const &copy);

        void execute_ok(void) const;

};

#endif
