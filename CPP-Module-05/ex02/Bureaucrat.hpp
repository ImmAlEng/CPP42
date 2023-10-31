/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:22:37 by iengels           #+#    #+#             */
/*   Updated: 2023/10/31 02:08:55 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"
#pragma once

class AForm;

class Bureaucrat
{
    private:
        const std::string name;
        size_t grade;
    public:
        Bureaucrat(void);
        Bureaucrat(const std::string &name, size_t grade);
        Bureaucrat(Bureaucrat const &copy);
        ~Bureaucrat();

        Bureaucrat const& operator=(Bureaucrat const &copy);

        std::string const &getName(void) const;
        size_t const &getGrade(void) const;

        void increase_Grade(void);
        void decrease_Grade(void);

        void signAForm(AForm &aform);
        void executeForm(AForm const & aform) const;

        class   GradeTooHighException : public std::exception
        {
            public:
				virtual char const	*what(void) const throw();

        };
        class GradeTooLowException : public std::exception
        {
            public:
				virtual char const	*what(void) const throw();
        };
};

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif