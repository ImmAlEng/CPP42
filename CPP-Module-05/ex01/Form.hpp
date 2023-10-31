/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:10:19 by iengels           #+#    #+#             */
/*   Updated: 2023/10/31 19:12:01 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#pragma once

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool is_signed;
        const size_t sign_grade;
        const size_t exec_grade;

    public:
        Form(void);
        Form(const std::string& name, const size_t& sign_grade, const size_t& exec_grade);
        Form(Form const &copy);
        ~Form();

        Form const& operator= (Form const &copy);

        const std::string& getName(void) const;
        bool const& getIsSigned(void) const;
        const size_t& getSignGrade(void) const;
        const size_t& getExecGrade(void) const;

        void beSigned(Bureaucrat &bureaucrat);

        class GradeTooHighException : public std::exception
        {
            virtual const char *what(void) const throw();
        };
        class GradeTooLowException : public std::exception
        {
            virtual const char * what(void) const throw();
        };

};

std::ostream& operator<<(std::ostream &out, Form const& form);

#endif
