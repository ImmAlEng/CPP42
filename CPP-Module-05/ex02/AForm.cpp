/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:24:36 by iengels           #+#    #+#             */
/*   Updated: 2023/10/31 01:21:58 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : name("default"), is_signed(false), sign_grade(42), exec_grade(42)
{
    std::cout << "AForm default constructor is called - " << name << " Aform  with sign_grade "
              << sign_grade << " and exec_grade " << exec_grade << " was created. Signed? " << (is_signed ? "Yes" : "No") << std::endl;
}

AForm::AForm(const std::string &name, const size_t &sign_grade, const size_t &exec_grade) : name(name), is_signed(false), sign_grade(sign_grade), exec_grade(exec_grade)
{
    std::cout << "AForm normal constructor is called - " << name << " Aform  with sign_grade "
              << sign_grade << " and exec_grade " << exec_grade << " was created. Signed? " << (is_signed ? "Yes" : "No") << std::endl;
}

AForm::AForm(AForm const &copy) : name(copy.getName()), sign_grade(copy.getSignGrade()), exec_grade(copy.getExecGrade())
{
    std::cout << "AForm copy constructor is called - " << name << " Aform  with sign_grade "
              << sign_grade << " and exec_grade " << exec_grade << " was created. Signed? " << (is_signed ? "Yes" : "No") << std::endl;
    *this = copy;
}

AForm::~AForm()
{
    std::cout << "AForm deconstructor is called - " << name << " Aform  with sign_grade "
              << sign_grade << " and exec_grade " << exec_grade << " was destroyed. Signed? " << (is_signed ? "Yes" : "No") << std::endl;
}

AForm const &AForm::operator=(AForm const &copy)
{
    std::cout << "AForm assignment operator is called" << std::endl;
    if (this != &copy)
    {
        is_signed = copy.getIsSigned();
    }
    return (*this);
}

std::string const &AForm::getName(void) const
{
    return (name);
}

const bool &AForm::getIsSigned(void) const
{
    return (is_signed);
}

size_t const &AForm::getSignGrade(void) const
{
    return (sign_grade);
}

size_t const &AForm::getExecGrade(void) const
{
    return (exec_grade);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->getSignGrade())
        throw(AForm::GradeTooLowException());
    else
        is_signed = true;
}

char const *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is to high!");
}

char const *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is to low!");
}

char const *AForm::FormNotSignedException::what() const throw()
{
    return ("Form is not signed!");
}

std::ostream &operator<<(std::ostream &out, AForm const &Aform)
{

    out << Aform.getName() << ": sign_grade: " << Aform.getSignGrade() << ", exec_grade: " << Aform.getExecGrade() << " - is Signed? "
        << (Aform.getIsSigned() ? "Yes" : "No");
    return (out);
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!getIsSigned())
        throw AForm::FormNotSignedException();
    if (getExecGrade() < executor.getGrade())
        throw AForm::GradeTooLowException();
    execute_ok();    
}
