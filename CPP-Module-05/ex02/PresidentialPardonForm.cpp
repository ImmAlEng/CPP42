/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 23:24:40 by iengels           #+#    #+#             */
/*   Updated: 2023/10/31 01:38:54 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), target("home")
{
    std::cout << "PresidentialPardonForm default constructor is called - " << getName() << " PresidentialPardonForm  with sign_grade "
              << getSignGrade() << " and exec_grade " << getExecGrade() << " was created. Signed? " << (getIsSigned() ? "Yes" : "No")
              << "! Target: " << target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
    std::cout << "PresidentialPardonForm normal constructor is called - " << getName() << " PresidentialPardonForm  with sign_grade "
              << getSignGrade() << " and exec_grade " << getExecGrade() << " was created. Signed? " << (getIsSigned() ? "Yes" : "No")
              << "! Target: " << target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : AForm(copy.getName(), copy.getSignGrade(), copy.getExecGrade()), target(copy.target)
{
    std::cout << "PresidentialPardonForm copy constructor is called - " << getName() << " PresidentialPardonForm  with sign_grade "
              << getSignGrade() << " and exec_grade " << getExecGrade() << " was created. Signed? " << (getIsSigned() ? "Yes" : "No")
              << "! Target: " << target << std::endl;
    *this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm deconstructor is called - " << getName() << " PresidentialPardonForm  with sign_grade "
              << getSignGrade() << " and exec_grade " << getExecGrade() << " was destroyed. Signed? " << (getIsSigned() ? "Yes" : "No")
              << "! Target: " << target << std::endl;
}

PresidentialPardonForm const &PresidentialPardonForm::operator=(PresidentialPardonForm const &copy)
{
    std::cout << "PresidentialPardonForm assignment operator is called" << std::endl;
    if (this != &copy)
    {
        AForm::operator=(copy);
    }
    return (*this);
}

void PresidentialPardonForm::execute_ok(void) const
{
    std::cout << "We inform that " << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
