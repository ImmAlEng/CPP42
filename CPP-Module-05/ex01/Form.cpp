/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:59:59 by iengels           #+#    #+#             */
/*   Updated: 2023/10/30 12:51:41 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : name("default"), is_signed(false), sign_grade(42), exec_grade(42)
{
    std::cout << "Form default constructor is called - " << name << " form  with sign_grade "
              << sign_grade << " and exec_grade " << exec_grade << " was created. Signed? " << (is_signed ? "Yes" : "No") << std::endl;
}

Form::Form(const std::string &name, const size_t &sign_grade, const size_t &exec_grade) : name(name), is_signed(false), sign_grade(sign_grade), exec_grade(exec_grade)
{
    std::cout << "Form normal constructor is called - " << name << " form  with sign_grade "
              << sign_grade << " and exec_grade " << exec_grade << " was created. Signed? " << (is_signed ? "Yes" : "No") << std::endl;
}

Form::Form(Form const &copy) : name(copy.getName()), sign_grade(copy.getSignGrade()), exec_grade(copy.getExecGrade())
{
    std::cout << "Form copy constructor is called - " << name << " form  with sign_grade "
              << sign_grade << " and exec_grade " << exec_grade << " was created. Signed? " << (is_signed ? "Yes" : "No") << std::endl;
    *this = copy;
}

Form::~Form()
{
    std::cout << "Form deconstructor is called - " << name << " form  with sign_grade "
              << sign_grade << " and exec_grade " << exec_grade << " was destroyed. Signed? " << (is_signed ? "Yes" : "No") << std::endl;
}

Form const &Form::operator=(Form const &copy)
{
    std::cout << "Form assignment operator is called" << std::endl;
    if (this != &copy)
    {
        is_signed = copy.getIsSigned();
    }
    return (*this);
}

std::string const &Form::getName(void) const
{
    return (name);
}

const bool &Form::getIsSigned(void) const
{
    return (is_signed);
}

size_t const &Form::getSignGrade(void) const
{
    return (sign_grade);
}

size_t const &Form::getExecGrade(void) const
{
    return (exec_grade);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->getSignGrade())
        throw(Form::GradeTooLowException());
    else
        is_signed = true;
}

char const *Form::GradeTooHighException::what() const throw()
{
    return ("Grade is to high!");
}

char const *Form::GradeTooLowException::what() const throw()
{
    return ("Grade is to low!");
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{

    out << form.getName() << ": sign_grade: " << form.getSignGrade() << ", exec_grade: " << form.getExecGrade() << " - is Signed? "
        << (form.getIsSigned() ? "Yes" : "No");
    return (out);
}
