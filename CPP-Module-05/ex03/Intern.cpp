/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:26:28 by iengels           #+#    #+#             */
/*   Updated: 2023/10/31 19:02:31 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
    std::cout << "Intern default constructor called - Intern created" << std::endl;
}

Intern::Intern(Intern const &copy)
{
    std::cout << "Intern copy constructor called - Intern created" << std::endl;
    *this = copy;
}

Intern::~Intern()
{
    std::cout << "Intern deconstructor called - Intern destroyed" << std::endl;
}

Intern const &Intern::operator=(Intern const &copy)
{
    std::cout << "Intern assignment operator called" << std::endl;
    (void)copy;
    return (*this);
}

AForm *Intern::makeForm(const std::string &name, const std::string &target) const
{
    int i = 0;

    const std::string forms[3] = {
        "robotomy request",
        "shrubbery request",
        "presidential request"};

    AForm *(Intern::*function[])(const std::string &target) const = {
        &Intern::makeRobo,
        &Intern::makePresident,
        &Intern::makeShrub};
    i = 0;
    while (i < 3)
    {
        if (name == forms[i])
            break;
        i++;
    }
    switch (i)
    {
        case 0:
            return (this->*function[0])(target);
        case 1:
            return (this->*function[1])(target);
        case 2:
            return (this->*function[2])(target);
        default:
        {
            std::cout << "Intern can not create form: " << name << ", because name does not match any known form" << std::endl;
            return NULL;
        }
    }
}

AForm *Intern::makeRobo(const std::string &target) const
{
    std::cout << "Intern creates RobotomyRequestForm" << std::endl;
    return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresident(const std::string &target) const
{
    std::cout << "Intern creates PresidentialPardonForm" << std::endl;
    return (new PresidentialPardonForm(target));
}

AForm *Intern::makeShrub(const std::string &target) const
{
    std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
    return (new ShrubberyCreationForm(target));
}
