/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 23:25:19 by iengels           #+#    #+#             */
/*   Updated: 2023/10/31 01:37:52 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), target("default")
{
    std::cout << "RobotomyRequestForm default constructor is called - " << getName() << " RobotomyRequestForm  with sign_grade "
              << getSignGrade() << " and exec_grade " << getExecGrade() << " was created. Signed? " << (getIsSigned() ? "Yes" : "No") 
              << "! Target: " << target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
    std::cout << "RobotomyRequestForm normal constructor is called - " << getName() << " RobotomyRequestForm  with sign_grade "
              << getSignGrade() << " and exec_grade " << getExecGrade() << " was created. Signed? " << (getIsSigned() ? "Yes" : "No")
              << "! Target: " << target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm(copy.getName(), copy.getSignGrade(), copy.getExecGrade()), target(copy.target)
{
    std::cout << "RobotomyRequestForm copy constructor is called - " << getName() << " RobotomyRequestForm  with sign_grade "
              << getSignGrade() << " and exec_grade " << getExecGrade() << " was created. Signed? " << (getIsSigned() ? "Yes" : "No")
              << "! Target: " << target << std::endl;
    *this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm deconstructor is called - " << getName() << " RobotomyRequestForm  with sign_grade "
              << getSignGrade() << " and exec_grade " << getExecGrade() << " was destroyed. Signed? " << (getIsSigned() ? "Yes" : "No")
              << "! Target: " << target << std::endl;
}

RobotomyRequestForm const &RobotomyRequestForm::operator=(RobotomyRequestForm const &copy)
{
    std::cout << "RobotomyRequestForm assignment operator is called" << std::endl;
    if (this != &copy)
    {
        AForm::operator=(copy);
    }
    return (*this);
}

void RobotomyRequestForm::execute_ok(void) const
{
    if (std::rand() % 2)
        std::cout << "* drilling noises * " << target << " has been robotomized" << std::endl;
    else
        std::cout << "Robotomy on " << target << "has failed" << std::endl;
}
