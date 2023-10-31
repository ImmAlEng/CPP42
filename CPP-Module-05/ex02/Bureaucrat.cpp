/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 23:10:41 by iengels           #+#    #+#             */
/*   Updated: 2023/10/31 02:01:10 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("Default"), grade(42)
{
    std::cout << "Bureaucrat default constructor called - " << name << " created with grade " << grade << "." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, size_t grade) : name(name), grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << "Bureaucrat naming constructor called - " << name << " created with grade " << grade << "." << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : name(copy.getName())
{
    std::cout << "Bureaucrat copy constructor called - " << name << " created with grade " << grade << "." << std::endl;
    *this = copy;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat deconstructor called - " << name << " with grade " << grade << " destroyed." << std::endl;
}

Bureaucrat const &Bureaucrat::operator=(Bureaucrat const &copy)
{
    std::cout << "Bureaucrat assignment operator called." << std::endl;
    if (this != &copy)
        grade = copy.getGrade();
    return (*this);
}

std::string const &Bureaucrat::getName(void) const
{
    return (this->name);
}

size_t const &Bureaucrat::getGrade(void) const
{
    return (this->grade);
}

void Bureaucrat::increase_Grade(void)
{
    if (grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        grade++;
}

void Bureaucrat::decrease_Grade(void)
{
    if (grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        grade--;
}

void Bureaucrat::signAForm(AForm &aform)
{
    try
    {
        aform.beSigned(*this);
        std::cout << "Bureaucrat " << this->getName() << " has signed " << aform.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << this->getName() << " couldn’t sign " << aform.getName() << " because " << e.what() << "." << std::endl;
    }
}

char const *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is to high!");
}

char const *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is to low!");
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{

    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return (out);
}

void Bureaucrat::executeForm(AForm const &aform) const
{
    try
    {
        aform.execute(*this);
        std::cout << getName() << " executed " << aform.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << this->getName() << " couldn’t execute " << aform.getName() << " because " << e.what() << "." << std::endl;
    }
}
