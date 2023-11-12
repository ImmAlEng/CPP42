/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:24:24 by iengels           #+#    #+#             */
/*   Updated: 2023/10/31 19:16:45 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#pragma once

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool is_signed;
        const size_t sign_grade;
        const size_t exec_grade;

    public:
        virtual void execute_ok(void) const = 0;
        AForm(void);
        AForm(const std::string& name, const size_t& sign_grade, const size_t& exec_grade);
        AForm(AForm const &copy);
        virtual ~AForm();

        AForm const& operator= (AForm const &copy);

        const std::string& getName(void) const;
        bool const& getIsSigned(void) const;
        const size_t& getSignGrade(void) const;
        const size_t& getExecGrade(void) const;

        void execute(Bureaucrat const & executor) const;
        void beSigned(Bureaucrat &bureaucrat);

        class GradeTooHighException : public std::exception
        {
            virtual const char *what(void) const throw();
        };
        class GradeTooLowException : public std::exception
        {
            virtual const char * what(void) const throw();
        };
        class FormNotSignedException : public std::exception {
			public:
				virtual const char *	what() const throw();
		};
};

std::ostream& operator<<(std::ostream &out, AForm const& Aform);

#endif
